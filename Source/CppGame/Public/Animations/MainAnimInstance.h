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
	// Анимационый BluePrin знает пешку к которой принадлежит и это часто бывает нужно,
	 APawn* Pawn;// но анимационый общается с Character через Pawn.

	 UPROPERTY(EditDefaultsOnly,BlueprintReadOnly) // Это для GameDisagner.
	 float Speed;// Это переменая для оси Horizantal в BlendSpace.


};
