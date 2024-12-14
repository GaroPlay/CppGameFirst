// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MyGameModeBase.h"
#include "GameMode/MainPlayerHUD.h"// Подключаем Header у AMainPlayerHUD.

AMyGameModeBase::AMyGameModeBase() : Super() 
{											
	ConstructorHelpers::FClassFinder<APawn>PlayerClass(TEXT("/Game/BluePrint/BP_PlayerCharacter"));

	
	if (PlayerClass.Class != NULL) 
	{
		DefaultPawnClass = PlayerClass.Class;// Устанавливаю BluePrint пешку в GameMode.
	}	
	HUDClass = AMainPlayerHUD::StaticClass();// Устанавливаем HUDClass который хранит сылку на класс,
	//виджета из движка не путать с экземаляром как класс виджета  по умолчанию.
	
}
