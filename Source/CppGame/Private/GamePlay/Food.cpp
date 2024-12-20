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
	RootComponent = Mesh; // Cpp-файл конструктор.

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AFood::OnPickup);// Создали и активировали,
												  //Dispatcher который отслеживает пересечение.
}

void AFood::OnPickup(UPrimitiveComponent* OverLappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyUndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ABaseCharacter* Character = Cast < ABaseCharacter>(OtherActor);// Получяем доступ или сылку на того Character,
	//который сопрекаснулся с данным объектом, для полуыения доступа к функциям которые у Character и тут не видны.
	Character->EatFood();// Использую функцию которая есть у всех ABaseCharacter но из другого класса.
	Character->AddHealt(AddedHealth);// Использую функцию которая есть у всех ABaseCharacter но из другого класса.
	Destroy();// Уничтожае данного Actor на сцене после отрабоки его логики.
}

