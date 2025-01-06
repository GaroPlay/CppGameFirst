// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MainPlayerHUD.h"
#include "Blueprint/UserWidget.h" // Это обезательно для функции CreateWidget <UUserWidget> 
AMainPlayerHUD::AMainPlayerHUD(): Super()// Вызвать родительскию реализацию конструктора всегда хорошо.
{
	// Главная цель конструкторая у HUD найти виджет что создан в движке,
	// и записать его в свое поле для главного виджет.
	ConstructorHelpers::FClassFinder <UUserWidget> WBPHUD(TEXT("/Game/UI/WBP_HUD")); 
	// С верху так мы получили сылку на визуальную часть Widget которую создали в движке. 

	HUDClass = WBPHUD.Class;// Тут уже в поле класса подходящего типа для вмещения в себя,
		  // widget который  мы создали в движке, мы записываем в это поле экземпляр,
		  // нашего из движка виджет. 
}
void AMainPlayerHUD::BeginPlay() 
{
	Super::BeginPlay();
	if (HUDClass != nullptr) //Проверяем что HUDClass существует.
	{
		UUserWidget* Widget = CreateWidget <UUserWidget> (GetWorld(), HUDClass);
		// UUserWidget* Widget = Создаем указатель в которой поместим экземпляр.
		//  Функция CreateWidget <Тут тип данных которого тот от кого содадут экземпляр>.
		//   HUDClass - Это тот от кого создадут экземпляр
		if (Widget) //Проверка что тут Widget не пустышка.
		{
			Widget->AddToViewport();// Вывыодим экземпляр на монитор.
		}
	}
}
