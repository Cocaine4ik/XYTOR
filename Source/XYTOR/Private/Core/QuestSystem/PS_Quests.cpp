// XYTOR. All Rights Reserved.


#include "Core/QuestSystem/PS_Quests.h"

#include "Core/QuestSystem/Structures/S_Quest.h"

void APS_Quests::FinishQuest(uint8 Index)
{
    CompletedQuests.Push(AvailableQuests[Index]);
    AvailableQuests.RemoveAt(Index);
}

void APS_Quests::UpdateQuests(EE_SubquestType Type)
{
    for (uint8 i=0; i<AvailableQuests.Num(); i++)
        if (AvailableQuests[i]->Update(Type))
        {
            OnQuestChanged.Broadcast(AvailableQuests[i]);
            if (AvailableQuests[i]->IsCompleted())
                FinishQuest(i--); // Increment is only for TArray
        }
}

void APS_Quests::AddQuest(FName QuestName)
{
    UQuest* Quest = NewObject<UQuest>(UQuest::StaticClass());
    if (Quest)
    {
        AvailableQuests.Push(Quest);
        OnQuestChanged.Broadcast(Quest);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No such quest"));
    }
}

void APS_Quests::TokensChanged()
{
    UpdateQuests(EE_SubquestType::Token);
}

void APS_Quests::ItemsChanged()
{
    UpdateQuests(EE_SubquestType::Item);
}
