//
// indicator.cpp for trade in /Users/aurel/Documents/Epitech/trade-bis/src/
//
// Made by aurelien louisditpicard
// Login   <louisd_a@epitech.eu>
//
// Started on  Sat Jun  6 02:21:11 2015 aurelien louisditpicard
// Last update Tue Jun 23 02:07:14 2015 aurelien louisditpicard
//

#include "trade.hpp"

#include <cmath>

float       trade::indicator::sma(int period, int offset)
{
    int     k = 0;
    float   total = 0.0;
    size_t  it = 0;

    if ((period + offset) > (int)prices.size())
        return (price);
    it = (prices.size() - 1) - offset;
    while (k++ < period)
    {
      total += prices[it--];
    }
    return (total / ((float)k - 1));
}

float       trade::indicator::ema(int period, int offset)
{
    float   psma = sma(period, std::abs(offset - 1));
    float   mult = (2 / (period + 1));

    return ((price - psma) * mult + psma);
}

int        trade::indicator::rsi(int period, int offset)
{
    int     average_up = 1;
    int     average_down = 1;
    int     k = 0;

    if ((period + offset) > (int)prices.size())
        return (50);
    for (size_t i = (prices.size() - 1) - offset; i > 1; i--)
    {
        if (k++ == period)
            break;
        if (prices[i] > prices[i - 1])
            average_up++;
        else
            average_down++;
    }
    return (100 - (100 / (1 + average_up / average_down)));
}
