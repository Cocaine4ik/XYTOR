// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_Dialogue.h"
#include "Components/ActorComponent.h"
#include "AC_DialogueHandler.generated.h"

class UNPCDialogueGraphNode;
class UPlayerDialogueGraphNode;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBeginDialogueSignature, const UNPCDialogueGraphNode*, NPCNode, const TArray<UPlayerDialogueGraphNode*>, PlayerDialogueNodes);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnProceedDialogueSignature, const UPlayerDialogueGraphNode*, Node);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndDialogueSignature);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XYTOR_API UAC_DialogueHandler : public UAC_Dialogue
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UAC_DialogueHandler();

    UPROPERTY(BlueprintAssignable, VisibleAnywhere)
    FOnBeginDialogueSignature OnBeginDialogueDelegate;
    
    UPROPERTY(BlueprintAssignable, VisibleAnywhere)
    FOnProceedDialogueSignature OnProceedDialogueDelegate;
    
    UPROPERTY(BlueprintAssignable, VisibleAnywhere)
    FOnEndDialogueSignature OnEndDialogueDelegate;

protected:
    UPROPERTY(BlueprintReadOnly,Category = "Dialogues")
    UNPCDialogueGraphNode* CurrentNPCNode;

    UPROPERTY(BlueprintReadOnly, Category = "Dialogues")
    TArray<UPlayerDialogueGraphNode*> CurrentPlayerDialogueNodes;
    
    // Called when the game starts
    virtual void BeginPlay() override;
    
public:
    UFUNCTION(BlueprintCallable)
    void BeginDialogue();
    
    UFUNCTION(BlueprintCallable)
    void OnProceedDialogue(const UPlayerDialogueGraphNode* Node);
    
    UFUNCTION(BlueprintCallable)
    void EndDialogue();

    bool IsProceed() const { return bIsProceed; }
    
private:
    bool bIsProceed = false;
};