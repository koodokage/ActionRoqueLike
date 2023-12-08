// UNREAL ENGINE ROQUE LIKE GAME PROJECT 

#include "GPCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AGPCharacter::AGPCharacter(){
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;


	m_SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component");
	m_SpringArmComp->SetupAttachment(RootComponent);
	m_SpringArmComp->TargetArmLength = 550.f;
	m_SpringArmComp->bUsePawnControlRotation = true;

	m_CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	m_CameraComp->SetupAttachment(m_SpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;

}

// Called when the game starts or when spawned
void AGPCharacter::BeginPlay(){
	Super::BeginPlay();
	
}

void AGPCharacter::MoveForward(float value){

	FRotator rotation = GetControlRotation();
	rotation.Roll = 0.f;
	rotation.Pitch = 0.f;

	AddMovementInput(rotation.Vector(), value);
}

void AGPCharacter::MoveRight(float value){
	
	FRotator rotation = GetControlRotation();
	rotation.Roll = 0.f;
	rotation.Pitch = 0.f;

	FVector rightVector = FRotationMatrix(rotation).GetScaledAxis(EAxis::Y);

	AddMovementInput(rightVector, value);
}

void AGPCharacter::PrimaryAttack(){

	FVector muzzleLocation = GetMesh()->GetSocketLocation("gun_muzzle");
	FRotator muzzleRotation  = GetMesh()->GetSocketRotation("gun_muzzle");

	FTransform weaponTransform = FTransform(muzzleRotation, muzzleLocation);
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(m_ProjectileClass,weaponTransform,SpawnParams);
}

// Called every frame
void AGPCharacter::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGPCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGPCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AGPCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AGPCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed,this, &AGPCharacter::PrimaryAttack);
	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &AGPCharacter::Jump);

}

