/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:29:00 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/11 20:29:03 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "DateModule.hpp"
#include "NetworkModule.hpp"
#include "HostUserModule.hpp"
#include "MemoryModule.hpp"
#include "CpuModule.hpp"

void printVector( std::vector<std::string> const & vec)
{
    for(int i=0; i<vec.size(); ++i)
    {
        if (!(vec[i].empty()))
            std::cout << vec[i] << std::endl;
    }
}

int main( void )
{
    DateModule date("Date/time module");
    date.updateData();
    std::cout << date.getModulName() << std::endl;
    printVector(date.getModulData());
    std::cout << std::endl;

    HostUserModule host("Hostname/username module");
    host.updateData();
    std::cout << host.getModulName() << std::endl;
    printVector(host.getModulData());
    std::cout << std::endl;

    CpuModule cpu("CPU module");
    cpu.updateData();
    std::cout << cpu.getModulName() << std::endl;
    printVector(cpu.getModulData());
    std::cout << std::endl;

    MemoryModule mem("RAM module");
    mem.updateData();
    std::cout << mem.getModulName() << std::endl;
    printVector(mem.getModulData());
    std::cout << std::endl;

    NetworkModule net("Network throughput module");
    net.updateData();
    std::cout << net.getModulName() << std::endl;
    printVector(net.getModulData());
    std::cout << std::endl;

    return 0;
}