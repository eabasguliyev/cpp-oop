#pragma once
#include "RecipeItem.h"

class Meal
{
protected:
	RecipeItem** ingredients;
	size_t ingredient_count;
	std::string name;

public:
	Meal() :ingredients(NULL), ingredient_count(0), name("") {}

	Meal(const std::string& name)
	{
		setName(name);
	}

	void setName(const std::string &);
	std::string getName() const;
	virtual void printRecipe() const;
	virtual void taste() const {};
	void addIngredient(Ingredient*, const size_t&);
	size_t getIngredientCount() const;
	void setIngredientCount(const size_t&);
	virtual ~Meal() = 0;
};

class Pizza : public Meal
{

};

class Kabab : public Meal
{

};

class Dolma : public Meal
{

};

