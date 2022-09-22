// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameplayAbility.h"

FGameplayAbilityInfo::FGameplayAbilityInfo():
	CoolDown(0.0f),
	Cost(0.0f),
	CostType(ECostType::Mana),
	Icon(nullptr),
	AbilityClass(nullptr)
{
}

FGameplayAbilityInfo::FGameplayAbilityInfo(float CoolDown, float Cost, ECostType CostType, UMaterialInstance* Icon, TSubclassOf<UBaseGameplayAbility> AbilityClass):
	CoolDown(CoolDown),
	Cost(Cost),
	CostType(CostType),
	Icon(Icon),
	AbilityClass(AbilityClass)
{
}

FGameplayAbilityInfo UBaseGameplayAbility::GetAbilityInfo()
{
	UGameplayEffect* CooldownEffect = GetCooldownGameplayEffect();
	UGameplayEffect* CostEffect = GetCostGameplayEffect();

	float Cooldown = 0.0f;
	float Cost = 0.0f;
	ECostType CostType = ECostType::Mana;

	if (CooldownEffect && CostEffect)
	{
		CooldownEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(1, Cooldown);
		if (CostEffect->Modifiers.Num() > 0)
		{
			FGameplayModifierInfo CostEffectModifierInfo = CostEffect->Modifiers[0];
			CostEffectModifierInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(1, Cost);

			FGameplayAttribute CostAttribute = CostEffectModifierInfo.Attribute;
			FString CostAttributeName = CostAttribute.AttributeName;
			if (CostAttributeName == "Health")
			{
				CostType = ECostType::Health;
			}
			else if (CostAttributeName == "Mana")
			{
				CostType = ECostType::Mana;
			}
			else if(CostAttributeName == "Energy")
			{
				CostType = ECostType::Energy;
			}
		}
		return FGameplayAbilityInfo(Cooldown, Cost, CostType, Icon, GetClass());
	}

	return FGameplayAbilityInfo();
}
