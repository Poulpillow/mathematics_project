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

    return 0;
}