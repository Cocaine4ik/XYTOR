// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
// #include "UObject/NoExportTypes.h"
// #include "ExtraTools.generated.h"
//
// /**
//  * 
//  */
// UCLASS()
// class XYTOR_API UExtraTools : public UObject
// {
// 	GENERATED_BODY()
// 	
// };

namespace ExtraTools
{
    template<typename StructureType>
    StructureType* GetStructureFromTable(const FString& Path, FName RowName)
    {
        if (const UDataTable* Table = LoadObject<UDataTable>(nullptr, *Path))
        {
            return Table->FindRow<StructureType>(RowName, "");
        }
        
        UE_LOG(LogTemp, Error, TEXT("Failed to load DataTable: %s"), *Path);
        return nullptr;
    }
}
