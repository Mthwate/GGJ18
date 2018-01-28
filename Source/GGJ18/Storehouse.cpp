// Fill out your copyright notice in the Description page of Project Settings.

#include "Storehouse.h"

AStorehouse::AStorehouse() {
	FoodCapacity = 15;
	WoodCapacity = 15;
	StoneCapacity = 15;
}

int AStorehouse::GetFoodCapacity() {
	return FoodCapacity;
}

int AStorehouse::GetWoodCapacity() {
	return WoodCapacity;
}

int AStorehouse::GetStoneCapacity() {
	return StoneCapacity;
}