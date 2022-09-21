// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChangedDelegate, float, Health, float, Maxhealth);

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

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnHpChanged;
};