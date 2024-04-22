// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_Inventory.h"
#include "GameFramework/PlayerState.h"
#include "PS_Inventory.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API APS_Inventory : public APlayerState
{
	GENERATED_BODY()
protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UAC_Inventory* InventoryComponent;

public:
    APS_Inventory();
    
    UFUNCTION(BlueprintCallable)
    UAC_Inventory* GetInventory() const;
};