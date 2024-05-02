// XYTOR. All Rights Reserved.


#include "Core/Dialogues/AC_Dialogue.h"

#include "AC_DialogueHandler.h"

// Sets default values for this component's properties
UAC_Dialogue::UAC_Dialogue()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;

    InteractingText = FText::FromString(TEXT("Talk (E)"));
}

void UAC_Dialogue::Interact(AActor* InteractingActor)
{
    Super::Interact(InteractingActor);

    if (!InteractingActor) return;

    const auto DialogueHandler = InteractingActor->GetComponentByClass<UAC_DialogueHandler>();
    if(!DialogueHandler) return;

    DialogueHandler->BeginDialogue(DialogueGraph);
}