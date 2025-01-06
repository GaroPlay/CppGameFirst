
#include "UIwidget/BasePlaUserWidget.h"
#include "Kismet/KismetTextLibrary.h"
#include "Interfaces/InfoCharacter.h"


void UBasePlaUserWidget::NativeConstruct()
{
	Super::NativeConstruct();// Вызываем родительскую реализацию всегда хорошо.
	MainActor = GetOwningPlayerPawn();// Записываем пешку влдаельца в поле класса.
}

AActor* UBasePlaUserWidget::GetMainActor()
{

	return MainActor;
}

void UBasePlaUserWidget::SetMainActor(AActor *Actor) 
{

	MainActor = Actor;
}
bool UBasePlaUserWidget::IsLifeCharacter()
{
	
	if (MainActor != nullptr)
	{
		return !IInfoCharacter::Execute_IsDead(MainActor);
	}
	else
	{
		return false;
	}
}

FText UBasePlaUserWidget::GetHealt()
{
	
	if (MainActor != nullptr)
	{
		return FloatToFText(IInfoCharacter::Execute_GetHealt(MainActor), 1, 0);
	}
	else
	{
		return FText();
	}
}

FText UBasePlaUserWidget::FloatToFText(float Value, int CollichestvoZnacovDoZapytoi, int CollichestvoZnacovPosleZapytoi)
{
	// Value - пердоваемое сюда число которое привратится в строку.
   // CollichestvoZnacovPosleZapytoi - до кокого знака округлять Value.
	return UKismetTextLibrary::Conv_FloatToText(Value, ERoundingMode::FromZero, false, false, CollichestvoZnacovDoZapytoi, 324, 0, CollichestvoZnacovPosleZapytoi);
	//UKismetTextLibrary::Conv_FloatToText - статик функция из #include "Kismet/KismetTextLibrary.h".
}

