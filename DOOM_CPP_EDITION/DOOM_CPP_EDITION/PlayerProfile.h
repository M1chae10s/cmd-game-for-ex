#pragma once
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include "Story.h"
using namespace std;
class Player
{

public:
	int health;
	int damage;
	int lvl;
	string playerName;

	
	Player()
	{
		playerName = "empty";
		health = 100;
		damage = 25;
	}
	Player(string playerName)
	{
		this->playerName = playerName;
	}
	int getHealth()
	{
		return health;
	}
	int getDamage()
	{
		return damage;
	}
	void setHealth(int health)
	{
		this->health = health;
	}
	void setDamage(int damage)
	{
		this->damage = damage;
	}
	void attack()
	{
		cout << playerName << "Хладнокровно избивает монстра и наносит " << damage << " единиц урона\n";

	}
	virtual void getInfo()
	{
		cout << "Имя героя - " << playerName << endl;
		cout << "Урон        - " << damage << endl;
		cout << "Здоровье    - " << health << endl;
	}
};
