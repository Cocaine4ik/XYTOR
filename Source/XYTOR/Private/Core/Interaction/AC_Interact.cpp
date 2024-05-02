// XYTOR. All Rights Reserved.


#include "Core/Interaction/AC_Interact.h"

// Sets default values for this component's properties
UAC_Interact::UAC_Interact()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_Interact::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_Interact::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAC_Interact::Interact(AActor* InteractingActor)
{
}



