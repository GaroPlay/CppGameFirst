// Fill out your copyright notice in the Description page of Project Settings.


#include "UIwidget/HUDGeneralWidget.h"
#include <Characters/BaseCharacter.h>
#include "Kismet/KismetTextLibrary.h"

FText UHUDGeneralWidget::GetHealt()
{
	ABaseCharacter* Character = Cast <ABaseCharacter>(GetPawn());// ��� Cast ��� ������ �������� � ���������� Pawn.
	return FloatToFText(Character->GetHealt(),2,0);

}

FText UHUDGeneralWidget::GetCountApples()
{
	ABaseCharacter* Character = Cast <ABaseCharacter>(GetPawn());
	return FloatToFText(Character->GetCountFoods(),1);// ���
}

FText UHUDGeneralWidget::GetTimerText()
{
	float SecondsValue = GetWorld()->GetTimeSeconds();
	float SantiSecondsValue = FMath::RoundToInt(SecondsValue * 100) % 100; 
	// � ����� �������� �� SecondsValue ����������� � ��������� ����� ������� �������,
	// ������� ��������� � ����������� ���������� �������� � SantiSeconds.

	FTimespan Timespan = FTimespan::FromSeconds(SecondsValue);
	// ���� ����� ������ �� ����� (SecondsValue) ���������� ������ � ��� ������� FromSeconds,
	// �� ������ FTimespan ������� �� ���� ������ ������ � ���� � ������� ��� � ��������� �, 
	// ���������� ������ Timespan (Timespan ��� �� ����� � ��������� �� �����).

	FText Hours = FloatToFText (Timespan.GetHours(),2);
	FText Minutes = FloatToFText(Timespan.GetMinutes(),2);
	FText Seconds = FloatToFText(Timespan.GetSeconds(),2);
	// ������ �� ��������� Timespan �� �������� ���� ������ � ������� � ���������� �� � ��������� � ����� �����.
	FText SantiSeconds = FloatToFText(SantiSecondsValue,2);

	FString StringFormat("Test Version (1.0.0):: {Hours}:{Minutes}:{Seconds}.{SantiSeconds}");
	// ������� ������� ������ �� ��� � ������� ��������� �� ��������� ��������� ��������� �� �������.
	FTextFormat Format = FTextFormat:: FromString(StringFormat);
	// C����� ������ ������ ������ � ������� ��������� ��� ����������� �� ������ � �����.
	return FText::Format(Format, Hours, Minutes, Seconds, SantiSeconds);
	//��� �������� ������� FText::Format ������ ��� ���������� ���� Format Text,
	// �� ������ FTextFormat Format, � ��������� ������ ������� �� ����� {Hours} {Minutes}.
}

FText UHUDGeneralWidget::FloatToFText (float Value,int CollichestvoZnacovDoZapytoi, int CollichestvoZnacovPosleZapytoi)
{
 // Value - ����������� ���� ����� ������� ����������� � ������.
// CollichestvoZnacovPosleZapytoi - �� ������ ����� ��������� Value.
	return UKismetTextLibrary::Conv_FloatToText(Value, ERoundingMode::FromZero, false, false, CollichestvoZnacovDoZapytoi,324,0, CollichestvoZnacovPosleZapytoi);
//UKismetTextLibrary::Conv_FloatToText - ������ ������� �� #include "Kismet/KismetTextLibrary.h".
// ERoundingMode::FromZero - ���������� ������ ���������� �����, � ���������� �����.
// false - ������������ ������� � �����.
// false - ����������� ����� ��� ������������ �������.
}