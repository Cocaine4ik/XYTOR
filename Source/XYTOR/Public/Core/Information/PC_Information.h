// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "W_InformationBase.h"
#include "Core/Player/PC_Base.h"
#include "Interfaces/IPC_Information.h"
#include "PC_Information.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class XYTOR_API APC_Information : public APC_Base, public IIPC_Information
{
protected:

    UPROPERTY(EditDefaultsOnly, Category="Widgets")
    TSubclassOf<UW_InformationBase> InformationWidgetClass;
    
public:

    virtual void BeginPlay() override;
    
    UFUNCTION(BlueprintCallable)
    virtual void DisplayInformation_Implementation() const override;

private:
    GENERATED_BODY()

};
