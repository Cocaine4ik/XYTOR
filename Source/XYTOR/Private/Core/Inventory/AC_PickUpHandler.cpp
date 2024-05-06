// XYTOR. All Rights Reserved.


#include "Core/Inventory/AC_PickUpHandler.h"

#include "Core/Inventory/PC_Inventory.h"

void UAC_PickUpHandler::Interact(AActor* InteractingActor)
{
    Super::Interact(InteractingActor);
    Cast<APC_Inventory>(InteractingActor)->PickUpItem(ItemName);
    GetOwner()->Destroy();
}
