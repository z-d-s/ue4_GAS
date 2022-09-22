// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"

UAttributeSetBase::UAttributeSetBase() :
	Health(100.0f),
	MaxHealth(Health.GetBaseValue()),
	Mana(100.0f),
	MaxMana(Mana.GetBaseValue()),
	Energy(100.0f),
	MaxEnergy(Energy.GetBaseValue())
{
	
}

void UAttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
	{
		Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), 0.0f, MaxHealth.GetCurrentValue()));
		UE_LOG(LogTemp, Error, TEXT("Health:%f MaxHealth:%f"), Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
		OnHpChanged.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Mana)))
	{
		Mana.SetCurrentValue(FMath::Clamp(Mana.GetCurrentValue(), 0.0f, MaxMana.GetCurrentValue()));
		UE_LOG(LogTemp, Error, TEXT("Mana:%f MaxMana:%f"), Mana.GetCurrentValue(), MaxMana.GetCurrentValue());
		OnMpChanged.Broadcast(Mana.GetCurrentValue(), MaxMana.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Energy)))
	{
		Energy.SetCurrentValue(FMath::Clamp(Energy.GetCurrentValue(), 0.0f, MaxEnergy.GetCurrentValue()));
		UE_LOG(LogTemp, Error, TEXT("Energy:%f MaxEnergy:%f"), Energy.GetCurrentValue(), MaxEnergy.GetCurrentValue());
		OnEnergyChanged.Broadcast(Energy.GetCurrentValue(), MaxEnergy.GetCurrentValue());
	}
}