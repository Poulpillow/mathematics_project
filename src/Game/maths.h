#pragma once
#include <iostream>

inline float expo(float lambda)
{
    float proba = (float)rand() / RAND_MAX;
    return ((-log(proba) / lambda));
}

inline int geometric(float proba)
{
    int   number_extra_room = 0;
    float tirage            = (float)rand() / RAND_MAX;
    while (tirage > proba) {
        number_extra_room += 1;
        tirage = (float)rand() / RAND_MAX;
    }
    return number_extra_room;
}