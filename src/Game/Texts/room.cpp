#include "room.h"
#include "../Entities/monster.h"
#include "../Entities/player.h"
#include "../PlayerInput.h"
#include "chest.h"
#include "fight.h"

static int new_room()
{
    return 0;
}

void room(player& playerone)
{
    const int number_monster = new_room();
    if (number_monster == 0) {
        const auto command = get_command_from_player();
        if (command == "open") {
            open_chest(items);
        }
        else {
            for (int i = 0; i < number_monster; i++) {
                Monster new_monster = set_monster();
                fight(playerone, new_monster);
            }
        }
    }
}