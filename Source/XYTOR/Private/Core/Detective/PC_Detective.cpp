// XYTOR. All Rights Reserved.


#include "Core/Detective/PC_Detective.h"

#include "Core/Detective/AC_ExploringHandler.h"

void APC_Detective::CheckEvidence(AActor* Actor) const
{
    UActorComponent* Component = Actor->GetComponentByClass(UAC_ExploringHandler::StaticClass());
    if(!Component) return;

    UAC_ExploringHandler* EvidenceComponent = Cast<UAC_ExploringHandler> (Component);
    EvidenceComponent->Detect();
}
