// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "Card.h"

Card::Card()
{

}

Card::Card(std::string name_, int level_, std::vector<CardClass> c_Class_, CardStatus status_)
    : name(name_),
      level(level_),
      c_Class(c_Class_),
      status(status_)
{}

Card::~Card()
{

}

std::string Card::getName() const {
    return this->name;
}

void Card::setName(std::string name_){
    this->name = name_;
}

int Card::getLevel() const{
    return this->level;
}

void Card::setLevel(int level_){
    this->level = level_;
}

std::string Card::getCardStatus() const{
    return stati.at(this->status);
}

void Card::setCardStatus(CardStatus status_){
    this->status = status_;
}
std::vector<int> Card::getOrders() const
{
    return orders;
}

void Card::setOrders(const std::vector<int> &value)
{
    orders = value;
}
std::vector<CardClass> Card::getC_Class() const
{
    return c_Class;
}

void Card::setC_Class(const std::vector<CardClass> &value)
{
    c_Class = value;
}

void Card::useOrder(int id)
{

}

void Card::useOrder(int id, CharacterCard *cha)
{
    Order o;
    o.getOrder(id)(2,cha);
}

void Card::play()
{

}



Card::operator std::string() const{
    std::stringstream s;
    s << "Name: " << this->name << std::endl
      << "Level: " << this->level << std::endl
      << "Classes: ";

    for(CardClass cla : c_Class){
        s << classes.at(cla) << " ";
    }

    s << std::endl;
    s << "Status: " << stati.at(this->status) << std::endl;

    return s.str();
}
