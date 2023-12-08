// UNREAL ENGINE ROQUE LIKE GAME PROJECT 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GPInteractableInterface.h"
#include "GPChest.generated.h"

UCLASS()
class ACTIONROQUELIKE_API AGPChest : public AActor, public IGPInteractableInterface
{
	GENERATED_BODY()

	void Interact_Implementation(APawn* intertacter);
	
public:	
	// Sets default values for this actor's properties
	AGPChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class UBoxComponent* BoxCollision;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
