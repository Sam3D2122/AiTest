// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerAi.h"
#include "CharAi.h"


void AControllerAi::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	// al momento della possessione 
	// memorizzo il pawn come puntatore ad APork
	CharRef = Cast<ACharAi>(InPawn);
}

void AControllerAi::Tick(float DeltaSeconds)
{

	Super::Tick(DeltaSeconds);



	if (CharRef->CurrentState != EStateAi::Idle) {

		switch (CharRef->CurrentState)
		{
		case EStateAi::Walk: {

			CharRef->Stamina -= 10 * DeltaSeconds;

			if (!CharRef->ValStamina()) {

				CharRef->ChangeStateAi(EStateAi::Sleep);

				PauseMove(GetCurrentMoveRequestID());

			}
		}


		break;

		case EStateAi::Sleep: {

				CharRef->Stamina += 10 * DeltaSeconds;

				if (CharRef->Stamina > CharRef->MaxStamina) {

					CharRef->Stamina = CharRef->MaxStamina;

					CharRef->ChangeStateAi(EStateAi::Walk);

				}

			}

		break;

		}

	}


}

void AControllerAi::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{

	Super::OnMoveCompleted(RequestID,Result);

	UE_LOG(LogTemp, Error, TEXT("Movimento Finito"));

	CharRef->bIsMove = false;
	CharRef->ChangeStateAi(EStateAi::Idle);

	

}
