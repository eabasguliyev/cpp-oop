#include "meals.h"
#include <assert.h>

void Meal::setName(const std::string& name)
{
	assert(!name.empty() && "Name can not be blank!");
	this->name = name;
}

std::string Meal::getName() const { return this->name; }

void Meal::printRecipe() const
{
	std::cout << "Recipe: " << std::endl;
	for (size_t i = 0, length = getIngredientCount(); i < length; i++)
	{
		std::cout << i + 1 << " . Ingredient: " << std::endl;
		this->ingredients[i]->getIngredient()->show();
		std::cout << "Amount: " << this->ingredients[i]->getAmount() << std::endl;
	}
}

size_t Meal::getIngredientCount() const { return this->ingredient_count; }

void Meal::setIngredientCount(const size_t & count)
{
	this->ingredient_count = count;
}

void Meal::addIngredient(Ingredient* ingredient, const size_t& amount)
{
	size_t new_size = getIngredientCount() + 1;

	auto new_ingredients = new RecipeItem * [new_size];

	if (new_ingredients != NULL)
	{
		for (size_t i = 0; i < new_size - 1; i++)
		{
			new_ingredients[i] = this->ingredients[i];
		}

		auto new_recipe_item = new RecipeItem(ingredient, amount);

		new_ingredients[new_size - 1] = new_recipe_item;

		this->ingredients = new_ingredients;
		setIngredientCount(new_size);
	}
}
size_t Meal::current_id = NULL;
void Meal::taste() const
{
	std::cout << "I don't know, what is this?" << std::endl;
}

void Meal::setID(const size_t& id)
{
	this->id = id;
}
size_t Meal::getID() const { return this->id; }


void Pizza::setSize(const std::string& size)
{
	this->size = size;
}
std::string Pizza::getSize() const { return this->size; }
void Pizza::printRecipe() const
{
	std::cout << "Meal ID: " << getID() << std::endl;
	std::cout << "Meal name: " << getName() << std::endl;
	std::cout << "Size: " << getSize() << std::endl;
	Meal::printRecipe();
}
void Pizza::taste() const
{
	std::cout << "Mmmm.... delicious!" << std::endl;
}

void Kabab::setType(const std::string& type)
{
	this->type = type;
}

std::string Kabab::getType() const { return this->type; }

void Kabab::printRecipe() const
{
	std::cout << "Meal ID: " << getID() << std::endl;
	std::cout << "Meal name: " << getName() << std::endl;
	std::cout << "Type: " << getType() << std::endl;
	Meal::printRecipe();
}
void Kabab::taste() const
{
	std::cout << "Mmmm.... delicious!" << std::endl;
}

void Dolma::printRecipe() const
{
	std::cout << "Meal ID: " << getID() << std::endl;
	std::cout << "Meal name: " << getName() << std::endl;
	Meal::printRecipe();
}

void Dolma::taste() const
{
	std::cout << "Mmmm.... delicious!" << std::endl;
}