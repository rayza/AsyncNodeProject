// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NotifyBoolChangeComponent.generated.h"

DECLARE_DYNAMIC_DELEGATE(FBoolVarChangedDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASYNCNODEPROJECT_API UNotifyBoolChangeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNotifyBoolChangeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
	FBoolVarChangedDelegate BoolVarChangedDelegate;

	UFUNCTION(BlueprintSetter)
	void SetBoolValue(bool InVal);

private:
	UPROPERTY(BlueprintSetter=SetBoolValue)
	bool BoolValue = false;
};
