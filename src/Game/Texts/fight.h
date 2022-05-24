#pragma once
#include <iostream>

void show_fight_command()
{
    std::cout << "[Fight / Run / Heal]" << std::endl;
}

template<typename Ack, typename Def>
void fight(Ack& fighter, Def& victim)
{
    victim.PV = victim.PV - (fighter.atk - victim.def);
}

void run()
{
    /*
    Tirage
    Regarde proba
    Si oui
        Nouvelle salle
    Si non
        Raté... Good luck
    */
}

void heal()
{
    /*
    Type command
    Heal player
    */
}