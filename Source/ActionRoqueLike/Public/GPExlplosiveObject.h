// UNREAL ENGINE ROQUE LIKE GAME PROJECT 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GPExlplosiveObject.generated.h"

UCLASS()
class ACTIONROQUELIKE_API AGPExlplosiveObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGPExlplosiveObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	class URadialForceComponent* RadialForceComponent;
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
