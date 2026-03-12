// Copyright GhostLazy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "Interaction/HighlightInterface.h"
#include "Interaction/SaveInterface.h"
#include "MyProject/MyProject.h"
#include "Checkpoint.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class MYPROJECT_API ACheckpoint : public APlayerStart, public ISaveInterface, public IHighlightInterface
{
	GENERATED_BODY()
	
public:
	
	ACheckpoint(const FObjectInitializer& ObjectInitializer);
	
	/* Save Interface Start */
	virtual bool ShouldLoadTransform_Implementation() override { return false; };
	virtual void LoadActor_Implementation() override;
	/* Save Interface End */
	
	UPROPERTY(BlueprintReadWrite, SaveGame)
	bool bReached = false;
	
	UPROPERTY(EditAnywhere)
	bool bBindOverlapCallback = true;
	
protected:
	
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	virtual void BeginPlay() override;
	
	/* Highlight Interface Start */
	virtual void SetMoveToLocation_Implementation(FVector& OutDestination) override;
	virtual void HighlightActor_Implementation() override;
	virtual void UnHighlightActor_Implementation() override;
	/* Highlight Interface End */
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> MoveToComponent;
	
	UPROPERTY()
	int32 CustomDepthStencilOverride = CUSTOM_DEPTH_TAN;
	
	UFUNCTION(BlueprintImplementableEvent)
	void CheckpointReached(UMaterialInstanceDynamic* DynamicMaterialInstance);
	
	UFUNCTION(BlueprintCallable)
	void HandleGlowEffects();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> CheckpointMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent> Sphere;
	
};
