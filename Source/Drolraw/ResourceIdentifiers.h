// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
class CharacterCard;
class Rank;
//class Playfield;

typedef std::vector<CharacterCard*> charList;
typedef std::vector<Rank*> Ranks;

namespace Feats
{
    enum ID
    {
        Charisma,
        Defend,
        MagicResistence,
        Markmanship,
        Medicine,
        Powerattack,
        Riding,
        Riposte,
        Scribe,
        Stealth
    };
}

namespace Traits
{
    enum ID
    {
        Unique,
        Epic,
        Cursed,
        None,
        Warlord,
        Overlord,
    };
}

namespace Equipment
{
    enum ID
    {
        Helm,
        Weapon,
        Shield,
        Armor,
        Steed,
        Gauntlet,
    };
}

enum CardClass{
    Cleric,
    Figher,
    Rogue,
    Wizard,
    multiclass,
    none
};

enum CardStatus{
    Ready,
    Spend,
    Stun,
    Dead,
    Destroyed
};

namespace Bonus_
{
    enum ID
    {
        Attack,
        Armor,
        Level,
        Skill,
        Hitpoint,
        Feats
    };
}

/**
 *
 */
class DROLRAW_API ResourceIdentifiers
{
public:
	ResourceIdentifiers();
	~ResourceIdentifiers();
};
