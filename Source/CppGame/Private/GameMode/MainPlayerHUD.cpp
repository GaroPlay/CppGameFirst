// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MainPlayerHUD.h"
#include "Blueprint/UserWidget.h" // ��� ����������� ��� ������� CreateWidget <UUserWidget> 
AMainPlayerHUD::AMainPlayerHUD(): Super()// ������� ������������ ���������� ������������ ������ ������.
{
	// ������� ���� ������������� � HUD ����� ������ ��� ������ � ������,
	// � �������� ��� � ���� ���� ��� �������� ������.
	ConstructorHelpers::FClassFinder <UUserWidget> WBPHUD(TEXT("/Game/UI/WBP_HUD")); 
	// � ����� ��� �� �������� ����� �� ���������� ����� Widget ������� ������� � ������. 

	HUDClass = WBPHUD.Class;// ��� ��� � ���� ������ ����������� ���� ��� �������� � ����,
		  // widget �������  �� ������� � ������, �� ���������� � ��� ���� ���������,
		  // ������ �� ������ ������. 
}
void AMainPlayerHUD::BeginPlay()
{
	Super::BeginPlay();//������� ������������ ����������,
	// ������ BeginPlay �� �� �� �����.
	if (HUDClass != nullptr) // ��� �������� ��� ���� ������ HUD ������� ������� � ���� �������,
	{// ������ �� ������ �������� ���������� ��������� � ����  ("/Game/UI/WBP_HUD") �������� �� ����.
	
		UUserWidget* Widget = CreateWidget <UUserWidget>(GetWorld(), HUDClass);
		// ������ ������ ������� �������� ������� ��� ������������� � HUDClass, � ����������,
		// ��� � ��������� c ������ Widget, GetWorld() -  ��������� �� ������� ��� ��� ����� � ����,
		// ������ ��� ����� �� �������.
		if (Widget) //�������� ��� ��� Widget �� ��������.
		{
			Widget->AddToViewport();// ����� Widget �� �������,
		}						   // ���� �����-�� ����.
	}
}