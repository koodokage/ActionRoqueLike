// UNREAL ENGINE ROQUE LIKE GAME PROJECT 

#include "GPCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AGPCharacter::AGPCharacter(){
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component");
	m_SpringArmComp->SetupAttachment(RootComponent);
	m_CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	m_CameraComp->SetupAttachment(m_SpringArmComp);

}

// Called when the game starts or when spawned
void AGPCharacter::BeginPlay(){
	Super::BeginPlay();
	
}

void AGPCharacter::MoveForward(float value){

	AddMovementInput(GetActorForwardVector(), value);
}

// Called every frame
void AGPCharacter::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGPCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &AGPCharacter::AddControllerYawInput);
	APlayerController* controller = Cast<APlayerController>(GetController());
	ULocalPlayer* localPlayer = controller->GetLocalPlayer();



}

