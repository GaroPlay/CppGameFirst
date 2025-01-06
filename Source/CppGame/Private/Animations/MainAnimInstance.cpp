// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/MainAnimInstance.h"
void UMainAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();// � ������ ������� ������ �������� ������������,
			// ���������� � ����� ����� ��������� ����� ����� ����� ����� ������� �����.
	Pawn = TryGetPawnOwner();// ���� � ���� ��������� ����� ��������� � ���� ������� ����,
							//���� � BluePrint ������� ������� �����.
}

void UMainAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);// � ������ ������� ������ �������� ������������,
					// ���������� � ����� ����� ��������� ����� ����� ����� ����� ������� �����.
	if (Pawn != nullptr) // ��� ��� ������ Is Valid �� ��������.
	{
		Speed = Pawn->GetVelocity().Size(); // ���������� � ��������� ��� BlendSpace ��������,
		// �������� ��������� ������ �����, �� �������� � GetVelocity() � ���� ������� Size() ,
		// ������ ��� �� ����� ���� float.
	}
}
