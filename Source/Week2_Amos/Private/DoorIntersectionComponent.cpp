// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorIntersectionComponent.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Engine/TriggerBox.h"



// Sets default values for this component's properties
UDoorIntersectionComponent::UDoorIntersectionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorIntersectionComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentRotateTime = 0.0f;
	XDesireRotator  = FRotator (0.0f,-90.0f,0.0f);

	 StartRotation = GetOwner()->GetActorRotation();
	 FinalRotation = GetOwner()->GetActorRotation() + XDesireRotator;
	//DeltaRotator = XDesireRotator - GetOwner()->GetActorRotation();
	//FinalRotator = GetOwner()->GetActorRotation() + XDesireRotator;



	// ...
	
}


// Called every frame
void UDoorIntersectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// to create a frame rate independent 
	// ...
    

	

   if (Triggerbox && GetWorld()->GetFirstLocalPlayerFromController()) {


	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PlayerPawn && Triggerbox->IsOverlappingActor(PlayerPawn)) {
	    if (CurrentRotateTime < TimeToRotate)
	    {
		 CurrentRotateTime +=DeltaTime; // addng deltatime to currentRotateTime
	    	float RolateAlpha =  FMath::Clamp(CurrentRotateTime/TimeToRotate,0.0f,1.0f);
		  FRotator CurrentRotatoation = FMath::Lerp (StartRotation,FinalRotation,RolateAlpha); 
	     //CurrentRotatoation += DeltaRotator * DeltaTime;
	      GetOwner()->SetActorRotation(CurrentRotatoation);
	  
	    }
	}


   }
}

