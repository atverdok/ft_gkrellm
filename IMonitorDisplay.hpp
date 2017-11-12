/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:04:14 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/11 19:04:22 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef I_MONITOR_DISPLAY_HPP
# define I_MONITOR_DISPLAY_HPP

# include <iostream>
# include <vector>


class   IMonitorDisplay {

private:
    
    IMonitorDisplay( IMonitorDisplay const & );
    IMonitorDisplay & operator=( IMonitorDisplay const & );

public:

    IMonitorDisplay( void ) { };
    virtual         ~IMonitorDisplay( void ) { };

    virtual void    init( void ) = 0;
    virtual void    run( void ) = 0;

};

#endif