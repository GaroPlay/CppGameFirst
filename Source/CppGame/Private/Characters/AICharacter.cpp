// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AICharacter.h"
#include "Characters/AIContollers/EatAIController.h" // Прокладываем путь от Header у NPC ,
													// к папке где AEatAIController.
AAICharacter::AAICharacter() : Super()
{
	AIControllerClass = AEatAIController::StaticClass(); // Эта строчка в классе NPC - character,
	// полный эквивалент (AI Controller Class - из BluePritn) и служит для вселение контролера в,
	// пешку за место (AEatAIController:: ты должен указывать нужный класс контролера),
	// это синтактсис  (::StaticClass();) тут нет выбора.
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned; // Эта строчка полный аналог Auto Possess AI,
				 // в режиме PlacedInWorldOrSpawned, чтобы контролер вселился в пешку при любой ситуации.
}
