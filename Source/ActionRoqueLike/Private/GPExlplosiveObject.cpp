// UNREAL ENGINE ROQUE LIKE GAME PROJECT 


#include "GPExlplosiveObject.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGPExlplosiveObject::AGPExlplosiveObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh Component");
	RootComponent = Mesh;
	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("Radial Force Component");
	RadialForceComponent->SetupAttachment(Mesh);


}

// Called when the game starts or when spawned
void AGPExlplosiveObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGPExlplosiveObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

