// Fill out your copyright notice in the Description page of Project Settings.


#include "UIwidget/HUDGeneralWidget.h"
#include <Characters/BaseCharacter.h>
#include "Kismet/KismetTextLibrary.h"

FText UHUDGeneralWidget::GetHealt()
{
	ABaseCharacter* Character = Cast <ABaseCharacter>(GetPawn());// Это Cast тут актора приводим к наследнику Pawn.
	return FloatToFText(Character->GetHealt(),0);

}

FText UHUDGeneralWidget::GetCountApples()
{
	ABaseCharacter* Character = Cast <ABaseCharacter>(GetPawn());
	return FloatToFText(Character->GetCountFoods());
}

FText UHUDGeneralWidget::GetTimerText()
{
	float SecondsValue = GetWorld()->GetTimeSeconds();
	float SantiSecondsValue = FMath::RoundToInt(SecondsValue * 100) % 100; 
	// С верху получили от SecondsValue милесекунды и отбросили более меньшие еденици,
	// вермени результат с количеством милесекунд записали в SantiSeconds.

	FTimespan Timespan = FTimespan::FromSeconds(SecondsValue);
	// Сюда нужно подать за место (SecondsValue) количество секунд и эта функция FromSeconds,
	// из класса FTimespan соберет из этих секунд минуты и часы и запишет это в переменую с, 
	// уникальным именем Timespan (Timespan это не число а структура из чисел).

	FText Hours = FloatToFText (Timespan.GetHours());
	FText Minutes = FloatToFText(Timespan.GetMinutes());
	FText Seconds = FloatToFText(Timespan.GetSeconds());
	// Сверху из структуры Timespan мы получаем часы минуты и секунды и записываем их в переменые с типом текст.
	FText SantiSeconds = FloatToFText(SantiSecondsValue);

	FString StringFormat("Test Version (1.0.0):: {Hours}:{Minutes}:{Seconds}.{SantiSeconds}");
	// Сначало создаем щаблон то что в скобках заменится на переменые остольное останется не изменым.
	FTextFormat Format = FTextFormat:: FromString(StringFormat);
	// Cверху меняем только шаблон в скобках остольное тут конвертация из строки в текст.
	return FText::Format(Format, Hours, Minutes, Seconds, SantiSeconds);
	//Тут вызываем функцию FText::Format именно она эквивалент ноды Format Text,
	// ей подаем FTextFormat Format, и переменые которы встанут на место {Hours} {Minutes}.
}

FText UHUDGeneralWidget::FloatToFText(float Value, int CollichestvoZnacovPosleZapytoi)
{
 // Value - пердоваемое сюда число которое привратится в строку.
// CollichestvoZnacovPosleZapytoi - до кокого знака округлять Value.
	return UKismetTextLibrary::Conv_FloatToText(Value, ERoundingMode::FromZero, false, false,1,324,0, CollichestvoZnacovPosleZapytoi);
//UKismetTextLibrary::Conv_FloatToText - статик функция из #include "Kismet/KismetTextLibrary.h".
// ERoundingMode::FromZero - Определяет способ округления числа, к ближайщему числу.
// false - использовать запятую в числе.
// false - групировать число или использовать пробелы.
}
