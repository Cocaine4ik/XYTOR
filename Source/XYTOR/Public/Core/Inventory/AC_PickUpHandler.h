// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_InteractionHandler.h"
#include "AC_PickUpHandler.generated.h"

class ASceneItem;
/**
 * 
 */
UCLASS()
class XYTOR_API UAC_PickUpHandler : public UAC_InteractionHandler
{
    GENERATED_BODY()

    friend ASceneItem;
protected:
    UPROPERTY(VisibleAnywhere)
    FName ItemName;
public:
    virtual void Interact(AActor* InteractingActor) override;
};
