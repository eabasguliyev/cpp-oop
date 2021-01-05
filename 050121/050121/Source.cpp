#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <map>
bool Desct(int a, int b)
{
	return a > b;
}


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
	void setAge(const int& age) { this->age = age; }

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
//functor class
class ByAge
{
	bool order;

public:
	ByAge(const bool& order)
	{
		setOrder(order);
	}
	void setOrder(const bool& order) { this->order = order; }

	bool operator()(const Kitty& a, const Kitty& b)
	{
		if (order)
			return a.getAge() < b.getAge();
		else
			return a.getAge() > b.getAge();
	}
};

class ByAgeStr
{
	std::string order;

public:
	ByAgeStr(const std::string& order)
	{
		setOrder(order);
	}
	void setOrder(const std::string& order) { this->order = order; }

	bool operator()(const Kitty& a, const Kitty& b)
	{
		if (order == "Asc")
			return a.getAge() < b.getAge();
		else if(order == "Desc")
			return a.getAge() > b.getAge();
	}
};

class ByName
{
	std::string order;

public:
	ByName(const std::string& order)
	{
		setOrder(order);
	}
	void setOrder(const std::string& order) { this->order = order; }

	bool operator()(const Kitty& a, const Kitty& b)
	{
		if (order == "Asc")
			return a.getName() < b.getName();
		else
			return a.getName() > b.getName();
	}
};

// functor > predicate


// FUNCTOR VS PREDICATE

int increment(int i)
{
	return i + 1;
}

int doubleIncrement(int i)
{
	return i * 2;
}

int incrementByFifthy(int i)
{
	return i + 50;
}

class Increment
{
	int num;

public:
	Increment(const int& num) : num(num) {}

	int operator()(const int& arr_num)
	{
		return arr_num + num;
	}
};


class Decrease
{
	double percent;
public:
	Decrease(const double& percent) : percent(percent) {}
	
	double operator() (const double& arr_num)
	{
		return arr_num - ((arr_num * percent) / 100);
	}
};


int mult(int a, int b)
{
	//std::cout << "a: " << a << std::endl;
	return a * b;
}

void print(const int& i)
{
	std::cout << i << std::endl;
}

class Student
{
	std::string name;
	std::string surname;
	double score;
public:
	Student(const std::string& name, const std::string& surname,
		const double& score) :name(name), surname(surname), score(score) {}

	std::string getName() const { return this->name; }
	std::string getSurname() const { return this->surname; }
	double getScore() const { return this->score; }
};

// questions

class A {
public:
	std::map<int, int> datas;
	virtual ~A() = 0 {}
};

class B : public A
{
public:
	void show() {
		for (auto& data : datas)
		{
			std::cout << data.first << " " << data.second << std::endl;
		}
	}
};
void main()
{
	B obj;

	obj.datas.insert({ 1, 1 });
	obj.datas.insert({ 2, 2 });
	obj.datas.insert({ 3, 3 });
	obj.show();

	//lambda expression - anonim funksiyalar
	//with class

	/*std::vector<Student> students;

	students.emplace_back("john", "johnlu", 76);
	students.emplace_back("leyla", "ibrahimova", 87);
	students.emplace_back("ramiz", "memmedov", 98);
	students.emplace_back("mike", "tyson", 100);

	for_each(students.begin(), students.end(), [](const Student& s)
		{
			std::cout << std::string(20, '#') << std::endl;
			std::cout << "Name: " << s.getName() << std::endl;
			std::cout << "Score: " << s.getScore() << std::endl;
		});

	int c = count_if(students.begin(), students.end(), [](const Student& s)
		{
			return s.getScore() >= 80;
		});

	std::cout << "Count of best students: " << c << std::endl;*/

	//std::vector<int> v;

	//for (size_t i = 0; i < 15; i++)
	//{
	//	v.push_back(rand() % 15);
	//}

	////for_each(v.begin(), v.end(), [](int i) {
	////	i *= 10;
	////	std::cout << i << ' ';
	////	});

	//std::cout << std::endl;

	//std::sort(v.begin(), v.end(), [](int a, int b)-> bool
	//	{
	//		return a > b;
	//	});

	///*for_each(v.begin(), v.end(), [](int i) {
	//	i *= 10;
	//	std::cout << i << ' ';
	//	});*/

	//std::cout << std::endl;

	//for (auto& i : v)
	//{
	//	std::cout << i << ' ';
	//}std::cout << std::endl;
	////ilk tapdighini geri qaytarir
	///*auto p = std::find_if(v.begin(), v.end(), [](int i)
	//	{
	//		return i < 7;
	//	});

	//std::cout << *p << std::endl;*/

	//// count 

	//int c = count_if(v.begin(), v.end(), [](int i)->bool
	//	{
	//		return i > 8;
	//	});

	//std::cout << "Count: " << c << std::endl;

	/*std::vector<int> v;

	for (size_t i = 0; i < 10; i++)
	{
		v.emplace_back(rand() % 10 + 1);
	}
	v.emplace_back(7);
	v.emplace_back(7);*/
	//reverse(v.begin(), v.end());
	//std::sort(v.begin(), v.end(), Desct);
	//std::sort(v.begin(), v.end());
	//for (auto& i : v)
	//{
	//	std::cout << i << ' ';
	//}std::cout << std::endl;

	//std::cout << "Max: " << *(std::max_element(v.begin(), v.end())) << std::endl;
	//std::cout << "Min: " << *(std::min_element(v.begin(), v.end())) << std::endl;
	//
	////std::replace(v.begin(), v.end(), 5, 11);

	//for (auto& i : v)
	//{
	//	std::cout << i << ' ';
	//}std::cout << std::endl;


	//int sum = accumulate(v.begin(), v.end(), 0);

	//std::cout << "Sum: " << sum << std::endl;

	//int product = accumulate(v.begin(), v.end(), 1, mult);

	//std::cout << "Product: " << product << std::endl;

	
	//count
	/*for (auto& i : v)
	{
		std::cout << i << ' ';
	}std::cout << std::endl;


	int count = std::count(v.begin(), v.end(), 7);
	std::cout << "Count: " << count << std::endl;*/

	// find

	//for (auto & i : v)
	//{
	//	std::cout << i << ' ';
	//}std::cout << std::endl;

	/*try
	{
		auto data = find(v.begin(), v.end(), 55);

		std::cout << "Element: " << *data << std::endl;
	}
	catch (const std::exception& ex)
	{
		ex.what();
	}*/

	// binary search
	//eyni elementde problem yaradir
	/*std::sort(v.begin(), v.end());

	bool result = std::binary_search(v.begin(), v.end(), 7);

	std::cout << std::boolalpha << result << std::endl;*/

	//const int size = 8;
	//double arr[size] = { 1,2,3,4,5,6,7,8 };

	//for (size_t i = 0; i < size; i++)
	//{
	//	std::cout << arr[i] << ' ';
	//}std::cout << std::endl;

	////transform(arr, arr + size, arr, increment);
	////transform(arr, arr + size, arr, doubleIncrement);
	////transform(arr, arr + size, arr, incrementByFifthy);
	//transform(arr, arr + size, arr, Increment(100));
	//for (size_t i = 0; i < size; i++)
	//{
	//	std::cout << arr[i] << ' ';
	//}std::cout << std::endl;
	//transform(arr, arr + size, arr, Decrease(20));

	//for (size_t i = 0; i < size; i++)
	//{
	//	std::cout << arr[i] << ' ';
	//}std::cout << std::endl;
	//std::list<Kitty> kitties;

	//kitties.push_back(Kitty("Toplan", "Top123", 35));
	//kitties.push_back(Kitty("Mestan", "Qara", 8));
	//kitties.push_back(Kitty("Jay-jay", "qara jay", 5));
	//kitties.push_back(Kitty("Garfield", "HungryKitty", 50));

	//std::cout << "Un ordered list" << std::endl;

	//printKitties(kitties);

	////std::cout << "After remove" << std::endl;
	//std::cout << "Sorted" << std::endl;
	//
	////kitties.sort(ByAgeStr("Asc"));
	//kitties.sort(ByName("Desc"));
	////kitties.remove_if(nicknameGreaterThan7);

	//printKitties(kitties);
	/*list<int> a;

	for (size_t i = 0; i < 10; i++)
	{
		a.push_back(rand() % 10);
	}

	std::cout << "Unsorted" << std::endl;

	for (auto& i : a)
	{
		std::cout << i << " ";
	}std::cout << std::endl;

	a.sort(Desct);

	for (auto& i : a)
	{
		std::cout << i << " ";
	}std::cout << std::endl;*/
}