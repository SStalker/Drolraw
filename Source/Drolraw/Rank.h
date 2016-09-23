// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ResourceIdentifiers.h"
/**
 *
 */
class DROLRAW_API Rank
{
public:
    enum DIRECTION{
        Left,
        Right
    };
    Rank(int row_);
    charList getRank() const;
    void setRank(const charList &value);
    void insertCharacter(CharacterCard *cha);
    void insertCharacter(CharacterCard *newChar, CharacterCard *adjacentChar, DIRECTION d);
    void deleteCharacter(CharacterCard *cha);
    int getRow() const;
    void setRow(int value);
    int numberOfCharacters();
    int getPositionOfChar(CharacterCard *cha) const;
    charList getAdjacentCharacters(CharacterCard *middleChar) const;

private:
    charList rank;
    int row;
};
