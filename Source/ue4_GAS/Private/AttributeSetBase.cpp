// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"

UAttributeSetBase::UAttributeSetBase():Health(100.0f), MaxHealth(Health.GetBaseValue())
{
	
}

void UAttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
	{
		UE_LOG(LogTemp, Error, TEXT("Health:%f MaxHealth:%f"), Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
		OnHpChanged.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
	}
}