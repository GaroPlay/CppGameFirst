// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/Spawner.h"
#include "Kismet/KismetMathLibrary.h" // Это библиотека обезательна для, 
									 // функции (Random Point In Bounding Box)
ASpawner::ASpawner() // Реализуем конструктор.
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// Устанавливаем значения по умолчанию у полей //	
	 bIsOnse = false; // Спавним  безконечно.
	 SpawnPerTime = 5;// Количество Actor которые заспавнятся.

	 Box = CreateDefaultSubobject <UBoxComponent> (TEXT("BoxCollision"));// Создали и,
										   // поместиле в поле компонент BoxCollision.
	 Box->SetCollisionProfileName(TEXT("NoCollision"));// Нам нужен BoxCollision а вот,
								  // чтобы он мог сталкиватся с чемто на сцене не надо.	
	 RootComponent = Box; 
}
void ASpawner::BeginPlay()// Реализуем BeginPlay.
{
	Super::BeginPlay();// Вызываем родительскую реализацию метода.
	FTimerHandle TimerHadle;// Объявляем таймер и снизу реализуем.
	GetWorldTimerManager().SetTimer(TimerHadle, this, &ASpawner::Spawn, 1, !bIsOnse, 0);
}
void ASpawner::Spawn()//Этот клас вызывает SpawnActor указаное GameDisagner количество раз.
{
	for (int i = 0; i < SpawnPerTime; i++) // Цыкл на количество заспавнов.
	{
		FRotator Rotation (0, 0, 0);// Это поворот тех объектов которых ты спавниш.
		FVector Location= UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), Box->GetScaledBoxExtent());
		// С верху это кординаты куда заспавнить Actor естествено в нутри нашего BoxCollision.
		// Это функция полный аналог ноды Random Point in Bounding Box.
		GetWorld()->SpawnActor <AActor>(SpawnClass, Location, Rotation);//Эта функция полный эквивалент,
		// ноды (Spawn Actor from Class)  
		// <AActor> - Тут надо указать тип данных объекта который хочеш заспавнить,
		// SpawnClass - Сюда название класса который хотим спавнить можеш взять из Header-файла только убери префикс.
		// GetWorld()->SpawnActor - Это синтаксис.
	}
}



