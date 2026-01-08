// Copyright GhostLazy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AuraGameModeBase.generated.h"

class UCharacterClassInfo;
/**
 * 
 */
UCLASS()
class MYPROJECT_API AAuraGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaluts")
	TObjectPtr<UCharacterClassInfo> CharacterClassInfo;
};
