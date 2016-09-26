// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "DrolrawGameMode.h"

ADrolrawGameMode::ADrolrawGameMode(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
  //UE_LOG(LogTemp, Warning, TEXT("Your message"));
  DefaultPawnClass = AGamer::StaticClass();
  FString path = FPaths::GameContentDir();
  path += "Xml/Deverenian.xml";

  const FXmlFile file(path);

  UE_LOG(LogTemp, Warning, TEXT("Your message %s"), *file.GetLastError());
  UE_LOG(LogTemp, Warning, TEXT("Your message %s"), *path);

  const FXmlNode* SceneNode = file.GetRootNode();

	const TArray<FXmlNode*> assetNodes = SceneNode->GetChildrenNodes();

	for (int i = 0; i < assetNodes.Num(); i++)
	{
		const TArray<FXmlNode*> meshNodes = assetNodes[i]->GetChildrenNodes();
    UE_LOG(LogTemp, Warning,TEXT("%s"), *assetNodes[i]->GetContent());
		for (int j = 0; j < meshNodes.Num(); j++)
		{
			FString tag = meshNodes[j]->GetAttribute("value");

      UE_LOG(LogTemp, Warning,TEXT("%s"), *tag);
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, tag);
		}
	}
  //CardLoader cl;
}
