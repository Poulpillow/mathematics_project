#include "fight.h"
#include <iostream>
#include "../PlayerInput.h"
#include "../maths.h"
#include "chest.h"
#include "texts.h"

static void show_fight_command()
{
    std::cout << "[Fight / Run / Heal]" << std::endl;
}

template<typename Ack, typename Def>
void attack(Ack& fighter, Def& victim)
{
    // Annonce des PV
    std::cout << victim.name << " have " << victim.PV << " PV\n"
              << std::endl;

    int bonus_atk = static_cast<int>(expo(0.5));
    int pv_lost   = victim.def - fighter.atk - bonus_atk;

    if (pv_lost < 0) {
        victim.PV += pv_lost;
        std::cout << victim.name << " loss " << pv_lost << " PV\n"
                  << std::endl;
    }
    else {
        std::cout << "MISS\n"
                  << std::endl;
    }

    std::cout << victim.name << " have now " << victim.PV << " PV\n"
              << std::endl;
}

static void heal(player& player)
{
    player.PV += 5;
    std::cout << "You have " << player.PV << std::endl;
}

static void monster_drop(player& playerone)
{
    int tirage = rand() % (1 + 0 + 1) + 0;
    if (tirage == 1) {
        open_chest(loots, playerone);
    }
}

void fight(player& playerone, Monster& monsterone)
{
    show_monster_name(monsterone);
    playerone.monster_encounters++;
    bool player_turn = true;
    while (player_is_alive(playerone) && monster_is_alive(monsterone)) {
        if (player_turn) {
            show_fight_command();
            const auto command = get_command_from_player();
            if (command == "fight") {
                attack(playerone, monsterone);
            }
            else if (command == "run") {
                if (playerone.PV < 3) {
                    std::cout << "You ran away from the fight." << std::endl;
                    playerone.number_runway++;
                    break;
                }
                else {
                    float tirage = (float)rand() / RAND_MAX;
                    if (tirage < 0.2) {
                        std::cout << "You ran away from the fight." << std::endl;
                        playerone.number_runway++;
                        break;
                    }
                    else {
                        std::cout << "You tried to ran away... To bad you miss." << std::endl;
                    }
                }
            }
            else if (command == "heal") {
                heal(playerone);
            }
            else {
                std::cout << unknow << std::endl;
            }
            player_turn = false;
        }
        else {
            std::cout << monsterone.name << " attack" << std::endl;
            attack(monsterone, playerone);
            player_turn = true;
        }
    }
    if (player_is_alive(playerone)) {
        monster_drop(playerone);
    }
}