#include "game.h"
#include "./Texts/room.h"
#include "Entities/player.h"
#include "PlayerInput.h"
#include "Texts/texts.h"
#include "maths.h"

static int set_room()
{
    float number_choosen = 0;
    int   number_room    = 10;
    while ((std::cout << "Please choose a number between " << std::to_string(0.01) << " and " << std::to_string(0.99) << " : ") && (!(number_choosen = get_input_from_the_player<float>()) || number_choosen < 0.01 || number_choosen > 0.99)) {
        std::cout << "That's not a number between " << std::to_string(0.01) << " and " << std::to_string(0.99) << ". ";
    }
    number_room += geometric(number_choosen);
    return number_room;
}

static player introduction()
{
    return display_title_screen();
}

void dungeon_adventure()
{
    player hero        = introduction();
    int    number_room = set_room();
    int    actual_room = 1;
    while (player_is_alive(hero) && actual_room != number_room) {
        room(hero);
        actual_room++;
    }
    // fin
}

static void end()
{
}