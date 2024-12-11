// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MyGameModeBase.h"

AMyGameModeBase::AMyGameModeBase() : Super() // Вызываем сначало родительскую, 
{											// реализацию это всегда хорошо.
	ConstructorHelpers::FClassFinder<APawn>PlayerClass(TEXT("/Game/BluePrint/BP_PlayerCharacter"));

	// ConstructorHelpers - Это класс помогает использовать из Content Browser в с++.
	if (PlayerClass.Class != NULL) // Проверям что переменая PlayerClass в себе содержит что конкретное.
	{
		DefaultPawnClass = PlayerClass.Class;// Устанавливаю BluePrint пешку в GameMode.
	}	
}
