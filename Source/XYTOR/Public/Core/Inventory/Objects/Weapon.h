// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "UObject/NoExportTypes.h"
#include "Weapon.generated.h"

/**
 * Base class for Weapon. It provides compatibility with inventory system. 
 */
UCLASS(BlueprintType)
class XYTOR_API UWeapon : public UItem
{
	GENERATED_BODY()
	
};
