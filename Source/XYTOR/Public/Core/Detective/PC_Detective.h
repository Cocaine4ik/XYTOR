// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Interaction/PC_Interaction.h"
#include "PC_Detective.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API APC_Detective : public APC_Interaction
{
	GENERATED_BODY()
    
public:
    UFUNCTION(BlueprintCallable)
    void CheckEvidence(AActor* Actor) const;
    // static void CheckIfEvidence(AActor* Actor);

};
