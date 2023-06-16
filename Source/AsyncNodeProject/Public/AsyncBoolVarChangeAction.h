// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncBoolVarChangeAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBoolVarChangedActionDelegate);

/**
 * 
 */
UCLASS()
class ASYNCNODEPROJECT_API UAsyncBoolVarChangeAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

private:
	// UPROPERTY()
	UActorComponent* NotifyingActorComponent;
	
public:
	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Flow Control",
		WorldContext = "WorldContextObject"))
	static UAsyncBoolVarChangeAction* AsyncWaitForBoolVarChange(UObject* WorldContextObject, UNotifyBoolChangeComponent* NotifyingActorComponent);

	UFUNCTION(meta=(WorldContext="WorldContextObject"))
	void HandleBoolVarChanged();

	UPROPERTY(BlueprintAssignable)
	FBoolVarChangedActionDelegate BoolVarChanged;
};
