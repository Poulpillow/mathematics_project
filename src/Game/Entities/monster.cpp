#include "monster.h"

Monster set_monster()
{
    Monster monster;
    std::cout << "What your name ? ";
    std::cin >> monster.name;
    return monster;
}

void show_monster_name(Monster monster)
{
    std::cout << "A " << monster.name << " appeared" << std::endl;
}

bool monster_is_alive(Monster monster)
{
    return monster.PV;
}