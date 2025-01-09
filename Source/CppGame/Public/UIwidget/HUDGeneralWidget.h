// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIwidget/BasePlaUserWidget.h"
#include "HUDGeneralWidget.generated.h"

/**
 * 
 */
UCLASS()
class CPPGAME_API UHUDGeneralWidget : public UBasePlaUserWidget
{
	GENERATED_BODY()

public:
	

protected:
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetCountApplesInt();

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FText GetCountApples();

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FText GetTimerText();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetNameCpp();

	UFUNCTION(BlueprintCallable)
	void UpdatePanelEnemis(UPanelWidget * Panel, UPanelWidget* PanelTwo, TSubclassOf <AActor> FindClass, TSubclassOf <UBasePlaUserWidget> WidgetEnemyClass, TSubclassOf <UBasePlaUserWidget> WidgetYouWinClass);

	
};
