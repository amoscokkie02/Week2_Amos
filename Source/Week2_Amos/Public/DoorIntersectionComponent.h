// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "DoorIntersectionComponent.generated.h"



class ATriggerBox;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEEK2_AMOS_API UDoorIntersectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorIntersectionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

  UPROPERTY (EditAnyWhere)
  FRotator XDesireRotator = FRotator::ZeroRotator;

  FRotator StartRotation = FRotator::ZeroRotator;
  FRotator FinalRotation = FRotator::ZeroRotator;

  UPROPERTY (EditAnyWhere)
  float TimeToRotate = 1.0f;
  float CurrentRotateTime = 0.0f;
  
 UPROPERTY (EditAnyWhere)
 ATriggerBox* Triggerbox;


 UPROPERTY (EditAnyWhere)
 FRuntimeFloatCurve  FloatCurve ;

};
