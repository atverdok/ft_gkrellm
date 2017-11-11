/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostUserModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:01:33 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/11 23:01:35 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INFO_MODULE_HPP
# define INFO_MODULE_HPP

# include <vector>
#include "IMonitorModule.hpp"

class   HostUserModule : public IMonitorModule {

private:
    std::string const           _moduleName;
    std::vector<std::string>    _moduleData; 

    HostUserModule( void );
    HostUserModule( HostUserModule const & );
	HostUserModule & operator=( HostUserModule const & );

public:
    virtual ~HostUserModule( void );
    HostUserModule( std::string const & );

    void                                updateData( void );
    std::string const &                 getModulName( void ) const;
    std::vector<std::string> const &    getModulData(void) const;


};

#endif