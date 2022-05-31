#include "player.h"

player set_player()
{
    player player;
    std::cout << "What your name ? ";
    std::cin >> player.name;
    return player;
}

void show_player_name(player player)
{
    std::cout << "Your name is " << player.name << std::endl;
    std::cout << "You have " << player.PV << " PV" << std::endl;
}

bool player_is_alive(player player)
{
    return (player.PV < 0) ? false : true;
}