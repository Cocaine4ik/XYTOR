// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IInteractable.generated.h"

class UAC_Interact;

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractable : public UInterface
{
    GENERATED_BODY()
};

class IInteractable
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    TSubclassOf<UAC_Interact> GetHandlerClass() const;
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FText GetInteractingText() const;
};
/**
 * 
 */