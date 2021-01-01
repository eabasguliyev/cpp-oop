#include <iostream>
#include <vector>

std::string& getName(std::vector<std::string>& mealList, const std::string& name)
{
	for (auto& i : mealList)
	{
		if (name == i)
			return i;
	}

	throw std::string("Not found");
}
void main()
{
	std::vector<std::string> strings;

	strings.emplace_back("dolma");
	strings.emplace_back("pizza");
	strings.emplace_back("burger");
	strings.emplace_back("sushi");

	for (auto& i : strings)
	{
		std::cout << "Name: " << i << std::endl;
	}

	try
	{
		std::string& name = getName(strings, "pizza");
		name = "Pizzas";
		std::cout << "Deyishildi: " << name << std::endl;
	}
	catch (const std::string& ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}

	for (const auto &i : strings)
	{
		std::cout << "Name: " << i << std::endl;
	}
}