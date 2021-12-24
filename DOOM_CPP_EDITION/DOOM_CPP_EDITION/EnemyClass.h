#pragma once
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <windows.h>
using namespace std;
class Enemy
{
public:
	int damage;
	int health;
	string enemyName;
	Enemy()
	{
		health = 100;
		damage = 100;
		enemyName = "Empty";
	}
	virtual void getInfo()
	{
		cout << "Вид монстра - " << enemyName << endl;
		cout << "Урон        - " << damage << endl;
		cout << "Здоровье    - " << health << endl;
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
};
class Demon: virtual public Enemy
{
public:
	Demon()
	{
		enemyName = "ДЕМОН (обыкновенный)";
		damage = 10;
		health = 30;
	}

	~Demon()
	{
		cout << enemyName << " был жестоко разорван на части" << endl;
	}
};
class SuperDemon : virtual public Enemy
{
public:
	SuperDemon()
	{
		enemyName = "ДЕМОН (необыкновенный)";
		damage = 30;
		health = 50;
	}
	~SuperDemon()
	{
		cout << enemyName << " был жестоко разорван на части" << endl;
	}
};