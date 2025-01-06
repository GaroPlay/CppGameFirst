// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/MainAnimInstance.h"
void UMainAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();// ¬ первую очередь всегда вызываем родиетльскую,
			// реализацию и потом снизу дополн€ем своей иначе можно вобще сломать класс.
	Pawn = TryGetPawnOwner();// —уем в нашу переменую пешку владельца у этой функции есть,
							//нода в BluePrint котора€ работае также.
}

void UMainAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);// ¬ первую очередь всегда вызываем родиетльскую,
					// реализацию и потом снизу дополн€ем своей иначе можно вобще сломать класс.
	if (Pawn != nullptr) // Ёто как аналог Is Valid из макросов.
	{
		Speed = Pawn->GetVelocity().Size(); // «аписываем в переменую дл€ BlendSpace скорость,
		// движени€ владельца тоесть пешки, но скорость в GetVelocity() в виде вектора Size() ,
		// сводит его до числа типа float.
	}
}
