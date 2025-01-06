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

public:
	void SetMainActor(AActor* Actor);
protected:
	virtual void NativeConstruct() override; // ��� ��� ���������� BeginPlay � ����� ������,
	// ������ ��� ���������� ����� ��� ���������� ������� ���� ������� � ����������������.

	AActor* GetMainActor();


	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetHealt();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsLifeCharacter();

	FText FloatToFText(float Value, int CollichestvoZnacovDoZapytoi = 2, int CollichestvoZnacovPosleZapytoi = 2);


private:
		AActor* MainActor;


};
