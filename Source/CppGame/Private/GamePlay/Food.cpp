// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/Food.h"
#include <Characters/BaseCharacter.h>

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

void AFood::OnPickup(UPrimitiveComponent* OverLappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyUndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ABaseCharacter* Character = Cast < ABaseCharacter>(OtherActor);// �������� ������ ��� ����� �� ���� Character,
	//������� ������������� � ������ ��������, ��� ��������� ������� � �������� ������� � Character � ��� �� �����.
	Character->EatFood();// ��������� ������� ������� ���� � ���� ABaseCharacter �� �� ������� ������.
	Character->AddHealt(AddedHealth);// ��������� ������� ������� ���� � ���� ABaseCharacter �� �� ������� ������.
	Destroy();// ��������� ������� Actor �� ����� ����� �������� ��� ������.
}
