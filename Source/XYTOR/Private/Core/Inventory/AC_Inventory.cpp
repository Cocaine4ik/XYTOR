// XYTOR. All Rights Reserved.


#include "Core/Inventory/AC_Inventory.h"

// Sets default values for this component's properties
UAC_Inventory::UAC_Inventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_Inventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

ExtraTools::Counter<UItem*>* UAC_Inventory::GetCounterByName(FName ItemName)
{
    for (auto& Counter: Storage)
    {
        if (Counter.Value->GetItemName()==ItemName)
            return &Counter;
    }
    return nullptr;
}

const ExtraTools::Counter<UItem*>* UAC_Inventory::GetCounterByName(FName ItemName) const
{
    for (const auto& Counter: Storage)
    {
        if (Counter.Value->GetItemName()==ItemName)
            return &Counter;
    }
    return nullptr;
}

uint8 UAC_Inventory::AddItem(FName ItemName, uint8 Count)
{
    ExtraTools::Counter<UItem*>* Counter = GetCounterByName(ItemName);
    if (Counter)
        Counter->Count+=Count;
    else
    {
        UItem* Item = UItem::MakeItem(ItemName);
        if (!Item)
            return 0;
        
        Storage.Push({Item, Count});
        return Count;
    }
    return Count;
}

uint8 UAC_Inventory::RemoveItem(FName ItemName, uint8 Count)
{
    ExtraTools::Counter<UItem*>* Counter = GetCounterByName(ItemName);
    Count = FMath::Min(Counter->Count, StaticCast<int32>(Count));
    Counter->Count-=Count;    
    return Count;
}

bool UAC_Inventory::Contains(FName ItemName, uint8 Count) const
{
    return GetCounterByName(ItemName)!=nullptr;
}

int32 UAC_Inventory::GetCountOfItem(FName ItemName) const
{
    const ExtraTools::Counter<UItem*>* Counter = GetCounterByName(ItemName);
    if (Counter)
        return Counter->Count;
    return 0;
}

void UAC_Inventory::AddItemByPointer(UItem* ItemName, int32 Count)
{
    AddItem(ItemName->GetItemName(), Count);
}

void UAC_Inventory::RemoveItemByPointer(UItem* ItemName, int32 Count)
{
    RemoveItem(ItemName->GetItemName(), Count);
}

const TArray<ExtraTools::Counter<UItem*>>& UAC_Inventory::GetItems() const
{
    return Storage;
}


// Called every frame
void UAC_Inventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

