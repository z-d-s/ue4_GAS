// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChangedDelegate, float, Value, float, MaxValue);

UCLASS()
class UE4_GAS_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UAttributeSetBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSet")
	FGameplayAttributeData Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSet")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSet")
	FGameplayAttributeData Mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSet")
	FGameplayAttributeData MaxMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSet")
	FGameplayAttributeData Energy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSet")
	FGameplayAttributeData MaxEnergy;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnHpChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnMpChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnEnergyChanged;
};