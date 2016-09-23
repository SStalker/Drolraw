// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <random>
/**
 *
 */
class DROLRAW_API Dice
{
public:
    Dice();
    static int roll();
    static int roll(int bonus);

private:

    void initialize();
};
