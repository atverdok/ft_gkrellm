
#ifndef CURS_DISPLAY_HPP
# define CURS_DISPLAY_HPP


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

class   CursDisplay : public IMonitorDisplay {

private:
    WINDOW *_wd;

    CursDisplay( CursDisplay const & );
    CursDisplay & operator=( CursDisplay const & );
    
    void addStrWind(int y, int x, std::string str);
    void  printVector( std::vector<std::string> const & vec, int y, int x);

public:
    CursDisplay( void );
    virtual ~CursDisplay( void );

    void    init( void );
    void    run( void );


};

#endif