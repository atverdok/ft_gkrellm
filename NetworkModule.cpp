/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:05:42 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/11 22:19:02 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "NetworkModule.hpp"
#include <sstream>

#include <net/route.h>
#include <net/if.h>
#include <sys/sysctl.h>

NetworkModule::NetworkModule( std::string const & moduleName ) : IMonitorModule(),
	_moduleName(moduleName), _moduleData()
{
	_moduleData.resize(2);
}

NetworkModule::~NetworkModule( void ) {}

void                                NetworkModule::updateData( void )
{
	int         mib[6];
    char         *lim;
    char         *next;
    size_t         len;
    struct         if_msghdr *ifm;

    long int     ipackets = 0;
    long int     opackets = 0;
    long int     ibytes = 0;
    long int     obytes = 0;

    mib[0]= CTL_NET;// networking subsystem
    mib[1]= PF_ROUTE;// type of information
    mib[2]= 0;// protocol (IPPROTO_xxx)
    mib[3]= 0;// address family
    mib[4]= NET_RT_IFLIST2;// operation
    mib[5]= 0;

    sysctl(mib, 6, NULL, &len, NULL, 0);
    char buf[len];
    sysctl(mib, 6, buf, &len, NULL, 0);

    lim = buf + len;
    for (next = buf; next < lim; ) {
        ifm = (struct if_msghdr *)next;
        next += ifm->ifm_msglen;

        if (ifm->ifm_type == RTM_IFINFO2) {
            struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;

            if(if2m->ifm_data.ifi_type!=18) {
                opackets += if2m->ifm_data.ifi_opackets;
                ipackets += if2m->ifm_data.ifi_ipackets;
                obytes   += if2m->ifm_data.ifi_obytes;
                ibytes   += if2m->ifm_data.ifi_ibytes;
            }
        }
	}
	
	std::stringstream ss;
	ss << "packets in: " << ipackets;
	ss << " / packets out: " << opackets;
	_moduleData[0] = ss.str();
	
	ss.str(std::string());
	ss.precision(2);
    ss.setf(std::ios::fixed);
	ss << "data resived: " << static_cast<double>(ibytes) / 1024 / 1024 / 1024;
	ss << " GB / data sent: " << static_cast<double>(obytes) / 1024 / 1024 / 1024;
	ss << " GB";
    _moduleData[1] = ss.str();
}

std::vector<std::string> const &    NetworkModule::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 NetworkModule::getModulName( void ) const
{
	return _moduleName;
}       
