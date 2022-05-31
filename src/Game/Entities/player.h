#pragma once
#include <iostream>
#include <string>

struct player {
    std::string name;
    int         PV                 = 50;
    int         atk                = 10;
    int         def                = 10;
    int         gold               = 0;
    int         monster_encounters = 0;
    int         number_runway      = 0;
    int         chest_encounters   = 0;
};

player set_player();

void show_player_name(player player);

bool player_is_alive(player player);