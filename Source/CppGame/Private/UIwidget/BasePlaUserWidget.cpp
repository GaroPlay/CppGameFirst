// Fill out your copyright notice in the Description page of Project Settings.


#include "UIwidget/BasePlaUserWidget.h"

void UBasePlaUserWidget::NativeConstruct()
{
	Super::NativeConstruct();// �������� ������������ ���������� ������ ������.
	PlayerPawn = GetOwningPlayerPawn();// ���������� ����� ��������� � ���� ������.
}

APawn* UBasePlaUserWidget::GetPawn()
{
	return PlayerPawn;
}