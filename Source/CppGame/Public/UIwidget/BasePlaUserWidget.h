// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BasePlaUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CPPGAME_API UBasePlaUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override; // ��� ��� ���������� BeginPlay � ��� ������,
	// ������ ��� ���������� ����� ��� ���������� ������� ���� ������� � ����������������.

	APawn* GetPawn();
private:
		APawn* PlayerPawn;


};