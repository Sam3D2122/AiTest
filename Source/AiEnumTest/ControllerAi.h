// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ControllerAi.generated.h"

/**
 * 
 */
UCLASS()
class AIENUMTEST_API AControllerAi : public AAIController
{
	GENERATED_BODY()



	void OnPossess(APawn* InPawn);

	virtual void Tick(float DeltaSeconds);

	class ACharAi* CharRef{ nullptr };

	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result);





	
};
