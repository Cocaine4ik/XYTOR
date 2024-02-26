// XYTOR. All Rights Reserved.


#include "Core/QuestSystem/PC_Quests.h"

#include "Core/QuestSystem/PS_Quests.h"


class AHUD_WidgetManager;

void APC_Quests::BeginPlay()
{
    Super::BeginPlay();
    if(!QuestListWidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No widget class in PC_Energy"));
    }

    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());
    QuestListWidget = Cast<UW_QuestListBase>(HUD->AddWidgetByClass(QuestListWidgetClass));
    if (!QuestListWidget)
    {
        UE_LOG(LogTemp, Error, TEXT("QuestListWidget was not created: %s"), *QuestListWidgetClass->GetName());
    }
    
    if (APS_Quests* PS_Quests = Cast<APS_Quests>(GetPlayerState<APS_Quests>()))
    {
        PS_Quests->OnQuestChanged.AddUniqueDynamic(QuestListWidget, &UW_QuestListBase::UpdateQuest);
    }
}
