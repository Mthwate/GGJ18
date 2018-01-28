// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GGJ18_API ResourceStore
{

public:
	ResourceStore();

	int GetFood();
	void SetFood(int Amount);
	int GetMaxFood();

	int GetWood();
	void SetWood(int Amount);
	int GetMaxWood();

	int GetStone();
	void SetStone(int Amount);
	int GetMaxStone();

	int GetPeople();
	void SetPeople(int Amount);
	int GetMaxPeople();

private:
	int Food;
	int MaxFood;

	int Wood;
	int MaxWood;

	int Stone;
	int MaxStone;

	int People;
	int MaxPeople;
};
