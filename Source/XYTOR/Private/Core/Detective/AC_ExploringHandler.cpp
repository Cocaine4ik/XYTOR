// XYTOR. All Rights Reserved.


#include "Core/Detective/AC_ExploringHandler.h"


void UAC_ExploringHandler::Detect()
{
    InitDetecting();
    
    TextComponent->SetVisibility(true);
    UAC_Interact* InteractComponent = Cast<UAC_Interact> (GetOwner()->GetComponentByClass(UAC_Interact::StaticClass()));
    if (!InteractComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("Evidence without AC_Interaction"));
        return;
    }
    InteractComponent->SetInteractingText(FText::FromString("Explore"));
    InteractComponent->SetCanInteract(true);
}

void UAC_ExploringHandler::Explore()
{
}

void UAC_ExploringHandler::Interact(AActor* InteractingActor)
{
    Super::Interact(InteractingActor);
}

void UAC_ExploringHandler::InitDetecting()
{
    if (TextComponent) return;
    UE_LOG(LogTemp, Error, TEXT("Check"));
    TextComponent = GetOwner()->CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text render"));
    TextComponent->SetText(FText::FromString("##################################"));
    TextComponent->SetTextRenderColor(FColor::Red);
    TextComponent->SetVisibility(true);
}
