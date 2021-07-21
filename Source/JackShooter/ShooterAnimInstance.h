// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShooterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class JACKSHOOTER_API UShooterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UShooterAnimInstance();

	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);

	virtual void NativeInitializeAnimation() override;

protected:

	// Handle turn in place variables
	void TurnInPlace();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class AShooterCharacter* ShooterCharacter;

	// The speed of the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement,  meta = (AllowPrivateAccess = "true"))
	float Speed;

	// Whether or not in the air
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bIsInAir;

	// Whether or not moving
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating;

	// Offset Yaw Used for Straifing
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement, meta = (AllowPrivateAccess = "true")) 
	float MovementOffsetYaw;

	// Offset Yaw the Frame before we stopped moving
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float LastMovementOffsetYaw;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bAiming;

	// Yaw of Character this frame 
	float CharacterYaw;

	// Yaw of character's previous frame
	float CharacterYawLastFrame;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turn in Place", meta = (AllowPrivateAccess = "true"))
	float RootYawOffset;

	// The Pitch of aim rotation used for Aim Offset
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turn in Place", meta = (AllowPrivateAccess = "true"))
	float Pitch;

	// True when Reloading used to prevent aim offset while reloading
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turn in Place", meta = (AllowPrivateAccess = "true"))
	bool bReloading;
};
