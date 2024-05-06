// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IInteractable.h"
#include "Item.h"
#include "Core/Inventory/AC_PickUpHandler.h"
#include "GameFramework/Actor.h"
#include "SceneItem.generated.h"

UCLASS(BlueprintType)
class XYTOR_API ASceneItem : public AActor, public IInteractable
{
public:
    virtual FText GetInteractingText_Implementation() const override;

private:
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere, meta=(ExposeOnSpawn=true))
    FName ItemName;

    // UPROPERTY()
    // UItem* ItemObject = nullptr;
    
    UPROPERTY(BlueprintReadOnly)
    UStaticMeshComponent* MeshComponent;
    UPROPERTY(BlueprintReadOnly)
    UAC_PickUpHandler* InteractComponent;
    
public:
	// Sets default values for this actor's properties
	ASceneItem();
    // UFUNCTION(BlueprintCallable, DisplayName="InitWithItem")
    void Init(const UItem* Item);

    // UFUNCTION(BlueprintCallable, DisplayName="InitWithName")
    void Init(FName Name);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
