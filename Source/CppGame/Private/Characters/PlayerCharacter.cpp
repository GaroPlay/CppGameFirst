// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"


APlayerCharacter::APlayerCharacter():Super()
{

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom")); // ������� � �������� � ���� ������.
	FollowCamera = CreateDefaultSubobject< UCameraComponent>(TEXT("FollowCamera"));// ������� � �������� � ���� ������.
	
	CameraBoom->SetupAttachment(RootComponent);// ������ ����� ����� � Root � ���������.
	FollowCamera->SetupAttachment(CameraBoom);// ������ ������ � ����� �����.


	
	CameraBoom->TargetArmLength = 450.0f;// ���� �������� ��������� ����� ����� �� BluePrint � ��������� � �++.
	CameraBoom->bUsePawnControlRotation = true;// ������ ��������� �� BluePrint ����� ������������ ���.
	FollowCamera->bUsePawnControlRotation = false;

	OurCharacterMovementComponent = GetCharacterMovement(); // �������� ��������� ��������


}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);	
	PlayerInputComponent->BindAxis("MoveFB", this, &APlayerCharacter::MoveFB);// ��� ���������� ���������� Input,
	PlayerInputComponent->BindAxis("MoveLR", this, &APlayerCharacter::MoveLR);// �� ������ � ������� �� �++,
																			 //������� ��������� ��������.
	PlayerInputComponent->BindAxis("LookLR",this,&APawn::AddControllerYawInput);// ���� ����� �� �����.
	PlayerInputComponent->BindAxis("LookUD", this, &APawn::AddControllerPitchInput);//���� ����� �� �����.

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);// ��� �������� �� �������,
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump);// ������� ������ �������,
													// � ������� ����������� ��������� � ���������� ���������� �������.
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




