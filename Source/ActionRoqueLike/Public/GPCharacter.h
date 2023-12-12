// UNREAL ENGINE ROQUE LIKE GAME PROJECT 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GPCharacter.generated.h"

UCLASS()
class ACTIONROQUELIKE_API AGPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGPCharacter();

protected:

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* m_SpringArmComp;
	
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* m_CameraComp;
	
	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> m_ProjectileClass;
	UPROPERTY(EditAnywhere,Category="Attack")
	UAnimMontage* m_PrimaryAttackAnim;
	UPROPERTY(EditAnywhere,Category = "Attack")
	UAnimMontage* m_MagicAttackAnim;

	UPROPERTY(VisibleAnywhere)
	class UGPInteractionComponent* m_InteractionComp;

	FTimerHandle m_TimerHandler;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);
	void PrimaryAttack();
	void MagicAttack();
	void PrimaryInteract();

public:	

	UFUNCTION()
	void MontageEvent(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	FRotator GetLookRotation(const FVector& start,const FVector& target) {

		FVector location;
		FRotator rotation;
		FVector endLocation = GetCameraViewPoint(location,rotation);
		FVector direction = (target - start).GetSafeNormal();
		FQuat lookQuat = FQuat::FindBetween(FVector::ForwardVector, direction);
		FRotator lookAtRotation = lookQuat.Rotator();
		return lookAtRotation;
	}

	FVector GetCameraViewPoint(FVector& location, FRotator& rotation) {

		GetController()->GetPlayerViewPoint(location, rotation);
		return  (location + (rotation.Vector() * 100000.f));
	}

};
