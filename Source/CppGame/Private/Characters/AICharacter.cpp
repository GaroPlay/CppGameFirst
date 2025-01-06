// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AICharacter.h"
#include "Characters/AIContollers/EatAIController.h" // ������������ ���� �� Header � NPC ,
													// � ����� ��� AEatAIController.
AAICharacter::AAICharacter() : Super()
{
	AIControllerClass = AEatAIController::StaticClass(); // ��� ������� � ������ NPC - character,
	// ������ ���������� (AI Controller Class - �� BluePritn) � ������ ��� �������� ���������� �,
	// ����� �� ����� (AEatAIController:: �� ������ ��������� ������ ����� ����������),
	// ��� ����������  (::StaticClass();) ��� ��� ������.
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned; // ��� ������� ������ ������ Auto Possess AI,
				 // � ������ PlacedInWorldOrSpawned, ����� ��������� �������� � ����� ��� ����� ��������.
}
