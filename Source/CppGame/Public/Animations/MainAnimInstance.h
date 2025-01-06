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
	 virtual void NativeInitializeAnimation() override;// ��� Begin Play
	 // Event BluePrint Initialize Animation - ��� ��� ������� ���������� � ������.
	 virtual void NativeUpdateAnimation(float DeltaSeconds)override;//��� Event Tic
	 // Event BluePrint Update Animation - ��� ��� ������� ���������� � ������.
	 
protected:
	// ����������� BluePrin ����� ����� � ������� ����������� � ��� ����� ������ �����,
	 APawn* Pawn;// �� ����������� �������� � Character ����� Pawn.

	 UPROPERTY(EditDefaultsOnly,BlueprintReadOnly) // ��� ��� GameDisagner.
	 float Speed;// ��� ��������� ��� ��� Horizantal � BlendSpace.


};
