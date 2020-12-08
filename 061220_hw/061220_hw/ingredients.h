#pragma once
#include <iostream>


class Ingredient
{
protected:
	std::string name;
	double fats;
	double protein;
	double carbohydrates;
	size_t kcal;
public:
	Ingredient() = delete;

	Ingredient(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal)
	{
		setName(name);
		setFats(fats);
		setProtein(protein);
		setCarbohydrates(carbohydrates);
		setKcal(kcal);
	}

	Ingredient(const Ingredient& ingredient)
	{
		setName(ingredient.getName());
		setFats(ingredient.getFats());
		setProtein(ingredient.getProtein());
		setCarbohydrates(ingredient.getCarbohydrates());
		setKcal(ingredient.getKcal());
	}

	Ingredient& operator=(const Ingredient& ingredient)
	{
		setName(ingredient.getName());
		setFats(ingredient.getFats());
		setProtein(ingredient.getProtein());
		setCarbohydrates(ingredient.getCarbohydrates());
		setKcal(ingredient.getKcal());
		return *this;
	}

	void setName(const std::string&);

	std::string getName() const;

	void setFats(const double&);

	double getFats() const;

	void setProtein(const double&);

	double getProtein() const;

	void setCarbohydrates(const double&);

	double getCarbohydrates() const;

	void setKcal(const size_t&);

	size_t getKcal() const;

	virtual ~Ingredient() = 0 {}

	virtual void show() = 0;
};

class Mushrooms :public Ingredient
{
public:
	Mushrooms(const std::string& name, const double & fats, const double & protein,
		const double & carbohydrates, const size_t & kcal) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{}

	void show() override
	{
		Ingredient::show();
	}
};

class Meat :public Ingredient
{
public:
	Meat(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{}

	void show() override
	{
		Ingredient::show();
	}
};

class Spices :public Ingredient
{
public:
	Spices(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{}

	void show() override
	{
		Ingredient::show();
	}
};

class Cheese :public Ingredient
{
public:
	Cheese(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{}

	void show() override
	{
		Ingredient::show();
	}
};

class Tomatoes :public Ingredient
{
public:
	Tomatoes(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{}

	void show() override
	{
		Ingredient::show();
	}
};