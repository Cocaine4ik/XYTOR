// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subquest.h"
#include "UObject/NoExportTypes.h"
#include "Quest.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API UQuest : public UObject
{
	GENERATED_BODY()

    UPROPERTY()
    TArray<USubquest*> Subquests;
    uint8 CurrentSubquest = 0u;
    // APS_Quests* QuestCore; 

    FText Title;
    FText Description;
    

    bool Init(FName QuestName);
public:
    UQuest() = default;
    UQuest(FName QuestName);
    bool IsCompleted() const;
    bool Update(EE_SubquestType Type);
};
