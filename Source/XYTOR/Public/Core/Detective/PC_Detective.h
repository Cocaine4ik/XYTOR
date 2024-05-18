// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_ExploringHandler.h"
#include "Core/Interaction/PC_Interaction.h"
#include "PC_Detective.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API APC_Detective : public APC_Interaction
{
	GENERATED_BODY()

protected:
    UPROPERTY()
    TArray<UAC_ExploringHandler*> DetectiveComponents;
    UPROPERTY(BlueprintReadOnly)
    bool bShouldDetect = false;

    void DetectAll() const;
    void UnDetectAll() const;
public:
    UFUNCTION(BlueprintCallable)
    bool SetShouldDetect(bool Value);
    UFUNCTION(BlueprintCallable)
    bool ToggleShouldDetect();
    UFUNCTION(BlueprintCallable)
    bool DetectEvidence(AActor* Actor);
    UFUNCTION(BlueprintCallable)
    bool UnDetectEvidence(AActor* Actor);
    // static void CheckIfEvidence(AActor* Actor);

};
