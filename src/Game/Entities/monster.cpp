#include "monster.h"
#include "math.h"

static void get_stats(Monster& monster)
{
    float first_number  = (float)rand() / RAND_MAX;
    float second_number = (float)rand() / RAND_MAX;

    double attack  = sqrt(-2 * log(first_number)) * cos(2 * 3.14 * second_number);
    double defence = sqrt(-2 * log(first_number)) * sin(2 * 3.14 * second_number);
    ;

    monster.atk += static_cast<int>(attack);
    monster.def += static_cast<int>(defence);
}

Monster set_monster()
{
    Monster monster;
    float   tirage = (float)rand() / RAND_MAX;
    if (tirage < 0.4) {
        monster.name = monster_name[0];
    }
    else if (0.4 < tirage && tirage < 0.7) {
        monster.name = monster_name[1];
    }
    else if (0.7 < tirage && tirage < 0.9) {
        monster.name = monster_name[2];
    }
    else {
        monster.name = monster_name[3];
    }
    get_stats(monster);
    return monster;
}

void show_monster_name(Monster monster)
{
    std::cout << "A " << monster.name << " appeared" << std::endl;
}

bool monster_is_alive(Monster monster)
{
    return (monster.PV < 0) ? false : true;
}