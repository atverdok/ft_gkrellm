/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostUserModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:01:40 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/11 23:01:42 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "HostUserModule.hpp"
#include <sstream>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdio.h>

HostUserModule::HostUserModule( std::string const & moduleName ) : IMonitorModule(),
	_moduleName(moduleName), _moduleData()
{
	_moduleData.resize(2);
}

HostUserModule::~HostUserModule( void ) {}

void                                HostUserModule::updateData( void )
{
    struct passwd *pw;
    char buffer[255];
    size_t bufferlen = 255;

    pw = getpwuid(getuid());
    std::stringstream ss;
    ss << "User: " << pw->pw_name;
    _moduleData[0] = ss.str();

    ss.str(std::string());
    sysctlbyname("kern.hostname", &buffer, &bufferlen, NULL, 0);
    ss << "Hostname: " << buffer;
    _moduleData[1] = ss.str();

}

std::vector<std::string> const &    HostUserModule::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 HostUserModule::getModulName( void ) const
{
	return _moduleName;
}