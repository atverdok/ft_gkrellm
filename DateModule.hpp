/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:29:13 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/11 20:29:15 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_MODULE_HPP
# define DATE_MODULE_HPP

# include <vector>
#include "IMonitorModule.hpp"

class   DateModule : public IMonitorModule {

private:
    std::string const           _moduleName;
    std::vector<std::string>    _moduleData; 

    DateModule( void );
    DateModule( DateModule const & );
	DateModule & operator=( DateModule const & );

public:
    virtual ~DateModule( void );
    DateModule( std::string const & );

    void                                updateData( void );
    std::string const &                 getModulName( void ) const;
    std::vector<std::string> const &    getModulData(void) const;


};

#endif