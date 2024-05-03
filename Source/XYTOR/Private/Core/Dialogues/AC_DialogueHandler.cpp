// XYTOR. All Rights Reserved.

#include "Core/Dialogues/AC_DialogueHandler.h"
#include "PS_Tokens.h"
#include "DialogueGraph/PlayerDialogueGraphNode.h"

// Sets default values for this component's properties
UAC_DialogueHandler::UAC_DialogueHandler()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
    // ...
}

bool UAC_DialogueHandler::InitializeTokens()
{
    if (Tokens) return true;
    
    if (const auto Controller = Cast<AController>(GetOwner()))
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("BeginDialogue")));

        Tokens = Controller->GetPlayerState<APS_Tokens>();

        if (Tokens) return true;
        
    }
    return false;
}

void UAC_DialogueHandler::BeginDialogue(UDialogueGraph* Dialogue)
{
    DialogueGraph = Dialogue;

    if (!DialogueGraph || !InitializeTokens())
    {
        return;
    }

    DialogueGraph->UpdateValidationTags(Tokens->GetTokens());
    
    CurrentNPCNode = DialogueGraph->GetStartDialogueNode();

    CurrentPlayerDialogueNodes = DialogueGraph->GetPlayerDialogueNodes(CurrentNPCNode);

    OnBeginDialogueDelegate.Broadcast(CurrentNPCNode, CurrentPlayerDialogueNodes);

}

void UAC_DialogueHandler::ProceedDialogue(const UPlayerDialogueGraphNode* Node)
{
    if (!DialogueGraph || !Node || !Tokens)
    {
        return;
    }
    
    CurrentNPCNode = nullptr;

    Tokens->UpdateTokens(Node->GetResultData().ResultTags);
    DialogueGraph->UpdateValidationTags(Tokens->GetTokens());
    
    CurrentNPCNode = DialogueGraph->GetNPCDialogueNode(Node);

    if (CurrentNPCNode)
    {
        CurrentPlayerDialogueNodes.Empty();
        CurrentPlayerDialogueNodes = DialogueGraph->GetPlayerDialogueNodes(CurrentNPCNode);

        OnProceedDialogueDelegate.Broadcast(CurrentNPCNode, CurrentPlayerDialogueNodes);
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
}


