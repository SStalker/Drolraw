// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "Item.h"

Item::Item() : Card()
{

}

Item::Item(std::string name, int level, std::vector<CardClass> c_Class, CardStatus status, int attack, int armorclass, std::vector<Traits::ID> t , std::vector<Equipment::ID> eqs)
    : Card(name,level,c_Class, status),
      attackPower(attack),
      armor(armorclass),
      traits(t),
      equipStates(eqs)
{}
int Item::getAttackPower() const
{
    return attackPower;
}

void Item::setAttackPower(int value)
{
    attackPower = value;
}
int Item::getArmor() const
{
    return armor;
}

void Item::setArmor(int value)
{
    armor = value;
}
std::vector<Traits::ID> Item::getTraits() const
{
    return traits;
}

void Item::setTraits(const std::vector<Traits::ID> &value)
{
    traits = value;
}

std::map<Feats::ID, int> Item::getFeats() const
{
    return feats;
}

void Item::setFeats(const std::map<Feats::ID, int> &value)
{
    feats = value;
}
std::vector<Equipment::ID> Item::getEquipStates() const
{
    return equipStates;
}

void Item::setEquipStates(const std::vector<Equipment::ID> &value)
{
    equipStates = value;
}

void Item::play()
{

}
