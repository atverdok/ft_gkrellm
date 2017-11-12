/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:08:36 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/12 00:08:38 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPU_MODULE_HPP
# define CPU_MODULE_HPP

# include <vector>
#include "IMonitorModule.hpp"

class   CpuModule : public IMonitorModule {

private:
    std::string const           _moduleName;
    std::vector<std::string>    _moduleData; 
    unsigned long long _1previousTotalTicks;
    unsigned long long _1previousIdleTicks;

    float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
    float GetCPULoad();
    

    CpuModule( void );
    CpuModule( CpuModule const & );
	CpuModule & operator=( CpuModule const & );

public:
    virtual ~CpuModule( void );
    CpuModule( std::string const & );

    void                                updateData( void );
    std::string const &                 getModulName( void ) const;
    std::vector<std::string> const &    getModulData(void) const;


};

#endif