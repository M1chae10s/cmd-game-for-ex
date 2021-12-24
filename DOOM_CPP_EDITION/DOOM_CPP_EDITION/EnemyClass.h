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
		cout << "��� ������� - " << enemyName << endl;
		cout << "����        - " << damage << endl;
		cout << "��������    - " << health << endl;
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
		enemyName = "����� (������������)";
		damage = 10;
		health = 30;
	}

	~Demon()
	{
		cout << enemyName << " ��� ������� �������� �� �����" << endl;
	}
};
class SuperDemon : virtual public Enemy
{
public:
	SuperDemon()
	{
		enemyName = "����� (��������������)";
		damage = 30;
		health = 50;
	}
	~SuperDemon()
	{
		cout << enemyName << " ��� ������� �������� �� �����" << endl;
	}
};