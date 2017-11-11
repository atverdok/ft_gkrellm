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

#include <curl/curl.h>
# include "NetworkModule.hpp"
# include <iostream>

NetworkModule::NetworkModule( std::string const & moduleName ) : IMonitorModule(),
	_moduleName(moduleName), _moduleData()
{
	_moduleData.resize(1);
}

NetworkModule::~NetworkModule( void ) {}

void                                NetworkModule::updateData( void )
{
	FILE		*info;
	char		buf[256];
	int			i = 0;

	// info = popen("/usr/bin/top -l1 | /usr/bin/head -n10 | /usr/bin/grep 'Networks' | /usr/bin/tr ' ,:' '\n' | sed -n '/[0-9]/p' | /usr/bin/tr '/' '\n'", "r");
	info = popen("/usr/bin/top -l1 | /usr/bin/head -n10 | /usr/bin/grep 'Networks' | /usr/bin/tr ' ,:' '\n' | sed -n '/[0-9]/p' | /usr/bin/tr '\n' ' '", "r");
	if (info == NULL)
    {
		_moduleData[0] = "Error get data";
		return ;
	}
    while (fgets(buf, 256, info) != NULL)
    {
		_moduleData[i] = strdup(buf);
		++i;
	}
	pclose(info);
}

std::vector<std::string> const &    NetworkModule::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 NetworkModule::getModulName( void ) const
{
	return _moduleName;
}       
