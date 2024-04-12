// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "E_ItemType.h"
#include "Engine/DataTable.h"

#include "S_Item.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FS_Item : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Title")
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ToolTip")
    FText ToolTip;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ItemType")
    EE_ItemType ItemType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ItemType")
    UTexture2D* Icon;
};
