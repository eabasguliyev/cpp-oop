#ifndef COOKING_DEVICES_H
#define COOKING_DEVICES_H
#include "meals.h"

class CookingDevice
{
protected:
	Meal* meal;
	bool isCooked;
	size_t second;

public:
	CookingDevice() :meal(NULL), isCooked(false), second(0) {}

	virtual void cook() {}
	void setMeal(Meal* meal)
	{
		this->meal = meal;
	}

	void setSecond(const size_t& second)
	{
		this->second = second;
	}

	size_t getSecond() const { return this->second; }

	virtual ~CookingDevice() = 0 {}
};


class Oven : public CookingDevice {
public:
	Oven()
	{

	}

	void cook()
	{
		if (this->meal == NULL)
			std::cout << "Oven is empty. Set something!" << std::endl;

		Sleep(this->second * 1000);
	}
};

class Barbecue : public CookingDevice
{
public:
	Barbecue()
	{

	}

	void cook()
	{
		if (this->meal == NULL)
			std::cout << "Barbecue is empty. Set something!" << std::endl;

		Sleep(this->second * 1000);
	}
};

class Pot : public CookingDevice
{
public:
	Pot()
	{

	}

	void cook()
	{
		if (this->meal == NULL)
			std::cout << "Pot is empty. Set something!" << std::endl;

		Sleep(this->second * 1000);
	}
};
#endif