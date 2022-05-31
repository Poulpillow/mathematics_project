#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Entities/objects.h"
#include "../Entities/player.h"

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
            int effect = (rand() % 5) + 1;
            item       = set_object(items[i], effect);
        }
    }
    return item;
}

inline void apply_item(player& playerone, const objects& item)
{
    if (item.name == "Sword" || item.name == "Claw") {
        playerone.atk += item.effect;
        std::cout << "You have " << playerone.atk << " attack" << std::endl;
    }
    else if (item.name == "Armor" || item.name == "Leather") {
        playerone.def += item.effect;
        std::cout << "You have " << playerone.def << " defence" << std::endl;
    }
    else if (item.name == "Potion" || item.name == "Medicinal herbs") {
        playerone.PV += item.effect;
        std::cout << "You have " << playerone.PV << " PV" << std::endl;
    }
    else if (item.name == "Gold") {
        playerone.gold += item.effect;
        std::cout << "You have " << playerone.gold << " gold" << std::endl;
    }
}

inline void open_chest(const std::vector<std::string>& items, player& playerone)
{
    objects item_obt = get_object(items);
    show_objects(item_obt);
    apply_item(playerone, item_obt);
}