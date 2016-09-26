// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "Gamer.h"


// Sets default values
AGamer::AGamer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create our components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 51.0f), FRotator(-90.0f, 0.0f, 0.0f));
	OurCameraSpringArm->TargetArmLength = 200.f;
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 3.0f;

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);

	//Take control of the default Player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Init variables
	currentClickedTarget = nullptr;
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

	if(currentClickedTarget != nullptr)
	{
		APlayerController* PlayerController = Cast<APlayerController>(GetController());

		if (PlayerController != nullptr)
		{
			FVector mouseLocation, mouseDirection, currentLocation, newLocation;
			// Retrieve worldcoordinates from mouseposition
			PlayerController->DeprojectMousePositionToWorld(mouseLocation, mouseDirection);

			// Set current Location of actor
			currentLocation = currentClickedTarget->GetActorLocation();
			//newLocation = FVector(currentLocation.X + mouseDirection.X*3, currentLocation.Y + mouseDirection.Y*3, currentLocation.Z);

			FVector Orgin;
      FVector BoundsExtent;
			// Retrieve the bounding box of the actor to get the current origin
      currentClickedTarget->GetActorBounds(true, Orgin, BoundsExtent);

			// Calculate the new location.. lerp from a to b
			FVector C = FMath::Lerp(mouseDirection*200+mouseLocation, Orgin, 0.5f);

			// Z wont change
			C.Z = currentLocation.Z;

			// Set new locatiob
			currentClickedTarget->SetActorLocation(C);
		}
	}
}

// Called to bind functionality to input
void AGamer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	//Hook up events for "Click"
	InputComponent->BindAction("Click", IE_Pressed, this, &AGamer::click);
}

void AGamer::click()
{
	// If currentClickedTarget != nullptr then reset it.
	if(currentClickedTarget != nullptr)
	{
		currentClickedTarget = nullptr;
		return;
	}


	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController != nullptr)
	{
			FHitResult TraceResult(ForceInit);
			PlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, TraceResult);
			FString TraceString;

			if (TraceResult.GetActor() != nullptr)
			{
					//TraceString += FString::Printf(TEXT("Trace Actor %s."), *TraceResult.GetActor()->GetName());
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Actor clicked: %s"), *TraceResult.GetActor()->GetName()));
					currentClickedTarget = TraceResult.GetActor();
			}

			if (TraceResult.GetComponent() != nullptr)
			{
					//TraceString += FString::Printf(TEXT("Trace Comp %s."), *TraceResult.GetComponent()->GetName());
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Component clicked: %s"), *TraceResult.GetComponent()->GetName()));
			}

			//TheHud->TraceResultText = TraceString;
	}


}
