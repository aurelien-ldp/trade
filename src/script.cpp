//
// script.cpp for trade in /Users/aurel/Documents/Epitech/trade-bis/src/
//
// Made by aurelien louisditpicard
// Login   <louisd_a@epitech.eu>
//
// Started on  Sat Jun  6 03:02:21 2015 aurelien louisditpicard
// Last update Sat Jun  6 21:42:32 2015 aurelien louisditpicard
//

#include "script.hpp"

#include <string>
#include <sstream>
#include <chaiscript/chaiscript_stdlib.hpp>

chaiscript::ChaiScript  script::chai;
std::string             script::name;

void    script::init()
{
    // Load functions
    chai.add(chaiscript::fun(&trade::buy), "buy");
    chai.add(chaiscript::fun(&trade::sell), "sell");
    chai.add(chaiscript::fun(&trade::wait), "wait");
    chai.add(chaiscript::fun(&trade::indicator::sma), "sma");
    chai.add(chaiscript::fun(&trade::indicator::ema), "ema");

    // Load variables
    chai.add_global(chaiscript::var(0), "all");

    // Load script file
    chai.eval_file(script::name);
}

void    script::execute(void)
{
    // Update variables
    std::ostringstream s;
    s << "all = " << trade::nb_share << ";";
    chai(s.str());

    // Call the update function
    chai.eval("update()");
}
