// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/WidgetManager/Widgets/W_NormalBase.h"
#include "AC_DialogueHandler.h"
#include "DialogueGraph/PlayerDialogueGraphNode.h"
#include "W_DialogueWindow.generated.h"


class UVerticalBox;
class UW_DialogueLine;
class UImage;
class UTextBlock;

UCLASS()
class XYTOR_API UW_DialogueWindow : public UW_NormalBase
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UVerticalBox* PlayerDialogueLineContainer;

    UPROPERTY(meta = (BindWidget))
    UImage* NPCDialogueIcon;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* NPCDialogueText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> DialogueLineClass;
    
    virtual void NativeOnInitialized() override;

public:
    UFUNCTION(BlueprintCallable)
    void OnBeginDialogue(const UNPCDialogueGraphNode* NPCNode, const TArray<UPlayerDialogueGraphNode*> PlayerDialogueNodes);

    UFUNCTION(BlueprintCallable)
    void OnProceedDialogue(const UPlayerDialogueGraphNode* Node);
    
    UFUNCTION(BlueprintCallable)
    UAC_DialogueHandler* GetDialogueHandler() const { return DialogueHandler; };

private:
    UPROPERTY()
    UAC_DialogueHandler* DialogueHandler;
};