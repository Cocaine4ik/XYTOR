// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "S_Subquest_Item.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FS_Subquest_Item : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RequiredItems")
    TMap<FName, uint8> RequiredItems;
};

