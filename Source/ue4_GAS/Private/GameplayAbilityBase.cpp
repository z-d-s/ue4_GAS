// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilityBase.h"
#include "Materials/MaterialInstance.h"
#include "Kismet/KismetStringLibrary.h"

FGameplayAbilityInfo UGameplayAbilityBase::GetAbilityInfo()
{
	UGameplayEffect* CooldownEffect = GetCooldownGameplayEffect();
	UGameplayEffect* CostEffect = GetCostGameplayEffect();
	if (CooldownEffect && CostEffect)
	{
		float CoolDownDuration = 0.f;
		CooldownEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(1, CoolDownDuration);
	
		float Cost = 0.f;
		EAbilityCostType CostType;
	
		if (CostEffect->Modifiers.Num() > 0)
		{
			FGameplayModifierInfo Modifierinfo = CostEffect->Modifiers[0];
			Modifierinfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(1, Cost);
			FGameplayAttribute CostAttribute = Modifierinfo.Attribute;
			FString CostAttributeName = CostAttribute.AttributeName;
			if (CostAttributeName == UKismetStringLibrary::Conv_ByteToString((uint8)EAbilityCostType::Health))
			{
				CostType = EAbilityCostType::Health;
			}
			else if (CostAttributeName == UKismetStringLibrary::Conv_ByteToString((uint8)EAbilityCostType::Mana))
			{
				CostType = EAbilityCostType::Mana;
			}
			else if (CostAttributeName == UKismetStringLibrary::Conv_ByteToString((uint8)EAbilityCostType::Energy))
			{
				CostType = EAbilityCostType::Energy;
			}
		}
		return FGameplayAbilityInfo(CoolDownDuration, Cost, CostType, UIMaterial, GetClass());
	}
	return FGameplayAbilityInfo();
}