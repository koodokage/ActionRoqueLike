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
	
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnCollisionHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	class URadialForceComponent* RadialForceComponent;
	
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Mesh;


};
