// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MyGameModeBase.h"

AMyGameModeBase::AMyGameModeBase() : Super() // �������� ������� ������������, 
{											// ���������� ��� ������ ������.
	ConstructorHelpers::FClassFinder<APawn>PlayerClass(TEXT("/Game/BluePrint/BP_PlayerCharacter"));

	// ConstructorHelpers - ��� ����� �������� ������������ �� Content Browser � �++.
	if (PlayerClass.Class != NULL) // �������� ��� ��������� PlayerClass � ���� �������� ��� ����������.
	{
		DefaultPawnClass = PlayerClass.Class;// ������������ BluePrint ����� � GameMode.
	}	
}