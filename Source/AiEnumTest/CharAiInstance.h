// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharAiInstance.generated.h"

/**
 * 
 */
UCLASS()
class AIENUMTEST_API UCharAiInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	virtual void NativeBeginPlay();
	virtual void NativeUpdateAnimation(float DeltaSeconds);
	class ACharAi* CharRef{ nullptr };

protected:
	UPROPERTY(BlueprintReadOnly,Category = "Movement")
	float SpeedForward;
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float SpeedRight;

	
};
