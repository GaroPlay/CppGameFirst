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
	Super::BeginPlay();
	if (HUDClass != nullptr) //��������� ��� HUDClass ����������.
	{
		UUserWidget* Widget = CreateWidget <UUserWidget> (GetWorld(), HUDClass);
		// UUserWidget* Widget = ������� ��������� � ������� �������� ���������.
		//  ������� CreateWidget <��� ��� ������ �������� ��� �� ���� ������� ���������>.
		//   HUDClass - ��� ��� �� ���� �������� ���������
		if (Widget) //�������� ��� ��� Widget �� ��������.
		{
			Widget->AddToViewport();// �������� ��������� �� �������.
		}
	}
}
