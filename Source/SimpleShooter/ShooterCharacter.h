// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
		bool IsDead() const;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	void SpeedUp();
	void SpeedDown();

	void Fire();

	// void LookUp(float AxisValue); 부모클래스에 존재함

private:
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		float SpeedRate = 1.f;

	UPROPERTY(EditDefaultsOnly)
		float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
		float Health = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Gun")
		TSubclassOf<class AGun> GunClass;

	UPROPERTY()
		class AGun* Gun;
};

