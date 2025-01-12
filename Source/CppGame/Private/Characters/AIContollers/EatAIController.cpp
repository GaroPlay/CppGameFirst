// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AIContollers/EatAIController.h"
#include "Navigation/PathFollowingComponent.h"// Это обезательно для MoveTo.
#include "Kismet/GameplayStatics.h" // Это обезательно для GetAllActorsOfClass.
#include "GamePlay/Food.h"// Подключаем класс A Food в этот класс.
#include "UObject/UObjectGlobals.h" // Это для Is Valid.
#include "Characters/BaseCharacter.h"
#include "Interfaces/InfoCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"




void AEatAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);// Вызываем родительскую реализацию.
	Eat();
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEatAIController::CheckFood, 0.5, true, 0);
}


void AEatAIController::CheckFood() 
{
	
	AActor* NewNearestFood = GetNearestFood();

	if (!IsValid(NewNearestFood)) 
	{
		MoveToRandom();
		return;
	}
	else 
	{
		IsMovingToRandomlocation = false;
	}
	
		NearestFood = NewNearestFood;
		FAIMoveRequest MoveRequest(NewNearestFood);
		MoveRequest.SetAcceptanceRadius(5);
		MoveTo(MoveRequest);
}

FVector AEatAIController::RandomPointGA_Implementation()
{
	return FVector(

		FMath::FRandRange(MinPointPandomMinusX, MaxPointPandomPlusX), // Используйте FRandRange для float
		FMath::FRandRange(MinPointPandomMinusY, MaxPointPandomPlusY),
		0.0f
	);
}

void AEatAIController::MoveToRandom()
{

	if (IsMovingToRandomlocation) return;
	IsMovingToRandomlocation = true;

	//DrawDebugSphere(GetWorld(), RandomPointGA(), 50, 8, FColor::Green, false, 10, 0, 2);
	FAIMoveRequest MoveRequest(RandomPointGA());

	MoveRequest.SetAcceptanceRadius(50);
	
	StopMovement();
	MoveTo(MoveRequest);

}


void AEatAIController::Eat()
{
	if (!IsValid(NearestFood)) 
	{
		StartEatWitchDelay();
		return;
	}	
	 
	 FAIMoveRequest MoveRequest (NearestFood); // На эту строчку выдало краш 
	 MoveRequest.SetAcceptanceRadius(20);

	 MoveTo(MoveRequest);
	// GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, FString::Printf(TEXT("MoveTo")));
}

void AEatAIController::StartEatWitchDelay()
{
	FTimerHandle TimerHandleEat;
	GetWorldTimerManager().SetTimer(TimerHandleEat, this, &AEatAIController::Eat, 0.1, false, 0);
	//GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Green, FString::Printf(TEXT("StartEatWitchDelay")));
}

void AEatAIController::OnMoveCompleted (FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Blue, FString::Printf(TEXT("OnMoveCompleted")));
	
	StartEatWitchDelay();
	IsMovingToRandomlocation = false;

}

AActor* AEatAIController::GetNearestFood()
{
	TArray <AActor*> OutActors;// Объевляем динамически массив указателей типа AActor в который,
							  // в который будем записывать всю найденую еду.

	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, FString::Printf(TEXT("Number of actors: %d"), OutActors.Num()));

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFood::StaticClass(), OutActors); 

	if (OutActors.IsEmpty()) return nullptr; // Глянуть такую запись
		
		
	

	TArray <AFood*> NearesFoodsArray;
	for (int32 i = OutActors.Num() - 1; i >= 0; --i) // Цикл в обратном порядке!
	{
		AFood* FoodActor = Cast<AFood>(OutActors[i]); // Это cast

		if (FoodActor)
		{
			if (FoodActor->GetDistanceTo(GetPawn()) < 1300.0f) // Тестим 
			{
				NearesFoodsArray.Add(FoodActor);
			}
		}	
	}
	
	if (NearesFoodsArray.IsEmpty()) return nullptr;


	APawn* MainActor = GetPawn();
	ABaseCharacter* CharacterHealt = Cast <ABaseCharacter>(GetPawn());// Это каст

	
	if (!IsValid(CharacterHealt)) return nullptr;

	NearesFoodsArray.Sort([CharacterHealt](const AFood & A, const AFood& B)
	{
		auto GetFoodCost = [CharacterHealt](const AFood & InFood)->float 
		{
			const float HealtThis = IInfoCharacter::Execute_GetHealt(CharacterHealt);
		const float DistanceTo = FVector::Dist2D(CharacterHealt->GetActorLocation(), InFood.GetActorLocation());

		const float Cost = (HealtThis - ((DistanceTo / CharacterHealt->GetMovementComponent()->GetMaxSpeed())) * CharacterHealt->GetDamegePerSecond());
		return  InFood.GetAddedHealth() + Cost;
		};
			
		return GetFoodCost(A) > GetFoodCost(B);
	});
	return NearesFoodsArray[0];
}
