// UNREAL ENGINE ROQUE LIKE GAME PROJECT 


#include "GPChest.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

void AGPChest::Interact_Implementation(APawn* intertacter){

	UE_LOG(LogTemp,Display,TEXT("INTERACTED"));
	FText PawnNameText = FText::FromString(intertacter->GetName());
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Blue, PawnNameText.ToString());
}

// Sets default values
AGPChest::AGPChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	BoxCollision->SetupAttachment(Mesh);

	
}

// Called when the game starts or when spawned
void AGPChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGPChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

