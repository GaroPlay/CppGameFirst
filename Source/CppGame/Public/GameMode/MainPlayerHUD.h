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
	// ���� ����� ������ ����� Widget BluePrint ������� �� �������,
	// � ������ � ������� ��� ��� ������ � ������� �� ViemPort.
	// ����� ���� ����� ���� ��������� � ���������� � GameMode.
public:
	AMainPlayerHUD();// ��������� ����������� ����� ������.
	
	UPROPERTY(BlueprintReadOnly);
	UUserWidget* Widget;
protected: 
	 virtual void BeginPlay() override;// ��� BeginPlay � ������� ������ ����������� ��,
			   	   // ���� ����� ��������� �� ������ Actor(������ �� �������� ��������).
private:
	TSubclassOf<class UUserWidget> HUDClass;// ��� ���� ������ �������� � ���� ��� Widget ��� �� ������� � ������,
										   // HUDClass - ��� ���������� ��� ������ ���� � ������, 
								// UUserWidget - ���� ��� ������ ������� � ���� ��� Widget ��� �� ������� � ������,
	// TSubclassOf<class UUserWidget>  - ������� ���� ��� ����� ������� ����� ����� ������� � ���� UUserWidget,
   // ��� �� ������� � ������.


};
