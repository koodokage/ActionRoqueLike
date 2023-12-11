// UNREAL ENGINE ROQUE LIKE GAME PROJECT 


#include "GPInteractionComponent.h"
#include "GPInteractableInterface.h"

// Sets default values for this component's properties
UGPInteractionComponent::UGPInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGPInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UGPInteractionComponent::Interact(){

	FCollisionObjectQueryParams queryParams;
	queryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* owner = GetOwner();

	FVector eyeLocation;
	FRotator eyeRotation;
	owner->GetActorEyesViewPoint(eyeLocation,eyeRotation);
	FVector end = eyeLocation + (eyeRotation.Vector() * 1000);

	//LINE TRACE
	//FHitResult hitResult;
	//GetWorld()->LineTraceSingleByObjectType(hitResult,eyeLocation,end,queryParams);
	AActor* hitActor;

	//if (hitActor != nullptr){

	//	if (hitActor->Implements<UGPInteractableInterface>()) {

	//		APawn* pawn = Cast<APawn>(owner);
	//		IGPInteractableInterface::Execute_Interact(hitActor, pawn);
	//		DrawDebugLine(GetWorld(), eyeLocation, end, FColor::Green, false, .5f, 0, 1);
	//		return;
	//	}
	//}

	//DrawDebugLine(GetWorld(),eyeLocation,end,FColor::Red,false,.5f,0,1);


	//SPHERE TRACE
	TArray<FHitResult> hits;
	FCollisionShape collisionShape;
	collisionShape.SetSphere(30.f);
	GetWorld()->SweepMultiByObjectType(hits, eyeLocation, end, FQuat::Identity, queryParams, collisionShape);

	for (FHitResult result : hits)
	{
		hitActor = result.GetActor();
		if (hitActor != nullptr) {

			if (hitActor->Implements<UGPInteractableInterface>()) {

				APawn* pawn = Cast<APawn>(owner);
				IGPInteractableInterface::Execute_Interact(hitActor, pawn);
				DrawDebugSphere(GetWorld(),result.ImpactPoint,30.f,10,FColor::Green,false,.5f,0U,1);
				continue;
			}
		}

		DrawDebugSphere(GetWorld(), result.ImpactPoint, 30.f, 10, FColor::Red, false, .5f, 0U, 1);
	}



}


// Called every frame
void UGPInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

