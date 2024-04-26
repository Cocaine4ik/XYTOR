// XYTOR. All Rights Reserved.


#include "Core/Inventory/PC_Inventory.h"

#include "Core/Inventory/PS_Inventory.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"

class AHUD_WidgetManager;

void APC_Inventory::BeginPlay()
{
    Super::BeginPlay();
    INIT_WIDGET_IN_BEGIN_PLAY(PC_Inventory, UW_InventoryBase, InventoryWidgetClass, InventoryWidget);
    APS_Inventory* PS = GetPlayerState<APS_Inventory>();
    if (PS)
    {
        PS->GetInventory()->OnInventoryChanged.AddUniqueDynamic(InventoryWidget, &UW_InventoryBase::UpdateItem);
        PS->GetInventory()->OnItemActivated.AddUniqueDynamic(InventoryWidget, &UW_InventoryBase::UW_InventoryBase::ActivateItem);
        PS->GetInventory()->OnItemDeactivated.AddUniqueDynamic(InventoryWidget, &UW_InventoryBase::UW_InventoryBase::DeactivateItem);
        
        InventoryWidget->OnItemRemoved.BindUObject(PS->GetInventory(), &UAC_Inventory::RemoveItemByPointer);
        InventoryWidget->OnItemActivated.BindUObject(PS->GetInventory(), &UAC_Inventory::ActivateItem);
        InventoryWidget->OnItemDeactivated.BindUObject(PS->GetInventory(), &UAC_Inventory::DeactivateItem);

        
    }
    
}

void APC_Inventory::DisplayInventory() const
{
    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager> (GetHUD());
    if(HUD)
    {
        HUD->ToggleNormalWidgetByClass(InventoryWidgetClass);
    }
}
