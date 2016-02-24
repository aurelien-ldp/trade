//
// script.cpp for trade in /Users/aurel/Documents/Epitech/trade-bis/src/
//
// Made by aurelien louisditpicard
// Login   <louisd_a@epitech.eu>
//
// Started on  Sat Jun  6 03:02:21 2015 aurelien louisditpicard
// Last update Tue Jun 23 01:45:27 2015 aurelien louisditpicard
//

#include "script.hpp"

#include <string>
#include <sstream>
#include <chaiscript/chaiscript.hpp>
#include <chaiscript/chaiscript_stdlib.hpp>

chaiscript::ChaiScript  script::chai(chaiscript::Std_Lib::library());
std::string             script::name;

void    script::init()
{
    // Load functions
    chai.add(chaiscript::fun(&trade::buy), "buy");
    chai.add(chaiscript::fun(&trade::sell), "sell");
    chai.add(chaiscript::fun(&trade::wait), "wait");
    chai.add(chaiscript::fun(&trade::percent_of_money), "percent_of_money");
    chai.add(chaiscript::fun(&trade::indicator::sma), "sma");
    chai.add(chaiscript::fun(&trade::indicator::ema), "ema");
    chai.add(chaiscript::fun(&trade::indicator::rsi), "rsi");

    // Load variables
    chai.add_global(chaiscript::var(0), "all");
    chai.add_global(chaiscript::var(0), "price");

    // Load script file
    chai.eval_file(script::name);
}

void    script::execute(void)
{
    // Update variables
    std::ostringstream s;
    s << "all = " << trade::nb_share << ";";
    s << "\n";
    s << "price = " << trade::price << ";";
    chai(s.str());

    // Call the update function
    chai.eval("update()");
}
