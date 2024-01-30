// Fill out your copyright notice in the Description page of Project Settings.


#include "CharAiInstance.h"
#include "CharAi.h"

void UCharAiInstance::NativeBeginPlay()
{

	Super::NativeBeginPlay();

	CharRef = Cast<ACharAi>(TryGetPawnOwner());

}

void UCharAiInstance::NativeUpdateAnimation(float DeltaSeconds)
{

	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!CharRef) return;


	SpeedForward = CharRef->GetVelocity().Length();


}


