/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:04:31 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/11 19:04:33 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MONITOR_MODULE_HPP
# define I_MONITOR_MODULE_HPP

# include <iostream>
# include <vector>

class   IMonitorModule {

private:
    
    IMonitorModule( IMonitorModule const & );
    IMonitorModule & operator=( IMonitorModule const & );

public:

    IMonitorModule( void ) { };
    virtual         ~IMonitorModule( void ) { };

    virtual void                                updateData( void ) = 0;
    virtual std::string const &                 getModulName( void ) const = 0;
    virtual std::vector<std::string> const &    getModulData(void) const = 0;

};

#endif
