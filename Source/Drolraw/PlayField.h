// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Rank.h"
#include "CharacterCard.h"
#include <vector>
#include "ResourceIdentifiers.h"
/**
 *
 */
class DROLRAW_API PlayField
{
public:
    PlayField();
    ~PlayField();
    int getRankOfChar(CharacterCard *charToFind) const;
    int numberOfRanks();
    Rank* getRank( int pos );
    bool checkIllegalRank();
    void drawPlayField();
private:
    Ranks rs;
};
