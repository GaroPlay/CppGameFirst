// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/HealtComponent.h" 
#include "BaseCharacter.generated.h"

UCLASS()
class CPPGAME_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	ABaseCharacter();

	FText GetName();

	float GetCountFoods();

	float GetHealt();

	bool IsDead();

	void AddHealt(float AddedHealt);

	void EatFood();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int CountFoods;
	float TimerRate;

	UPROPERTY(VisibleAnywhere)// Обезательно.
	UHealtComponent* HealtComponent;

	UPROPERTY(EditDefaultsOnly,Category="Settings",meta = (ClampMin = "0",ClampMax ="100"))
	float DamegePerSecond;

	UPROPERTY(EditDefaultsOnly,Category = "Settings")
	USoundBase* Sound; // Тип данных, знак(*) обезательно, уникальное имя.

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	 UAnimMontage* AnimMontageDeath;// Тип данных, знак(*) обезательно, уникальное имя.
	

	
	void Damage();

    UFUNCTION(BlueprintCallable)
	void OnDead();


};
