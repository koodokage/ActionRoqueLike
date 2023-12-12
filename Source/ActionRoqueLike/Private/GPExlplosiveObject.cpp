// UNREAL ENGINE ROQUE LIKE GAME PROJECT 


#include "GPExlplosiveObject.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGPExlplosiveObject::AGPExlplosiveObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh Component");
	RootComponent = Mesh;

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("Radial Force Component");
	RadialForceComponent->SetupAttachment(Mesh);

}

void AGPExlplosiveObject::PostInitializeComponents(){
	Super::PostInitializeComponents();
	Mesh->OnComponentHit.AddDynamic(this,&AGPExlplosiveObject::OnCollisionHit);
	UE_LOG(LogTemp, Display, TEXT("INITIALIZED"));

}


void AGPExlplosiveObject::OnCollisionHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit){

	UE_LOG(LogTemp,Display,TEXT("HITTED"));
	FString combinedText = FString::Printf(TEXT("LOCATION : %s"),*Hit.ImpactPoint.ToString());
	DrawDebugString(GetWorld(),Hit.ImpactPoint,combinedText,nullptr,FColor::Red);
}