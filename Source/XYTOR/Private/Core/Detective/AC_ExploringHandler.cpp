// XYTOR. All Rights Reserved.


#include "Core/Detective/AC_ExploringHandler.h"


void UAC_ExploringHandler::UnHighlight() const
{
    UE_LOG(LogTemp, Warning, TEXT("Evidance lost"));
    bHighlighted = false;
    ChangeInteractionComponent();
}

void UAC_ExploringHandler::Highlight() const
{
    UE_LOG(LogTemp, Warning, TEXT("Evidance found"));
    bHighlighted = true;
    ChangeInteractionComponent();
}

void UAC_ExploringHandler::DisplayLoading() const
{
    
}

void UAC_ExploringHandler::ChangeInteractionComponent() const
{
    
    UAC_Interact* InteractComponent = Cast<UAC_Interact> (GetOwner()->GetComponentByClass(UAC_Interact::StaticClass()));
    if (!InteractComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("Evidence without AC_Interaction"));
        return;
    }
    if (bHighlighted)
    {
        InteractComponent->SetInteractingText(FText::FromString("Explore"));
        InteractComponent->SetCanInteract(true);
    }
    else
    {
        InteractComponent->SetCanInteract(false);
    }
}

void UAC_ExploringHandler::Detect() const
{
    Highlight();
    if (TextComponent)
        DisplayShortInformation();
}

void UAC_ExploringHandler::UnDetect() const
{
    UnHighlight();
}


void UAC_ExploringHandler::Interact(AActor* InteractingActor)
{
    Super::Interact(InteractingActor);

    if (TextComponent)
        DisplayLoading();
    
    InitDetecting();
    DisplayLongInformation();
}

void UAC_ExploringHandler::InitDetecting()
{
    if (TextComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("Double Initialisation in UAC_ExploringHandler"));
        return;
    }

    AActor* Owner = GetOwner();
    if (!Owner)
    {
        UE_LOG(LogTemp, Error, TEXT("Owner of UAC_Evidence is nullptr"));
        return;
    }
    TextComponent = NewObject<UTextRenderComponent>(Owner, UTextRenderComponent::StaticClass(), TEXT("EvidenceText"));
    if (TextComponent)
    {
        TextComponent->SetTextRenderColor(FColor::Red);
        TextComponent->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
        TextComponent->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextTop);
        TextComponent->SetRelativeLocation({0,0,50});

        TextComponent->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
        TextComponent->RegisterComponent();
    }
    else
        UE_LOG(LogTemp, Error, TEXT("Failed to create TextRenderComponent"));
}


void UAC_ExploringHandler::DisplayShortInformation() const
{
    TextComponent->SetText(ShortInfo);
    TextComponent->SetVisibility(true);
}

void UAC_ExploringHandler::DisplayLongInformation() const
{
    TextComponent->SetText(LongInfo);
    TextComponent->SetVisibility(true);
}
