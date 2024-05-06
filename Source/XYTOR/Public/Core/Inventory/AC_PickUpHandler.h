// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Interaction/AC_Interact.h"
#include "AC_PickUpHandler.generated.h"

class ASceneItem;
/**
 * 
 */
UCLASS()
class XYTOR_API UAC_PickUpHandler : public UAC_Interact
{
    GENERATED_BODY()

    friend ASceneItem;
protected:
    UPROPERTY(VisibleAnywhere)
    FName ItemName;
public:
    virtual void Interact(AActor* InteractingActor) override;
};
