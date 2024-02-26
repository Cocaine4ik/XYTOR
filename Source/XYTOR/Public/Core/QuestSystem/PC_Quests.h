// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Widgets/W_QuestListBase.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "PC_Quests.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API APC_Quests : public APlayerController
{
    GENERATED_BODY()
public:
    UPROPERTY()
    UW_QuestListBase* QuestListWidget;
protected:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UW_QuestListBase> QuestListWidgetClass;
public:
    virtual void BeginPlay() override;
	
};
