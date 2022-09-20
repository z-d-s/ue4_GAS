// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "AbilitySystemComponent.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComp"));
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void ACharacterBase::GetAbility(TSubclassOf<UGameplayAbility> Ability)
{
	if (Ability && AbilitySystemComp)
	{
		AbilitySystemComp->GiveAbility(FGameplayAbilitySpec(Ability, 1));
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

