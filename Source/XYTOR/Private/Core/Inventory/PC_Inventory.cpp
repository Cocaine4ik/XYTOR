// XYTOR. All Rights Reserved.


#include "Core/Inventory/PC_Inventory.h"

#include "Core/WidgetManager/HUD_WidgetManager.h"

class AHUD_WidgetManager;

void APC_Inventory::BeginPlay()
{
    Super::BeginPlay();
    INIT_WIDGET_IN_BEGIN_PLAY(PC_Inventory, UW_InventoryBase, InventoryWidgetClass, InventoryWidget);
}

void APC_Inventory::DisplayInventory() const
{
    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager> (GetHUD());
    if(HUD)
    {
        HUD->ToggleNormalWidgetByClass(InventoryWidgetClass);
    }
}
