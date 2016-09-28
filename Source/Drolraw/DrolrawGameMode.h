// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Gamer.h"
#include "XmlParser.h"
#include "CardLoader.h"
#include "DrolrawGameMode.generated.h"

/**
 *
 */
UCLASS()
class DROLRAW_API ADrolrawGameMode : public AGameMode
{
	GENERATED_BODY()

	ADrolrawGameMode(const FObjectInitializer& ObjectInitializer);

	bool loadCards();

	FString files[1];
	CardLoader cl;
	std::vector<CharacterCard*> *deverenian;
};
