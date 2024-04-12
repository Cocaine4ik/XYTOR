// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "W_InventoryBase.h"
#include "GameFramework/PlayerController.h"
#include "PC_Inventory.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API APC_Inventory : public APlayerController
{
	GENERATED_BODY()
protected:
    UPROPERTY()
    UW_InventoryBase* InventoryWidget;
    UPROPERTY(EditAnywhere, Category="Widgets")
    TSubclassOf<UW_InventoryBase> InventoryWidgetClass;

public:
    virtual void BeginPlay() override;
    UFUNCTION(BlueprintCallable)
    void DisplayInventory() const;
};
