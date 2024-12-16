// Fill out your copyright notice in the Description page of Project Settings.


#include "UIwidget/BasePlaUserWidget.h"

void UBasePlaUserWidget::NativeConstruct()
{
	Super::NativeConstruct();// Вызываем родительскую реализацию всегда хорошо.
	PlayerPawn = GetOwningPlayerPawn();// Записываем пешку влдаельца в поле класса.
}

APawn* UBasePlaUserWidget::GetPawn()
{
	return PlayerPawn;
}
