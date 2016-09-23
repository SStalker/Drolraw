// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "PlayField.h"

PlayField::PlayField()
{
    // Speicher reservieren für die Ränge
    this->rs.reserve(10);
    this->rs.push_back(new Rank(1));
    this->rs.push_back(new Rank(2));
    this->rs.push_back(new Rank(3));
}

PlayField::~PlayField()
{
    for(auto it = this->rs.begin(); it != this->rs.end(); ++it)
        delete *it;
}

int PlayField::getRankOfChar(CharacterCard *charToFind) const{

    for(Rank *rk : rs)
        for(CharacterCard *c : rk->getRank())
            if(c == charToFind)
                return rk->getRow();

    return -1;
}

int PlayField::numberOfRanks()
{
    return rs.size();
}

Rank* PlayField::getRank(int pos)
{
    if( pos <= rs.size() )
        return rs.at(pos);

    return nullptr;
}

bool PlayField::checkIllegalRank()
{
    int ranks = rs.size();

    for( int i = 0; i < (ranks-1); i++ ) {

        Rank *current = rs.at(i);
        Rank *after = rs.at(i+1);

        //if()
        if( current->numberOfCharacters() < after->numberOfCharacters() )
            return true;
    }

    return false;
}

void PlayField::drawPlayField()
{
    for(Rank *rk : rs) {
        for(CharacterCard *c : rk->getRank()){
            std::cout << "|| " << c->getName() << " ||   ";
        }
        std::cout << std::endl;
    }
}
