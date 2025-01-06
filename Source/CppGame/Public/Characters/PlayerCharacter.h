// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CPPGAME_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	APlayerCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)		//������ ��������� ����� ������� �������� �������� � Details BluePrint.
	USpringArmComponent* CameraBoom;// ��� ����������� ������ ������� ���� SpringArm ��� ����� �����.
	
	UPROPERTY(VisibleAnywhere)//������ ��������� ����� ������� �������� �������� � Details BluePrint.
	UCameraComponent* FollowCamera; // ��� ����������� ������ ���� Camera ������ �����.

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	UAnimMontage* AnimMontageJump;						// ������ � ������� ������ ������ ����� ����,��� ��� � �� ���� ��� ��������� ����� �������� ������.

	void MoveFB(float ScaleValue);
	void MoveLR(float ScaleValue);
	void Jump();
	void StopJump();
	// ��� ������� � Header-�����. 
	void Move (EAxis::Type axis, float ScaleValue);
	
};
	