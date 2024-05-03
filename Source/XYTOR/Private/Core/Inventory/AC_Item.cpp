// XYTOR. All Rights Reserved.


#include "Core/Inventory/AC_Item.h"
#include "Core/Inventory/PS_Inventory.h"

UAC_Item::UAC_Item()
{
    InteractingText = FText::FromString(TEXT("Pick up (E)"));
}

void UAC_Item::Interact(AActor* InteractingActor)
{
    Super::Interact(InteractingActor);

    if (!InteractingActor) return;

    const auto Controller = Cast<AController>(InteractingActor);
    if (!Controller) return;

    const auto PlayerState = Controller->GetPlayerState<APS_Inventory>();
    if (!PlayerState) return;
    
    for (const auto& Item : Items)
    {
        PlayerState->GetInventory()->AddItem(Item.Key, Item.Value);
    }
}