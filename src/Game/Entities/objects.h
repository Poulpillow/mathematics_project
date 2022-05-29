#pragma once
#include <iostream>
#include <string>

struct objects {
    std::string name;
    int         effect;
};

inline objects set_object(const std::string& name, const int& effect)
{
    objects item;
    item.name   = name;
    item.effect = effect;
    return item;
};

inline void show_objects(const objects& item)
{
    std::cout << "You got a " << item.name << std::endl;
};