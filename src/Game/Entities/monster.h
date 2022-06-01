#pragma once
#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> monster_name = {
    "Goblin",
    "Spider",
    "Orc",
    "Dragon",
};

struct Monster {
    std::string name;
    int         PV  = 15;
    int         atk = 2;
    int         def = 2;
};

Monster set_monster();

void show_monster_name(Monster monster);

bool monster_is_alive(Monster monster);