
#include "GraficDisplay.hpp"

GraficDisplay::GraficDisplay( void ) 
{
     _window.create(sf::VideoMode(2400, 2000), "SYSTEM MONITOR");
 }

GraficDisplay::~GraficDisplay( void ) { }

void    GraficDisplay::init( void )
{
    
}

void    GraficDisplay::run( void )
{
        


        int i;
    
        sf::Font font;
        font.loadFromFile("./inc/Orbitron-Regular.ttf");
        
    
        ParticleSystem particles(10000);
        sf::Clock clock;
    
    
        
        sf::Text text;    
        text.setFont(font);
        text.setString("SYSTEM MONITOR");
        text.setCharacterSize(64);
        text.setFillColor(sf::Color::Black);
        text.setPosition(2400 / 2 - 5 * 64, 50);
    
    
        HostUserModule host("Hostname/username:");
        OsInfoModule os("OS info:");
        DateModule date("Date/time module");
        CpuModule cpu("CPU:");
        MemoryModule mem("RAM:");
        NetworkModule net("Network:");
    
        clock_t cur;
        clock_t cur2;
        cur2 = std::clock();
        cur = std::clock();
        while (_window.isOpen())
        {
            sf::Event event;
            i = 0;
            while (_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    _window.close();
            }
    
            sf::Vector2i mouse = sf::Mouse::getPosition(_window);
            particles.setEmitter(_window.mapPixelToCoords(mouse));
    
            sf::Time elapsed = clock.restart();
            particles.update(elapsed);
    
            _window.clear(sf::Color::White);
    
            date.updateData();
            draw_text( date.getModulData()[0], 3, 2400 - 400, 32);
            i++;
    
            host.updateData();
            draw_text( host.getModulName(), 200 + i++ * 64, 2400 / 4, 48) ;
            i += get_str_vec( host.getModulData(), 200 + i * 64);
            
            os.updateData();
            draw_text( os.getModulName(), 200 + i++ * 64, 2400 / 4, 48) ;
            i += get_str_vec( os.getModulData(), 200 + i * 64);
    
            if ( (std::clock() - cur) / CLOCKS_PER_SEC >= 1)
            {
                cpu.updateData();
                cur = std::clock();
            }
            draw_text( cpu.getModulName(), 200 + i++ * 64, 2400 / 4, 48) ;
            i += get_str_vec( cpu.getModulData(), 200 + i * 64);
    
            if ( (std::clock() - cur2) / CLOCKS_PER_SEC >= 1)
            {
                mem.updateData();
                cur2 = std::clock();
            }
            draw_text( mem.getModulName(), 200 + i++ * 64, 2400 / 4, 48) ;
            i += get_str_vec(  mem.getModulData(), 200 + i * 64);
            
            net.updateData();
            draw_text( net.getModulName(), 200 + i++ * 64, 2400 / 4, 48) ;
            i += get_str_vec( net.getModulData(), 200 + i * 64);
    
            _window.draw(particles);
            _window.draw(text);
            _window.display();
        }
}

void            GraficDisplay::draw_text(std::string const & str, int y , int x, int size )
{
    sf::Text    text;
    sf::Font font;
    font.loadFromFile("./inc/Arial.ttf");
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x, y);
    _window.draw(text);
}

int            GraficDisplay::get_str_vec(std::vector<std::string> const & vec, int y)
{
    size_t i;
    for (i = 0; i < vec.size(); i++ )
    {
        draw_text( vec[i] ,  y + 64 * i , 2400 / 4 + 96, 32);
    }
    return (i);
}