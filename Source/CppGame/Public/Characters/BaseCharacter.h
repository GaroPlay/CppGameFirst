// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/HealtComponent.h" 
#include "Interfaces/InfoCharacter.h"
#include "Interfaces/ActionsCharacter.h"
#include "BaseCharacter.generated.h"

UCLASS()
class CPPGAME_API ABaseCharacter : public ACharacter, public IInfoCharacter, public IActionsCharacter
{
	GENERATED_BODY()

public:
	
	ABaseCharacter();


	UFUNCTION(BlueprintNativeEvent)
	void OnEating();
	
	UFUNCTION(BlueprintNativeEvent)
	void OnEventDead();



	UFUNCTION(BlueprintNativeEvent)
	FText GetName(); // Предупреждение для интерфиейса это норма
	virtual FText GetName_Implementation() override;

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	float GetCountFoods();
	virtual float GetCountFoods_Implementation() override;

	UFUNCTION(BlueprintNativeEvent)
	float GetHealt();
	virtual float GetHealt_Implementation() override;

	UFUNCTION(BlueprintNativeEvent)
	bool IsDead();
	virtual bool IsDead_Implementation() override;



	UFUNCTION(BlueprintNativeEvent)
	void AddHealt(float AddedHealt);
	virtual void AddHealt_Implementation(float AddedHealt) override;

	UFUNCTION(BlueprintNativeEvent)
	void EatFood();
	virtual void EatFood_Implementation() override;


	float GetDamegePerSecond()const { return DamegePerSecond; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Settings",BlueprintReadOnly)
	int CountWinFoods; // ТУТ

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

	void PlayerPosses();
	FTimerHandle FallingTimer;


};
