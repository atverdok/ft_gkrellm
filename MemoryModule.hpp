/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemoryModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:15:02 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/11 23:15:04 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MODULE_HPP
# define MEMORY_MODULE_HPP

# include <vector>
#include "IMonitorModule.hpp"

class   MemoryModule : public IMonitorModule {

private:
    std::string const           _moduleName;
    std::vector<std::string>    _moduleData; 

    MemoryModule( void );
    MemoryModule( MemoryModule const & );
    MemoryModule & operator=( MemoryModule const & );
    
public:
    virtual ~MemoryModule( void );
    MemoryModule( std::string const & );

    void                                updateData( void );
    std::string const &                 getModulName( void ) const;
    std::vector<std::string> const &    getModulData(void) const;


};

#endif