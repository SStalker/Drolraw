// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Card.h"
#include "ResourceIdentifiers.h"
#include <vector>
#include <map>
/**
 *
 */
class DROLRAW_API Item : public Card
{
public:
    Item();
    Item(std::string name, int level, std::vector<CardClass> c_Class, CardStatus status, int attack, int armorclass, std::vector<Traits::ID> t, std::vector<Equipment::ID> eqs );

    int getAttackPower() const;
    void setAttackPower(int value);

    int getArmor() const;
    void setArmor(int value);

    std::vector<Traits::ID> getTraits() const;
    void setTraits(const std::vector<Traits::ID> &value);

    std::map<Feats::ID, int> getFeats() const;
    void setFeats(const std::map<Feats::ID, int> &value);

    std::vector<Equipment::ID> getEquipStates() const;
    void setEquipStates(const std::vector<Equipment::ID> &value);

    virtual void play();

private:
    int attackPower;
    int armor;
    std::vector<Traits::ID> traits;
    std::vector<Equipment::ID> equipStates;
    std::map<Feats::ID, int> feats;

};
