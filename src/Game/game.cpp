#include "game.h"
#include "Entities/player.h"
#include "Texts/texts.h"

static player introduction()
{
    return display_title_screen();
}

void dungeon_adventure()
{
    player hero = introduction();
}

static void end()
{
}