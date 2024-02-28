// XYTOR. All Rights Reserved.


#include "Core/QuestSystem/Objects/Quest.h"

#include "Core/QuestSystem/Structures/S_Quest.h"

bool UQuest::Init(FName QuestName)
{
    static FString QuestTablePath = "/Script/Engine.DataTable'/Game/XYTOR/DataTables/QuestSystem/DT_Quests.DT_Quests'";

    // Load the DataTable asset
    UDataTable* QuestTable = LoadObject<UDataTable>(nullptr, *QuestTablePath);

    // Check if the DataTable is loaded successfully
    if (QuestTable)
    {
        NameInTable=QuestName;
        FS_Quest* QuestData = QuestTable->FindRow<FS_Quest>(QuestName, "");
        Title = QuestData->Title;
        Description = QuestData->Description;

        for (auto SubquestInfo: QuestData->Subquests)
        {
            Subquests.Push(USubquest::MakeSubquest(SubquestInfo, this));
        }
    }
    else
    {
        // Handle the case where loading the DataTable failed
        UE_LOG(LogTemp, Error, TEXT("Failed to load DataTable: %s"), *QuestTablePath);
    }

    return false;
}

UQuest::UQuest(FName QuestName)
{
    Init(QuestName);
}

bool UQuest::IsCompleted() const
{
    return CurrentSubquest>=Subquests.Num();
}

bool UQuest::Update(EE_SubquestType Type)
{
    if (Subquests[CurrentSubquest]->Update(Type))
    {
        ++CurrentSubquest;
        return true;
    }

    return false;
}

const FText& UQuest::GetTitle() const
{
    return Title;
}

const FText& UQuest::GetDescription() const
{
    return Description;
}

const FName& UQuest::GetNameInTable() const
{
    return NameInTable;
}

const TArray<USubquest*>& UQuest::GetSubquests() const
{
    return Subquests;
}
