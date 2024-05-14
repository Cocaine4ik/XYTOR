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
    UPROPERTY(EditAnywhere)
    FText LongInfo;
    UPROPERTY(EditAnywhere)
    FText ShortInfo;
    
    UPROPERTY()
    UTextRenderComponent* TextComponent = nullptr;
    mutable bool bHighlighted = false;
    FTimerHandle TimerHandler;

    void FirstInteraction();
    
    void UnHighlight() const;
    void Highlight() const;
    float DisplayLoading() const;
    void InitDetecting();

    void DisplayShortInformation() const;
    void DisplayLongInformation() const;
    void ChangeInteractionComponent() const;
public:
    void Detect() const;
    void UnDetect() const;

    virtual void Interact(AActor* InteractingActor) override;
};
