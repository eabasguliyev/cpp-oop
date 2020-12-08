#include "RecipeItem.h"


void RecipeItem::setIngredient(Ingredient* ingredient)
{
	this->ingredient = ingredient;
}

void RecipeItem::setAmount(const size_t& amount)
{
	this->amount = amount;
}

size_t RecipeItem::getAmount() const { return this->amount; }

Ingredient* RecipeItem::getIngredient() const { return this->ingredient; }