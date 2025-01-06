// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIwidget/BasePlaUserWidget.h"
#include "EnemyWidgetList.generated.h"

/**
 * 
 */
UCLASS()
class CPPGAME_API UEnemyWidgetList : public UBasePlaUserWidget
{
	GENERATED_BODY()
	
protected:

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FText GetName();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FLinearColor GetTextColor();

private:
	UPROPERTY (EditDefaultsOnly)
	FLinearColor ColorLive;

	UPROPERTY(EditDefaultsOnly)
	FLinearColor ColorDeath;
};
