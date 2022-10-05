// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealingItem.generated.h"

UCLASS()
class TOONTANKS_API AHealingItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealingItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere,BluePrintReadOnly,Category = "Components",meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere,BluePrintReadOnly,Category = "Components",meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ItemMesh;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp,AActor* OtherActor,UPrimitiveComponent* OtherComp,FVector NormalImpluse,const FHitResult& Hit);
	UPROPERTY(EditAnywhere,Category = "Combat")
	float HealNum = 50.f;
};
