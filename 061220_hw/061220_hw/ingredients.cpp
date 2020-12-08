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
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Fats: " << this->getFats() << std::endl;
	std::cout << "Protein: " << this->getProtein() << std::endl;
	std::cout << "Carbohydrates: " << this->getCarbohydrates() << std::endl;
	std::cout << "Kcal: " << this->getKcal() << std::endl;
}