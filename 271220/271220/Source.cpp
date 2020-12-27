#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <forward_list>

class Number
{
	std::string name;
	std::string number;
};
class PhoneBook
{
	std::vector<Number> numbers;
public:

	void addNumber(const Number& number)
	{
		// burada yoxlama apar.
		numbers.push_back(number);
	}
};
struct Car
{
	std::map<std::string, std::string> properties;

	void print() const
	{
		for (auto& i : properties)
		{
			std::cout << i.first;
			std::cout << "  -  ";
			std::cout << i.second << std::endl;
		}
	}
};
struct Ypx
{
	std::map<std::string, std::vector<std::string>> penalties;

	void print()
	{
		for (auto& penalty : penalties)
		{
			std::cout << "Car no: " << penalty.first << std::endl << std::endl;
			std::cout << "Penalties:\n";

			for (auto& data : penalty.second)
			{
				std::cout << data << std::endl;
			}

			std::cout << std::endl;
		}
	}

	void showCarPenalties(const std::string& car_no)
	{
		std::vector<std::string> penalty = penalties[car_no];

		for (auto& p : penalty)
		{
			std::cout << p << std::endl;
		}
	}
};


int sum(int a, int b)
{
	return a + b;
}

int diff(int a, int b)
{
	return a - b;
}

int mult(int a, int b)
{
	return a * b;
}

int division(int a, int b)
{
	if(b != 0)
		return a / b;
	throw std::string("Divided by zero");
}

int rem(int a, int b)
{
	if (b != 0)
		return a % b;
	throw std::string("Divided by zero");
}


#include <iomanip>

class Kitty
{
	std::string name;
	std::string nickname;
	int age;
public:
	Kitty() : name(""), nickname(""), age(0) {}
	Kitty(const std::string& name, const std::string& nickname,
		const int& age)
	{
		setName(name);
		setNickname(nickname);
		setAge(age);
	}
	
	//setters
	void setName(const std::string& name) { this->name = name; }
	void setNickname(const std::string& nickname) { this->nickname = nickname; }
	void setAge(const int & age) { this->age = age; }

	//getters
	std::string getName()const { return this->name; }
	std::string getNickname()const { return this->nickname; }
	int getAge() const { return this->age; }

	void show() const
	{
		std::cout << "#########################" << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Nickname: " << getNickname() << std::endl;
		std::cout << "Age: " << getAge() << std::endl;
	}
};

void printKitties(const std::list<Kitty>& kitties)
{
	for (auto& kitty : kitties)
	{
		std::cout << std::setw(15) << std::left << kitty.getName() <<
			std::setw(20) << std::left << kitty.getNickname() <<
			std::setw(5) << std::left << kitty.getAge() << std::endl;
	}
}


// Predicate

//Ascending - artan
// Descending - azalan
bool byNameAsc(const Kitty& cat1, const Kitty& cat2)
{
	return cat1.getName() < cat2.getName();
}

bool byNameDesc(const Kitty& cat1, const Kitty& cat2)
{
	return cat1.getName() > cat2.getName();
}

bool byAgeAsc(const Kitty& cat1, const Kitty& cat2)
{
	return cat1.getAge() < cat2.getAge();
}

bool byAgeDesc(const Kitty& cat1, const Kitty& cat2)
{
	return cat1.getAge() > cat2.getAge();
}

bool tooOld(const Kitty& kitty)
{
	return kitty.getAge() > 20;
}

bool nicknameGreaterThan7(const Kitty& kitty)
{
	return kitty.getNickname().length() > 7;
}
void main()
{


	//std::list<Kitty> kitties;

	//kitties.push_back(Kitty("Toplan", "Top123", 35));
	//kitties.push_back(Kitty("Mestan", "Qara", 8));
	//kitties.push_back(Kitty("Jay-jay", "qara jay", 5));
	//kitties.push_back(Kitty("Garfield", "HungryKitty", 50));

	//std::cout << "Un ordered list" << std::endl;

	//printKitties(kitties);

	//std::cout << std::endl;
	//std::cout << "Ordered list" << std::endl;

	////kitties.sort();

	//// predicate

	//std::cout << "By name ascending\n";
	//kitties.sort(byNameAsc);

	//printKitties(kitties);

	//std::cout << std::endl;

	//std::cout << "By name descending\n";
	//kitties.sort(byNameDesc);

	//printKitties(kitties);

	//std::cout << std::endl;


	//std::cout << "By age ascending\n";
	//kitties.sort(byAgeAsc);

	//printKitties(kitties);

	//std::cout << "By age descending\n";
	//kitties.sort(byAgeDesc);

	//printKitties(kitties);
	//

	//std::cout << "After remove " << std::endl;
	//kitties.remove_if(tooOld);
	//printKitties(kitties);

	std::list<Kitty> kitties;

	kitties.push_back(Kitty("Toplan", "Top123", 35));
	kitties.push_back(Kitty("Mestan", "Qara", 8));
	kitties.push_back(Kitty("Jay-jay", "qara jay", 5));
	kitties.push_back(Kitty("Garfield", "HungryKitty", 50));

	std::cout << "Un ordered list" << std::endl;

	printKitties(kitties);

	std::cout << "After remove" << std::endl;

	kitties.remove_if(nicknameGreaterThan7);

	printKitties(kitties);
	/*try
	{
		std::map<char, int(*)(int, int)> calc;

		calc['+'] = sum;
		calc['-'] = diff;
		calc['*'] = mult;
		calc['/'] = division;
		calc['%'] = rem;


		int num1, num2 = 0;
		char op = ' ';

		std::cout << "Num1 >> ";

		std::cin >> num1; std::cin.ignore();

		std::cout << "Operator >> ";

		std::cin >> op; std::cin.ignore();

		std::cout << "Num2 >> ";
		std::cin >> num2; std::cin.ignore();


		try
		{
			std::cout << calc[op](num1, num2);
		}
		catch (const std::string& ex)
		{
			std::cout << "Error: " << ex << std::endl;
		}
	}
	catch (const std::exception& ex)
	{
		ex.what();
	}*/

	// binary search tree'a esaslanir: 
		// 1. set; set<int> s -> unikal olur,
							// eyni elementler olmur
		// 2. multiset;  multiset<int> unikal olmur
						// eyni elementden bir neche dene
						// ola biler.
		// 3. map -> unikal olur.
		// 4. multiMap -> unikal olmur ( dictionary )


	// 1. set, unikal olur ve sort olunmushdur.

	/*std::set<int> s;
	for (size_t i = 0; i < 10; i++)
	{
		int num = rand() % 10;
		std::cout << num << ' ';
		s.insert(num);
	}std::cout << std::endl;

	for (auto data : s)
	{
		std::cout << data << ' ';
	}std::cout << std::endl;*/

	// 2. map
	// key - value
	// "apple" - "alma"

	//std::map<int, std::string>mp;

	//mp.insert({ 12, "Ferrari 458" });
	//mp.insert({ 0, "Mustang" });
	//mp.insert({ 0, "Ford" });
	//mp.insert({ 4, "VAZ2107" });
	//mp.insert({ 5, "Opel" });
	//mp.insert({ 7, "Galendevagen" });

	//for (auto car : mp)
	//{
	//	
	//	std::cout << car.first; // key
	//	std::cout << " : ";
	//	std::cout << car.second << std::endl; // key value
	//}

	/*std::map<std::string, std::string> ypx;

	ypx.insert({ "99-CE-999", "Mercedes 55 Amg" });
	ypx.insert({ "90-AA-001", "Mercedes Maybach" });
	ypx.insert({ "10-TT-100", "Hyundai Santafe" });
	ypx.insert({ "99-CC-777", "Porche Cayenne" });

	ypx["90-AA-001"] = "Kia Optima";
	ypx["90-AA-002"] = "Hyundai Senata";
	
	for (auto car : ypx)
	{
		std::cout << car.first << " - ";
		std::cout << car.second << std::endl;
	}*/

	//std::cout << ypx["99-CC-778"] << std::endl;
	
	//Car c1;

	//c1.properties["Name"] = "Ford Mustang";
	//c1.properties["Speed"] = "400";
	//c1.properties["Mass"] = "2000kg";

	//Car c2;
	//c2.properties["Name"] = "Nissan GTR350";
	//c2.properties["Speed"] = "320";
	//c2.properties["Mass"] =	 "1000kg";
	//c2.properties["Engine-type"] = "Comprosser";

	//c1.print();
	//std::cout << std::endl;
	//c2.print();

	//std::cout << c1.properties["Name"] << std::endl;

	//// kochurmek
	//c1.properties = c2.properties;

	//c1.print();
	//std::cout << std::endl;
	//c2.print();

	/*Ypx y;

	y.penalties["99-CC-999"].push_back("Suret heddi 60AZN");
	y.penalties["99-CC-999"].push_back("Dayanma durma 20AZN");
	y.penalties["99-CC-999"].push_back("Kemer 40AZN");

	y.penalties["90-AA-777"].push_back("Qosha xett 100AZN");
	y.penalties["90-AA-777"].push_back("Dayanma durma 20AZN");
	y.penalties["90-AA-777"].push_back("Suret heddi 60AZN");*/

	//y.print();

	//y.showCarPenalties("90-AA-777");

	//y.penalties.erase("key") delete

	//multi set eyni elementler elave oluna bilir, unikal olmur
	// ve sort olunur.

	/*std::multiset<int> mset;

	for (size_t i = 0; i < 10; i++)
	{
		int num = rand() % 10;
		std::cout << num << ' ';
		mset.insert(num);
	}std::cout << std::endl;

	for (auto i : mset)
	{
		std::cout << i << " ";
	}std::cout << std::endl;*/

	/*std::multimap<std::string, std::string> multimp;
	multimp.insert({ "Bmw", "Black" });
	multimp.insert({ "Audi", "White" });
	multimp.insert({ "Bmw", "Yellow-Red" });

	for (auto& i : multimp)
	{
		std::cout << i.first << " - " << i.second << std::endl;
	}*/

	// list and forward list;
	//forward list ancaq next'i saxladighi uchun geriye getmek olmur.
	// buna gore de decrement operatoru overload olunmayib.

	//std::forward_list<int>fl; // only next
	//std::list<int> l; // both - prev and next

	//for (size_t i = 0; i < 10; i++)
	//{
	//	fl.push_front(i);
	//	l.push_back(i);
	//}

	//for (auto& i : fl)
	//{
	//	std::cout << i << ' ';
	//}std::cout << std::endl;

	//for (auto& i : l)
	//{
	//	std::cout << i << ' ';
	//}std::cout << std::endl;
}