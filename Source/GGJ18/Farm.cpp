// Fill out your copyright notice in the Description page of Project Settings.

#include "Farm.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

AFarm::AFarm() {

	ProductionRate = 2.5f;
}

void AFarm::Tick(float DeltaTime) {

}

float AFarm::GetProductionRate() {
	return ProductionRate;
}

void AFarm::SetProductionRate(float Amount) {
	ProductionRate = FMath::Clamp(Amount, 0.0f, Amount);
}