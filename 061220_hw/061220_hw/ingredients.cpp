#include "ingredients.h"
#include <assert.h>

void Ingredient::setName(const std::string& name)
{
	assert(!name.empty() && "Name can not be blank!");
	this->name = name;
}

std::string Ingredient::getName() const { return this->name; }

void Ingredient::setFats(const double& fats)
{
	assert(fats >= 0 && "Fats must be greater than zero!");
	this->fats = fats;
}

double Ingredient::getFats() const { return this->fats; }

void Ingredient::setProtein(const double& protein)
{
	assert(protein >= 0 && "Protein must be greater than zero!");
	this->protein = protein;
}

double Ingredient::getProtein() const { return this->protein; }

void Ingredient::setCarbohydrates(const double& carbohydrates)
{
	assert(carbohydrates >= 0 && "Carbohydrates must be greater than zero!");
	this->carbohydrates = carbohydrates;
}

double Ingredient::getCarbohydrates() const { return this->carbohydrates; }

void Ingredient::setKcal(const size_t& kcal)
{
	assert(kcal >= 0 && "Kcal must be greater than zero!");
	this->kcal = kcal;
}

size_t Ingredient::getKcal() const { return this->kcal; }

void Ingredient::show() {
	std::cout << "ID: " << this->getID() << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Fats: " << this->getFats() << std::endl;
	std::cout << "Protein: " << this->getProtein() << std::endl;
	std::cout << "Carbohydrates: " << this->getCarbohydrates() << std::endl;
	std::cout << "Kcal: " << this->getKcal() << std::endl;
}

void Ingredient::setID(const size_t& id)
{
	this->id = id;
}
size_t Ingredient::getID() const { return this->id; }

size_t Ingredient::current_id = NULL;

void Meat::setMeatCategory(const std::string & category)
{
	this->meat_category = category;
}

std::string Meat::getMeatCategory() const { return this->meat_category; }

void Meat::setCountry(const std::string& country)
{
	this->country = country;
}

std::string Meat::getCountry() const { return this->country; }

void Meat::show()
{
	Ingredient::show();
}

void Cheese::show()
{
	Ingredient::show();
}

void Cheese::setSoftToHard(const std::string& soft_to_hard)
{
	this->soft_to_hard = soft_to_hard;
}
std::string Cheese::getSoftToHard() const { return this->soft_to_hard; }
void Cheese::setSourceOfMilk(const std::string& source_of_milk)
{
	this->source_of_milk = source_of_milk;
}
std::string Cheese::getSourceOfMilk() const { return this->source_of_milk; }
void Cheese::setCountry(const std::string& country) {
	this->country = country;
}
std::string Cheese::getCountry() const { return this->country; }

void Spices::show()
{
	Ingredient::show();
}

void Spices::setBotanicalBasis(const std::string& botanical_basis)
{
	this->botanical_basis = botanical_basis;
}
std::string Spices::getBotanicalBasis() const { return this->botanical_basis; }

void Tomatoes::setColor(const std::string& color)
{
	this->color = color;
}

std::string Tomatoes::getColor() const { return this->color; }

void Tomatoes::show()
{
	Ingredient::show();
}

void Mushrooms::setCountry(const std::string& country)
{
	this->country = country;
}

std::string Mushrooms::getCountry() const { return this->country; }

void Mushrooms::show()
{
	Ingredient::show();
}

void Potatoes::setCountry(const std::string& country)
{
	this->country = country;
}
std::string Potatoes::getCountry() const { return this->country; }
void Potatoes::setType(const std::string& type)
{
	this->type = type;
}
std::string Potatoes::getType() const { return this->type; }
void Potatoes::show()
{
	Ingredient::show();
}

void Onions::setCountry(const std::string& country)
{
	this->country = country;
}
std::string Onions::getCountry() const { return this->country; }
void Onions::setType(const std::string& type)
{
	this->type = type;
}
std::string Onions::getType() const { return this->type; }
void Onions::show()
{
	Ingredient::show();
}

void Eggplant::setCountry(const std::string& country)
{
	this->country = country;
}

std::string Eggplant::getCountry() const { return this->country; }

void Eggplant::show()
{
	Ingredient::show();
}