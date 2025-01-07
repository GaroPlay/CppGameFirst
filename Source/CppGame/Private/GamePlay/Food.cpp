// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/Food.h"

#include "Interfaces/ActionsCharacter.h"


// Sets default values
AFood::AFood()
{
	PrimaryActorTick.bCanEverTick = false;
	AddedHealth = 5;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionProfileName(TEXT("Food"));
	RootComponent = Mesh; // Cpp-���� �����������.

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AFood::OnPickup);// ������� � ������������,
												  //Dispatcher ������� ����������� �����������.

}

float AFood::GetAddedHealth() const // ��� ���� �������� 
{
	return AddedHealth;
}



void AFood::OnPickup(UPrimitiveComponent* OverLappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyUndex, bool bFromSweep, const FHitResult & SweepResult)
{
	IActionsCharacter::Execute_EatFood (OtherActor);
	IActionsCharacter::Execute_AddHealt(OtherActor,AddedHealth);
	Destroy();
}





