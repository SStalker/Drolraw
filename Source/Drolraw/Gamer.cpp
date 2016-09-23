// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "Gamer.h"


// Sets default values
AGamer::AGamer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGamer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGamer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AGamer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

