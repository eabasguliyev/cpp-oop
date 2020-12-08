#pragma once
#include "ingredients.h"

class RecipeItem
{
	Ingredient* ingredient;
	size_t amount;
public:
	RecipeItem():ingredient(NULL), amount(0){}

	RecipeItem(Ingredient* ingredient, const size_t& amount)
	{
		setIngredient(ingredient);
		setAmount(amount);
	}

	void setAmount(const size_t &);

	void setIngredient(Ingredient*);

	size_t getAmount() const;

	Ingredient* getIngredient() const;

	RecipeItem(RecipeItem&& ingredients) noexcept
	{
		this->ingredient = ingredients.ingredient;
		ingredients.ingredient = NULL;
		this->amount = ingredients.amount;
		ingredients.amount = 0;
	}

	RecipeItem & operator=(RecipeItem&& ingredients) noexcept
	{
		delete this->ingredient;
		//--------
		this->ingredient = ingredients.ingredient;
		ingredients.ingredient = NULL;
		this->amount = ingredients.amount;
		ingredients.amount = 0;

		return *this;
	}
};