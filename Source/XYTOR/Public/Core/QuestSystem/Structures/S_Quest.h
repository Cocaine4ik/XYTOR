// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"

#include "S_Quest.generated.h"


struct FS_Subquest;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FS_Quest : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Title")
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Description")
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Subquests")
    TArray<FS_Subquest> Subquests;
};
