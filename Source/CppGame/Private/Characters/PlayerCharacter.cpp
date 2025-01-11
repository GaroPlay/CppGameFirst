// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"


APlayerCharacter::APlayerCharacter():Super()
{

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom")); // Создаем и присваем в поле объект.
	FollowCamera = CreateDefaultSubobject< UCameraComponent>(TEXT("FollowCamera"));// Создаем и присваем в поле объект.
	
	CameraBoom->SetupAttachment(RootComponent);// Крепим селфи палку к Root у персонажа.
	FollowCamera->SetupAttachment(CameraBoom);// Крепим камеру к селфи палке.


	
	CameraBoom->TargetArmLength = 450.0f;// Беру название параметра селфи палки из BluePrint и использую в с++.
	CameraBoom->bUsePawnControlRotation = true;// Многие параметры из BluePrint можно использовать тут.
	FollowCamera->bUsePawnControlRotation = false;

	OurCharacterMovementComponent = GetCharacterMovement(); // Получаем компонент движения


}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);	
	PlayerInputComponent->BindAxis("MoveFB", this, &APlayerCharacter::MoveFB);// Тут производим связывание Input,
	PlayerInputComponent->BindAxis("MoveLR", this, &APlayerCharacter::MoveLR);// из движка и функции из с++,
																			 //которая выполняет действие.
	PlayerInputComponent->BindAxis("LookLR",this,&APawn::AddControllerYawInput);// Тоже самое на мышку.
	PlayerInputComponent->BindAxis("LookUD", this, &APawn::AddControllerPitchInput);//Тоже самое на мышку.

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);// Тут действие по нажатию,
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump);// поэтому другая функция,
													// с больщим количеством арументов и обработкай отпускания клавищи.
}

void APlayerCharacter::Jump()	  {
	bPressedJump = true;
	//GEngine->AddOnScreenDebugMessage(-1, 0.5, FColor::Red,TEXT(" bPressedJump "));


	bool IsCharacterFalling = OurCharacterMovementComponent->IsFalling();
	if (IsCharacterFalling) return;

	if (AnimMontageJump != nullptr) {
		PlayAnimMontage(AnimMontageJump);
	}

}

void APlayerCharacter::StopJump() {
	bPressedJump = false;
}

void APlayerCharacter::MoveFB(float ScaleValue) {	
	Move(EAxis::X, ScaleValue);

}
void APlayerCharacter::MoveLR(float ScaleValue) {
	Move(EAxis::Y, ScaleValue);
}
void APlayerCharacter::Move (EAxis::Type axis,float ScaleValue) {
	if ((Controller != NULL) && (ScaleValue != 0))
	{
		FRotator Rotator = Controller->GetControlRotation();
		FRotator YawRotation(0, Rotator.Yaw, 0);
		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(axis);
		AddMovementInput(Direction, ScaleValue);
	}
}




