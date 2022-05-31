#pragma once
#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> monster_name = {
    "Dragon",
    "Gobelin",
    "Spider",
    "Orc",
};

struct Monster {
    std::string name;
    int         PV  = 40;
    int         atk = 5;
    int         def = 5;
};

Monster set_monster();

void show_monster_name(Monster monster);

bool monster_is_alive(Monster monster);