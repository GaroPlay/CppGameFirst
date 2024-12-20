// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include <Kismet/GameplayStatics.h>

ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; // ��� ���������� �������� ��� �������� ��������� � ��� ���.

	DamegePerSecond = 5;
	CountFoods = 0;
	TimerRate = 0.1;
	GetMesh()->SetCollisionProfileName ("SkeletalMesh");
	GetCharacterMovement()->bOrientRotationToMovement = true;	
}

FText ABaseCharacter::GetName()
{
	return FText::FromString( UKismetSystemLibrary::GetDisplayName(this));
}

float ABaseCharacter::GetCountFoods()// � ���� ������� ���� �������� float �� int
{
	return  CountFoods;
}

float ABaseCharacter::GetHealt()
{
	return 0.0f;
}

bool ABaseCharacter::IsDead()
{
	return false;
}

void ABaseCharacter::AddHealt(float AddedHealt)
{

}

void ABaseCharacter::EatFood()
{
	CountFoods++;
	UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle DamageTimer;// ��� ������� ��������� ���� ������ ��� ����� ����� ������� ������.
	GetWorldTimerManager().SetTimer(DamageTimer,this, &ABaseCharacter::Damage, TimerRate,true,0.1);// ��� � ����� ��� ��� ����,
																								 //������ �� ���� �� ���������.
	
}

void ABaseCharacter::Damage()
{
	 
}

void ABaseCharacter::Dead()
{
	if(AnimMontageDeath!= nullptr) PlayAnimMontage(AnimMontageDeath);// ��� ����� ���� � character,
		  //� ��� ������ ���� ������ ��������� ������� ��������� �� ����������� ������������������.
		 // ���� ����� �� ���� Play Anim Montage.
	UnPossessed();// ���� ����� ����� ��������� ������ ���������� ��� ������.
	GetMesh()->SetSimulatePhysics(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}





