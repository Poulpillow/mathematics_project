#include <math.h>
#include <stdlib.h>
#include <ctime>
#include "Game/PlayerInput.h"
#include "Game/game.h"
#include "Game/maths.h"

int main()
{
    // Init for random
    auto seedTime = time(NULL);
    srand(static_cast<unsigned int>(seedTime));

    // First time
    dungeon_adventure();

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
    return 0;
}

/* STRUCTURE

main.cpp

    main()
    {
        dungeon_adventure();
    }

game.cpp

    dungeon_adventure()
    {
        introduction();
        while(player.pv!=0 || room.number != 10)
        {
            room();
            room.number ++;
        }
        end(player.pv);
    }

    introduction()
    {
        show_title();
        create_player();
        show_rules();
        set_up_menu();
    }

    end(player.pv)
    {

    }

room.cpp

    room()
    {
        new_room();
        if(number_monster==0)
        {
            display_chest();
        }
        else
        {
            set_up_monster();
            fight();
        }
    }

    new_room()
    {
        number_monster();
    }

chest.cpp

    display_chest()
    {
        ...
    }

fight.cpp

    fight()
    {
        while(player.pv!=0 && monster.pv!=0)
        {
            if(is_player_turn)
            {

            }
            else
            {

            }
        }
    }

tour à tour entre joueur et monstres (un monstre à la fois)
choix joueurs :
attaquer //
fuir
se soigner
fin combat si tous les monstres sont morts ou que le joueur meurt
loot du stuff // (voir ce qu’on fait si 0)

menu.cpp

    set_up_menu()
    {

    }

player.cpp

monster.cpp


sortie salle
proposition boire potion (s’il en a une)
+ X PV pour le joueur
message gagné (recommence la boucle) ou message perdu (game over)


Message fin
Ouai t’es trop fort (générique)
Ah bah zut recommence
Tableau des statistiques
Proposer de rejouer



*/