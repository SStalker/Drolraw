// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "CardLoader.h"

CardLoader::CardLoader()
{

  //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("CardLoader")));
  /*const FXmlFile file(L"Content/Xml/Deverenian.xml");


	const FXmlNode* SceneNode = file.GetRootNode();

	const TArray<FXmlNode*> assetNodes = SceneNode->GetChildrenNodes();

	for (int i = 0; i < assetNodes.Num(); i++)
	{
		const TArray<FXmlNode*> meshNodes = assetNodes[i]->GetChildrenNodes();

		for (int j = 0; j < meshNodes.Num(); j++)
		{
			FString tag = meshNodes[j]->GetTag();

			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, tag);
		}
	}*/
}

CardLoader::~CardLoader()
{
}
