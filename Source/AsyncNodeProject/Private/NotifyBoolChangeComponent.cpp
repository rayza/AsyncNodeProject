// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyBoolChangeComponent.h"

// Sets default values for this component's properties
UNotifyBoolChangeComponent::UNotifyBoolChangeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNotifyBoolChangeComponent::BeginPlay()
{
	Super::BeginPlay();

	// FTimerHandle MemberTimerHandle;
	// GetOwner()->GetWorldTimerManager().SetTimer(MemberTimerHandle, [this]()
	// {
	// 	SetBoolValue(true);
	// }, 1.0f, false, 2.0f);
}


// Called every frame
void UNotifyBoolChangeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UNotifyBoolChangeComponent::SetBoolValue(bool InVal)
{
	BoolValue = InVal;
	BoolVarChangedDelegate.ExecuteIfBound();
}

