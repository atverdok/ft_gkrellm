/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:33:17 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/12 09:33:19 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OsInfoModule.hpp"
#include <sstream>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdio.h>

OsInfoModule::OsInfoModule( std::string const & moduleName ) : IMonitorModule(),
	_moduleName(moduleName), _moduleData()
{
	_moduleData.resize(2);
}

OsInfoModule::~OsInfoModule( void ) {}

void                                OsInfoModule::updateData( void )
{
    char buffer[255];
    size_t bufferlen = 255;

    std::stringstream ss;
    sysctlbyname("kern.ostype", &buffer, &bufferlen, NULL, 0);
    ss << "OS type: " << buffer;
    _moduleData[0] = ss.str();

    ss.str(std::string());
    sysctlbyname("kern.osrelease", &buffer, &bufferlen, NULL, 0);
    ss << "OS release: " << buffer;
    _moduleData[1] = ss.str();

}

std::vector<std::string> const &    OsInfoModule::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 OsInfoModule::getModulName( void ) const
{
	return _moduleName;
}