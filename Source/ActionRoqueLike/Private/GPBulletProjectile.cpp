// UNREAL ENGINE ROQUE LIKE GAME PROJECT 


#include "GPBulletProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AGPBulletProjectile::AGPBulletProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SphereComp = CreateDefaultSubobject<USphereComponent>("Sphere Component");
	m_SphereComp->SetCollisionProfileName("Projectile");
	RootComponent = m_SphereComp;

	m_Particle = CreateDefaultSubobject<UParticleSystemComponent>("VFX");
	m_Particle->SetupAttachment(m_SphereComp);

	m_ProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Component");
	m_ProjectileComp->InitialSpeed = 3500.f;
	m_ProjectileComp->bRotationFollowsVelocity = true;
	m_ProjectileComp->bInitialVelocityInLocalSpace = true;
	m_ProjectileComp->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void AGPBulletProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGPBulletProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

