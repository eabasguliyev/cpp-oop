#ifndef MEALS_H
#define MEALS_H
#include "RecipeItem.h"

class Meal
{
protected:
	size_t id;
	RecipeItem** ingredients;
	size_t ingredient_count;
	std::string name;

public:
	static size_t current_id;
	Meal() :ingredients(NULL), ingredient_count(0), name("") {}

	Meal(const std::string& name)
	{
		setName(name);
		setID(++current_id);
	}

	Meal& operator=(const std::string& name)
	{
		setName(name);
		setID(++current_id);
	}

	void setID(const size_t & id);
	size_t getID() const;
	void setName(const std::string &);
	std::string getName() const;
	virtual void printRecipe() const;
	virtual void taste() const;
	void addIngredient(Ingredient*, const size_t&);
	size_t getIngredientCount() const;
	void setIngredientCount(const size_t&);
	virtual ~Meal() = 0 {}
};

class Pizza : public Meal
{
	std::string size;
public:
	Pizza() : size("") {}
	Pizza(const std::string& name, const std::string& size):Meal(name)
	{
		setSize(size);
	}
	void setSize(const std::string& size);
	std::string getSize() const;
	void printRecipe() const;
	void taste() const;
};

class Kabab : public Meal
{
	std::string type;
public:

	Kabab() : type("") {}
	Kabab(const std::string& name, const std::string& type) : Meal(name)
	{
		setType(type);
	}
	void setType(const std::string& type);
	std::string getType() const;
	void printRecipe() const;
	void taste() const;
};

class Dolma : public Meal
{
public:
	Dolma() {}
	Dolma(const std::string& name) :Meal(name) {}

	void printRecipe() const;
	void taste() const;
};

#endif