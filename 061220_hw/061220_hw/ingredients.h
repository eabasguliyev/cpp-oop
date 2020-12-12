#ifndef INGREDIENTS_H
#define INGREDIENTS_H
#include <iostream>


class Ingredient
{
protected:
	size_t id;
	std::string name;
	double fats;
	double protein;
	double carbohydrates;
	size_t kcal;
public:
	static size_t current_id;
	Ingredient() = delete;

	Ingredient(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal)
	{
		setName(name);
		setFats(fats);
		setProtein(protein);
		setCarbohydrates(carbohydrates);
		setKcal(kcal);
		setID(++current_id);
	}

	void setID(const size_t& id);
	size_t getID() const;
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
	std::string country;
public:
	Mushrooms(const std::string& name, const double & fats, const double & protein,
		const double & carbohydrates, const size_t & kcal, const std::string country) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{
		setCountry(country);
	}

	void setCountry(const std::string& country);

	std::string getCountry() const;

	void show();
};

class Meat :public Ingredient
{
	std::string meat_category;
	std::string country;

public:
	Meat(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal, const std::string& category, const std::string & country) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{
		setMeatCategory(category);
		setCountry(country);
	}

	void setMeatCategory(const std::string & category);

	std::string getMeatCategory() const;

	void setCountry(const std::string& country);

	std::string getCountry() const;

	void show() override;
};

class Spices :public Ingredient
{
	std::string botanical_basis;
public:
	Spices(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal, const std::string& botanical_basis) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{
	}

	void setBotanicalBasis(const std::string& botanical_basis);
	std::string getBotanicalBasis() const;
	void show() override;
};

class Cheese :public Ingredient
{
	std::string soft_to_hard;
	std::string source_of_milk;
	std::string country;
public:
	Cheese(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal, const std::string & soft_to_hard, const std::string& source_of_milk, const std::string & country) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{
		setSoftToHard(soft_to_hard);
		setSourceOfMilk(source_of_milk);
		setCountry(country);
	}

	void setSoftToHard(const std::string& soft_to_hard);
	std::string getSoftToHard() const;
	void setSourceOfMilk(const std::string& source_of_milk);
	std::string getSourceOfMilk() const;
	void setCountry(const std::string& country);
	std::string getCountry() const;

	void show() override;
};

class Tomatoes :public Ingredient
{
	std::string color;
public:
	Tomatoes(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal, const std::string & color) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{
		setColor(color);
	}

	void setColor(const std::string& color);
	std::string getColor() const;
	void show() override;
};

class Potatoes :public Ingredient
{
	std::string country;
	std::string type;
public:
	Potatoes(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal, const std::string& country, const std::string& type) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{
		setCountry(country);
		setType(type);
	}

	void setCountry(const std::string& country);
	std::string getCountry() const;
	void setType(const std::string& type);
	std::string getType() const;
	void show() override;
};

class Onions :public Ingredient
{
	std::string country;
	std::string type;
public:
	Onions(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal, const std::string& country, const std::string  & type) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{
		setCountry(country);
		setType(type);
	}

	void setCountry(const std::string& country);
	std::string getCountry() const;
	void setType(const std::string& type);
	std::string getType() const;
	void show() override;
};

class Eggplant :public Ingredient
{
	std::string country;
public:
	Eggplant(const std::string& name, const double& fats, const double& protein,
		const double& carbohydrates, const size_t& kcal, const std::string country) :Ingredient(name, fats, protein, carbohydrates, kcal)
	{
		setCountry(country);
	}

	void setCountry(const std::string& country);

	std::string getCountry() const;

	void show();
};

#endif