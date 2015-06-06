//
// main.cpp for trade in /Users/aurel/Documents/Epitech/trade-bis/src/
//
// Made by aurelien louisditpicard
// Login   <louisd_a@epitech.eu>
//
// Started on  Fri Jun  5 23:36:39 2015 aurelien louisditpicard
// Last update Sat Jun  6 21:58:21 2015 aurelien louisditpicard
//

#include <iostream>
#include <string>

#include "script.hpp"

static void         read_config(std::string const &name = "trade.conf")
{
    std::ifstream   conf (name, std::ios::in);
    std::string     buffer;
    size_t          p;

    if(conf.is_open())
    {
        while(getline(conf, buffer))
        {
            if ((p = buffer.rfind("script=")) != std::string::npos)
                script::name = buffer.substr(p+7);
        }
        conf.close();
    }
    else
    {
        std::cerr << "Unable to open \"trade.conf\" file, default is set to \"strategy.chai\"" << std::endl;
        script::name = "strategy.chai";
    }
}

int         main()
{
    read_config();
    try
    {
        script::init();
        trade::init();
        while (trade::current::turn != trade::start::turn)
        {
            if (trade::current::turn == trade::start::turn - 1)
            {
                trade::sell(trade::nb_share);
                break;
            }
            trade::get_next_price();
            script::execute();
        }
        return (0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
