// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn == nullptr)
		return;

	if(AIBehaviorTree != nullptr)
	{
		RunBehaviorTree(AIBehaviorTree);

		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}

	SetFocus(PlayerPawn);
}

void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// BT �ǽ�
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//if (PlayerPawn == nullptr)
	//	return;
	//if(LineOfSightTo(PlayerPawn))
	//{
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
	//}
	//else
	//{
	//	GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	//}

	// �׳� ���� AI�� ������ ���� �Լ� ���� Ʈ�� �̿��� ����
	//if(LineOfSightTo(PlayerPawn))
	//{
	//	SetFocus(PlayerPawn);
	//	MoveToActor(PlayerPawn, AcceptanceRadius);
	//}
	//else
	//{
	//	ClearFocus(EAIFocusPriority::Gameplay);
	//	StopMovement();
	//}

}