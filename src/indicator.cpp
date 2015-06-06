//
// indicator.cpp for trade in /Users/aurel/Documents/Epitech/trade-bis/src/
//
// Made by aurelien louisditpicard
// Login   <louisd_a@epitech.eu>
//
// Started on  Sat Jun  6 02:21:11 2015 aurelien louisditpicard
// Last update Sat Jun  6 19:34:56 2015 aurelien louisditpicard
//

#include "trade.hpp"

#include <cmath>

float       trade::indicator::sma(int period, int offset)
{
    int     k = 1;
    float   total = 0.0;
    size_t  it = 0;

    if ((period + offset) > (int)prices.size())
        return (price);
    it = (prices.size() - 1) - offset;
    while (k++ < period)
    {
        total += prices[it];
    }
    return (total / (float)k);
}

float       trade::indicator::ema(int period, int offset)
{
    float   psma = sma(period, std::abs(offset - 1));
    float   mult = (2 / (period + 1));

    return ((price - psma) * mult + psma);
}
