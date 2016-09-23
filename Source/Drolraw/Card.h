// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ResourceIdentifiers.h"
#include "Order.h"
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <map>
/**
 *
 */
class DROLRAW_API Card
{
public:

	    std::map<CardClass, std::string> classes{
	        {CardClass::Cleric, "Cleric"},
	        {CardClass::Figher, "Figher"},
	        {CardClass::Rogue, "Rogue"},
	        {CardClass::Wizard, "Wizard"},
	        {CardClass::multiclass, "multiclass"},
	        {CardClass::none, "none"},
	    };


	    std::map<CardStatus, std::string> stati{
	        {CardStatus::Ready, "Ready"},
	        {CardStatus::Spend, "Spend"},
	        {CardStatus::Stun, "Stunned"},
	        {CardStatus::Dead, "Dead"},
	        {CardStatus::Destroyed, "Destroyed"},
	    };

	    Card();
	    Card(std::string name_, int level_, std::vector<CardClass> c_Class_, CardStatus status_);
	    virtual ~Card();
	    std::string getName() const;
	    void setName(std::string name);

	    int getLevel() const;
	    void setLevel(int level);

	    std::string getCardStatus() const;
	    void setCardStatus(CardStatus status);

	    std::vector<int> getOrders() const;
	    void setOrders(const std::vector<int> &value);

	    operator std::string() const;

	    std::vector<CardClass> getC_Class() const;
	    void setC_Class(const std::vector<CardClass> &value);

	    void useOrder(int id);

	    void useOrder(int id, CharacterCard *cha);

	    void virtual play();

	private:

	    std::string name;
	    int level;
	    std::vector<CardClass> c_Class;
	    CardStatus status;
	    std::vector<int> orders;
};
