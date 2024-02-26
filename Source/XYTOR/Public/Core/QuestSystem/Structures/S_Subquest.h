// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "S_Subquest.generated.h"

enum class EE_SubquestType : uint8;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FS_Subquest : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Title")
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Description")
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Type")
    EE_SubquestType Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DataName")
    FName DataName;
};
