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
        show_chest_command();
        const auto command = get_command_from_player();
        if (command == "open") {
            open_chest(items, playerone);
            playerone.chest_encounters++;
        }
        else {
            std::cout << unknow << std::endl;
        }
    }
    else {
        for (int i = 0; i < number_monster; i++) {
            Monster new_monster = set_monster();
            fight(playerone, new_monster);
        }
    }
}