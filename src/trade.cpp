//
// trade.cpp for trade in /Users/aurel/Documents/Epitech/trade-bis/src/
//
// Made by aurelien louisditpicard
// Login   <louisd_a@epitech.eu>
//
// Started on  Sat Jun  6 02:11:40 2015 aurelien louisditpicard
// Last update Sun Jun  7 01:45:59 2015 aurelien louisditpicard
//

#include "trade.hpp"
#include <limits>

float               trade::current::money;
int                 trade::current::turn;
float               trade::start::money;
int                 trade::start::turn;
float               trade::price;
std::vector<float>  trade::prices;
int                 trade::nb_share;

void    trade::init(void)
{
    std::cin >> start::money;
    std::cin >> start::turn;
    current::money = start::money;
    current::turn = 0;
    nb_share = 0;
}

void    trade::get_next_price(void)
{
    std::cin >> price;
    if (std::cin.fail())
    {
        std::cerr << "Input failed for turn: " << trade::current::turn << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        price = prices.back();
    }
    prices.push_back(price);
    ++current::turn;
}

std::ostream & operator<<(std::ostream & o, std::vector<float> const &v)
{
    o << "[ ";
    for (size_t i = 0; i < v.size(); i++)
    {
        o << v[i];
        if (i != v.size() - 1)
            o << ", ";
    }
    o << " ]";
    return (o);
}

void    trade::debug_dump_info(void)
{
    std::cerr << "trade::current::money -> " << trade::current::money << std::endl;
    std::cerr << "trade::current::turn -> " << trade::current::turn << std::endl;
    std::cerr << "trade::start::money -> " << trade::start::money << std::endl;
    std::cerr << "trade::start::turn -> " << trade::start::turn << std::endl;
    std::cerr << "trade::price -> " << trade::price << std::endl;
    std::cerr << "trade::prices -> " << trade::prices << std::endl;
}

void        trade::buy(int nb)
{
    float   order_price = (nb * price);
    float   com = order_price * 0.15 / 100;

    if ((order_price + com) < current::money)
    {
        std::cout << "buy " << nb << std::endl;
        nb_share += nb;
        current::money -= nb * price;
    }
    else
    {
        wait();
    }
}

void    trade::sell(int nb)
{
    if (nb_share == 0)
    {
        wait();
        return ;
    }
    if (nb <= nb_share)
    {
        std::cout << "sell " << nb << std::endl;
        nb_share -= nb;
        current::money += nb * price;
    }
    else if (nb > nb_share)
    {
        std::cout << "sell " << nb_share << std::endl;
        nb_share = 0;
        current::money += nb_share * price;
    }
    else
        wait();
}

void    trade::wait(void)
{
    std::cout << "wait" << std::endl;
}

int     trade::percent_of_money(int percentage)
{
    return ((current::money * percentage / 100) / price);
}
