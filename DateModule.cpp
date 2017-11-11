/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:29:21 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/11 20:29:23 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <sstream>
# include "DateModule.hpp"

DateModule::DateModule( std::string const & moduleName ) : IMonitorModule(),
    _moduleName(moduleName), _moduleData()
{
    _moduleData.resize(1);
}

DateModule::~DateModule( void ) {}

void                                DateModule::updateData( void )
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    std::stringstream ss;
    ss << (now->tm_year + 1900) << '-'
    << (now->tm_mon + 1) << '-'
    <<  now->tm_mday << ' '
    <<  now->tm_hour << '/'
    <<  now->tm_min << '/'
    <<  now->tm_sec;

    _moduleData[0] = ss.str();
}

std::vector<std::string> const &    DateModule::getModulData( void ) const
{
    return _moduleData;
}

std::string const &                 DateModule::getModulName( void ) const
{
    return _moduleName;
}       
