

#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ToonTanksGameModeBase.h"
UHealthComponent::UHealthComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

}


void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	ToonTankGamemode = Cast<AToonTanksGameModeBase>(UGameplayStatics::GetGameMode(this));
	Health = MaxHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this,&UHealthComponent::DamageTaken);
	
}



void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	GetOwner();

}
void UHealthComponent::DamageTaken(AActor* DamegedActor,float Damage,const UDamageType* DamageType,class AController* Instigator,AActor* DamegeCauser){
	if(Damage<=0.f)return;
	Health -= Damage;
	if(Health<=0 && ToonTankGamemode){
		ToonTankGamemode->ActorDied(DamegedActor);
	}
}
void UHealthComponent::HealHealth(float HealNum)
{
	if(HealNum+Health>=MaxHealth)
	{
		Health=MaxHealth;
	}
	else
	{
		Health+=HealNum;
	}
}
