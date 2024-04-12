// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Inventory/S_Item.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API UItem : public UObject
{
	GENERATED_BODY()
protected:
    FS_Item* ItemData;

public:
    bool Init(FName ItemName);
    UItem() = default;
    UItem(FName ItemName);
    
};
