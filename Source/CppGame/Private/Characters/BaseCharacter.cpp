// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include <Kismet/GameplayStatics.h>

ABaseCharacter::ABaseCharacter() : Super()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; // тут конструктр включает при создание персонажа в нем тик.

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

float ABaseCharacter::GetCountFoods()// у этой функции надо помяньть float на int
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

	if(Sound != nullptr) UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle DamageTimer;// Тут создаем переменую типа таймер она нужна чтобы хранить таймер.
	GetWorldTimerManager().SetTimer(DamageTimer,this, &ABaseCharacter::Damage, TimerRate,true,0.1);// Тут я думаю что при нуле,
																								 //таймер не разу не сработает.
	
}

void ABaseCharacter::Damage()
{
	 
}

void ABaseCharacter::Dead()
{
	if(AnimMontageDeath!= nullptr) PlayAnimMontage(AnimMontageDeath);// Это метод есть у character,
		  //и ему просто надо подать переменую которая указывает на анимационую последовательность.
		 // есть такая же нода Play Anim Montage.
	UnPossessed();// Этот метод лещит контролер игрока упровления над пешкой.
	GetMesh()->SetSimulatePhysics(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}





