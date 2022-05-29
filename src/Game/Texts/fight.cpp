#include "fight.h"
#include <iostream>
#include "../Entities/player.h"
#include "../PlayerInput.h"
#include "chest.h"

static void show_fight_command()
{
    std::cout << "[Fight / Run / Heal]" << std::endl;
}

template<typename Ack, typename Def>
void attack(Ack& fighter, Def& victim)
{
    victim.PV = victim.PV - (fighter.atk - victim.def);
}

static void run()
{
    /*
    Tirage
    Regarde proba
    Si oui
        Nouvelle salle
    Si non
        Raté... Good luck
    */
}

static void heal(player& player)
{
    player.PV += 5;
}

static void monster_drop()
{
    int tirage = rand() % (1 + 0 + 1) + 0;
    if (tirage == 1) {
        open_chest(loots);
    }
}

void fight(player& playerone, player& playertwo)
{
    const auto command = get_command_from_player();
    if (command == "fight") {
        std::cout << "fight" << std::endl;
        attack(playerone, playertwo);
    }
    else if (command == "run") {
        std::cout << "run" << std::endl;
        run();
    }
    else if (command == "heal") {
        std::cout << "heal" << std::endl;
        heal(playerone);
    }
    else {
        std::cout << unknow << std::endl;
    }
}