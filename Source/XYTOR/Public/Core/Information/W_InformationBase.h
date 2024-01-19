// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/WidgetManager/Widgets/W_NormalBase.h"
#include "W_InformationBase.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API UW_InformationBase : public UW_NormalBase
{
	GENERATED_BODY()
protected:
    UPROPERTY(BlueprintReadOnly, Category="W_InformationBase")
    TArray<FName> Entities;
public:
    void SetEntities(const TArray<FName>& NewEntities);
};