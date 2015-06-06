//
// script.hpp for trade in /Users/aurel/Documents/Epitech/trade-bis/include/
//
// Made by aurelien louisditpicard
// Login   <louisd_a@epitech.eu>
//
// Started on  Sat Jun  6 02:55:33 2015 aurelien louisditpicard
// Last update Sat Jun  6 21:42:40 2015 aurelien louisditpicard
//

#ifndef SCRIPT_H_
# define SCRIPT_H_

#include "trade.hpp"

#include <chaiscript/chaiscript.hpp>

namespace script
{
    extern chaiscript::ChaiScript  chai;
    extern std::string             name;

    // functions
    void    init();
    void    execute(void);

}   /* script */

#endif /* !SCRIPT_H_ */
