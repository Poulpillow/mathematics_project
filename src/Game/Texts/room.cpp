#include "room.h"
#include "../Entities/monster.h"
#include "../Entities/player.h"
#include "../PlayerInput.h"
#include "chest.h"
#include "fight.h"
#include "texts.h"

void room(player& playerone)
{
    const int number_monster = (rand() % 3);
    if (number_monster == 0) {
        std::cout << "You are a lucky guy today ! That's a treasure room !\nEnjoy the feeling of being rich ... " << std::endl;
        while (true) {
            show_chest_command();
            const auto command = get_command_from_player();
            if (command == "open") {
                open_chest(items, playerone);
                playerone.chest_encounters++;
                break;
            }
            else {
                std::cout << unknow << std::endl;
            }
        }
        std::cout << "Nice catch ! Now let's go back to adventure !" << std::endl;
    }
    else {
        std::cout << "I think I hear some noise ..." << std::endl;
        if (number_monster == 1) {
            std::cout << "This is a guard room !\nOh you know, from a different perspective that's not so bad ! There is only one monster !" << std::endl;
        }
        else if (number_monster == 2) {
            std::cout << "Uhoh that's a high security room !\nAnd the destiny choose for you ... death ! Now FIGHT FIGHT FIGHT" << std::endl;
        }
        for (int i = 0; i < number_monster; i++) {
            Monster new_monster = set_monster();
            fight(playerone, new_monster);
        }
    }
}