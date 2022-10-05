// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();
	APlayerController* GetTankPlayerController()const{return PlayerController;};
	bool bAlive = true;
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere,Category = "Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere,Category = "Components")
	class UCameraComponent* Camera;
	void Move(float Value);
	void Turn(float Value);
	UPROPERTY(EditAnywhere,Category = "Movement")
	float Speed=800.0;
	UPROPERTY(EditAnywhere,Category = "Movement")
	float TurnRate=120.0;
	APlayerController* PlayerController;
};
 