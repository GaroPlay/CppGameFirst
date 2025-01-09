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

	CountWinFoods = 25;
}

void ABaseCharacter::OnEating_Implementation()
{

}


  
FText ABaseCharacter::GetName_Implementation()
{
	return FText::FromString( UKismetSystemLibrary::GetDisplayName(this));
}

float ABaseCharacter::GetCountFoods_Implementation()
{
	return  CountFoods;
}

float ABaseCharacter::GetHealt_Implementation()
{
	if (HealtComponent != nullptr) 
	{
		return HealtComponent->GetHealt();
	}
	return 0.0f;
}

bool ABaseCharacter::IsDead_Implementation()
{
	if (HealtComponent != nullptr) 
	{
		return HealtComponent->GetIsDead();
	}
	return 0;
}

void ABaseCharacter::OnEventDead_Implementation()
{

}



void ABaseCharacter::AddHealt_Implementation(float AddedHealt)
{
	
	if (HealtComponent != nullptr)
	{
		HealtComponent->AddHealt(AddedHealt);
	}

}

void ABaseCharacter::EatFood_Implementation()
{
	CountFoods++;

		if (IsValid(Sound))
		{
			if (HealtComponent->GetHealt() + HealtComponent->VolumeAddSound > 100)
			{
			UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation(), 0.0); // Тут Меняем громкость !!!
			}
			else  
			{
				UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation(), 0.1); // Тут Меняем громкость !!!
			}			
		}
		OnEating( );
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
		if (HealtComponent->GetHealt() <= 0) 
		{
			OnEventDead();
		}
	}
	//  Снизу дебаг не забыть убрать !!!
	// GEngine->AddOnScreenDebugMessage(-1, 0.1, FColor::Red, FString::FromInt(GetHealt()));// не забыть удалить это Print String	

}
void ABaseCharacter::OnDead()
{
	if (AnimMontageDeath != nullptr) 
	{
		PlayAnimMontage(AnimMontageDeath);	
	} 	
	
	GetWorldTimerManager().SetTimer(ABaseCharacter::FallingTimer, this, &ABaseCharacter::PlayerPosses, 0.1f, true, 0.0);	
}
void ABaseCharacter::PlayerPosses()
{
		
	if (!GetCharacterMovement()->IsFalling())
	{
		UnPossessed();
		GetMesh()->SetSimulatePhysics(true);
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetWorldTimerManager().ClearTimer(FallingTimer);
	}
}







