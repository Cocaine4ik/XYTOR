// XYTOR. All Rights Reserved.


#include "Core/Dialogues/W_DialogueWindow.h"
#include "DialogueGraph/PlayerDialogueGraphNode.h"
#include "DialogueGraph/NPCDialogueGraphNode.h"
#include "AC_DialogueHandler.h"
#include "W_DialogueLine.h"
#include "Components/VerticalBox.h"
#include "Components/Image.h"
#include "Components/MultiLineEditableText.h"
#include "Components/TextBlock.h"
#include "GameFramework/Character.h"

void UW_DialogueWindow::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    const auto Controller = GetOwningPlayer();
    if (!Controller) return;

    const auto Character = Controller->GetCharacter();
    if (!Character) return;

    DialogueHandler = Character->GetComponentByClass<UAC_DialogueHandler>();
    if (!DialogueHandler) return;
    
    DialogueHandler->OnBeginDialogueDelegate.AddDynamic(this, &UW_DialogueWindow::OnBeginDialogue);
} 

void UW_DialogueWindow::OnBeginDialogue(const UNPCDialogueGraphNode* NPCNode, const TArray<UPlayerDialogueGraphNode*> PlayerDialogueNodes)
{
    if (!NPCNode || !PlayerDialogueLineContainer || !NPCDialogueIcon || !NPCDialogueText) return;

    PlayerDialogueLineContainer->ClearChildren();
    
    const auto NPCIcon = NPCNode->GetVisualData().Icon;
    if (!NPCIcon)
    {
        NPCDialogueIcon->SetBrushFromTexture(NPCIcon);
    }
    
    const auto Text = NPCNode->GetVisualData().DialogueText;
    NPCDialogueText->SetText(Text);

    for (const auto Node : PlayerDialogueNodes)
    {
        const auto PlayerDialogueLineWidget = CreateWidget<UW_DialogueLine>(GetWorld(), DialogueLineClass);
        if (!PlayerDialogueLineWidget) continue;
        
        PlayerDialogueLineWidget->SetDialogueWindow(this);
        PlayerDialogueLineWidget->SetPlayerNode(Node);

        const auto PlayerIcon = Node->GetVisualData().Icon;
        if (PlayerIcon)
        {
            PlayerDialogueLineWidget->SetDialogueIcon(PlayerIcon);
        }

        const auto PlayerText = Node->GetVisualData().DialogueText;
        PlayerDialogueLineWidget->SetDialogueText(PlayerText);

        PlayerDialogueLineContainer->AddChild(PlayerDialogueLineWidget);
    }
}

void UW_DialogueWindow::OnProceedDialogue(const UPlayerDialogueGraphNode* Node)
{
    if (Node)
    {
        DialogueHandler->OnProceedDialogueDelegate.Broadcast(Node);
    }
}

