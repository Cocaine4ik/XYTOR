// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/ExtraTools.h"
#include "Core/Inventory/Objects/Item.h"
#include "AC_Inventory.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryChanged, const UItem*, UpdatedItem, int32, Count);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XYTOR_API UAC_Inventory : public UActorComponent
{
	GENERATED_BODY()

protected:
    TArray<ExtraTools::Counter<UItem*>> Storage;
    
public:	
	// Sets default values for this component's properties
	UAC_Inventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    ExtraTools::Counter<UItem*>* GetCounterByName(FName ItemName);
    const ExtraTools::Counter<UItem*>* GetCounterByName(FName ItemName) const;
    
public:
    UFUNCTION(BlueprintCallable)
    uint8 AddItem(FName ItemName, uint8 Count);
    UFUNCTION(BlueprintCallable)
    uint8 RemoveItem(FName ItemName, uint8 Count);
    UFUNCTION(BlueprintCallable)
    bool Contains(FName ItemName, uint8 Count) const;
    UFUNCTION(BlueprintCallable)
    int32 GetCountOfItem(FName ItemName) const;

    UFUNCTION(BlueprintCallable)
    void AddItemByPointer(UItem* ItemName, int32 Count);
    UFUNCTION(BlueprintCallable)
    void RemoveItemByPointer(UItem* ItemName, int32 Count);

    const TArray<ExtraTools::Counter<UItem*>>& GetItems() const;
    
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    FOnInventoryChanged OnInventoryChanged;
};
