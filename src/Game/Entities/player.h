#pragma once
#include <iostream>
#include <string>

struct player {
    std::string name;
    int         PV   = 50;
    int         atk  = 5;
    int         def  = 5;
    int         gold = 0;
};

player set_player();

void show_player_name(player player);

bool player_is_alive(player player);