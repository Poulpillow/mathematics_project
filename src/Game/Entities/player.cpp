#include "player.h"

player set_player()
{
    player player;
    std::cout << "What is your name ? ";
    std::cin >> player.name;
    return player;
}

void show_player_name(player player)
{
    std::cout << "Your name is " << player.name << " is that correct ?" << std::endl;
}

bool player_is_alive(player player)
{
    return (player.PV < 0) ? false : true;
}