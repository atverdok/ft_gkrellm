
#ifndef GRAFIC_DISPLAY_HPP
# define GRAFIC_DISPLAY_HPP


#include "IMonitorDisplay.hpp"

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
#include <SFML/Graphics.hpp>
#include "Particle.hpp"
#include <time.h>

class   GraficDisplay : public IMonitorDisplay {

private:
    sf::RenderWindow _window;

    GraficDisplay( GraficDisplay const & );
    GraficDisplay & operator=( GraficDisplay const & );
    
    void  draw_text(std::string const & str, int y , int x, int size );
    int   get_str_vec(std::vector<std::string> const & vec, int y);

public:
    GraficDisplay( void );
    virtual ~GraficDisplay( void );

    void    init( void );
    void    run( void );


};

#endif