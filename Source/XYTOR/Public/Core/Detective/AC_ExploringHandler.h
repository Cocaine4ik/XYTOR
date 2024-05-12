// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_InteractionHandler.h"
#include "Components/TextRenderComponent.h"
#include "Core/Interaction/AC_Interact.h"
#include "AC_ExploringHandler.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class XYTOR_API UAC_ExploringHandler : public UAC_InteractionHandler
{
    GENERATED_BODY()

protected:
    UPROPERTY()
    UTextRenderComponent* TextComponent = nullptr;
    void Highlight() const;
    void DisplayLoading() const;
    void InitDetecting();
public:
    void Detect();
    void UnDetect();

    virtual void Interact(AActor* InteractingActor) override;
};
