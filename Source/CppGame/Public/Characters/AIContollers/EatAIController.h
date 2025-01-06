// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <Kismet/KismetMathLibrary.h>
#include "EatAIController.generated.h"
/**
 * 
 */
UCLASS()
class CPPGAME_API AEatAIController : public AAIController
{
	GENERATED_BODY()



public:
	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
			// ������� ���� ��� ������ ������ Success - � Header-�����.
	
	UFUNCTION(BlueprintPure,BlueprintCallable, BlueprintNativeEvent)
	FVector  RandomPointGA();// ��� Dispatcher

protected:
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(Category = "Settings", BlueprintReadWrite, VisibleAnywhere)
	float MinPointPandomMinusX = - 1000;

	UPROPERTY(Category = "Settings", BlueprintReadWrite, VisibleAnywhere)
	float MaxPointPandomPlusX =    1000;

	UPROPERTY(Category = "Settings", BlueprintReadWrite, VisibleAnywhere)
	float MinPointPandomMinusY = -1000;

	UPROPERTY(Category = "Settings", BlueprintReadWrite, VisibleAnywhere)
	float MaxPointPandomPlusY = 1000;

private:
	APawn* PawnThis;
	AActor* NearestFood;
	bool IsMovingToRandomlocation = false;




	AActor* GetNearestFood();
	void CheckFood();
	void Eat();
	void StartEatWitchDelay();
	void MoveToRandom();

};
