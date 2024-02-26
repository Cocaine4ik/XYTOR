// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "S_Subquest_Token.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FS_Subquest_Token : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RequiredTokens")
    TArray<FName> RequiredTokens;
};
