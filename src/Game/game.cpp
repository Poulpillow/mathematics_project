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
    while ((std::cout << "Now that all is settle and before we beggin, please choose a number between " << std::to_string(0.01) << " and " << std::to_string(0.99) << " : ") && (!(number_choosen = get_input_from_the_player<float>()) || number_choosen < 0.01 || number_choosen > 0.99)) {
        std::cout << "You dummy ! That's not a number between " << std::to_string(0.01) << " and " << std::to_string(0.99) << "! Try again !";
    }
    std::cout << "You want to know why ? Well that is a secret ! Sorry but I will not tell you ! Anyway, let's go in the first room !\n"
              << std::endl;
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
    std::cout << "In the dark dongeon we go !\n"
              << std::endl;
    while (player_is_alive(hero) && actual_room != number_room + 1) {
        std::cout << "/----------------------------------------------------------------------------------------------------------/\n/------------------------------------------- ROOM NUMBER " << actual_room << " ------------------------------------------------/\n/----------------------------------------------------------------------------------------------------------/"
                  << "\n\n\n"
                  << std::endl;
        room(hero);
        actual_room++;
        if (player_is_alive(hero)) {
            std::cout << "Tired yet ? Come on ! To the next challenge we go !\n"
                      << std::endl;
        }
    }

    // End of the Game
    std::cout << "\n/----------------------------------------------------------------------------------------------------------/\n";
    if (hero.PV <= 0) {
        std::cout << "\nOhhhhh come onnnn ! You were so close ! Do you know all the money I bet on your success !\nAt the end I finally began to trust in you\nWhat a shame ...\nOh no do not cry ! I am sorry\nTo apologize, let me show you something to cheer you up !" << std::endl;
    }
    else {
        std::cout << "\nOh what ? You actually win ?! With only " << hero.PV << " PV left !" << std::endl;
        std::cout << "I misjugded you so much ! Well congrats hero !\nYou want to know what is your price ?\nWell ... uhm ... let me see ...\nOf course ! You won ... Statistics about your play ! What you really thought you will earn something better ?\nToo bad ! " << std::endl;
    }

    // Statistics

    std::cout << R"(
/----------------------------------------------------------------------------------------------------------/
/-------------------------------------------- STATISTICS --------------------------------------------------/
/----------------------------------------------------------------------------------------------------------/                                               
    )" << std::endl;

    std::cout << "\nWell now let s see the luck you had in this play !\n\n"
              << std::endl;

    std::cout << "You passed " << actual_room - 1 << " rooms !\n"
              << std::endl;
    if (actual_room >= 13) {
        std::cout << "And that was not easy !\n"
                  << std::endl;
    }

    std::cout << "You earned " << hero.gold << " gold during your adventure !\n"
              << std::endl;
    if (hero.gold >= 30) {
        std::cout << "Congrats ! You have now the money to by you a shrubbery ! You will thank me later for that !\n"
                  << std::endl;
    }

    std::cout << "You encoutered " << hero.chest_encounters << " chests\n"
              << std::endl;
    if ((hero.chest_encounters / actual_room) >= 0.7) {
        std::cout << "If every hero had that luck before ...\n"
                  << std::endl;
    }

    std::cout << "You encoutered " << hero.monster_encounters << " monsters\n"
              << std::endl;

    std::cout << "You ran away " << hero.number_runway << " times\n"
              << std::endl;
    if ((hero.number_runway / actual_room) >= 0.4) {
        std::cout << "That's a little bit exagerated, do not you think ?\n"
                  << std::endl;
    }

    float luck_monsters = static_cast<float>(hero.monster_encounters) / static_cast<float>(actual_room);
    std::cout << "The average of monsters per room is " << luck_monsters << std::endl;
    if (luck_monsters <= 0.5) {
        std::cout << "A lot of people would love to live this peacefully !\n"
                  << std::endl;
    }
    else if (luck_monsters >= 0.5 && luck_monsters <= 1) {
        std::cout << "Did you see a four-leaf clover recently ?\n"
                  << std::endl;
    }
    else if (luck_monsters >= 1 && luck_monsters <= 1.5) {
        std::cout << "You choose to live in hard mode do you ?\n"
                  << std::endl;
    }
    else {
        std::cout << "Wow that's far beyond the statistics ... I think Gaia does not like you ...\n"
                  << std::endl;
    }

    // Last message
    std::cout << "Well that was a great adventure don t you think ?\n"
              << "Maybe you want to try it again ?\n[Y/N]" << std::endl;
    const auto command = get_character_from_player();
    if (command == 'y') {
        std::cout << "Good choice my friend ! Let's go back !\n"
                  << std::endl;
        dungeon_adventure();
    }
    else {
        std::cout << "Uh well, I though our friendship was true ... But I guess not ... Goodbye ... " << hero.name << std::endl;
    }
}