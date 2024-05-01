// XYTOR. All Rights Reserved.


#include "Core/Interaction/PC_Interaction.h"

#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "Core/Interaction/AC_Interact.h"
#include "VectorTypes.h"
#include "Core/Interaction/IInteractable.h"
#include "GameFramework/Character.h"

class AHUD_WidgetManager;

void APC_Interaction::BeginPlay()
{
    Super::BeginPlay();
    if(!InteractionWidgetClass)
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
    if (CurrentObjectIndex<0) return;
    
    UActorComponent* HandlerComponent = this->GetComponentByClass(IInteractable::Execute_GetHandlerClass(ObjectsToInteract[CurrentObjectIndex]));
    if (HandlerComponent)
    {
        Cast<UAC_Interact>(HandlerComponent)->Interact(ObjectsToInteract[CurrentObjectIndex]);
        return;
    }
    HandlerComponent = AddComponentByClass(IInteractable::Execute_GetHandlerClass(ObjectsToInteract[CurrentObjectIndex]), false, FTransform::Identity,false);
    if (HandlerComponent)
    {
        Cast<UAC_Interact>(HandlerComponent)->Interact(ObjectsToInteract[CurrentObjectIndex]);
    }
}

void APC_Interaction::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    if (ObjectsToInteract.IsEmpty()) return;

    int8 MinInd = 0;
    double Min = UE::Geometry::DistanceSquared(GetCharacter()->GetActorLocation(), ObjectsToInteract[0]->GetActorLocation());
    for (int8 i=1; i<ObjectsToInteract.Num(); ++i)
    {
        const double Dist = UE::Geometry::DistanceSquared(GetCharacter()->GetActorLocation(), ObjectsToInteract[i]->GetActorLocation());
        if (Dist<Min)
        {
            MinInd = i;
            Min = Dist;
        }
    }
    if (MinInd!=CurrentObjectIndex)
    {
        CurrentObjectIndex = MinInd;
        InteractionBase->UpdateMessage(IInteractable::Execute_GetInteractingText(ObjectsToInteract[CurrentObjectIndex]));
    }
}

bool APC_Interaction::AddActor(AActor* NewActor)
{
    if (!NewActor->Implements<UInteractable>())
        return false;

    ObjectsToInteract.Push(NewActor);
    return true;
}

bool APC_Interaction::RemoveActor(AActor* TargetActor)
{
    if (!TargetActor->Implements<UInteractable>())
        return false;
    
    const int32 IndexToRemove = ObjectsToInteract.Find(TargetActor);
    if (IndexToRemove == CurrentObjectIndex)
    {
        CurrentObjectIndex = -1;
        InteractionBase->CleanMessage();
    }
    else if (CurrentObjectIndex == ObjectsToInteract.Num()-1)
        CurrentObjectIndex = IndexToRemove;
    else if (IndexToRemove < CurrentObjectIndex)
        --CurrentObjectIndex;

    ObjectsToInteract.RemoveAtSwap(IndexToRemove);
    return true;
}
