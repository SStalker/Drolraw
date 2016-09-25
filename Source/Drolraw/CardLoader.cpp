// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "CardLoader.h"

CardLoader::CardLoader()
{
  const FXmlFile file(L"C:/file.xml");


	const FXmlNode* SceneNode = file.GetRootNode();

	const TArray<FXmlNode*> assetNodes = SceneNode->GetChildrenNodes();

	for (int i = 0; i < assetNodes.Num(); i++)
	{
		const TArray<FXmlNode*> meshNodes = assetNodes[i]->GetChildrenNodes();

		for (int i = 0; i < meshNodes.Num(); i++)
		{
			FString tag = meshNodes[i]->GetTag();

			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, tag);
		}
	}
}

CardLoader::~CardLoader()
{
}
