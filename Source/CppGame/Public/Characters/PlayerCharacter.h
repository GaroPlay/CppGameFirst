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
	UPROPERTY(VisibleAnywhere)		//Делаем настройки этого объекта полность видемыми в Details BluePrint.
	USpringArmComponent* CameraBoom;// Так объявляется объект который типа SpringArm или селфи палка.
	
	UPROPERTY(VisibleAnywhere)//Делаем настройки этого объекта полность видемыми в Details BluePrint.
	UCameraComponent* FollowCamera; // Так объявляется объект типа Camera синего цвета.

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	UAnimMontage* AnimMontageJump;						// Монтаж с прышком хранит каждая пешка сама,так как я не знаю кто конкретно имеет анимацию прыжка.

	void MoveFB(float ScaleValue);
	void MoveLR(float ScaleValue);
	void Jump();
	void StopJump();
	// Эта функция в Header-файле. 
	void Move (EAxis::Type axis, float ScaleValue);
	
};
	