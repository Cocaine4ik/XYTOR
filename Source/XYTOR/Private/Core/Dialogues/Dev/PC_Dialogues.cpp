// XYTOR. All Rights Reserved.


#include "Core/Dialogues/Dev/PC_Dialogues.h"

#include "AC_DialogueHandler.h"
#include "Core/Dialogues/W_DialogueWindow.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "DialogueGraph/NPCDialogueGraphNode.h"
#include "DialogueGraph/PlayerDialogueGraphNode.h"
#include "GameFramework/Character.h"

void APC_Dialogues::BeginPlay()
{
    Super::BeginPlay();
    
    const auto DialogueHandler = GetDialogueHandler();
    if (!DialogueHandler) return;
    
    DialogueHandler->OnBeginDialogueDelegate.AddDynamic(this, &APC_Dialogues::OnBeginDialogue);
    DialogueHandler->OnEndDialogueDelegate.AddUniqueDynamic(this, &APC_Dialogues::OnEndDialogue);

    InitializeWidgets();
}

void APC_Dialogues::OnBeginDialogue(const UNPCDialogueGraphNode* NPCNode, const TArray<UPlayerDialogueGraphNode*> PlayerDialogueNodes)
{

    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());

    if (!HUD)
    {
        UE_LOG(LogTemp, Error, TEXT("HUD doesn't exist."));
    }
    
    // if widget created and exists toggle it
    if (DialogueWindowWidget && !GetDialogueHandler()->IsProceed())
    {
        HUD->ToggleNormalWidgetByClass(DialogueWindowWidgetClass);
    }

}

void APC_Dialogues::OnEndDialogue()
{
    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());

    if (!HUD)
    {
        UE_LOG(LogTemp, Error, TEXT("HUD doesn't exist."));
        return;
    }

    HUD->HideCurrentNormalWidget();
}

bool APC_Dialogues::InitializeWidgets()
{
    if(!DialogueWindowWidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No widget class in PC_Dialogues."));
        return false;
    }

    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());

    if (!HUD)
    {
        UE_LOG(LogTemp, Error, TEXT("HUD doesn't exist."));
        return false;
    }
    // if widget is nullptr get it from HUD
    if (!DialogueWindowWidget)
    {
        DialogueWindowWidget = Cast<UW_DialogueWindow>(HUD->GetWidgetByClass(DialogueWindowWidgetClass));
    }

    // if widget doesn't exist in HUD - add widget
    if (!DialogueWindowWidget)
    {
        DialogueWindowWidget = Cast<UW_DialogueWindow>(HUD->AddWidgetByClass(DialogueWindowWidgetClass));
    }

    return true;
}

UAC_DialogueHandler* APC_Dialogues::GetDialogueHandler() const
{
    if (!GetCharacter()) return nullptr;
    
    const auto DialogueHandler = GetCharacter()->GetComponentByClass<UAC_DialogueHandler>();
    return DialogueHandler;
}