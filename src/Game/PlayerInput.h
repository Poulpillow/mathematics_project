#pragma once
#include <iostream>

template<typename T>
T get_input_from_the_player()
{
    T input;
    while (!(std::cin >> input)) {
        std::cout << "Invalide input" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}

char get_character_from_player()
{
    auto input = get_input_from_the_player<char>();
    return static_cast<char>(tolower(input));
}