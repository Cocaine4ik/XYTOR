// XYTOR. All Rights Reserved.


#include "Core/Detective/PC_Detective.h"
#include "Core/Detective/AC_ExploringHandler.h"

void APC_Detective::DetectAll() const
{
    for (const UAC_ExploringHandler* el: DetectiveComponents)
        el->Detect(EvidenceWidgetClass);
}

void APC_Detective::UnDetectAll() const
{
    for (const UAC_ExploringHandler* el: DetectiveComponents)
        el->UnDetect();
}

bool APC_Detective::SetShouldDetect(bool Value)
{
    if (bShouldDetect == Value)
        return bShouldDetect;
    
    bShouldDetect = Value;
    if (bShouldDetect)
        DetectAll();
    else
        UnDetectAll();
    return bShouldDetect;
}

bool APC_Detective::ToggleShouldDetect()
{
    return SetShouldDetect(!bShouldDetect);
}

bool APC_Detective::DetectEvidence(AActor* Actor)
{
    UAC_ExploringHandler* EvidenceComponent = Actor->GetComponentByClass<UAC_ExploringHandler>();
    if(!EvidenceComponent) return false;

    DetectiveComponents.Push(EvidenceComponent);
    if (bShouldDetect)
        EvidenceComponent->Detect(EvidenceWidgetClass);
    return true;
}

bool APC_Detective::UnDetectEvidence(AActor* Actor)
{
    UActorComponent* Component = Actor->GetComponentByClass(UAC_ExploringHandler::StaticClass());
    if(!Component) return false;

    UAC_ExploringHandler* EvidenceComponent = Cast<UAC_ExploringHandler> (Component);
    EvidenceComponent->UnDetect();
    return 0<DetectiveComponents.RemoveSingleSwap(EvidenceComponent);
    
}
