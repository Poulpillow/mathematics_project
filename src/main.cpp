#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "Game/Texts/chest.h"
#include "Game/game.h"
#include "Game/maths.h"

/*void rademacher()
{
    int tirage = rand() % (1 + 0 + 1) + 0;
    if (tirage == 0) {
        std::cout << "Perdu" << std::endl;
    }
    else if (tirage == 1) {
        std::cout << "Gagné" << std::endl;
        open_chest(loots);
    }
    else {
        std::cout << "Bonne question" << std::endl;
    }
}
*/
int main()
{
    auto seedTime = time(NULL);
    srand(static_cast<unsigned int>(seedTime));
    // rademacher();
    // std::cout << expo(0.05f) << std::endl;
    /*const auto command = get_commands();
    if (command == "open") {
        open_chest(items);
    }*/
    dungeon_adventure();
    return 0;
}