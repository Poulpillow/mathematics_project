#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "Game/Texts/texts.h"

/*struct monster {
    std::string name;
    int         level;
    int         PV;
};*/

const std::vector<std::string> objects = {
    "Sword",
    "Potion",
    "Armor",
    "Gold",
};

void open_chest(const std::vector<std::string> objects)
{
    float proba = (float)rand() / RAND_MAX;
    for (size_t i = 0; i < objects.size(); i++) {
        float min = i / 4.f;
        float max = (i + 1) / 4.f;
        if (proba >= min && proba < max) {
            std::cout << "Tu as obtenu " << objects[i] << " !" << std::endl;
        }
    }
}

int main()
{
    auto seedTime = time(NULL);
    srand(static_cast<unsigned int>(seedTime));
    display_title_screen();
    return 0;
}