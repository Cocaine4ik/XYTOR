// XYTOR. All Rights Reserved.

#include "Core/Dialogues/AC_DialogueHandler.h"

// Sets default values for this component's properties
UAC_DialogueHandler::UAC_DialogueHandler()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}


// Called when the game starts
void UAC_DialogueHandler::BeginPlay()
{
    Super::BeginPlay();

    OnProceedDialogueDelegate.AddUniqueDynamic(this, &UAC_DialogueHandler::OnProceedDialogue);
}

void UAC_DialogueHandler::BeginDialogue()
{
    if (!DialogueGraph)
    {
        return;
    }

    // DialogueGraph->InitializeValidationTags();
    CurrentNPCNode = DialogueGraph->GetStartDialogueNode();

    CurrentPlayerDialogueNodes = DialogueGraph->GetPlayerDialogueNodes(CurrentNPCNode);

    OnBeginDialogueDelegate.Broadcast(CurrentNPCNode, CurrentPlayerDialogueNodes);

    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("BeginDialogue")));
}

void UAC_DialogueHandler::OnProceedDialogue(const UPlayerDialogueGraphNode* Node)
{
    bIsProceed = true;
    
    if (!DialogueGraph)
    {
        return;
    }

    if (!Node)
    {
        return;
    }
    CurrentNPCNode = nullptr;
    CurrentNPCNode = DialogueGraph->GetNPCDialogueNode(Node);

    if (CurrentNPCNode)
    {
        CurrentPlayerDialogueNodes.Empty();
        CurrentPlayerDialogueNodes = DialogueGraph->GetPlayerDialogueNodes(CurrentNPCNode);

        OnBeginDialogueDelegate.Broadcast(CurrentNPCNode, CurrentPlayerDialogueNodes);
    }

    if (!CurrentNPCNode)
    {
        EndDialogue();
    }
}

void UAC_DialogueHandler::EndDialogue()
{
    OnEndDialogueDelegate.Broadcast();

    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("EndDialogue")));

    DialogueGraph = nullptr;
    bIsProceed = false;
}