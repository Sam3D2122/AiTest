// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharAi.generated.h"



UENUM(BlueprintType)
enum class EStateAi : uint8 {
	Walk = 0 UMETA(DisplayName = "Walk"),
	Idle = 1  UMETA(DisplayName = "Idle"),
	Work = 2     UMETA(DisplayName = "Work"),
	Sleep = 3	UMETA(DisplayName = "Sleep")

};

UCLASS()
class AIENUMTEST_API ACharAi : public ACharacter
{
	GENERATED_BODY()


	


protected:

	UPROPERTY(EditAnyWhere, Category = "Movement");
	TArray <FVector> ArrayLoc;

	int IndexLoc = 0;

	class AControllerAi* ControllerRef;

   UPROPERTY(EditAnyWhere,Category="Movement")
   float MaxRadiusDist{ 1000.f };

public:

	// Sets default values for this character's properties
	ACharAi();


	bool bIsMove = false;

	float MaxStamina{ FMath::FRandRange(100.f,500.f) };

	float Stamina{ MaxStamina };

	UPROPERTY(EditAnywhere)
	EStateAi CurrentState{ EStateAi::Idle };

	UPROPERTY(EditAnywhere)
	bool bIsPath = false;

	FVector LocToMove;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	void ChangeStateAi(EStateAi NewState);

	bool ValStamina();
	
	void SearchLocation();

	
};
