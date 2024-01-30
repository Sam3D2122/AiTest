// Fill out your copyright notice in the Description page of Project Settings.

#include "CharAi.h"
#include "ControllerAi.h"
#include "AI/NavigationSystemBase.h"
#include "NavigationSystem.h"


// Sets default values


ACharAi::ACharAi()
{
}

// Called when the game starts or when spawned
void ACharAi::BeginPlay()
{
	Super::BeginPlay();

	ControllerRef = Cast<AControllerAi>(GetController());

	
		
	ChangeStateAi(EStateAi::Idle);

	
	
}

void ACharAi::ChangeStateAi(EStateAi NewState)
{
	CurrentState = NewState;

	switch (CurrentState)
	{
	case EStateAi::Walk: {

		if (!bIsMove) {
			
			UE_LOG(LogTemp, Error, TEXT("Nessuna richiesta di movimento"));
			SearchLocation();
			bIsMove = true;
			ControllerRef->MoveToLocation(LocToMove, 30);
			DrawDebugSphere(GetWorld(), LocToMove, 60, 32, FColor::Red,true);
		}
		
		else {
			UE_LOG(LogTemp, Error, TEXT("richiesta di movimento"));
			ControllerRef->ResumeMove(ControllerRef->GetCurrentMoveRequestID());
		}
	}

	break;
	
	
	case EStateAi::Idle: {

		if (ValStamina()) {

			ChangeStateAi(EStateAi::Walk);

		}
		else ChangeStateAi(EStateAi::Sleep);
	}
		
	break;



	}


}

bool ACharAi::ValStamina()
{



	if(CurrentState==EStateAi::Sleep || Stamina < 0){
		
		return false;
	}
	
	else {
		return true;
	}
}

void ACharAi::SearchLocation()
{

	if (bIsPath) {
		
		IndexLoc++;

		if (IndexLoc > ArrayLoc.Num() - 1) {

			IndexLoc = 0;
			LocToMove = ArrayLoc[IndexLoc];
			return;

		}

		LocToMove=ArrayLoc[IndexLoc];

		UE_LOG(LogTemp, Warning, TEXT("Direzione Path"));
	}

	else
	{
		FNavLocation Temp;
		UNavigationSystemV1::GetNavigationSystem(GetWorld())->GetRandomReachablePointInRadius(GetActorLocation(), MaxRadiusDist, Temp);
		LocToMove = Temp.Location;

		UE_LOG(LogTemp, Warning, TEXT("Direzione Autonoma"));
	}
		
		

}





