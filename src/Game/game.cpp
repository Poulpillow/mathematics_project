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
    // Beginning of the Game

    player hero        = introduction();
    int    number_room = set_room();
    int    actual_room = 1;

    // Loop of rooms

    while (player_is_alive(hero) && actual_room != number_room + 1) {
        std::cout << "\n\n\nROOM NUMBER " << actual_room << "\n\n\n";
        room(hero);
        actual_room++;
    }

    // End of the Game

    if (hero.PV <= 0) {
        std::cout << "MESSAGE YOU LOST" << std::endl;
    }
    else {
        std::cout << "MESSAGE YOU WIN" << std::endl;
        std::cout << "You have " << hero.PV << " left !" << std::endl;
    }

    // Statistics

    std::cout << "Let's see the luck you had in this play !\n"
              << std::endl;
    std::cout << "You passed " << actual_room << " rooms !" << std::endl;
    std::cout << "You earned " << hero.gold << " gold during your adventure !" << std::endl;
    std::cout << "You encoutered " << hero.monster_encounters << " monsters" << std::endl;
    std::cout << "You ran away " << hero.number_runway << " times" << std::endl;
    std::cout << "You encoutered " << hero.chest_encounters << " chests" << std::endl;

    int luck_monsters = hero.monster_encounters / actual_room;
    if (luck_monsters <= 0.5) {
        std::cout << "LUCKY" << std::endl;
    }
    else if (luck_monsters >= 0.5 && luck_monsters <= 1) {
        std::cout << "IT'S OK" << std::endl;
    }
    else if (luck_monsters >= 1 && luck_monsters <= 1.5) {
        std::cout << "UNLUCKY" << std::endl;
    }
    else {
        std::cout << "HARDCORE" << std::endl;
    }

    // Last message
    std::cout << "LAST MESSAGE\n"
              << "TRY AGAIN ?\n[Y/N]" << std::endl;
    const auto command = get_character_from_player();
    if (command == 'y') {
        dungeon_adventure();
    }
    else {
        std::cout << "SEE YOU SOON" << std::endl;
    }
}