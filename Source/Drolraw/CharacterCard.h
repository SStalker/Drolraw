// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Card.h"
#include "Item.h"
#include "Dice.h"
#include "Rank.h"
#include "PlayField.h"
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

/**
 *
 */
class DROLRAW_API CharacterCard : public Card
{
public:
	enum Faction{
			Deverenian,
			Dwarf,
			Elf,
			FreeKingdom,
			Nothrog,
			TheChosen,
			Mercenaries
	};

	CharacterCard();
	CharacterCard(std::string name,
						int level,
						std::vector<CardClass> cardClass,
						CardStatus status
	);

	CharacterCard(
			std::string name,
			int level,
			std::vector<CardClass> cardClass,
			CardStatus status,
			int numberOfAttacks,
			std::vector<int> attackPower,
			int armor,
			bool alignment,
			int skill,
			int hitpoints
	);

	operator std::string() const;

	int getNumberOfAttacks() const;
	void setNumberOfAttacks(int value);

	std::vector<int> getAttackPower() const;
	void setAttackPower(std::vector<int> power);

	int getArmor() const;
	void setArmor(int value);

	bool getAlignment() const;
	void setAlignment(bool value);

	std::map<Feats::ID, int> getFeats() const;
	void setFeats(const std::map<Feats::ID, int> &value);

	void setFeat(Feats::ID, int value);

	int getSkill() const;
	void setSkill(int value);

	int getHitpoints() const;
	void setHitpoints(int value);

	std::vector<Item> getItems() const;
	void setItems(const std::vector<Item> &value);

	void equipItem(Item item);

	bool canEquip(Item item);

	bool hasItem(Equipment::ID equip);

	void attackMeleeStrike( CharacterCard &enemy);

	void attack(CharacterCard &enemy, int power);

	void defend(int power);

	void move(int direction, int ranks);

	Rank *getRank() const;
	void setRank(Rank *value);

	virtual void play();

private:

	int numberOfAttacks;
	std::vector<int> attackPower;
	int armor;
	bool alignment;
	std::map<Feats::ID, int> feats;
	int skill;
	int hitpoints;
	std::vector<Item> items;
	Rank *rank;
	//std::vector<Bonus> bonus;
};
