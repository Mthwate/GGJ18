// Fill out your copyright notice in the Description page of Project Settings.

#include "VillageDefenseGameInstance.h"


///////////////////////////////////////////////////////////
// Object Initialization

void UVillageDefenseGameInstance::Init() {

	
	// cost { food, wood, stone }
	BuildingCosts.house = {
		{ 1, 1, 0 },
		{ 2, 2, 0 },
	};

	BuildingCosts.farm = {
		{ 0, 1, 1 },
		{ 0, 2, 2 },
	};

}

FBuildingCosts UVillageDefenseGameInstance::GetBuildingCosts() {
	return BuildingCosts;
}