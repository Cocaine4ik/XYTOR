// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "E_SubquestType.h"
#include "Core/Information/PS_Information.h"
#include "./Objects/Quest.h"
#include "GameFramework/PlayerState.h"
#include "PS_Quests.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestChanged, UQuest*, QuestObject);

/**
 * 
 */
UCLASS()
class XYTOR_API APS_Quests : public APS_Information
{
	GENERATED_BODY()
    UPROPERTY()
    TArray<UQuest*> AvailableQuests;
    UPROPERTY()
    TArray<UQuest*> CompletedQuests;

    void FinishQuest(uint8 Index);
public:
    UPROPERTY(BlueprintAssignable, VisibleAnywhere)
    FOnQuestChanged OnQuestChanged;
    
    void UpdateQuests(EE_SubquestType Type);
    UFUNCTION(BlueprintCallable)
    void AddQuest(FName QuestName);

    void TokensChanged();
    void ItemsChanged();
};
