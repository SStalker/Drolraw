// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "DrolrawGameMode.h"

ADrolrawGameMode::ADrolrawGameMode(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
  //UE_LOG(LogTemp, Warning, TEXT("Your message"));
  DefaultPawnClass = AGamer::StaticClass();
  files[0] = "Xml/Deverenian.xml";

  deverenian = new std::vector<CharacterCard*>();

  loadCards();
}

bool ADrolrawGameMode::loadCards()
{
  FString path = FPaths::GameContentDir();

  for(FString f : files)
  {
    UE_LOG(LogTemp, Warning, TEXT("Files to load: %s"), *f);
    cl.openXMLFile(path + f);
    cl.loadAllCards(deverenian);
  }

  for(CharacterCard* cc : *deverenian)
  {
    std::cout << "Name: " << cc->getName() << std::endl;
    std::cout << "Image: " << cc->getImagePath() << std::endl;
  }

  return true;
}
