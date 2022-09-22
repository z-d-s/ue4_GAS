// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BaseGameplayAbility.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ECostType : uint8
{
	Health,
	Mana,
	Energy
};

USTRUCT(BlueprintType)
struct FGameplayAbilityInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	float CoolDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	float Cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	ECostType CostType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	UMaterialInstance* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	TSubclassOf<UBaseGameplayAbility> AbilityClass;

	FGameplayAbilityInfo();

	FGameplayAbilityInfo(float CoolDown, float Cost, ECostType CostType, UMaterialInstance* Icon, TSubclassOf<UBaseGameplayAbility> AbilityClass);
};

UCLASS()
class UE4_GAS_API UBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	UMaterialInstance* Icon;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	FGameplayAbilityInfo GetAbilityInfo();
};