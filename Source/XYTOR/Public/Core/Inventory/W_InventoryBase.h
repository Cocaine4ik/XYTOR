// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/WidgetManager/Widgets/W_NormalBase.h"
#include "W_InventoryBase.generated.h"

class UItem;

//DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnItemRemovedDelegate, UItem*, Item, int32, Count);
DECLARE_DELEGATE_TwoParams(FOnItemRemovedDelegate, UItem*, int32);
DECLARE_DELEGATE_OneParam(FOnItemStatusChanged, UItem*);

/**
 * 
 */
UCLASS()
class XYTOR_API UW_InventoryBase : public UW_NormalBase
{
	GENERATED_BODY()
public:
    FOnItemRemovedDelegate OnItemRemoved;
    FOnItemStatusChanged OnItemActivated, OnItemDeactivated;
    
    UFUNCTION(BlueprintCallable)
    void UpdateItem(const UItem* Item, int32 Count);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ActivateItem(UItem* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DeactivateItem(UItem* Item);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RemoveItemFromInventory(UItem* Item, int32 Count);
    UFUNCTION(BlueprintCallable)
    void ActivateItemInInventory(UItem* Item, bool IsActivated);
    
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void AddItem(const UItem* Item, int32 Count);
    
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void RemoveItem(const UItem* Item, int32 Count);
};
