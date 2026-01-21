// Copyright GhostLazy

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/PlayerInterface.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AAuraCharacter : public AAuraCharacterBase, public IPlayerInterface
{
	GENERATED_BODY()
public:
	AAuraCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/* Player Interface Start */
	virtual void AddToXP_Implementation(int32 InXP) override;
	virtual void LevelUp_Implementation() override;
	/* Player Interface End */
	
	/* Combat Interface Start */
	virtual int32 GetPlayerLevel_Implementation() override;
	/* Combat Interface End */
private:
	virtual void InitAbilityActorInfo() override;
};
