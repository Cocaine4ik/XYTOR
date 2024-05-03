// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Interaction/AC_Interact.h"
#include "AC_Item.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XYTOR_API UAC_Item : public UAC_Interact
{
    GENERATED_BODY()

public:
    UAC_Item();
    
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
    TMap<FName, int32> Items;
    
    virtual void Interact(AActor* InteractingActor) override;
};