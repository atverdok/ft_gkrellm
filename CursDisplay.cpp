
#include "CursDisplay.hpp"

CursDisplay::CursDisplay( void ) { }

CursDisplay::~CursDisplay( void ) { endwin(); }

void    CursDisplay::init( void )
{
    _wd = initscr();
    cbreak();
    noecho();
    clear();
    refresh();
    keypad(_wd, true);
    nodelay(_wd, true);
    curs_set(0);
    start_color();
    attron(A_BOLD);
    box(_wd, 0, 0);
    attroff(A_BOLD);
    init_pair(1, COLOR_CYAN, COLOR_WHITE);
    init_pair(2, COLOR_RED, COLOR_WHITE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    wbkgd(_wd, COLOR_PAIR(1));
}

void    CursDisplay::run( void )
{
    HostUserModule host("Hostname/username module");
    OsInfoModule os("OS info module");
    DateModule date("Date/time module");
    MemoryModule mem("RAM module");
   NetworkModule net("Network throughput module");
    CpuModule cpu("CPU module");

    while (1)
    {
        clear();

        struct winsize size;
        ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
        attron(COLOR_PAIR(4));
        attron(A_REVERSE);
        addStrWind(2, size.ws_col / 2 - 12, "S Y S T E M   M O N I T O R");
        attroff(A_REVERSE);
        attroff(COLOR_PAIR(4));

        attron(COLOR_PAIR(3));
        host.updateData();
        attron(A_BOLD);
        addStrWind( 6, 5,  host.getModulName() );
        attroff(A_BOLD);
        printVector(host.getModulData(), 8, 5);

        os.updateData();
        attron(A_BOLD);
        addStrWind(12, 5, os.getModulName() );
        attroff(A_BOLD);
        printVector(os.getModulData(), 14, 5);

        date.updateData();
        attron(A_BOLD);
        addStrWind (18, 5, date.getModulName() );
        attroff(A_BOLD);
        printVector(date.getModulData(), 20, 5);

        attron(A_BOLD);
        addStrWind(24, 5,  cpu.getModulName() );
        attroff(A_BOLD);

        cpu.updateData();
       // attron(COLOR_PAIR(2));
        printVector(cpu.getModulData(), 26, 5);
       // attroff(COLOR_PAIR(2));
        // while (true)
        // {
        //       cpu.updateData();
        //       printVector(cpu.getModulData());
        //       std::cout << std::endl;
        //       usleep(50000);
        // }

        attron(COLOR_PAIR(3));
        mem.updateData();
        attron(A_BOLD);
        addStrWind( 30, 5, mem.getModulName() );
        attroff(A_BOLD);
        //attron(COLOR_PAIR(2));
        printVector(mem.getModulData(), 32, 5);
        //attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(3));
        net.updateData();
        attron(A_BOLD);
        addStrWind ( 36, 5, net.getModulName() );
        attroff(A_BOLD);
        printVector(net.getModulData(), 38, 5);
        attroff(COLOR_PAIR(3));
        refresh();
        usleep(100000);
    }
}

void            CursDisplay::addStrWind(int y, int x, std::string str)
{

    for (size_t i = 0; i < str.size(); i++)
    {
        mvaddch(y, x + i, str[i]);
    }
}

void  CursDisplay::printVector( std::vector<std::string> const & vec, int y, int x)
{
    for ( size_t i = 0; i < vec.size(); i++ )
    {
        addStrWind(y + i, x, vec[i]);
    }
}