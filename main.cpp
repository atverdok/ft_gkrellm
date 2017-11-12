/* ************************************************************************** */
/*                                                                              */
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
#include "OsInfoModule.hpp"
#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>

#include "CursDisplay.hpp"
#include "GraficDisplay.hpp"


void        run_graphic( void );
void        run_shell( void );



int main( int ac, char **av )
{
    if (ac == 2 && !strcmp(av[1],"-t"))
    {
        // g_flag = 0;
        // run_shell();
        CursDisplay curs;
        curs.init();
        curs.run();
    }
    else if (ac == 2 && !strcmp(av[1], "-g"))
    {
        // g_flag = 1;
        // run_graphic();
        GraficDisplay grafic;
        grafic.init();
        grafic.run();
    }
    else
        std::cout << "usage ./ft_gkrellm  < -t > || < -g >." << std::endl;
    
        return 0;
}