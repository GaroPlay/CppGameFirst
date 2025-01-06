// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"// Ёто дл€ Box Colision из BluePrint.
#include "Spawner.generated.h"

UCLASS()
class CPPGAME_API ASpawner : public AActor
{
	GENERATED_BODY()
public:	
	ASpawner();//  онструктор.
protected:
	virtual void BeginPlay() override;// BeginPlay.
private:
	UPROPERTY(VisibleAnywhere)	// Ётот макрос дл€ дуступа к этой переменым у экземпл€ра на сцене в Details.
	UBoxComponent* Box;			// Ёто поле вмещ€ет в себ€ Box Colision из BluePrint.

	UPROPERTY(EditAnywhere,Category = "Settings")// Ёто чтобы переменую снизу видно было везде в движке.
	TSubclassOf <AActor> SpawnClass; // Ёто поле укажет пользоваетль из движка.

	UPROPERTY(EditAnywhere, Category = "Settings")
	float SpawnPerTime; // Ёто количестов Actor которые заспавн€тс€ за одно использованние.

	UPROPERTY(EditAnywhere, Category = "Settings")
	bool bIsOnse; // Ёто флаг на одноразовый заспавн.

	void Spawn();// Ётот метод вызывает функцию SpawnActor.
};
