// Copyright GhostLazy

#pragma once

#include "CoreMinimal.h"
#include "Checkpoint/Checkpoint.h"
#include "MapEntrance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMapEntrance : public ACheckpoint
{
	GENERATED_BODY()
	
public:
	
	AMapEntrance(const FObjectInitializer& ObjectInitializer);
	
	/* Highlight Interface Start */
	virtual void HighlightActor_Implementation() override;
	/* Highlight Interface End */
	
	/* Save Interface Start */
	virtual void LoadActor_Implementation() override;
	/* Save Interface End */
	
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> DestinationMap;
	
	UPROPERTY(EditAnywhere)
	FName DestinationPlayerStartTag;
	
protected:
	
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                             const FHitResult& SweepResult) override;
	
};
