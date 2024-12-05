// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"

APlayerCharacter::APlayerCharacter():Super()
{

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	CameraBoom->TargetArmLength = 450.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject< UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveFB", this, &APlayerCharacter::MoveFB);
	PlayerInputComponent->BindAxis("MoveLR", this, &APlayerCharacter::MoveLR);
	PlayerInputComponent->BindAxis("LookLR",this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUD", this, &APawn::AddControllerPitchInput);


}

void APlayerCharacter::MoveFB(float ScaleValue)
{	
	Move(EAxis::X, ScaleValue);
}

void APlayerCharacter::MoveLR(float ScaleValue)
{
	
	
	Move(EAxis::Y, ScaleValue);
}

void APlayerCharacter::Move (EAxis::Type axis,float ScaleValue)
{
	if ((Controller != NULL) && (ScaleValue != 0))
	{
		FRotator Rotator = Controller->GetControlRotation();
		FRotator YawRotation(0, Rotator.Yaw, 0);
		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(axis);
		AddMovementInput(Direction, ScaleValue);

	}

}


