// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealtComponent.h"

UHealtComponent::UHealtComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsDead = false;
	MaxHealt = 100;
	Healt = MaxHealt;


}

void UHealtComponent::AddHealt(float Add) 
{
	float Temp = Healt + Add;
	Healt = FMath::Min(Temp, MaxHealt);
}
void UHealtComponent::Damage(float Damage) {
	float Temp = Healt - Damage;
	Healt = FMath::Max(Temp, 0);
	if (Healt <= 0 && !bIsDead) {

		bIsDead = true;
		DispatcherDead.Broadcast();// ��� ���������� ����� Delegate, ������� �������� ���� ��� ��������,
		//DispatcherDead- ���������� ��� Delegate,Broadcast ������� ������� � BluePrint ���������� Call.
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


