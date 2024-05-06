// XYTOR. All Rights Reserved.


#include "Core/Inventory/Objects/SceneItem.h"

#include "Core/ExtraTools.h"

FText ASceneItem::GetInteractingText_Implementation() const
{
    return FText::FromString("Pick up");
}

// Sets default values
ASceneItem::ASceneItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    InteractComponent = CreateDefaultSubobject<UAC_PickUpHandler>(TEXT("AC_PickUpHandler"));
}

void ASceneItem::Init(const UItem* Item)
{
    InteractComponent->ItemName = ItemName = Item->GetItemName();
    MeshComponent->SetStaticMesh(Item->GetItemData().Mesh);
}

void ASceneItem::Init(FName Name)
{
    InteractComponent->ItemName = ItemName = Name;
    if (const FS_Item* Data = ExtraTools::GetStructureFromTable<FS_Item>("/Script/Engine.DataTable'/Game/XYTOR/DataTables/Inventory/DT_Items.DT_Items'", ItemName))
    {
        MeshComponent->SetStaticMesh(Data->Mesh);
    }
}

// Called when the game starts or when spawned
void ASceneItem::BeginPlay()
{
	Super::BeginPlay();
    InteractComponent->ItemName = ItemName;
}

// Called every frame
void ASceneItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

