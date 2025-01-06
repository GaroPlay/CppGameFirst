// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"// ��� ��� Box Colision �� BluePrint.
#include "Spawner.generated.h"

UCLASS()
class CPPGAME_API ASpawner : public AActor
{
	GENERATED_BODY()
public:	
	ASpawner();// �����������.
protected:
	virtual void BeginPlay() override;// BeginPlay.
private:
	UPROPERTY(VisibleAnywhere)	// ���� ������ ��� ������� � ���� ��������� � ���������� �� ����� � Details.
	UBoxComponent* Box;			// ��� ���� ������� � ���� Box Colision �� BluePrint.

	UPROPERTY(EditAnywhere,Category = "Settings")// ��� ����� ��������� ����� ����� ���� ����� � ������.
	TSubclassOf <AActor> SpawnClass; // ��� ���� ������ ������������ �� ������.

	UPROPERTY(EditAnywhere, Category = "Settings")
	float SpawnPerTime; // ��� ���������� Actor ������� ����������� �� ���� ��������������.

	UPROPERTY(EditAnywhere, Category = "Settings")
	bool bIsOnse; // ��� ���� �� ����������� �������.

	void Spawn();// ���� ����� �������� ������� SpawnActor.
};
