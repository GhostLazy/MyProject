// Copyright GhostLazy


#include "AbilitySystem/Abilities/Electrocute.h"

FString UElectrocute::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	
	return FString::Printf(TEXT(
		"<Title>ELECTROCUTE</>\n\n"
			
		"<Small>Level: </><Level>%d</>\n"
		"<Small>Mana Cost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
		"<Default>Emits a beam of lightning, connecting with the target, propagating to %d additional targets nearby, repeatedly causing: </><Damage>%d</><Default> lightning damage with a chance to stun</>"),
		
		Level, ManaCost, Cooldown, FMath::Min(Level - 1, MaxNumShockTargets), ScaledDamage);
}

FString UElectrocute::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	
	return FString::Printf(TEXT(
		"<Title>NEXT LEVEL</>\n\n"
			
		"<Small>Level: </><Level>%d</>\n"
		"<Small>Mana Cost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
		"<Default>Emits a beam of lightning, connecting with the target, propagating to %d additional targets nearby, repeatedly causing: </><Damage>%d</><Default> lightning damage with a chance to stun</>"),
		
		Level, ManaCost, Cooldown, FMath::Min(Level - 1, MaxNumShockTargets), ScaledDamage);
}
