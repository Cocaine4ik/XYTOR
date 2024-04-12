// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Energy/PC_Energy.h"
#include "GameFramework/PlayerController.h"
#include "Widgets/W_QuestListBase.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "PC_Quests.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API APC_Quests : public APC_Energy
{
    GENERATED_BODY()
protected:
    UPROPERTY()
    UW_QuestListBase* QuestListWidget;
    UPROPERTY(EditAnywhere, Category="Widgets")
    TSubclassOf<UW_QuestListBase> QuestListWidgetClass;
public:
    virtual void BeginPlay() override;
    UFUNCTION(BlueprintCallable)
    void DisplayQuests() const;
	
};
