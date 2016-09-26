// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "DrolrawGameMode.h"

ADrolrawGameMode::ADrolrawGameMode(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
  //UE_LOG(LogTemp, Warning, TEXT("Your message"));
  DefaultPawnClass = AGamer::StaticClass();

  //CardLoader cl;
}
