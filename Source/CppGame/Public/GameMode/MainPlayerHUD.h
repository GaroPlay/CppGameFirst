// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainPlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class CPPGAME_API AMainPlayerHUD : public AHUD
{
	GENERATED_BODY()
	// Цель этого класса найти Widget BluePrint который мы создали,
	// в движке и создать его для игрока и вывести на ViemPort.
	// Также этот класс надо настроить и подключить в GameMode.
public:
	AMainPlayerHUD();// Объевляем конструктор этого класса.
	
	UPROPERTY(BlueprintReadOnly);
	UUserWidget* Widget;
protected: 
	 virtual void BeginPlay() override;// Это BeginPlay у данного класса удивительно он,
			   	   // этот метод наследует от класса Actor(тоесть от родителя родителя).
private:
	TSubclassOf<class UUserWidget> HUDClass;// Это поле должно вместить в себя тот Widget что мы создали в движке,
										   // HUDClass - это уникальное имя нашего поля в классе, 
								// UUserWidget - Этот тип данных вмещяет в себя тот Widget что мы создали в движке,
	// TSubclassOf<class UUserWidget>  - Создаст поле или сылку которая своим типом вместит в себя UUserWidget,
   // что мы создали в движке.


};
