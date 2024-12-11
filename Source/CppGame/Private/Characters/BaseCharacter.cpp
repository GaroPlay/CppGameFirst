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

	HealtComponent = CreateDefaultSubobject< UHealtComponent > (TEXT("HealtComponent"));

	HealtComponent->DispatcherDead.AddDynamic ( this, &ABaseCharacter::OnDead);
	// HealtComponent - Это тот клас в котором создан Event Dispatcher.
	//->DispatcherDead - Это имя самого Event Dispatcher.
	//.AddDynamic -Это синтаксис (компилятор не подскажет сука).
	// this - Это указатель на объект который обработает полученый вызов обычно тут this.
	// &ABaseCharacter::OnDead - Это указатель на функцию которая произойдет когда получен вызов.
	// Это Сpp-фаил.
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
	if (HealtComponent != nullptr) 
	{
		return HealtComponent->GetHealt();
	}
	return 0.0f;
}

bool ABaseCharacter::IsDead()
{
	if (HealtComponent != nullptr) 
	{
		return HealtComponent->GetIsDead();
	}
	return 0;
}

void ABaseCharacter::AddHealt(float AddedHealt)
{
	if (HealtComponent != nullptr)
	{
		HealtComponent->AddHealt(AddedHealt);
	}
}

void ABaseCharacter::EatFood()
{
	CountFoods++;

	if (Sound != nullptr) 
	{
	  UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());
	} 
}

// Called when the game starts or when spawned

void ABaseCharacter::BeginPlay() {
	Super::BeginPlay();

	FTimerHandle DamageTimer;// Тут создаем переменую типа таймер она нужна чтобы хранить таймер.
	GetWorldTimerManager().SetTimer(DamageTimer,this, &ABaseCharacter::Damage, TimerRate,true,0.0);
}

void ABaseCharacter::Damage()
{
	if (HealtComponent != nullptr)
	{
		HealtComponent->Damage(TimerRate * DamegePerSecond);
	}
	//  Снизу дебаг не забыть убрать !!!
	 GEngine->AddOnScreenDebugMessage(-1, 0.1, FColor::Red, FString::FromInt(GetHealt()));// не забыть удалить это Print String
	
}

void ABaseCharacter::OnDead()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.1, FColor::Green, TEXT("DeatPlayer"));// не забыть удалить это Print String

	if (AnimMontageDeath != nullptr) 
	{
		PlayAnimMontage(AnimMontageDeath);
	} 	
	

	UnPossessed();
	
	GetMesh()->SetSimulatePhysics(true);

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);


}





