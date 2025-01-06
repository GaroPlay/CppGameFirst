// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MyGameModeBase.h"
#include "GameMode/MainPlayerHUD.h"// ���������� Header � AMainPlayerHUD.

AMyGameModeBase::AMyGameModeBase() : Super() 
{											
	ConstructorHelpers::FClassFinder<APawn>PlayerClass(TEXT("/Game/BluePrint/BP_PlayerCharacter"));

	
	if (PlayerClass.Class != NULL) 
	{
		DefaultPawnClass = PlayerClass.Class;// ������������ BluePrint ����� � GameMode.
	}	
	HUDClass = AMainPlayerHUD::StaticClass();// ������������� HUDClass ������� ������ ����� �� �����,
	//������� �� ������ �� ������ � ����������� ��� ����� �������  �� ���������.
	
}
