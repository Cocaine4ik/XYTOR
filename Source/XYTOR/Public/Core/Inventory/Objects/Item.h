// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Inventory/S_Item.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class XYTOR_API UItem : public UObject
{
	GENERATED_BODY()
protected:
    FName Name;
    FS_Item* ItemData;

    virtual bool AdditionalInit(FName ItemName); 
public:
    UFUNCTION(BlueprintPure)
    FName GetItemName() const;

    UFUNCTION(BlueprintPure)
    const FS_Item& GetItemData() const;
    
    UFUNCTION(BlueprintCallable)
    bool Init(FName ItemName);
    bool Init(FName ItemName, FS_Item* ItemStructure);
    
    UItem(FName ItemName);
    UItem(FName ItemName, FS_Item* ItemStructure);
    
    UItem() = default;

    UFUNCTION(BlueprintCallable)
    static UItem* MakeItem(FName ItemName);
    UFUNCTION(BlueprintCallable)
    static TSubclassOf<UItem> GetClass(EE_ItemType Type);

};