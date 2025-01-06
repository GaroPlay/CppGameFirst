// Fill out your copyright notice in the Description page of Project Settings.


#include "UIwidget/EnemyWidgetList.h"
#include "Interfaces/InfoCharacter.h"

FText UEnemyWidgetList::GetName()
{

	
	
	if (GetMainActor() != nullptr)		
	{
		return IInfoCharacter::Execute_GetName(GetMainActor());
	}
	else
	{
		return FText(); 
	}
}

FLinearColor UEnemyWidgetList::GetTextColor()
{
	if(GetMainActor() == nullptr)return ColorLive;

	if (IInfoCharacter::Execute_GetHealt(GetMainActor()) > 0)
	{
		return ColorLive;
	}
	
	return ColorDeath;
}

