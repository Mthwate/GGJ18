// Fill out your copyright notice in the Description page of Project Settings.

#include "VillageDefenseGameInstance.h"

///////////////////////////////////////////////////////////
// Constants
const int UVillageDefenseGameInstance::DEFAULTWIDTH = 6;
const int UVillageDefenseGameInstance::DEFAULTHEIGHT = 25;


///////////////////////////////////////////////////////////
// Object Initialization

void UVillageDefenseGameInstance::Init() {
	// Init the Grid
	for (int i = 0; i < DEFAULTWIDTH; i++) {
		Grid.Add(TArray<ABuilding*>());
		for (int j = 0; j < DEFAULTHEIGHT; j++) {
			Grid[i].Add(NULL);
		}
	}

	
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


//////////////////////////////////////////////////////////
// Getters and Setters

int UVillageDefenseGameInstance::GetFood() {
	return Food;
}

void UVillageDefenseGameInstance::SetFood(int Amount) {
	Food = FMath::Clamp(Amount, 0, GetMaxFood());
}

void UVillageDefenseGameInstance::AddFood(int Amount) {
	SetFood(Food + Amount);
}

void UVillageDefenseGameInstance::LoseFood(int Amount) {
	SetFood(Food - Amount);
}

int UVillageDefenseGameInstance::GetMaxFood() {
	return 9999; // Stub!
}

int UVillageDefenseGameInstance::GetWood() {
	return Wood;
}

void UVillageDefenseGameInstance::SetWood(int Amount) {
	Wood = FMath::Clamp(Amount, 0, GetMaxWood());
}

void UVillageDefenseGameInstance::AddWood(int Amount) {
	SetWood(Wood + Amount);
}

void UVillageDefenseGameInstance::LoseWood(int Amount) {
	SetWood(Wood - Amount);
}

int UVillageDefenseGameInstance::GetMaxWood() {
	return 9999; // Stub!
}

int UVillageDefenseGameInstance::GetStone() {
	return Stone;
}

void UVillageDefenseGameInstance::SetStone(int Amount) {
	Stone = FMath::Clamp(Amount, 0, GetMaxStone());
}

void UVillageDefenseGameInstance::AddStone(int Amount) {
	SetStone(Stone + Amount);
}

void UVillageDefenseGameInstance::LoseStone(int Amount) {
	SetStone(Stone - Amount);
}

int UVillageDefenseGameInstance::GetMaxStone() {
	return 9999; // Stub!
}

int UVillageDefenseGameInstance::GetPeople() {
	return People;
}

void UVillageDefenseGameInstance::SetPeople(int Amount) {
	People = FMath::Clamp(Amount, 0, GetMaxPeople());
}

void UVillageDefenseGameInstance::AddPeople(int Amount) {
	SetPeople(People + Amount);
}

void UVillageDefenseGameInstance::LosePeople(int Amount) {
	SetPeople(People - Amount);
}

int UVillageDefenseGameInstance::GetMaxPeople() {
	return 999; // Stub!
}

FBuildingCosts UVillageDefenseGameInstance::GetBuildingCosts() {
	return BuildingCosts;
}

ABuilding* UVillageDefenseGameInstance::GetBuildingAtLocation(int X, int Y) {
	return Grid[X][Y];
}

void UVillageDefenseGameInstance::PlaceBuilding(ABuilding* Building, int X, int Y, int Width, int Height) {
	if (CheckGrid(X, Y, Width, Height)) { // Check if the Building Can Be Placed
		// Add the Building to the List
		BuildingList.Add({ Building, X, Y });
		// Add the Building the Grid
		for (int i = X; i < X + Width; i++) {
			for (int j = Y; j < Y + Height; j++) {
				Grid[i][j] = Building;
			}
		}
	}
}

bool UVillageDefenseGameInstance::CheckGrid(int X, int Y, int Width, int Height) {
	if ((X + Width) >= DEFAULTWIDTH || (Y + Height) >= DEFAULTHEIGHT) {
		return false;
	} else {
		for (int i = X; i < X + Width; i++) {
			for (int j = Y; j < Y + Height; j++) {
				if (Grid[i][j] != NULL) {
					return false;
				}
			}
		}
		return true;
	}
}

int UVillageDefenseGameInstance::GetGridWidth() {
	return DEFAULTWIDTH;
}

int UVillageDefenseGameInstance::GetGridHeight() {
	return DEFAULTHEIGHT;
}