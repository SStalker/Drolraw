// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "XmlParser.h"
#include "CharacterCard.h"
#include <string>
#include <vector>
/**
 *
 */

class DROLRAW_API CardLoader
{
public:
	CardLoader();
	~CardLoader();

	CharacterCard* loadCard( const FXmlNode *element);

	void loadCharacter( const FXmlNode *element, CharacterCard *card );

	template< typename T >
	void loadItem( FXmlNode *element, T *card );

	template< typename T >
	void loadAction( FXmlNode *element, T *card );

	void loadAllCards( std::vector<CharacterCard*> *container );

	void openXMLFile( FString path );

	std::vector<int> splitAttack( FString atk );

private:
	FXmlFile file;
	FXmlNode* root;

};
