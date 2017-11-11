/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:05:51 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/11 22:05:53 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NETWORK_MODULE_HPP
# define NETWORK_MODULE_HPP

# include <vector>
#include "IMonitorModule.hpp"

class   NetworkModule : public IMonitorModule {

private:
    std::string const           _moduleName;
    std::vector<std::string>    _moduleData; 

    NetworkModule( void );
    NetworkModule( NetworkModule const & );
	NetworkModule & operator=( NetworkModule const & );

public:
    virtual ~NetworkModule( void );
    NetworkModule( std::string const & );

    void                                updateData( void );
    std::string const &                 getModulName( void ) const;
    std::vector<std::string> const &    getModulData(void) const;


};

#endif