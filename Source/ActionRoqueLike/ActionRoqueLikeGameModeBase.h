// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ActionRoqueLikeGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROQUELIKE_API AActionRoqueLikeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AActionRoqueLikeGameModeBase()
	{
		static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ActionRogueLike/Character/Blueprints/BP_ThirdPersonCharacter"));
		if (PlayerPawnBPClass.Class != NULL)
		{
			DefaultPawnClass = PlayerPawnBPClass.Class;
		}
	}
	
};
