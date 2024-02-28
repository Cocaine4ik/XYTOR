// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/QuestSystem/Structures/S_Subquest.h"
#include "UObject/NoExportTypes.h"
#include "Subquest.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class XYTOR_API USubquest : public UObject
{
	GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadOnly)
    FS_Subquest Data;
    UPROPERTY(BlueprintReadOnly)
    bool bComplete;
public:
    bool Init(const FS_Subquest& SubquestInfo);
    bool IsComplete() const;
    bool Update(EE_SubquestType Type);
    static USubquest* MakeSubquest(const FS_Subquest& Data, UObject* Parent);
protected:
    virtual bool Update() PURE_VIRTUAL(USubquest::Update, return false;);
    virtual bool Init(FName SubquestName) PURE_VIRTUAL(USubquest::SubquestName, return false;);
};
