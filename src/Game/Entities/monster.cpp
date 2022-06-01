#include "monster.h"
#include "math.h"

static void get_stats(Monster& monster)
{
    float first_number  = (float)rand() / RAND_MAX;
    float second_number = (float)rand() / RAND_MAX;

    double attack  = sqrt(-2 * log(first_number)) * cos(2 * 3.14 * second_number) + sqrt(-2 * log(first_number)) * sin(2 * 3.14 * second_number);
    double defence = sqrt(-2 * log(second_number)) * sin(2 * 3.14 * first_number) + sqrt(-2 * log(second_number)) * cos(2 * 3.14 * first_number);

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
        std::cout << "Oh! It is a Goblin ! Even a small human like you should get through that one !" << std::endl;
    }
    else if (0.4 < tirage && tirage < 0.7) {
        monster.name = monster_name[1];
        std::cout << "Ah ! It is a Gigantus Araignus ! And as the name suggests, you are not going to be able to stop him with just a fly swatter ! Good luck!" << std::endl;
    }
    else if (0.7 < tirage && tirage < 0.9) {
        monster.name = monster_name[2];
        std::cout << "Oooooooooooooooooooooooooooo It is an Orc. Finally a real challenge! It is time to prove you are up to it!" << std::endl;
    }
    else {
        monster.name = monster_name[3];
        std::cout << "Uhoh, That is a Dragon. I hope you made your will before you came..." << std::endl;
    }
    get_stats(monster);
    return monster;
}

void show_monster_name(Monster monster)
{
    std::cout << "\nA " << monster.name << " appeared !"
              << std::endl;
}

bool monster_is_alive(Monster monster)
{
    return (monster.PV < 0) ? false : true;
}