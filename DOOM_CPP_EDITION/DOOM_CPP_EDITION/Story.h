#pragma once
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <windows.h>
#include "PlayerProfile.h"
#include "EnemyClass.h"
#include "SaveAndLoad.h"
using namespace std;

class Story: virtual public Enemy, virtual public Player
{
public:
	int choise;
	int enemyID;
	Demon _demon;
	SuperDemon _sDemon;
	Player _player;
	SaveAndLoad _saveAndLoad;
Story(){}
virtual void LVL(int lvl)
{
	switch (lvl)
	{
	case 0:
	{
		cout << "-------------------����� ���� �������-------------------\n\n";
		Sleep(2000);
		cout << "------------------������� 0: ����������-----------------\n\n\n";
		Sleep(4000);
		cout << "����� �� ������:\n\t������� ��� �����������...\n";
		Sleep(3000);
		cout << "\t����...";
		Sleep(2000);
		cout << "\n\t� ��� ������� - �� �� �������\n";
		Sleep(2000);
		cout << "\t����� �������� ��� ���������� �������� � ��������� ���� ��������� �������, ��������?\n\n1 - ��\n2 - ���\n��: ";
		cin >> choise;
		if (choise == 2)
		{
			Sleep(1000);
			cout << "\n\t��, �������� �����...\n";
			Sleep(2000);
			cout << "\t��... ��� ����, �� �� ������� ���� �������...";
			Sleep(3000);
			exit;
		}
		Sleep(1000);
		cout << "\n\t�������! ��������� �������������,\n";
		Sleep(2000);
		cout << "\t����� ���� ������������\n";
		Sleep(2000);
		cout << "\t����� ��������, ����� � ������ ������� �������\n";
		Sleep(2000);
		cout << "\t(��� ��� ��� ���� �������)\n";
		Sleep(2000);
		cout << "\t��������� �� ������!\n";
		Sleep(2000);
		cout << "\t...\n";
		Sleep(2000);
		cout << "\t������ ���� ������� ������������.\n";
		Sleep(1000);
		cout << "\n---�������������---\n";
		cout << "����������, ���� ����� ";
		cin >> _player.playerName;
		Sleep(1000);
		cout << "\n\n\t�� ������, " << _player.playerName;
		Sleep(2000);
		cout << "\n\t� ���� ������ ���������� ���\n";
		Sleep(2000);
		cout << "\t�� �� �����, ���������\n";
		Sleep(2000);
		cout << "\t...\n";
		Sleep(2000);
		cout << "\t�� ��� �� ������������?\n";
		Sleep(2000);
		cout << "\t��, ��...\n";
		Sleep(2000);
		cout << "\t...���...���...\n";
		Sleep(2000);
		cout << "\t������� ��� �����������\n";
		Sleep(2000);
		cout << "\t�������� �� ������� ���� � ������\n";
		Sleep(2000);
		cout << "\t��� ����� �� �������, ��� ������� � �������\n";
		Sleep(2000);
		cout << "\t�� ����� ���� ������ �����\n";
		Sleep(2000);
		cout << "\t�� ��� ������ ���� ������...\n";
		Sleep(2000);
		cout << "\t����...\n\t..."<<_player.playerName;
		Sleep(3000);
		cout << "\n\n-------------------������� 0 ��������-------------------\n\n";
		cout << "1 - ����������� � ����������\n2 - ����������� � �����\n3 - ����� ��� ����������\n��� �����: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			_saveAndLoad.Save(_player.playerName, 1, _player.health);
			cout << "\n\n-----------------���������� ������������----------------\n\n";
			Sleep(2000);
			cout << "\n\n--------------������� �� ��������� �������--------------\n\n";
			LVL(1);
			break;
		}
		case 2:
		{	
			_saveAndLoad.Save(_player.playerName, 1, _player.health);
			cout << "\n\n-----------------���������� ������������----------------\n\n";
			Sleep(2000);
			cout << "\n\n----------------------����� �� ����---------------------\n\n";
			Sleep(2000);
			exit;
		}
		case 3:
		{
		cout << "\n\n----------------------����� �� ����---------------------\n\n";
		Sleep(2000);
			exit;
		}
		}
		break;
	}
	case 1:
	{
		Sleep(2000);
		cout << "\n\n\n----------------������� 1: ������ ��������--------------\n\n\n";
		Sleep(3000);
		cout << "\t����, ��� ����� ��� �������,\n";
		Sleep(2000);
		cout << "\t������� ��� ��������...\n";
		Sleep(2000);
		cout << "\t...\n";
		Sleep(2000);
		cout << "\t������� ��� ������ �������� ���� ������ �� �����)\n";
		Sleep(2000);
		cout << "\t�������\n";
		Sleep(2000);
		cout << "\t����, "<<playerName<<" ������������ ����� ������ ������ � ��������������� ���������\n";
		Sleep(2000);
		cout << "\t����� �� ���� ��������\n";
		Sleep(2000);
		srand(time(0));
		choise = rand() % 2 + 1;
		switch (choise)
		{
		case 1:
		{
			_demon.getInfo();
			enemyID = 1;
			break;

		}
		case 2:
		{
			_sDemon.getInfo();
			enemyID = 2;
			break;
		}
		}
		cout << "\n\t�� � ������ �� ��������� ����������...\n";
		Sleep(2000);
		cout << "\t��� �� �� ���������?\n\n---�������� ���������� ��������---\n1 - ��������� ����������� ������� ������ ����\n2 - �������� � �����������\n��� �����: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			Sleep(2000);
			if (enemyID == 1)
			{
				cout << "\n\n�� ������������� ������� ����������\n";
				_demon.setHealth(_demon.getHealth() - _player.getDamage());
				_player.setHealth(_player.getHealth() - _demon.getDamage());
				Sleep(2000);
				cout << "�� ������� " << _player.getDamage() << " ������ �����\n";
				Sleep(2000);
				cout << "� " << _demon.enemyName << " �������� " << _demon.getHealth() << " ������ ��������\n";
				Sleep(2000);
				cout <<  _demon.enemyName << " ���� ��� " << _demon.getDamage() << " ������ �����\n";
				Sleep(2000);
				cout << "� " << _player.playerName << " �������� " << _player.getHealth() << " ������ ��������";
				Sleep(2000);
				cout << "���� " << _demon.enemyName << " �������, �� ��������� ���";
				_demon.~Demon();
			}
			else
			{
				cout << "\n\n�� ������������� ������� ����������\n";
				_sDemon.setHealth(_sDemon.getHealth() - _player.getDamage());
				_player.setHealth(_player.getHealth() - _sDemon.getDamage());
				Sleep(2000);
				cout << "�� ������� " << _player.getDamage() << " ������ �����\n";
				Sleep(2000);
				cout << "� " << _sDemon.enemyName << " �������� " << _sDemon.getHealth() << " ������ ��������";
				Sleep(2000);
				cout << _sDemon.enemyName << " ���� ��� " << _sDemon.getDamage() << " ������ �����\n";
				Sleep(2000);
				cout << "� " << _player.playerName << " �������� " << _player.getHealth() << " ������ ��������";
				Sleep(2000);
				cout << "���� " << _sDemon.enemyName << " �������, �� ��������� ���";
				_sDemon.~SuperDemon();
			}

		}
		case 2:
		{
			Sleep(2000);
			if (enemyID == 1)
				cout << playerName << " ��� ������� � ���������� " << _demon.enemyName;
			else
				cout << playerName << " ��� ������� � ���������� " << _sDemon.enemyName;
			end();
		}
		}
		Sleep(2000);
		cout << "\n\n\t������� ������, " << _player.playerName << " ���������� � ��������� �����\n";
		Sleep(2000);
		cout << "\t� ������ ������ �� ������� ������������ ������, ������� � �������������...\n\t������� �� �� �������� � ����?\n\n";
		cout << "---�������� ���������� ��������---\n1 - �������� � ������\n2 - ���������\n��� �����: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			Sleep(2000);
			cout << "\n\n\t�� �������� � ������...";
			Sleep(2000);
			cout << "\n\n-------------------������� 1 ��������-------------------\n\n";
			cout << "1 - ����������� � ����������\n2 - ����������� � �����\n3 - ����� ��� ����������\n��� �����: ";
			cin >> choise;
			Sleep(3000);
			switch (choise)
			{
			case 1:
			{
				_saveAndLoad.Save(_player.playerName, 2, _player.health);
				cout << "\n\n-----------------���������� ������������----------------\n\n";
				Sleep(2000);
				cout << "\n\n--------------������� �� ��������� �������--------------\n\n";
				LVL(2);
				break;
			}
			case 2:
			{
				_saveAndLoad.Save(_player.playerName, 2, _player.health);
				cout << "\n\n-----------------���������� ������������----------------\n\n";
				Sleep(2000);
				cout << "\n\n----------------------����� �� ����---------------------\n\n";
				Sleep(2000);
				exit;
				break;
			}
			case 3:
			{
				cout << "\n\n----------------------����� �� ����---------------------\n\n";
				Sleep(2000);
				exit;
				break;
			}
			}
			break;
		}
		case 2:
		{
			Sleep(2000);
			cout << "\n\n\t�� �� �������� � ������ � �������� 10 ���...\n";
			Sleep(2000);
			cout << "\t...������������ �� ���� �������\n";
			Sleep(3000);
			end();
			break;
		}
		}
		break;
	}
	case 2:
	{
		Sleep(2000);
		cout << "\n\n\n----------------������� 2: � ���� �����--------------\n\n\n";
		Sleep(2000);
		cout << "\t����� �������� �� ����� ������� ������� ��������� ����\n";
		Sleep(2000);
		cout << "\t� ���� ������������� ���� ���� ������� �� ��������� ����\n";
		Sleep(2000);
		cout << "\t������ � ������ �������� �������� ��������� ����\n";
		Sleep(2000);
		cout << "\t� ��� ��������� ��� ��������, � � ����� � ���� ������ ����������� � ���� �����������\n";
		Sleep(2000);
		cout << "\t� ��� � ����� ������� �������� � UNITY\n";
		Sleep(2000);
		cout << "\t� ��� � ���� 127 �������� ������� �� ���� UNITY � ��������...� � � ��� ������������)\n";
		Sleep(2000);
		cout << "\t� ��� ����� 1:17, � ���� ��� ��������� ��������� ������ � ����������� Windows Froms\n";
		Sleep(2000);
		cout << "\t� ��� ��� �� ����� ����� �� ���������\n";
		Sleep(2000);
		cout << "\t� ��� � ���� �����\n";
		Sleep(2000);
		cout << "\t� ������ ���, ���������� 'Sleep', � ��� ������� ���� �����\n";
		Sleep(2000);
		cout << "\t� ��� ��� ������ ���� �������� �������\n";
		Sleep(2000);
		cout << "\t��������� ����\n";
		Sleep(2000);
		break;
		end();
	}
	}
}
void end()
{
	cout << "\n\n\n\n----------------���� ��������!--------------\n";
	Sleep(2000);
	cout << "\n\t�����, ��� ���� ���� � ���� ��������� �� ����� " << _player.playerName;
	_player.getInfo();
	cout << "\n������� ����� �������, ����� ����� �� ������� � �������� ��� ������ ������������� �������\n";
	cin >> choise;
	if (choise >= 0)
		exit;

	
}
};