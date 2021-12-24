#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include "Story.h"
#include "PlayerProfile.h"

class SaveAndLoad : virtual public Player
{
public:
	int healthProfile;
	int lvlProfile;

	SaveAndLoad()
	{
	}
	void Save(string name, int lvl, int health)
	{
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::ofstream out;
		out.open("D:\\"+name+".txt");
		if (out.is_open())
		{
			out << lvl <<  std::endl;
			out << health << std::endl;
		}

	}
	void Load(string name)
	{
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
			std::string line;
			std::ifstream in("D:\\" + name + ".txt"); 
			if (in.is_open())
			{

				in >> lvlProfile;
				in >> healthProfile;
			}
			in.close(); 

	}

};
