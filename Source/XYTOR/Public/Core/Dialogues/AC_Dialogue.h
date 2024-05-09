// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_InteractionHandler.h"
#include "DialogueGraph/DialogueGraph.h"
#include "AC_Dialogue.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XYTOR_API UAC_Dialogue : public UAC_InteractionHandler
{
    GENERATED_BODY()
    
    //FTestBool Test;
public:
    // Sets default values for this component's properties
    UAC_Dialogue();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogues System")
    UDialogueGraph* DialogueGraph;

public:
    UFUNCTION(Blueprintable)
    UDialogueGraph* GetDialogue() const { return DialogueGraph; }
    
    UFUNCTION(Blueprintable)
    void SetDialogue(UDialogueGraph* Dialogue) { DialogueGraph = Dialogue; }
    
    virtual void Interact(AActor* InteractingActor) override;
};
