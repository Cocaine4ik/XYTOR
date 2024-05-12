// XYTOR. All Rights Reserved.


#include "Core/Detective/AC_ExploringHandler.h"


void UAC_ExploringHandler::Highlight() const
{
    if (!TextComponent) return;

    TextComponent->SetVisibility(true);
}

void UAC_ExploringHandler::DisplayLoading() const
{
    
}

void UAC_ExploringHandler::Detect()
{
    if (TextComponent)
    {
        // Highlight()
    }
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

void UAC_ExploringHandler::UnDetect()
{
}


void UAC_ExploringHandler::Interact(AActor* InteractingActor)
{
    Super::Interact(InteractingActor);
}

void UAC_ExploringHandler::InitDetecting()
{
    if (TextComponent) return;

    AActor* Owner = GetOwner();
    if (!Owner)
    {
        UE_LOG(LogTemp, Error, TEXT("Owner of UAC_Evidence is nullptr"));
        return;
    }
    TextComponent = NewObject<UTextRenderComponent>(Owner, UTextRenderComponent::StaticClass(), TEXT("EvidenceText"));
    if (TextComponent)
    {
        TextComponent->SetText(FText::FromString("Evidence"));
        TextComponent->SetTextRenderColor(FColor::Red);
        TextComponent->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
        TextComponent->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextTop);
        TextComponent->SetRelativeLocation({0,0,50});

        TextComponent->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
        TextComponent->RegisterComponent();
        TextComponent->SetVisibility(true);
    }
    else
        UE_LOG(LogTemp, Error, TEXT("Failed to create TextRenderComponent"));
    
        
}
