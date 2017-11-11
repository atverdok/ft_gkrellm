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

CpuModule::CpuModule( std::string const & moduleName ) : IMonitorModule(),
	_moduleName(moduleName), _moduleData()
{
	_moduleData.resize(2);
}

CpuModule::~CpuModule( void ) {}

void                                CpuModule::updateData( void )
{
    char buffer[256];
    size_t bufferlen = 256;

    sysctlbyname("machdep.cpu.brand_string", &buffer, &bufferlen, NULL, 0);
    std::stringstream ss;
    ss << buffer;
    _moduleData[0] = ss.str();

}

std::vector<std::string> const &    CpuModule::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 CpuModule::getModulName( void ) const
{
	return _moduleName;
}