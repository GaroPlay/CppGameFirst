// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/Spawner.h"
#include "Kismet/KismetMathLibrary.h" // ��� ���������� ����������� ���, 
									 // ������� (Random Point In Bounding Box)
ASpawner::ASpawner() // ��������� �����������.
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// ������������� �������� �� ��������� � ����� //	
	 bIsOnse = false; // �������  ����������.
	 SpawnPerTime = 5;// ���������� Actor ������� �����������.

	 Box = CreateDefaultSubobject <UBoxComponent> (TEXT("BoxCollision"));// ������� �,
										   // ��������� � ���� ��������� BoxCollision.
	 Box->SetCollisionProfileName(TEXT("NoCollision"));// ��� ����� BoxCollision � ���,
								  // ����� �� ��� ����������� � ����� �� ����� �� ����.	
	 RootComponent = Box; 
}
void ASpawner::BeginPlay()// ��������� BeginPlay.
{
	Super::BeginPlay();// �������� ������������ ���������� ������.
	FTimerHandle TimerHadle;// ��������� ������ � ����� ���������.
	GetWorldTimerManager().SetTimer(TimerHadle, this, &ASpawner::Spawn, 1, !bIsOnse, 0);
}
void ASpawner::Spawn()//���� ���� �������� SpawnActor �������� GameDisagner ���������� ���.
{
	for (int i = 0; i < SpawnPerTime; i++) // ���� �� ���������� ���������.
	{
		FRotator Rotation (0, 0, 0);// ��� ������� ��� �������� ������� �� �������.
		FVector Location= UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), Box->GetScaledBoxExtent());
		// � ����� ��� ��������� ���� ���������� Actor ���������� � ����� ������ BoxCollision.
		// ��� ������� ������ ������ ���� Random Point in Bounding Box.
		GetWorld()->SpawnActor <AActor>(SpawnClass, Location, Rotation);//��� ������� ������ ����������,
		// ���� (Spawn Actor from Class)  
		// <AActor> - ��� ���� ������� ��� ������ ������� ������� ����� ����������,
		// SpawnClass - ���� �������� ������ ������� ����� �������� ����� ����� �� Header-����� ������ ����� �������.
		// GetWorld()->SpawnActor - ��� ���������.
	}
}



