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
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> m_ProjectileClass;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);
	void PrimaryAttack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
