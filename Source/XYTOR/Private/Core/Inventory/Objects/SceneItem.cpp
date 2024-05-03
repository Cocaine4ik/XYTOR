// XYTOR. All Rights Reserved.


#include "Core/Inventory/Objects/SceneItem.h"

#include "Core/ExtraTools.h"

// Sets default values
ASceneItem::ASceneItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    if (const FS_Item* Data = ExtraTools::GetStructureFromTable<FS_Item>("/Script/Engine.DataTable'/Game/XYTOR/DataTables/Inventory/DT_Items.DT_Items'", ItemName))
    {
        UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
        MeshComponent->SetStaticMesh(Data->Mesh);
    }
}

void ASceneItem::Init(const UItem* Item)
{
    //ItemObject = Item;
    ItemName = Item->GetItemName();
    MeshComponent->SetStaticMesh(Item->GetItemData().Mesh);
}

FName ASceneItem::PickUp()
{
    const FName Result = ItemName;
    BeginDestroy();
    return Result;
}

// Called when the game starts or when spawned
void ASceneItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASceneItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

