// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "CardLoader.h"

CardLoader::CardLoader()
{

  //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("CardLoader")));
  /*FString path = FPaths::GameDir();
  path += "Xml/Deverenian.xml";
  const FXmlFile file(path);

  UE_LOG(LogTemp, Warning, TEXT("Your message %s"), *file.GetLastError());
  UE_LOG(LogTemp, Warning, TEXT("Your message %s"), *path);*/
}

CardLoader::~CardLoader()
{
}

std::vector<int> CardLoader::splitAttack( FString atk ) {

    std::vector<int> power;

    TArray<FString> list = {};

    atk.ParseIntoArray(list, TEXT("|"), false);

    for( FString val : list )
        power.push_back(FCString::Atoi(*val));

    return power;
}


void CardLoader::openXMLFile(FString path){

  UE_LOG(LogTemp, Warning, TEXT("CardLoader::openXMLFile: %s"), *path);
  file.LoadFile(path);

  UE_LOG(LogTemp, Warning, TEXT("Your message %s"), *file.GetLastError());
  root = file.GetRootNode();

}



void CardLoader::loadCharacter(const FXmlNode *element, CharacterCard *card) {
    //CharacterCard *t = new CharacterCard();
    UE_LOG(LogTemp, Warning, TEXT("CardLoader::loadCharacter"));
    FString nameOfCard = element->GetAttribute("name");

    card->setName(TCHAR_TO_UTF8(*nameOfCard));

    FString pathToImage = element->GetAttribute("graphic");
    card->setImagePath(TCHAR_TO_UTF8(*pathToImage));

    UE_LOG(LogTemp, Warning, TEXT("CardLoader::loadCharacter::name %s"), *nameOfCard);

    TArray<FXmlNode*> attr = element->GetChildrenNodes();

    UE_LOG(LogTemp, Warning, TEXT("CardLoader::loadCharacter::attr NUM %i"), attr.Num());

    for(FXmlNode* node : attr)
    {
      FString attrKey = node->GetAttribute("key");
      FString attrVal = node->GetAttribute("value");
      UE_LOG(LogTemp, Warning, TEXT("Key: %s Value: %s"), *attrKey, *attrVal);

      if(attrKey == "Attack"){
          card->setAttackPower( splitAttack(attrVal) );
      }

      if( attrKey == "Armor" )
          card->setArmor( FCString::Atoi(*attrVal) );

      if( attrKey == "Level" )
          card->setLevel( FCString::Atoi(*attrVal) );

      if( attrKey == "Skill" )
          card->setSkill( FCString::Atoi(*attrVal) );

      if( attrKey == "Hitpoint" )
          card->setHitpoints( FCString::Atoi(*attrVal) );

      if(attrKey == "Alignment") {
         if(attrVal == "good")
              card->setAlignment(true);
         else
              card->setAlignment(false);
     }

     if( node->GetFirstChildNode() != nullptr ){
         FString key = attrKey;
         //qDebug() << key;

         if(key == "feats"){
             for (FXmlNode *innerNode : node->GetChildrenNodes()) {
                 FString innerKey = innerNode->GetAttribute("key");

                 FString innerValue = innerNode->GetAttribute("value");
                 UE_LOG(LogTemp, Warning, TEXT(">>> Key: %s Value: %s"), *innerKey, *innerValue);
                 //qDebug() << key << ": " << value << endl;

             }
         }else if(key == "classes"){
             for (FXmlNode *innerNode : node->GetChildrenNodes()) {

                 FString text = innerNode->GetContent();
                 //qDebug() << "text: " << text << endl;
                 //QString uiName = QString("checkBox%1").arg(text);
                 //qDebug() << text << uiName <<  endl;
                UE_LOG(LogTemp, Warning, TEXT(">>> Classes : %s"), *text);
             }
         }
     }

    }
}

template<typename T>
void CardLoader::loadItem(FXmlNode *element, T *card) {

}

template<typename T>
void CardLoader::loadAction(FXmlNode *element, T *card) {

}

void CardLoader::loadAllCards(std::vector<CharacterCard*> *container){
  UE_LOG(LogTemp, Warning, TEXT("CardLoader::loadAllCards"));

    const FXmlNode* element = root->FindChildNode("card");

    //FString typeOfCard = element->GetAttribute("type");
    //UE_LOG(LogTemp, Warning, TEXT("CardLoader::loadCard: %s"), *typeOfCard);

    //FXmlNode currentCard;
    CharacterCard *card = nullptr;

    for ( ; element != nullptr; element = element->GetNextNode() ) {
        card = loadCard(element);
        container->push_back( card );
    }
}

CharacterCard* CardLoader::loadCard( const FXmlNode *element){


    FString typeOfCard = element->GetAttribute("type");
    UE_LOG(LogTemp, Warning, TEXT("CardLoader::loadCard: %s"), *typeOfCard);
    //qDebug() << "Card type of: " << typeOfCard << "\n";

    if( typeOfCard == "Character" ) {
        CharacterCard* card = new CharacterCard();
        loadCharacter(element, card);
        return card;
        //qDebug() << "TEEEST: " << card->getName().data() << "\n";
    }

    return nullptr;

    /*else if( typeOfCard == "Item" ) {
        card = new T();
        loadItem(element, card);
    }
    else if( typeOfCard == "Action" ) {
        card = new T();
        loadAction(element, card);
    }*/
}


/*template< typename T>
void CardLoader::loadAllCards(std::vector<T*> *container){

    const FXmlNode* element = root->FindChildNode("card");

    //FXmlNode currentCard;

    for ( ; element != nullptr; element = element->GetNextNode() ) {
        T *card = loadCard(element, card);
        container->push_back( card );
    }
}

template< typename T >
T* CardLoader::loadCard( FXmlNode *element, T* card){


    FString typeOfCard = element->GetAttribute("type");
    UE_LOG(LogTemp, Warning, TEXT("CardLoader::loadCard: %s"), *typeOfCard);
    //qDebug() << "Card type of: " << typeOfCard << "\n";

    if( typeOfCard == "CharacterCard" ) {
        card = new T();
        loadCharacterCard(element, card);
        return card;
        //qDebug() << "TEEEST: " << card->getName().data() << "\n";
    }
    else if( typeOfCard == "Item" ) {
        card = new T();
        loadItem(element, card);
    }
    else if( typeOfCard == "Action" ) {
        card = new T();
        loadAction(element, card);
    }
}*/
