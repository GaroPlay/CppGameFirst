// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealtComponent.h"

UHealtComponent::UHealtComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsDead = false;
	MaxHealt = 100;
	Healt = MaxHealt;

	 VolumeAddSound = 0;

}

void UHealtComponent::AddHealt(float Add) 
{
	VolumeAddSound = Add;
	float Temp = Healt + Add;
	Healt = FMath::Min(Temp, MaxHealt);
}

void UHealtComponent::Damage(float Damage) {
	float Temp = Healt - Damage;
	Healt = FMath::Max(Temp, 0.0f);
	if (Healt <= 0 && !bIsDead) {

		bIsDead = true;
		DispatcherDead.Broadcast();// Так происходит вызов Delegate, который уведомит всех кто подписан,
		//DispatcherDead- уникальное имя Delegate,Broadcast фукнция которая в BluePrint называется Call.
	}
}

float UHealtComponent::GetHealt()
{
	return Healt;
}

bool UHealtComponent::GetIsDead()
{
	return bIsDead;
}



