/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:08:43 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/12 00:08:45 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "CpuModule.hpp"
#include <sstream>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdio.h>

#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

#include <math.h>

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

CpuModule::CpuModule( std::string const & moduleName ) : IMonitorModule(),
	_moduleName(moduleName), _moduleData()
{
	_moduleData.resize(3);
}

CpuModule::~CpuModule( void ) {}

float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
  unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
  unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
  float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
  _previousTotalTicks = totalTicks;
  _previousIdleTicks  = idleTicks;
  return ret;
}

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.
float GetCPULoad()
{
   host_cpu_load_info_data_t cpuinfo;
   mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
   if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
   {
      unsigned long long totalTicks = 0;
      for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
      return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
   }
   else return -1.0f;
}


void                                CpuModule::updateData( void )
{
    char buffer[256];
    size_t bufferlen = 256;

    sysctlbyname("machdep.cpu.brand_string", &buffer, &bufferlen, NULL, 0);
    std::stringstream ss;
    ss << buffer;
    _moduleData[0] = ss.str();

    // std::cout << GetCPULoad() * 100 << std::endl;
    float cpuLoad = GetCPULoad() * 100.0f;

    ss.str(std::string());
    ss << cpuLoad;
    _moduleData[1] = ss.str();
    ss.str(std::string());
    ss << "[ ";
    for (int i = 0; i < static_cast< int >(round(cpuLoad)); ++i)
    {
        ss << "\e[1;91m|\e[0m";
    }
    for (int i = static_cast< int >(round(cpuLoad)); i < 100; ++i)
    {
        ss << " ";
    }
    ss << " ]";
    _moduleData[2] = ss.str();
}

std::vector<std::string> const &    CpuModule::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 CpuModule::getModulName( void ) const
{
	return _moduleName;
}