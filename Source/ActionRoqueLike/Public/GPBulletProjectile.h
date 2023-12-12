// UNREAL ENGINE ROQUE LIKE GAME PROJECT 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GPBulletProjectile.generated.h"

UCLASS()
class ACTIONROQUELIKE_API AGPBulletProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGPBulletProjectile();

protected:

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class USphereComponent* m_SphereComp;
	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* m_ProjectileComp;
	UPROPERTY(VisibleAnywhere)
	class UParticleSystemComponent* m_Particle;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
