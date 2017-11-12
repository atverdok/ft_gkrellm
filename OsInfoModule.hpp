/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:33:11 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/12 09:33:13 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OSINFO_MODULE_HPP
# define OSINFO_MODULE_HPP

# include <vector>
#include "IMonitorModule.hpp"

class   OsInfoModule : public IMonitorModule {

private:
    std::string const           _moduleName;
    std::vector<std::string>    _moduleData; 

    OsInfoModule( void );
    OsInfoModule( OsInfoModule const & );
	OsInfoModule & operator=( OsInfoModule const & );

public:
    virtual ~OsInfoModule( void );
    OsInfoModule( std::string const & );

    void                                updateData( void );
    std::string const &                 getModulName( void ) const;
    std::vector<std::string> const &    getModulData(void) const;


};

#endif