// XYTOR. All Rights Reserved.


#include "Core/Interaction/PC_Interaction.h"
#include "Core/Interaction/AC_InteractionHandler.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "Core/Interaction/AC_Interact.h"
#include "VectorTypes.h"
#include "GameFramework/Character.h"

class AHUD_WidgetManager;

void APC_Interaction::BeginPlay()
{
    Super::BeginPlay();

    if (!InteractionWidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No widget class in PC_Information"));
    }
    else
    {
        AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());
        if (HUD)
        {
            UW_Base* temp = HUD->AddWidgetByClass(InteractionWidgetClass);
            InteractionBase = Cast<UW_InteractionBase>(temp);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("HUD is not correct"));
        }
    }
}

void APC_Interaction::Interact()
{
    if (CurrentObjectIndex<0 || CurrentObjectIndex>=ObjectsToInteract.Num()) return;
    
    // Check for null actor
    const auto* CurrentActor = ObjectsToInteract[CurrentObjectIndex];
    if (!CurrentActor) return;
    
    // Iterate over handlers and interact with each handler
    auto InteractOverHandlers = [this](const auto& Handlers){
        if (!Handlers.IsEmpty())
        {
            for (const auto Handler : Handlers)
            {
                Handler->Interact(this);
            }
        }
    };

    const UAC_Interact* InteractComponent = CurrentActor->GetComponentByClass<UAC_Interact>();
    if (!InteractComponent || !InteractComponent->CanInteract())
        return;
    
    // Get specific handlers setup from BP
    InteractOverHandlers(InteractComponent->GetHandlers());

    // If Handlers aren't empty, then we've already made interaction with specific handlers setup
    // So we don't need default
    // if (!Handlers.IsEmpty()) return;

    // Default handlers setup, get all handlers
    // CurrentActor->GetComponents<UAC_Interact>(Handlers);
    // InteractOverHandlers(Handlers);
    
}

void APC_Interaction::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    if (ObjectsToInteract.IsEmpty())
    {
        return;
    }

    int8 MinInd = 0;
    double Min = UE::Geometry::DistanceSquared(GetCharacter()->GetActorLocation(), ObjectsToInteract[0]->GetActorLocation());
    for (int8 i = 1; i < ObjectsToInteract.Num(); ++i)
    {
        const double Dist = UE::Geometry::DistanceSquared(GetCharacter()->GetActorLocation(), ObjectsToInteract[i]->GetActorLocation());
        if (Dist < Min)
        {
            MinInd = i;
            Min = Dist;
        }
    }
    if (MinInd != CurrentObjectIndex)
    {
        CurrentObjectIndex = MinInd;
        
        InteractionBase->UpdateMessage(GetInteractText(ObjectsToInteract[CurrentObjectIndex]));
    }
}

bool APC_Interaction::AddActor(AActor* NewActor)
{
    if (!NewActor->GetComponentByClass(UAC_Interact::StaticClass()))
    {
        return false;
    }

    ObjectsToInteract.Push(NewActor);
    return true;
}

bool APC_Interaction::RemoveActor(AActor* TargetActor)
{
    if (!TargetActor->GetComponentByClass(UAC_Interact::StaticClass()))
    {
        return false;
    }

    const int32 IndexToRemove = ObjectsToInteract.Find(TargetActor);
    if (IndexToRemove == CurrentObjectIndex)
    {
        CurrentObjectIndex = -1;
        InteractionBase->CleanMessage();
    }
    else if (CurrentObjectIndex == ObjectsToInteract.Num() - 1)
    {
        CurrentObjectIndex = IndexToRemove;
    }
    else if (IndexToRemove < CurrentObjectIndex)
    {
        --CurrentObjectIndex;
    }

    ObjectsToInteract.RemoveAtSwap(IndexToRemove);
    return true;
}

bool APC_Interaction::CanInteract(const AActor* TargetActor)
{
    return IsValid(TargetActor->GetComponentByClass(UAC_Interact::StaticClass()));
}

FText APC_Interaction::GetInteractText(const AActor* TargetActor)
{
    return TargetActor->GetComponentByClass<UAC_Interact>()->GetInteractingText();
}
