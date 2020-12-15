#include <iostream>
//#include <vector>
#include <typeinfo> // type_id
#include <string> // std::to_string, std::stoi

/*
class Animal
{
public:
	virtual void speak() {}
};

class Cat : public Animal {

};

class Person
{
public:
	//virtual void speak() {}
};

class Normal : public Person {

};

class Int
{
	int x;

public:
	Int(int x = 0) : x(x) {
		std::cout << "Conversion constructo called" << std::endl;
	}

	int getX() const { return x; }

	operator std::string()
	{
		std::cout << "Conversion operator" << std::endl;

		return std::to_string(x);
	}
};
*/
/*class Base {

public:
	int getX()
	{
		return 10;
	}
};

class Derived : public Base {

public:
	int getXDerived()
	{
		return 10;
	}
};

class Student {
	int x;
public:
	int getX()
	{
		return x;
	}
};*/

class Base {
protected:
	int value;
public:
	Base(int value) : value(value) {}

	virtual ~Base() {}
};

class Derived : public Base
{
protected:
	std::string name;

public:
	Derived(const int & value, const std::string & name):
		Base(value), name(name){ }

	std::string getName() const { return this->name; }
};

Base* getObject(bool isReturnDerived)
{
	if (isReturnDerived)
		return new Derived{ 1, "apple" };
	else
		return new Base{ 2 };
}

class Animal
{
public:
	Animal() {}
	virtual ~Animal() {}

};

class Cat : public Animal
{
public:
	Cat() {}
	void speakAsCat()
	{
		std::cout << "I am cat!" << std::endl;
	}

};

class Dog : public Animal
{
public:
	Dog() {}
	void speakAsDog()
	{
		std::cout << "I am dog!" << std::endl;
	}
};

class Dragon : public Animal
{
public:
	Dragon() {}
	void speakAsDragon()
	{
		std::cout << "I am dragon!" << std::endl;
	}
};


// Const cast

class Student
{
private:
	mutable int roll = 0; // const olsa deyishile bilir.
public:
	Student(int r) :roll(r) {}

	void fun() const {
		//this->roll = 100; // error;

		(const_cast<Student*>(this))->roll = 100;
	}

	int getRoll() const { return this->roll; }
};

class A
{
public:
	int getData()
	{
		return 10;
	}
};

void main()
{
	//vector

	/*std::vector<int> my_vector;

	my_vector.push_back(5);
	my_vector.push_back(4);


	for (size_t i = 0, length = my_vector.size(); i < length; i++)
	{
		std::cout << my_vector[i] << std::endl;
	}*/

	//typeid()

	/*int a = 5;
	float b = 10.6;
	char c = 'c';

	const type_info& ti_a = typeid(a);
	const type_info& ti_a2 = typeid(a);
	const type_info& ti_b = typeid(b);
	const type_info& ti_c = typeid(c);

	std::cout << ti_a.name() << std::endl;
	std::cout << ti_b.name() << std::endl;
	std::cout << ti_c.name() << std::endl;
	std::cout << ti_a.hash_code() << std::endl;
	std::cout << ti_a.before(ti_a2) << std::endl;
	std::cout << ti_a.before(ti_b) << std::endl;
	std::cout << ti_a.raw_name() << std::endl;
	std::cout << ti_a2.raw_name() << std::endl;
	std::cout << ti_b.raw_name() << std::endl;*/

	/*Cat cat;
	Animal& animal = cat;
	Normal normal;

	Person& person = normal;
	Person* person2 = new Normal;
	std::cout << "Reference to non-polymorphic base : " <<
		typeid(person).name() << std::endl;

	std::cout << "Reference to polymorphic base : " <<
		typeid(animal).name() << std::endl;

	std::cout << "Reference to polymorphic base : " <<
		typeid(*person2).name() << std::endl;*/

	//bad_ptr

	//Cat* bad_ptr = NULL;
	//std::cout << "bad_ptr points to none -> " << typeid(*bad_ptr).name()
	//	<< std::endl;

	//try
	//{
	//	//Cat* bad_ptr = NULL;
	//	//Normal* bad_ptr = NULL;
	//	//int* bad_ptr = NULL;
	//	Animal* bad_ptr = new Cat;
	//	std::cout << "bad_ptr points to none -> " << typeid(*bad_ptr).name()
	//		<< std::endl;
	//}
	//catch (const std::exception& ex)
	//{
	//	std::cout << "Error: " << ex.what() << std::endl;
	//}


	//Typecasting
	//implicit qeyri-ashkar

	//explicit ashkar

	// c++ supports four types of casting

	// Static cast
	// Dynamic cast
	// Const cast
	// Reinterpret cast


	// static cast

	// basic usage

	/*float f = 3.5;
	int b = static_cast<int>(f);

	std::cout << "b: " << b << std::endl;*/

	// problem without static casting
	
	/*int a = 10;
	char c = 'a';

	int* ptr = (int*) & c; // show us garbage data
	std::cout <<* ptr << std::endl;

	int* ptr2 = static_cast<int*> (&c); //compile time error
	*/ 

	// with class
	
	/*Int obj(32);

	std::string str = obj;

	std::cout << "str: " << str << std::endl;

	obj = 20;

	str = obj;
	std::cout << str << std::endl;

	std::string str2 = static_cast<std::string>(obj);

	std::cout << "str2: " << str2 << std::endl;
	obj = static_cast<Int>(30);

	std::cout << obj.getX() << std::endl;

	int a = std::stoi("a");

	std::cout << a << std::endl;*/

	//upcasting downcasting and benefits
	
	/*
	Derived d1;
	Base* b = (Base*)&d1;
	Base* b2 = static_cast<Base*> (&d1);
	Derived* d2 = static_cast<Derived*> (b2);


	Student* f = (Student*)(&d1);
	
	std::cout << f->getX() << std::endl;

	Student* f2 = static_cast<Student*>(&d1); //compile time error
	*/


	// Dynamic cast
	
	/*Base* obj = getObject(false);
	Derived* d = dynamic_cast<Derived*> (obj);


	if (d != NULL)
		std::cout << "Name: " << d->getName() << std::endl;
	else
		std::cout << "Can not cast base to derived : nullptr" << std::endl;*/
	
	/*Cat* cat1 = new Cat;
	Cat* cat2 = new Cat;
	Dog* dog1 = new Dog;
	Dog* dog2 = new Dog;
	Dragon* dragon1 = new Dragon;
	Dragon* dragon2 = new Dragon;
	Animal** animals = new Animal*[6]{ dog1, dog2, cat1, cat2,
		dragon1, dragon2 };

	for (size_t i = 0; i < 6; i++)
	{
		auto cat = dynamic_cast<Cat*>(animals[i]);

		if (cat != NULL)
			cat->speakAsCat();
		else
			std::cout << "I am not cat!" << std::endl;
	}*/


	//Const cast - compiler time
	
	/*Student s(10);

	std::cout << "Data: " << s.getRoll() << std::endl;

	s.fun();
	std::cout << "Data: " << s.getRoll() << std::endl;*/
	
	/*const int val = 10;
	const int val2 = 20;
	const int* ptr = &val;
	
	int* ptr1 = const_cast<int*>(ptr);


	*ptr1 = 1000;

	std::cout << "Val: " << val << std::endl;
	std::cout << "Ptr: " << *ptr << std::endl;
	std::cout << "Ptr2: " << *ptr1 << std::endl;*/

	//Reinterpret cast

	int* p = new int(65);
	char* ch = reinterpret_cast<char*>(p);
	A* a = reinterpret_cast<A*>(p);


	std::cout << "P: " << *p << std::endl;
	std::cout << "Ch: " << ch << std::endl;
	std::cout << "A: " << a->getData() << std::endl;
}