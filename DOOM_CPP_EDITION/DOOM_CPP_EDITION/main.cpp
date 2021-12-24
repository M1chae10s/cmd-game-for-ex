#include <iostream>
#include <ctime>
#include <stdio.h>
#include <windows.h>
#include "Game.h"
#include "Story.h"
#include "PlayerProfile.h"
#include "SaveAndLoad.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SaveAndLoad _saveAndLoad;
	Story _story;
	Player _player;
	int userChoise;
	cout << "1 - Продолжить\n2 - Начать новую игру\n\nВаш выбор: ";
	cin >> userChoise;
	switch (userChoise)
	{
	case 1:
	{
		cout << "\n Введите ваш никнейм\n";
		cin >> _player.playerName;
		_saveAndLoad.Load(_player.playerName);
		_story.lvl = _saveAndLoad.lvlProfile;
		_player.health = _saveAndLoad.healthProfile;
		_story.LVL(_player.lvl);
		break;
	}
	case 2:
	{
	_story.LVL(0);
		break;
	}
	}
	return 0;
}
