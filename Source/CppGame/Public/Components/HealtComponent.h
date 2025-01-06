// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealtComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDead);// Так создается,
//Event Dispatcher и его тип в скобках.

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPGAME_API UHealtComponent : public UActorComponent
{
	GENERATED_BODY()
public:		
	UHealtComponent();

	UPROPERTY(BluePrintReadWrite, BluePrintAssignable, BluePrintCallable)
	FDead DispatcherDead;
					
	float VolumeAddSound;

	void AddHealt(float Add);
	void Damage(float Damage);
	
	float GetHealt();
	bool  GetIsDead();

private:
	float Healt;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealt;

	bool bIsDead;


};
