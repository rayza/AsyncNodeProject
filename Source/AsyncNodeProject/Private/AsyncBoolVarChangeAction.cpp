// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncBoolVarChangeAction.h"

#include "NotifyBoolChangeComponent.h"

void UAsyncBoolVarChangeAction::Activate()
{
	Super::Activate();
}

UAsyncBoolVarChangeAction* UAsyncBoolVarChangeAction::AsyncWaitForBoolVarChange(UObject* WorldContextObject,
	UNotifyBoolChangeComponent* NotifyingActorComponent)
{
	UAsyncBoolVarChangeAction* Action = NewObject<UAsyncBoolVarChangeAction>();
	Action->NotifyingActorComponent = NotifyingActorComponent;
	Action->RegisterWithGameInstance(WorldContextObject);

	NotifyingActorComponent->BoolVarChangedDelegate.BindDynamic(Action, &UAsyncBoolVarChangeAction::HandleBoolVarChanged);

	return Action;
}

void UAsyncBoolVarChangeAction::HandleBoolVarChanged()
{
	BoolVarChanged.Broadcast();
}
