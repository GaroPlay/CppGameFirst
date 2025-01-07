// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Food.generated.h"

UCLASS()
class CPPGAME_API AFood : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFood();

	float GetAddedHealth()const;

	




private: // В Header-файле.
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY (EditDefaultsOnly,Category = "Settings")
	float AddedHealth;

	UFUNCTION (BlueprintCallable) // Этот макрос обезателен (Это Header)
	void OnPickup(UPrimitiveComponent * OverLappedComponent, AActor * OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyUndex, bool bFromSweep, const FHitResult & SweepResult);
	
	
};
