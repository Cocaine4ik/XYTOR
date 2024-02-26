// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/QuestSystem/Objects/Quest.h"
#include "Core/WidgetManager/Widgets/W_NormalBase.h"
#include "W_QuestListBase.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API UW_QuestListBase :  public UW_NormalBase
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void UpdateQuest(UQuest* Quest);
};
