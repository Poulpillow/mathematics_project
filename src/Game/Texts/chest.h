#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Entities/objects.h"

inline void show_chest_command()
{
    std::cout << "[Open]" << std::endl;
}

const std::vector<std::string> items = {
    "Sword",
    "Potion",
    "Armor",
    "Gold",
};

const std::vector<std::string> loots = {
    "Claw",
    "Medicinal herbs",
    "Leather",
    "Gold",
};

inline objects get_object(const std::vector<std::string>& items)
{
    float   proba = (float)rand() / RAND_MAX;
    objects item  = set_object("null", 0);
    for (size_t i = 0; i < items.size(); i++) {
        float min = i / 4.f;
        float max = (i + 1) / 4.f;
        if (proba >= min && proba < max) {
            item = set_object(items[i], 5);
        }
    }
    return item;
}

inline void open_chest(const std::vector<std::string>& items)
{
    objects item_obt = get_object(items);
    show_objects(item_obt);
}