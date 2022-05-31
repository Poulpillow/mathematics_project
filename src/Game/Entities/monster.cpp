#include "monster.h"
#include "math.h"

static void get_stats(Monster& monster)
{
    float first_number  = (float)rand() / RAND_MAX;
    float second_number = (float)rand() / RAND_MAX;

    double attack  = sqrt(-2 * log(first_number)) * cos(2 * 3.14 * second_number) + sqrt(-2 * log(first_number)) * sin(2 * 3.14 * second_number);
    double defence = sqrt(-2 * log(second_number)) * sin(2 * 3.14 * first_number) + sqrt(-2 * log(second_number)) * cos(2 * 3.14 * first_number);
    ;

    if (monster.name == "Gobelin") {
        monster.atk += static_cast<int>(fabs(attack) * 2) + 2;
        monster.def += static_cast<int>(fabs(defence) * 2) + 2;
    }
    else if (monster.name == "Spider") {
        monster.atk += static_cast<int>(fabs(attack) * 4) + 5;
        monster.def += static_cast<int>(fabs(defence) * 4) + 5;
        monster.PV += rand() % (10 - 2 + 1) + 2;
    }
    else if (monster.name == "Orc") {
        monster.atk += static_cast<int>(fabs(attack) * 7) + 8;
        monster.def += static_cast<int>(fabs(defence) * 7) + 8;
        monster.PV += rand() % (15 - 5 + 1) + 5;
    }
    else {
        monster.atk += static_cast<int>(fabs(attack) * 10) + 11;
        monster.def += static_cast<int>(fabs(defence) * 10) + 11;
        monster.PV += rand() % (20 - 10 + 1) + 10;
    }
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