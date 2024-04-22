// XYTOR. All Rights Reserved.


#include "Core/Inventory/W_InventoryBase.h"

void UW_InventoryBase::UpdateItem(const UItem* Item, int32 Count)
{
    if (Count>0)
        AddItem(Item, Count);
    else
        RemoveItem(Item, -Count);
}

void UW_InventoryBase::RemoveItemFromInventory(UItem* Item, int32 Count)
{
    OnItemRemoved.ExecuteIfBound(Item, Count);
}

void UW_InventoryBase::ActivateItemInInventory(UItem* Item, bool IsActivated)
{
    OnItemActivate.ExecuteIfBound(Item, IsActivated);
}


void UW_InventoryBase::RemoveItem_Implementation(const UItem* Item, int32 Count)
{
}

void UW_InventoryBase::AddItem_Implementation(const UItem* Item, int32 Count)
{
}
