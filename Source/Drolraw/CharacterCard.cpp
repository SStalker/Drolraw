// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "CharacterCard.h"
#include "PlayField.h"

CharacterCard::CharacterCard() : Card()
{

}

CharacterCard::CharacterCard(std::string name, int level, std::vector<CardClass> c_Class, CardStatus status)
    : Card(name,level,c_Class, status)
{

}

CharacterCard::CharacterCard(std::string name, int level, std::vector<CardClass> c_Class, CardStatus status, int numberOfAttacks_, std::vector<int> attackPower_, int armor_, bool alignment_, int skill_, int hitpoints_)
    : Card(name,level,c_Class, status)
{
  this->hitpoints = hitpoints_;
  this->numberOfAttacks = numberOfAttacks_;
  this->attackPower = attackPower_;
  this->armor = armor_;
  this->alignment = alignment_;
  this->skill = skill_;
}

int CharacterCard::getNumberOfAttacks() const
{
    return numberOfAttacks;
}

void CharacterCard::setNumberOfAttacks(int value)
{
    numberOfAttacks = value;
}
std::vector<int> CharacterCard::getAttackPower() const
{
    return attackPower;
}

void CharacterCard::setAttackPower( std::vector<int> power)
{
    /*for(int &power : attackPower){
        power += value;
    }*/
    this->attackPower = power;

}

int CharacterCard::getArmor() const
{
    return armor;
}

void CharacterCard::setArmor(int value)
{
    armor = value;
}
bool CharacterCard::getAlignment() const
{
    return alignment;
}

void CharacterCard::setAlignment(bool value)
{
    alignment = value;
}
std::map<Feats::ID, int> CharacterCard::getFeats() const
{
    return feats;
}

void CharacterCard::setFeats(const std::map<Feats::ID, int> &value)
{
    feats = value;
}

void CharacterCard::setFeat(Feats::ID fid, int value)
{
    if(this->feats.size() == 0){
        this->feats[fid] = value;
    }

    for( std::map<Feats::ID, int>::iterator it = feats.begin(); it != feats.end(); ++it){

        if( (*it).first == fid){

            this->feats.at(fid) = value;

        } else {

            this->feats[fid] = value;
        }
    }
}
int CharacterCard::getSkill() const
{
    return skill;
}

void CharacterCard::setSkill(int value)
{
    skill = value;
}
int CharacterCard::getHitpoints() const
{
    return hitpoints;
}

void CharacterCard::setHitpoints(int value)
{
    hitpoints = value;
}
std::vector<Item> CharacterCard::getItems() const
{
    return items;
}

void CharacterCard::setItems(const std::vector<Item> &value)
{
    items = value;
}

bool CharacterCard::canEquip(Item newItem)
{
    bool fitClass = false;
    bool levelHighEnough = false;
    /*
     *  Hier wird überprüft, ob die Karte dem jeweiligen CharacterCard zugewiesen werden kann.
     *  1.  Passt die Klasse
     *  2.  Ist das Level hoch genug
     *  3.  Überprüfen spezieller Eigenschaften(Item für gute oder böse bzw. für bestimmte Feats)
     *  4.  Ist das Item vielleicht schon vorhanden (zweite Waffe)? Abfrage nach löschen der vorherigen
     *
    */
    //if(this->getCardClass() != newItem.getCardClass()){ return false;}
    for(CardClass characterClasses : this->getC_Class()){
        for(CardClass itemClasses : newItem.getC_Class()){
            if(characterClasses == itemClasses)
                fitClass = true;
        }
    }

    if(newItem.getC_Class().at(0) == CardClass::none)
        fitClass = true;

    if( (this->getLevel() + this->getRank()->getRow()) >= newItem.getLevel())
        levelHighEnough = true;


    /*
        if(this)
        foreach(Item equippedItem , this->getItems()){
        if(equippedItem.)
        }
    */
    if(fitClass && levelHighEnough){
        std::cout << this->getName() << " can equip " << newItem.getName() << std::endl;
        return true;
    }

    std::cout << this->getName() << " can not equip " << newItem.getName() << std::endl;
    return false;
}

bool CharacterCard::hasItem(Equipment::ID equip)
{
    for(Item i : this->items){
        for(Equipment::ID eq : i.getEquipStates()){
            if(eq == equip)
                return true;
        }
    }

    return false;
}

void CharacterCard::attackMeleeStrike(CharacterCard &enemy)
{
    // Only attack without any other power items or so
    for(int attacks : this->getAttackPower()){
        this->attack(enemy,Dice::roll(attacks));
    }
}

void CharacterCard::attack(CharacterCard &enemy, int power)
{
    std::cout << this->getName() << " will attack " << enemy.getName() << " << Power: " << power << std::endl;
    enemy.defend(power);
}

void CharacterCard::defend(int power)
{
    std::cout << this->getName() << " defends the Attack with Armor: " << this->getArmor() <<
                 " against Power: " << power << std::endl;
    if(this->armor <= power){
        this->hitpoints--;
    }

    if(this->hitpoints < 1){
        std::cout << this->getName() << " is dead" << std::endl;
    }
}
Rank *CharacterCard::getRank() const
{
    return rank;
}

void CharacterCard::setRank(Rank *value)
{
    rank = value;
}

void CharacterCard::play(  )
{
    std::cout << "Level: " << this->getLevel() << std::endl;
    //std::cout << "Number ranks: " << playfield->numberOfRanks() << std::endl;

    //
    // checkIllegalRank();

}


void CharacterCard::equipItem(Item item)
{
    if(canEquip(item))
        items.push_back(item);
}









CharacterCard::operator std::string() const{
    std::stringstream s;
    Card *c = (Card*)this;

    s << (std::string)*c;
    s << "Attacks: (";
    for(unsigned int i = 0; i < attackPower.size(); i++){

        if(i == attackPower.size()-1){
            s << attackPower.at(i);
            break;
        }

        s << attackPower.at(i) << "|";
    }

    s << ")" << std::endl;

    s << "Armor: " << this->armor << std::endl
      << "Alignment: ";

         if(this->alignment){ s << "Good";}
         else{ s << "Evil"; }

    s << std::endl
      << "Skill: " << this->skill << std::endl
      << "Hitpoints: " << this->hitpoints << std::endl;

    s << "Feats: \n";
    for( auto pair : this->feats ){

        std::string tmp;
        switch(pair.first)
        {
            case 0 : tmp = "Charisma"; break;
            case 1 : tmp = "Defend"; break;
            case 2 : tmp = "MagicResistence"; break;
            case 3 : tmp = "Markmanship"; break;
            case 4 : tmp = "Medicine"; break;
            case 5 : tmp = "Powerattack"; break;
            case 6 : tmp = "Riding"; break;
            case 7 : tmp = "Riposte"; break;
            case 8 : tmp = "Scribe"; break;
            case 9 : tmp = "Stealth"; break;
        }
        s << "  " << tmp << " | " << pair.second << std::endl;
    }

    s << std::endl;
    return s.str();
}
