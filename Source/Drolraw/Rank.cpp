// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "Rank.h"
#include "CharacterCard.h"
#include <algorithm>

Rank::Rank(int row_)
    :row(row_)
{
}

charList Rank::getRank() const
{
    return rank;
}

void Rank::setRank(const charList &value)
{
    rank = value;
}

void Rank::insertCharacter(CharacterCard *cha)
{
    rank.push_back(cha);
    cha->setRank(this);
}

void Rank::insertCharacter(CharacterCard *newChar, CharacterCard *adjacentChar, DIRECTION d)
{
    auto it = std::find(rank.begin(), rank.end(), adjacentChar);

    if(d == DIRECTION::Left){

        rank.insert(it,newChar);

    }else{

        rank.insert(it+1, newChar);

    }
}

void Rank::deleteCharacter(CharacterCard *cha)
{
    auto it = rank.begin();

    for(;it != rank.end(); ++it){
        if(*it == cha){
            rank.erase(it);
            return;
        }
    }
}

int Rank::getRow() const
{
    return row;
}

void Rank::setRow(int value)
{
    row = value;
}

int Rank::numberOfCharacters()
{
    return rank.size();
}

int Rank::getPositionOfChar(CharacterCard *cha) const
{
    auto it = std::find(rank.begin(), rank.end(), cha);

    if(it != rank.end()){
        return std::distance(rank.begin(), it);
    }

    return -1;
}

charList Rank::getAdjacentCharacters(CharacterCard *middleChar) const
{
    int pos = getPositionOfChar(middleChar);
    int size = rank.size();
    if(this->rank.size() == 1){
        return charList{};
    }

    else if(this->rank.size() == 2){

        if(pos == 1){

            return charList{rank.at(0)};

        } else {

            return charList{rank.at(1)};
        }
    }

    else if(pos != 0){
        return charList{rank.at(pos-1), rank.at(pos+1)};
    }
    else if(pos == 0){
        return charList{rank.at(pos+1)};
    }
    else if(pos == size-1){
        return charList{rank.at(pos-1)};
    }
    else{
        return charList{};
    }
}
