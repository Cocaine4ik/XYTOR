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

    // Получить указатель на владельца этого компонента
    AActor* Owner = GetOwner();

    if (Owner)
    {
        // Создать новый экземпляр компонента UTextRenderComponent
        TextComponent = NewObject<UTextRenderComponent>(Owner, UTextRenderComponent::StaticClass(), TEXT("EvidenceText"));

        if (TextComponent)
        {
            // Установить текст и другие параметры компонента
            TextComponent->SetText(FText::FromString("Evidence"));
            TextComponent->SetTextRenderColor(FColor::Red);
            TextComponent->SetVisibility(true);
            TextComponent->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
            TextComponent->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextTop);
            TextComponent->SetRelativeLocation({0,0,100});

            // Добавить новый компонент к владельцу
            TextComponent->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
            TextComponent->RegisterComponent();
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to create TextRenderComponent"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Owner of UAC_Evidence is nullptr"));
    }
    
}
