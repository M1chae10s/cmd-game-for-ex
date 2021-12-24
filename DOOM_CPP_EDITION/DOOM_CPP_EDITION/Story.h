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
		cout << "-------------------НОВАЯ ИГРА СОЗДАНА-------------------\n\n";
		Sleep(2000);
		cout << "------------------Локация 0: Знакомство-----------------\n\n\n";
		Sleep(4000);
		cout << "Голос за кадром:\n\tДревнее зло пробудилось...\n";
		Sleep(3000);
		cout << "\tСтоп...";
		Sleep(2000);
		cout << "\n\tЯ так понимаю - мы не знакомы\n";
		Sleep(2000);
		cout << "\tДавай исправим эту неприятную ситуацию и продолжим нашу маленькую историю, согласен?\n\n1 - Да\n2 - Нет\nВы: ";
		cin >> choise;
		if (choise == 2)
		{
			Sleep(1000);
			cout << "\n\tХм, довольно грубо...\n";
			Sleep(2000);
			cout << "\tНу... мне жаль, ты не достоин этой истории...";
			Sleep(3000);
			exit;
		}
		Sleep(1000);
		cout << "\n\tОтлично! Позвольте представиться,\n";
		Sleep(2000);
		cout << "\tперед вами неповторимый\n";
		Sleep(2000);
		cout << "\tсамый красивый, умный и вообще хороший мальчик\n";
		Sleep(2000);
		cout << "\t(мне так моя мама говорит)\n";
		Sleep(2000);
		cout << "\tГооооолос за кадром!\n";
		Sleep(2000);
		cout << "\t...\n";
		Sleep(2000);
		cout << "\tТеперь твоя очередь представится.\n";
		Sleep(1000);
		cout << "\n---Представьтесь---\n";
		cout << "Здравствуй, меня зовут ";
		cin >> _player.playerName;
		Sleep(1000);
		cout << "\n\n\tНу привет, " << _player.playerName;
		Sleep(2000);
		cout << "\n\tУ тебя весьма интересное имя\n";
		Sleep(2000);
		cout << "\tНу да ладно, продолжим\n";
		Sleep(2000);
		cout << "\t...\n";
		Sleep(2000);
		cout << "\tНа чём мы остановились?\n";
		Sleep(2000);
		cout << "\tАх, да...\n";
		Sleep(2000);
		cout << "\t...кхм...кхм...\n";
		Sleep(2000);
		cout << "\tДревнее зло пробудилось\n";
		Sleep(2000);
		cout << "\tМонстрам не страшны гром и молнии\n";
		Sleep(2000);
		cout << "\tОни рыщут по планете, они безумны и жестоки\n";
		Sleep(2000);
		cout << "\tИм чужда лишь свежая кровь\n";
		Sleep(2000);
		cout << "\tНо они боятся лишь одного...\n";
		Sleep(2000);
		cout << "\tТебя...\n\t..."<<_player.playerName;
		Sleep(3000);
		cout << "\n\n-------------------Локация 0 пройдена-------------------\n\n";
		cout << "1 - Сохраниться и продолжить\n2 - Сохраниться и выйти\n3 - Выйти без сохранения\nВаш выбор: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			_saveAndLoad.Save(_player.playerName, 1, _player.health);
			cout << "\n\n-----------------Сохранение перезаписано----------------\n\n";
			Sleep(2000);
			cout << "\n\n--------------Переход на следующую локацию--------------\n\n";
			LVL(1);
			break;
		}
		case 2:
		{	
			_saveAndLoad.Save(_player.playerName, 1, _player.health);
			cout << "\n\n-----------------Сохранение перезаписано----------------\n\n";
			Sleep(2000);
			cout << "\n\n----------------------Выход из игры---------------------\n\n";
			Sleep(2000);
			exit;
		}
		case 3:
		{
		cout << "\n\n----------------------Выход из игры---------------------\n\n";
		Sleep(2000);
			exit;
		}
		}
		break;
	}
	case 1:
	{
		Sleep(2000);
		cout << "\n\n\n----------------Локация 1: Первое сражение--------------\n\n\n";
		Sleep(3000);
		cout << "\tИтак, наш герой или героиня,\n";
		Sleep(2000);
		cout << "\tочнулся или очнулась...\n";
		Sleep(2000);
		cout << "\t...\n";
		Sleep(2000);
		cout << "\tПозволь мне дальше называть тебя просто по имени)\n";
		Sleep(2000);
		cout << "\tСпасибо\n";
		Sleep(2000);
		cout << "\tИтак, "<<playerName<<" пробуждается после долгой спячки в полуразрушенном комплексе\n";
		Sleep(2000);
		cout << "\tВдруг на тебя кидается\n";
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
		cout << "\n\tНо в далеке ты замечаешь рельсотрон...\n";
		Sleep(2000);
		cout << "\tКак же ты поступишь?\n\n---Выберите дальнейшее действие---\n1 - Сражаться врукопашную подобно Палачу Рока\n2 - Побежать к рельсотрону\nВаш выбор: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			Sleep(2000);
			if (enemyID == 1)
			{
				cout << "\n\nВы обмениваетесь мощными пощёчинами\n";
				_demon.setHealth(_demon.getHealth() - _player.getDamage());
				_player.setHealth(_player.getHealth() - _demon.getDamage());
				Sleep(2000);
				cout << "Вы нанесли " << _player.getDamage() << " единиц урона\n";
				Sleep(2000);
				cout << "У " << _demon.enemyName << " осталось " << _demon.getHealth() << " единиц здоровья\n";
				Sleep(2000);
				cout <<  _demon.enemyName << " нанёс Вам " << _demon.getDamage() << " единиц урона\n";
				Sleep(2000);
				cout << "У " << _player.playerName << " осталось " << _player.getHealth() << " единиц здоровья";
				Sleep(2000);
				cout << "Пока " << _demon.enemyName << " оглушен, вы добиваете его";
				_demon.~Demon();
			}
			else
			{
				cout << "\n\nВы обмениваетесь мощными пощёчинами\n";
				_sDemon.setHealth(_sDemon.getHealth() - _player.getDamage());
				_player.setHealth(_player.getHealth() - _sDemon.getDamage());
				Sleep(2000);
				cout << "Вы нанесли " << _player.getDamage() << " единиц урона\n";
				Sleep(2000);
				cout << "У " << _sDemon.enemyName << " осталось " << _sDemon.getHealth() << " единиц здоровья";
				Sleep(2000);
				cout << _sDemon.enemyName << " нанёс Вам " << _sDemon.getDamage() << " единиц урона\n";
				Sleep(2000);
				cout << "У " << _player.playerName << " осталось " << _player.getHealth() << " единиц здоровья";
				Sleep(2000);
				cout << "Пока " << _sDemon.enemyName << " оглушен, вы добиваете его";
				_sDemon.~SuperDemon();
			}

		}
		case 2:
		{
			Sleep(2000);
			if (enemyID == 1)
				cout << playerName << " был схвачен и изуродован " << _demon.enemyName;
			else
				cout << playerName << " был схвачен и изуродован " << _sDemon.enemyName;
			end();
		}
		}
		Sleep(2000);
		cout << "\n\n\tПобедив демона, " << _player.playerName << " направился в следующий отсек\n";
		Sleep(2000);
		cout << "\tВ центре отсека Вы увидели демонический портал, ведущий в неизвестность...\n\tРискнёте ли вы прыгнуть в него?\n\n";
		cout << "---Выберите дальнейшее действие---\n1 - Прыгнуть в портал\n2 - Подождать\nВаш выбор: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			Sleep(2000);
			cout << "\n\n\tВы прыгнули в портал...";
			Sleep(2000);
			cout << "\n\n-------------------Локация 1 пройдена-------------------\n\n";
			cout << "1 - Сохраниться и продолжить\n2 - Сохраниться и выйти\n3 - Выйти без сохранения\nВаш выбор: ";
			cin >> choise;
			Sleep(3000);
			switch (choise)
			{
			case 1:
			{
				_saveAndLoad.Save(_player.playerName, 2, _player.health);
				cout << "\n\n-----------------Сохранение перезаписано----------------\n\n";
				Sleep(2000);
				cout << "\n\n--------------Переход на следующую локацию--------------\n\n";
				LVL(2);
				break;
			}
			case 2:
			{
				_saveAndLoad.Save(_player.playerName, 2, _player.health);
				cout << "\n\n-----------------Сохранение перезаписано----------------\n\n";
				Sleep(2000);
				cout << "\n\n----------------------Выход из игры---------------------\n\n";
				Sleep(2000);
				exit;
				break;
			}
			case 3:
			{
				cout << "\n\n----------------------Выход из игры---------------------\n\n";
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
			cout << "\n\n\tВы не прыгнули в портал и прождали 10 лет...\n";
			Sleep(2000);
			cout << "\t...Человечество не было спасено\n";
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
		cout << "\n\n\n----------------Локация 2: Я хочу спать--------------\n\n\n";
		Sleep(2000);
		cout << "\tПрошу прощения за столь краткую историю непонятно чего\n";
		Sleep(2000);
		cout << "\tУ меня действительно было мало времени на написание кода\n";
		Sleep(2000);
		cout << "\tОднако я владею базовыми навыками написания кода\n";
		Sleep(2000);
		cout << "\tИ мне интересна эта тематика, и я готов и буду дальше развиваться в этом направлении\n";
		Sleep(2000);
		cout << "\tА ещё я много времени потратил в UNITY\n";
		Sleep(2000);
		cout << "\tА ещё у меня 127 открытых вкладок на тему UNITY в браузере...и я в них ориентируюсь)\n";
		Sleep(2000);
		cout << "\tА ещё время 1:17, а надо ещё исправить некоторые косяки и подготовить Windows Froms\n";
		Sleep(2000);
		cout << "\tА ещё это всё равно никто не прочитает\n";
		Sleep(2000);
		cout << "\tА ещё я хочу спать\n";
		Sleep(2000);
		cout << "\tИ каждый раз, прописывая 'Sleep', я ещё сильнее хочу спать\n";
		Sleep(2000);
		cout << "\tИ все эти строки были написаны вручную\n";
		Sleep(2000);
		cout << "\tСпокойной ночи\n";
		Sleep(2000);
		break;
		end();
	}
	}
}
void end()
{
	cout << "\n\n\n\n----------------Игра окончена!--------------\n";
	Sleep(2000);
	cout << "\n\tЛадно, вот тебе инфа о твоём персонаже по имени " << _player.playerName;
	_player.getInfo();
	cout << "\nНажмите любую клавишу, чтобы выйти из консоли и заняться чем нибудь действительно стоющим\n";
	cin >> choise;
	if (choise >= 0)
		exit;

	
}
};