// Copyright GhostLazy


#include "Actor/AuraEnemySpawnPoint.h"
#include "Character/AuraEnemy.h"

void AAuraEnemySpawnPoint::SpawnEnemy()
{
	if (AAuraEnemy* Enemy = GetWorld()->SpawnActorDeferred<AAuraEnemy>(EnemyClass, GetActorTransform(), nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn))
	{
		Enemy->SetLevel(EnemyLevel);
		Enemy->SetCharacterClass(CharacterClass);
		Enemy->FinishSpawning(GetActorTransform());
		Enemy->SpawnDefaultController();	//手动生成AI控制器
	}
}
