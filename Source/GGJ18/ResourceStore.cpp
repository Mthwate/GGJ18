// Fill out your copyright notice in the Description page of Project Settings.

#include "ResourceStore.h"


ResourceStore::ResourceStore()
{
}

// FOOD

int ResourceStore::GetFood() {
	return FMath::Clamp(Food, 0, GetMaxFood());
}

void ResourceStore::SetFood(int Amount) {
	Food = FMath::Clamp(Amount, 0, GetMaxFood());
}

int ResourceStore::GetMaxFood() {
	return MaxFood;
}

// WOOD

int ResourceStore::GetWood() {
	return FMath::Clamp(Wood, 0, GetMaxWood());
}

void ResourceStore::SetWood(int Amount) {
	Wood = FMath::Clamp(Amount, 0, GetMaxWood());
}

int ResourceStore::GetMaxWood() {
	return MaxWood;
}

// STONE

int ResourceStore::GetStone() {
	return FMath::Clamp(Stone, 0, GetMaxStone());
}

void ResourceStore::SetStone(int Amount) {
	Stone = FMath::Clamp(Amount, 0, GetMaxStone());
}

int ResourceStore::GetMaxStone() {
	return MaxStone;
}

// PEOPLE

int ResourceStore::GetPeople() {
	return FMath::Clamp(People, 0, GetMaxPeople());
}

void ResourceStore::SetPeople(int Amount) {
	People = FMath::Clamp(Amount, 0, GetMaxPeople());
}

int ResourceStore::GetMaxPeople() {
	return MaxPeople;
}