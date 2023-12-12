// UNREAL ENGINE ROQUE LIKE GAME PROJECT 

#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GPCharacter.h"
#include "GPInteractionComponent.h"

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

	m_InteractionComp = CreateDefaultSubobject<UGPInteractionComponent>("Interaction Component");

	GetMesh()->GetAnimInstance()->OnPlayMontageNotifyBegin.AddDynamic(this, &AGPCharacter::MontageEvent);
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

	PlayAnimMontage(m_PrimaryAttackAnim); 

	FVector muzzleLocation = GetMesh()->GetSocketLocation("gun_muzzle");
	FRotator muzzleRotation;

	FVector location;
	FRotator rotation;
	FVector endLocation = GetCameraViewPoint(location,rotation);

	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	FHitResult hit;

	bool anyHit = GetWorld()->LineTraceSingleByChannel(
		hit,
		location, 
		endLocation,
		ECC_Visibility,params);

	if (anyHit) {

		muzzleRotation = GetLookRotation(muzzleLocation,hit.ImpactPoint);
		DrawDebugLine(GetWorld(), location, hit.ImpactPoint, FColor::Blue, false, 1.0f, 0, 1.0f);
	}
	else {
		muzzleRotation = GetLookRotation(muzzleLocation, endLocation);
		DrawDebugLine(GetWorld(), location, endLocation, FColor::Red, false, 1.0f, 0, 1.0f);
	}

	FTransform weaponTransform = FTransform(muzzleRotation, muzzleLocation);
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Instigator = this;
	SpawnParams.Owner = this;
	GetWorld()->SpawnActor<AActor>(m_ProjectileClass, weaponTransform, SpawnParams);

}

void AGPCharacter::MagicAttack(){

	PlayAnimMontage(m_MagicAttackAnim);
}


void AGPCharacter::PrimaryInteract(){

	m_InteractionComp->Interact();
}



void AGPCharacter::MontageEvent(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload){

	if (NotifyName == FName("Special")) {
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green,TEXT("OK"));
	}

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
	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &AGPCharacter::Jump);

	PlayerInputComponent->BindAxis("Turn", this, &AGPCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AGPCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AGPCharacter::PrimaryAttack);
	PlayerInputComponent->BindAction("MagicAttack", IE_Pressed, this, &AGPCharacter::MagicAttack);
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed,this, &AGPCharacter::PrimaryInteract);

}

