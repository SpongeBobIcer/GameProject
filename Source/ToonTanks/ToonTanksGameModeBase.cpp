// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Turret.h" 
#include "ToonTanksPlayerController.h"
void AToonTanksGameModeBase::ActorDied(AActor* DeadActor)
{
    if(DeadActor == Tank){
        Tank->HandleDestruction();
        if(ToonTanksPlayerController){
            Tank->DisableInput(Tank->GetTankPlayerController());
            ToonTanksPlayerController->SetPlayerEnabledState(false);
        }
        GameOver(false);
    }
    else if(ATurret* DestoryedTurret = Cast<ATurret>(DeadActor))
    {
        DestoryedTurret->HandleDestruction();
        --TargetTurrets;
        if(TargetTurrets==0){
            GameOver(true);
        }
    }
}
void AToonTanksGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    HandleGameStart();
}
void AToonTanksGameModeBase::HandleGameStart()
{   
    TargetTurrets = GetTargetTurretCount();
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
    ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this,0));
    StartGame();
    if(ToonTanksPlayerController)
    {
        ToonTanksPlayerController->SetPlayerEnabledState(false);
        FTimerHandle PlayerEnableTimerHandle;
        FTimerDelegate PlayerEnabledDelegate = FTimerDelegate::CreateUObject(
            ToonTanksPlayerController,
            &AToonTanksPlayerController::SetPlayerEnabledState,
            true
        );
        GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle,
            PlayerEnabledDelegate,
            StartDelay,
            false
        );
    }    
}
int32 AToonTanksGameModeBase::GetTargetTurretCount()
{
    TArray<AActor*> Turrets;
    UGameplayStatics::GetAllActorsOfClass(this,ATurret::StaticClass(),Turrets);
    return Turrets.Num();
}