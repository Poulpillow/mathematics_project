#pragma once
#include <iostream>

void pile_ou_face(float p)
{
    float tirage = (float)rand() / RAND_MAX;
    if (tirage < p) {
        std::cout << "Face : " << tirage << std::endl;
    }
    else {
        std::cout << "Pile : " << tirage << std::endl;
    }
}

void tirage_de()
{
    int tirage = (rand() % 6) + 1;
    std::cout << "Tu as tire " << tirage << std::endl;
}

void tirage_de_float()
{
    float tirage = (float)rand() / RAND_MAX;
    for (int i = 1; i <= 6; i++) {
        float min = (i - 1.f) / 6.f;
        float max = i / 6.f;
        if (tirage >= min && tirage < max) {
            std::cout << "Tu as tire " << i << std::endl;
        }
    }
}

void culmulative_distribution()
{
    float X = 0.f;
    while (X < 1) {
        float proba = (float)rand() / RAND_MAX;
        std::cout << proba << std::endl;
        X += proba;
        if (X > 1) {
            X -= proba;
            break;
        }
        std::cout << "X boucle : " << X << std::endl;
    }
    std::cout << "X avant : " << X << std::endl;
    X += 1 - X;
    std::cout << X << std::endl;
}

float expo(float gamma)
{
    float proba = (float)rand() / RAND_MAX;
    return (-gamma * log(1 - proba));
}