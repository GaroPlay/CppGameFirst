// Fill out your copyright notice in the Description page of Project Settings.


#include "UIwidget/HUDGeneralWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/PanelWidget.h"
#include "algorithm" 
#include "Interfaces/InfoCharacter.h"


int UHUDGeneralWidget::GetCountApplesInt()
{
	if (GetMainActor() != nullptr)
	{
		return (IInfoCharacter::Execute_GetCountFoods(GetMainActor()));
	}
	else
	{
		return 0;
	}
	
}

FText UHUDGeneralWidget::GetCountApples()
{
	

	if (GetMainActor() != nullptr)
	{
		return FloatToFText(IInfoCharacter::Execute_GetCountFoods(GetMainActor()), 1);
	}
	else 
	{
		return FText();
	}
}


FText UHUDGeneralWidget::GetNameCpp()
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

FText UHUDGeneralWidget::GetTimerText()
{
	float SecondsValue = GetWorld()->GetTimeSeconds();
	float SantiSecondsValue = FMath::RoundToInt(SecondsValue * 100) % 100; 
	
	FTimespan Timespan = FTimespan::FromSeconds(SecondsValue);
	
	FText Hours = FloatToFText (Timespan.GetHours(),2);
	FText Minutes = FloatToFText(Timespan.GetMinutes(),2);
	FText Seconds = FloatToFText(Timespan.GetSeconds(),2);
	// ������ �� ��������� Timespan �� �������� ���� ������ � ������� � ���������� �� � ��������� � ����� �����.
	FText SantiSeconds = FloatToFText(SantiSecondsValue,2);

	FString StringFormat("Test Version (1.1.2):: {Hours}:{Minutes}:{Seconds}.{SantiSeconds}");
	// ������� ������� ������ �� ��� � ������� ��������� �� ��������� ��������� ��������� �� �������.
	FTextFormat Format = FTextFormat:: FromString(StringFormat);
	// C����� ������ ������ ������ � ������� ��������� ��� ����������� �� ������ � �����.
	return FText::Format(Format, Hours, Minutes, Seconds, SantiSeconds);
	//��� �������� ������� FText::Format ������ ��� ���������� ���� Format Text,
	// �� ������ FTextFormat Format, � ��������� ������ ������� �� ����� {Hours} {Minutes}.
}
////////////////////////////////// REMAINDER 
void UHUDGeneralWidget::UpdatePanelEnemis (UPanelWidget* Panel, UPanelWidget* PanelTwo, TSubclassOf <AActor> FindClass, TSubclassOf <UBasePlaUserWidget> WidgetEnemyClass, TSubclassOf <UBasePlaUserWidget> WidgetYouWinClass)
{
	 TArray <AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), FindClass, OutActors);

	if (!OutActors.IsEmpty()) 
	{
		//////////////////////////////////Remainder

		FString NameP;

		if (IsValid(GetOwningPlayerPawn()))
		{
			NameP = GetOwningPlayerPawn()->GetName();
		}
		else 
		{
			 NameP = "";
		}

		OutActors.Sort([NameP](const AActor& A, const AActor& B) {

			if (A.GetName() < NameP) return false;
			return true;
		});
	
		//////////////////////////////////Remainder

		if (WidgetYouWinClass != nullptr) 
		{
		UBasePlaUserWidget* YouWin = CreateWidget < UBasePlaUserWidget > (this, WidgetYouWinClass);
		PanelTwo->AddChild(YouWin);
		
		}
		

		for (AActor* Actor : OutActors) 
		{
			UBasePlaUserWidget* Enemy = CreateWidget < UBasePlaUserWidget> (this, WidgetEnemyClass);
			// ������� ��������� � ������� �������� ��������� �� WidgetEnemyClass.
			Panel->AddChild(Enemy);//��������� �������� Widget � �������������.
			Enemy->SetMainActor(Actor);
		}

	
	}
}




