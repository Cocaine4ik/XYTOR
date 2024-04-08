// XYTOR. All Rights Reserved.


#include "Core/Dialogues/W_DialogueLine.h"

#include "Components/Image.h"
#include "Components/MultiLineEditableText.h"
#include "Components/TextBlock.h"

void UW_DialogueLine::NativeOnInitialized()
{
    Super::NativeOnInitialized();
}

void UW_DialogueLine::ProceedDialogue()
{
    if (DialogueWindow && PlayerNode)
    {
        DialogueWindow->GetDialogueHandler()->OnProceedDialogueDelegate.Broadcast(PlayerNode);
    }
}

void UW_DialogueLine::SetDialogueIcon(UTexture2D* Icon)
{
    PlayerDialogueIcon->SetBrushFromTexture(Icon);
}

void UW_DialogueLine::SetDialogueText(const FText& Text)
{
    PlayerDialogueText->SetText(Text);
}