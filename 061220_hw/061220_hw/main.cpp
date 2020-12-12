#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <strsafe.h>
#include "CookingDevices.h"

#define RED 4
#define YELLOW 6
#define WHITE 7

enum ARROWKEYS {
	KEY_UP = 72, KEY_DOWN = 80
};

void ConsoleScreenSettings();
struct ScreenOptions
{
	char** main_menu = nullptr;
	size_t mm_size = 0;
};

short MainMenu(ScreenOptions& so);

template <typename T>
void destroyData(T** data, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		delete data[i];
	}

	delete[] data;
}


template <typename T>
bool checkData(T** data, size_t count, size_t id)
{
	for (size_t i = 0; i < count; i++)
	{
		if (id == data[i]->getID())
			return true;
	}
	return false;
}

Ingredient* getIngredient(Ingredient ** ingredients, size_t count, size_t id)
{
	for (size_t i = 0; i < count; i++)
	{
		if (id == ingredients[i]->getID())
			return ingredients[i];
	}

	return NULL;
}
int getMealIndex(Meal** meals, size_t count, size_t id)
{
	for (size_t i = 0; i < count; i++)
	{
		if (id == meals[i]->getID())
			return i;
	}

	return -1;
}
void main()
{
	ConsoleScreenSettings();
	ScreenOptions so;
	
	Meal* kabab = new Kabab("Toyuq kababi", "manqal");
	Meal* dolma = new Dolma("Uch baci");
	Meal* pizza = new Pizza("Margherita", "small size");

	Meal** meals = new Meal * [3]{ kabab, dolma, pizza };

	CookingDevice* oven = new Oven();
	CookingDevice* barbecue = new Barbecue();
	CookingDevice* pot = new Pot();
	CookingDevice** devices = new CookingDevice * [3]{ oven, barbecue, pot };
	
	size_t ingredient_count = 9;
	Mushrooms* mushroom = new Mushrooms("Cremini", 10, 10, 10, 10, "USA");
	Meat* meat = new Meat("Beef", 20, 150, 60, 60, "Red Meat", "Russian");
	Cheese* cheese = new Cheese("Trappista", 10, 20, 30, 40, "semi-hard", "Cow", "Bosnia and Herzegovina");
	Cheese* cheese2 = new Cheese("Pizza cheese", 10, 20, 30, 40, "soft", "Cow", "Italia");
	Tomatoes* tomatoe = new Tomatoes("pomidor", 100, 150, 50, 300, "qirmizi");
	Potatoes* potatoes = new Potatoes("kartof", 100, 150, 50, 300, "Azerbaijan", "sari");
	Onions* onion = new Onions("Soghan", 10, 20, 30, 40, "Azerbaijan", "agh");
	Spices* spices = new Spices("qirmizi biber", 50, 60, 70, 80, "seed");
	Eggplant* eggplant = new Eggplant("Badimcan", 20, 30, 25, 50, "Azerbaijan");

	Ingredient** ingredients = new Ingredient * [ingredient_count]{ mushroom, meat, cheese, cheese2, potatoes, onion, eggplant, tomatoe, spices };


	while (1)
	{
		short choice = MainMenu(so);


		system("CLS");
		if (choice == 1)
		{
			for (size_t i = 0; i < 3; i++)
			{
				std::cout << "----------------------------" << std::endl;
				meals[i]->printRecipe();
			}
			std::cout << "----------------------\n\n";
		}
		else if(choice == 2)
		{
			destroyData(meals, 3);
			destroyData(devices, 3);
			destroyData(ingredients, ingredient_count);
			destroyData(so.main_menu, so.mm_size);
			exit(0);
		}
		else
		{
			continue;
		}

		short meal_id = 0;
		size_t meal_index = 0;
		std::cout << "Select meal" << std::endl;

		while (1)
		{
			std::cout << "Meal id: ";
			std::cin >> meal_id;

			if (checkData(meals, 3, meal_id))
			{
				meal_index = getMealIndex(meals, 3, meal_id);
				break;
			}

			std::cout << "Try again\n";
		}
		
		for (size_t i = 0; i < ingredient_count; i++)
		{
			std::cout << "---------------------------\n";
			ingredients[i]->show();
		}
		std::cout << "---------------------------\n";

		short ingredient_id = 0;

		std::cout << "Select ingredient" << std::endl;

		while (1)
		{
			std::cout << "Ingredient id: (-1 - exit) ";
			std::cin >> ingredient_id;

			if (ingredient_id == -1)
				break;
			else if (!checkData(ingredients, ingredient_count, ingredient_id))
			{
				std::cout << "Try again\n";
				continue;
			}
			 

			std::cout << "Ingredient count: ";

			short count = 0;

			std::cin >> count;

			meals[meal_index]->addIngredient(getIngredient(ingredients, ingredient_count, ingredient_id), count);

			std::cout << "Ingredient added!\n";
		}


		std::cout << "1. Oven" << std::endl << "2. Barbecue" << std::endl << "3. Pot" << std::endl;

		short device_choice = 0;

		std::cout << "Device: ";

		std::cin >> device_choice;
		
		std::cout << "Time(seconds): ";

		short seconds;

		std::cin >> seconds;

		devices[device_choice]->setMeal(meals[meal_index]);
		devices[device_choice]->setSecond(seconds);
		devices[device_choice]->cook();

		std::cout << "Meal is cooked!\n";
		

		meals[meal_index]->printRecipe();
		std::cin.ignore(255, '\n');
		std::cin.get();
	}
}

void ConsoleScreenSettings()
{
	HANDLE hConsoleIN = GetStdHandle(STD_INPUT_HANDLE);

	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);

	TCHAR consoleNewTitle[MAX_PATH];

	StringCchPrintf(consoleNewTitle, MAX_PATH, TEXT("MakeDish"));

	SetConsoleTitle(consoleNewTitle);

	HWND consoleWindow = GetConsoleWindow();
	MoveWindow(consoleWindow, 500, 58, 895, 518, TRUE);
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);


	CONSOLE_CURSOR_INFO cursor_info = {};

	cursor_info.bVisible = false;
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(hConsoleOUT, &cursor_info);
}


void PrintMenu(char** options, int size, int selected)
{
	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordinate = { 50, 10 };
	for (size_t i = 0; i < size; i++)
	{
		SetConsoleCursorPosition(hConsoleOUT, coordinate);
		if (i == selected)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			std::cout << i + 1 << ". " << options[i] << std::endl;;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else
		{
			std::cout << i + 1 << ". " << options[i] << std::endl;;
		}
		coordinate.Y++;
	}
}

short MenuInputWithKeyboard(char** options, short size, short& selected)
{
	while (true)
	{
		system("CLS");
		PrintMenu(options, size, selected - 1);

		int key = _getch();

		if (key == 224)
		{
			switch (_getch())
			{
			case KEY_UP:
			{
				if (selected > 1)
					selected--;
			}
			break;
			case KEY_DOWN:
			{
				if (selected < size)
					selected++;
			}
			break;
			}
		}
		else if (key == 13)
		{
			return selected;
		}
	}
}

short MainMenu(ScreenOptions& so)
{
	system("CLS");
	static short selected = 1;
	if (so.mm_size == 0)
	{
		so.mm_size = 2;
		so.main_menu = new char* [so.mm_size];
		so.main_menu[0] = _strdup("Print menu");
		so.main_menu[1] = _strdup("Exit");
	}

	return MenuInputWithKeyboard(so.main_menu, so.mm_size, selected);
}

