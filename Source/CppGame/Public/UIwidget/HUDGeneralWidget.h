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
protected:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetHealt();

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FText GetCountApples();

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FText GetTimerText();

	FText FloatToFText(float Value, int CollichestvoZnacovPosleZapytoi = 2);
};
