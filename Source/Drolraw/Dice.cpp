// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "Dice.h"
#include <chrono>

Dice::Dice()
{

}

int Dice::roll()
{
    unsigned int seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine e{seed1};
    static std::uniform_int_distribution<int> d{1,20};
    int currentRoll = d(e);
    //std::cout << "The dice rolled a: " << currentRoll << std::endl;
    return currentRoll;
}

int Dice::roll(int bonus)
{
    int currentRoll = Dice::roll();
    //std::cout << "  with a Bonus: +" << bonus  << " = " << currentRoll+bonus << std::endl << std::endl;
    return currentRoll+bonus;
}

void Dice::initialize()
{

}
