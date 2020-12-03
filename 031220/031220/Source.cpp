#include <iostream>

class Base
{
protected:
	int value;

public:
	int a;
	Base(int value)
	{
		this->value = value;
		//std::cout << "Constructor with Param Base" << std::endl;
	}

	virtual std::string getName()
	{
		return "I am Base";
	}

	int getValue()
	{
		return value;
	}

	~Base()
	{
		//std::cout << "Destructor Base" << std::endl;
	}
};

class Derived:public Base
{
public:
	Derived(int value):Base(value)
	{
		//std::cout << "Constructor with param Derived" << std::endl;
	}

	int getDouble()
	{
		return value * 2;
	}

	std::string getName()
	{
		return "I am Derived";
	}

	~Derived()
	{
		//std::cout << "Destructor derived" << std::endl;
	}
};

class Animal
{
protected:
	std::string name;

	Animal(std::string name)
	{
		this->name = name;
	}

public:
	std::string getName() const
	{
		return this->name;
	}

	virtual void speak()
	{
		std::cout << "??????????????????????????" << std::endl;
	}
};

class Cat : public Animal
{
public:
	Cat(std::string name) : Animal(name) {}

	void speak()
	{
		std::cout << "Meooooowwww" << std::endl;
	}

	void runForestRun() {}
};

class Dog :public Animal
{
public:
	Dog(std::string name) : Animal(name) {}

	void speak()
	{
		std::cout << "Havhavhav" << std::endl;
	}

	void BarkDogBark() {}
};

class Elephant :public Animal
{
public:
	Elephant(std::string name) : Animal(name) {}

	void speak()
	{
		std::cout << "Viiiiiuuuur" << std::endl;
	}
};

class Tiger :public Animal
{
public:
	Tiger(std::string name) :Animal(name) {}

	//void speak(int animal_id) override
	//void speak() override
	void speak() override final
	{
		std::cout << "Whaaaaahaiahaha" << std::endl;
	}
};
//template<typename T>
void showAnimal(Animal& animal)
{
	std::cout << "Name of animal: " << animal.getName() << std::endl;
	animal.speak();
}


//Binding

//Static Polymorphism
//Early Binding

//Dynamic Polymophism
//Late binding

void add(int a, int b)
{
	std::cout << a + b << std::endl;
}


class Human
{
protected:
	std::string name;
	int age;

	Human(const std::string& name, const int& age) :name(name), age(age) {}

public:
	virtual void Run()
	{
		std::cout << "My speed is not so good!" << std::endl;
	}

	virtual ~Human() {
		std::cout << "Destructor Human" << std::endl;
	}
};

class SimpleHuman : public Human
{
public:
	SimpleHuman(const std::string& name, const int& age) :Human(name, age)
	{
		std::cout << "Simple human constructor!" << std::endl;
	}

	~SimpleHuman()
	{
		std::cout << "Destructor simple human!" << std::endl;
	}
};

class UsainBolt : public Human
{
public:
	UsainBolt(const std::string& name, const int& age) :Human(name, age)
	{
		std::cout << "Usain Bolt constructor!" << std::endl;
	}

	void Run() override final
	{
		std::cout << "My speed is awesome!" << std::endl;
	}

	 ~UsainBolt()
	{
		std::cout << "Destructor Usain Bolt!" << std::endl;
	}
};

//virtual table haqqinda oxu.
void main()
{
	//Human* h1 = new SimpleHuman("Rafiq", 22);
	Human* h2 = new UsainBolt("Usain Bolt", 35);

	//h1->Run();

	h2->Run();

	//delete (UsainBolt*)h2;
	delete h2;
	// Early binding
	//add(10, 11);

	// Late binding
	//void (*ptr)(int, int) = add;

	//ptr(10, 11);
	/*Animal* toplan = new Dog("Toplan");
	Animal* mestan = new Cat("Mestan");
	Animal* fred = new Elephant("Elephant");

	std::cout << "Animal name: " << toplan->getName() << std::endl;
	toplan->speak();
	std::cout << "Animal name: " << mestan->getName() << std::endl;
	mestan->speak();

	std::cout << "Animal name: " << fred->getName() << std::endl;
	fred->speak();*/

	/*Animal* toplan = new Dog("Toplan");
	Animal* mestan = new Cat("Mestan");
	Animal* fred = new Elephant("Elephant");
	Animal* tiger = new Tiger("Tiger");*/
	//down cast
	/*auto dog = (Dog*)toplan;
	dog->BarkDogBark();*/

	
	// up cast
	/*auto dog2 = (Animal*)dog;

	dog2->speak();*/

	//Animal** animals = new Animal * [4]{ toplan, mestan, fred, tiger};
	/*Animal** animals = new Animal * [3]{ 
	new Dog("Toplan"),
	new Cat("Mestan"),
	new Elephant("Elephant")
	};
	*/
	/*for (size_t i = 0; i < 4; i++)
	{
		showAnimal(*animals[i]);
	}*/

	/*Base b(10);
	
	std::cout << b.getName() << std::endl;
	
	Derived d(20);

	std::cout << d.getName() << std::endl;*/
	
	/*Derived derived(55);

	Base *base = &derived;

	std::cout << base->getName() << std::endl;;*/

	/*Base* base = new Derived(10);


	std::cout << base->getName() << std::endl;*/
}


