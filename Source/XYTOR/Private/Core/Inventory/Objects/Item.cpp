// XYTOR. All Rights Reserved.


#include "Core/Inventory/Objects/Item.h"

#include "Core/ExtraTools.h"

bool UItem::Init(FName ItemName)
{
    FS_Item* Data = ExtraTools::GetStructureFromTable<FS_Item>(
        "/Script/Engine.DataTable'/Game/XYTOR/DataTables/Inventory/DT_Items.DT_Items'", ItemName);
    if (Data)
    {
        ItemData = Data;
        return true;
    }
    return false;
}

UItem::UItem(FName ItemName)
{
    Init(ItemName);
}
