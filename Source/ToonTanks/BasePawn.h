// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	void HandleDestruction();
protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();
private:
	UPROPERTY(VisibleAnywhere,BluePrintReadOnly,Category = "Components",meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere,BluePrintReadOnly,Category = "Components",meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere,BluePrintReadOnly,Category = "Components",meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere,BluePrintReadOnly,Category = "Components",meta = (AllowPrivateAccess = "true"))
	class USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(EditDefaultsOnly,Category = "Combat",meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AProjectile> ProjectileClass;
	UPROPERTY(EditAnywhere,Category = "Combat")
	class UParticleSystem* DeathExplosionParticle;
	UPROPERTY(EditAnywhere,Category = "Combat")
	class USoundBase* DeathSound;
	UPROPERTY(EditAnywhere,Category = "Combat")
	TSubclassOf<class UCameraShakeBase> DeadCameraShakeClass;
};
