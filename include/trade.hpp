//
// trade.hpp for trade in /Users/aurel/Documents/Epitech/trade-bis/include/
//
// Made by aurelien louisditpicard
// Login   <louisd_a@epitech.eu>
//
// Started on  Sat Jun  6 02:11:55 2015 aurelien louisditpicard
// Last update Sat Jun  6 17:05:23 2015 aurelien louisditpicard
//

#ifndef TRADE_HPP_
# define TRADE_HPP_

# include <vector>
# include <iostream>

namespace trade
{
    namespace current
    {
        extern float   money;
        extern int     turn;
    }   /* current */

    namespace start
    {
        extern float   money;
        extern int     turn;
    }   /* start */

    namespace indicator {
        float   sma(int period, int offset = 0);
        float   ema(int period, int offset = 0);
    }   /* indicator */

    extern float               price;
    extern std::vector<float>  prices;
    extern int                 nb_share;

    // functions
    void    init(void);
    void    get_next_price(void);
    void    debug_dump_info(void);
    void    buy(int nb);
    void    sell(int nb);
    void    wait(void);

}   /* trade */

std::ostream & operator<<(std::ostream & o, std::vector<float> const &v);

#endif /* !TRADE_HPP_ */
