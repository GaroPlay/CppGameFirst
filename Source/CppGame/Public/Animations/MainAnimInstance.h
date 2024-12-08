// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class CPPGAME_API UMainAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	 virtual void NativeInitializeAnimation() override;// Это Begin Play
	 // Event BluePrint Initialize Animation - так эта функция называется в движке.
	 virtual void NativeUpdateAnimation(float DeltaSeconds)override;//Это Event Tic
	 // Event BluePrint Update Animation - так эта функция называется в движке.
	 
protected:
	 APawn* Pawn;

	 UPROPERTY(EditDefaultOnly,BlueprintReadOnly)
	 float Speed;
};
