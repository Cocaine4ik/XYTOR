// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IInteractable.h"
#include "Item.h"
#include "Core/Inventory/AC_PickUpHandler.h"
#include "GameFramework/Actor.h"
#include "SceneItem.generated.h"

UCLASS(BlueprintType)
class XYTOR_API ASceneItem : public AActor
{
private:
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere, meta=(ExposeOnSpawn=true))
    FName ItemName;
    
    UPROPERTY(BlueprintReadOnly)
    UStaticMeshComponent* MeshComponent;
    
    UPROPERTY(BlueprintReadOnly)
    UAC_PickUpHandler* InteractComponent;
    
    UPROPERTY(BlueprintReadOnly)
    UAC_Interact* InteractConfig;
    
public:
	ASceneItem();
    // UFUNCTION(BlueprintCallable, DisplayName="InitWithItem")
    void Init(const UItem* Item);

    // UFUNCTION(BlueprintCallable, DisplayName="InitWithName")
    void Init(FName Name);

protected:
	virtual void BeginPlay() override;


};
