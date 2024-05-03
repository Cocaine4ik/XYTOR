// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "GameFramework/Actor.h"
#include "SceneItem.generated.h"

UCLASS(BlueprintType)
class XYTOR_API ASceneItem : public AActor
{
	GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere, meta=(ExposeOnSpawn=true))
    FName ItemName;

    // UPROPERTY()
    // UItem* ItemObject = nullptr;
    
    UPROPERTY(BlueprintReadOnly)
    UStaticMeshComponent* MeshComponent;
public:
	// Sets default values for this actor's properties
	ASceneItem();
    UFUNCTION(BlueprintCallable)
    void Init(const UItem* Item);

    UFUNCTION(BlueprintCallable)
    FName PickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
