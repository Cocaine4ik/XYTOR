// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/ExtraTools.h"
#include "Core/Inventory/Objects/Item.h"
#include "Objects/Ammo.h"
#include "Objects/Weapon.h"
#include "AC_Inventory.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryChanged, const UItem*, UpdatedItem, int32, Count);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemShareDelegate, UItem*, Item);

USTRUCT()
struct FCounterItem
{
    GENERATED_BODY()
    UPROPERTY()
    UItem* Value;
    int32 Count;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XYTOR_API UAC_Inventory : public UActorComponent
{
public:
    virtual void BeginPlay() override;

private:
    GENERATED_BODY()

private:
    void CallDelegateIfChanged(UItem* Item, int32 Count) const;
    UItem*& GetActiveItemSlotByType(EE_ItemType ItemType);
    UItem*& GetActiveItemSlotByType(const UItem* ItemType);

protected:
    UPROPERTY()
    TArray<FCounterItem> Storage;

    UPROPERTY()
    TArray<UItem*> ActiveItems; 
    
    FCounterItem* GetCounterByName(FName ItemName);
    const FCounterItem* GetCounterByName(FName ItemName) const;

    FCounterItem* GetCounterByName(FName ItemName, uint32 &Index);
    const FCounterItem* GetCounterByName(FName ItemName, uint32 &Index) const;

public:
	UAC_Inventory();
    
    UFUNCTION()
    void ActivateItem(UItem* Item);
    UFUNCTION()
    void DeactivateItem(UItem* Item);
    
    UFUNCTION(BlueprintCallable)
    uint8 AddItem(FName ItemName, uint8 Count);
    UFUNCTION(BlueprintCallable)
    uint8 RemoveItem(FName ItemName, uint8 Count);
    UFUNCTION(BlueprintCallable)
    bool Contains(FName ItemName, uint8 Count) const;
    UFUNCTION(BlueprintCallable)
    int32 GetCountOfItem(FName ItemName) const;

    UFUNCTION(BlueprintCallable)
    void AddItemByPointer(UItem* Item, int32 Count);
    UFUNCTION(BlueprintCallable)
    void RemoveItemByPointer(UItem* Item, int32 Count);

    const TArray<FCounterItem>& GetItems() const;
    
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    FOnInventoryChanged OnInventoryChanged;
    FItemShareDelegate OnItemActivated, OnItemDeactivated;
};
