// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"
#include "Components/CapsuleComponent.h"
#include "Tank.h"
#include "HealthComponent.h"
// Sets default values
AHealingItem::AHealingItem()
{
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh"));
	ItemMesh ->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHealingItem::BeginPlay()
{
	Super::BeginPlay();
	ItemMesh->OnComponentHit.AddDynamic(this,&AHealingItem::OnHit);
}

// Called every frame
void AHealingItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AHealingItem::OnHit(UPrimitiveComponent* HitComp,AActor* OtherActor,UPrimitiveComponent* OtherComp,FVector NormalImpluse,const FHitResult& Hit)
{
	if(OtherActor && OtherActor->GetClass()->IsChildOf(ATank::StaticClass())){
		TArray<UHealthComponent* > MyHealth;
		OtherActor->GetComponents(MyHealth,true);
		MyHealth[0]->HealHealth(HealNum);
		Destroy();
	}
}