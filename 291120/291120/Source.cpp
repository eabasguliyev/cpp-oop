#include <iostream>



class List
{

public:
	List() : head(NULL), tail(NULL) {}

private:
	class Node {
		int data;
		Node* next;
		Node* prev;
	};

private:
	Node* head;
	Node* tail;
};


class Product {
public:
	struct ProductType
	{
		enum type1 {
			FANCY, AWESOME, USEFUL
		};
	};

	struct ProductBoxType
	{
		enum type2 {
			BOX, BAG, CRATE
		};
	};

	Product(ProductType::type1 t, ProductBoxType::type2 bt, std::string name)
	{

	}
};

// Composition and Aggregation

class Time {
	int hour;
	int minute;
public:
	Time() {}

	Time(const int& minute, const int& hour)
	{
		setTime(minute, hour);
	}
	void setTime(const int& minute, const int& hour)
	{
		if (minute >= 0 && minute < 60)
			this->minute = minute;
		else
			this->minute = 0;

		if (hour >= 0 && hour < 24)
			this->hour = hour;
		else
			this->hour = 0;
	}

	int getMinute() const { return this->minute; }

	int getHour() const { return this->hour; }

	void showTime() const 
	{
		if (getHour() < 10)
			std::cout << '0';

		std::cout << getHour() << ':';

		if (getMinute() < 10)
			std::cout << '0';

		std::cout << getMinute() << std::endl;

	}
};

class Date {
	int day;
	int month;
	int year;

public:
	Date() {}
	Date(const int& day, const int& month, const int& year)
	{
		setDate(day, month, year);
	}

	void setDate(const int & day, const int & month, const int &year)
	{
		if (day > 0 && day <= 31)
			this->day = day;
		else
			this->day = 1;

		if (month > 0 && month <= 12)
			this->month = month;

		if (year > 0)
			this->year = year;
		else
			this->year = 0;

	}

	int getDay() const { return this->day; }

	int getMonth() const { return this->month; }

	int getYear() const { return this->year; }

	void showDate() const
	{
		if (getDay() < 10)
			std::cout << '0';

		std::cout << getDay() << '/';

		if (getMonth() < 10)
			std::cout << '0';

		std::cout << getMonth() << '/';

		if (getYear() < 100)
			std::cout << "20";

		std::cout << getYear() << std::endl;
	}
};

class Event
{
	std::string name;
	Time eventTime;
	Date eventDay;

public:
	Event(const int& minute, const int& hour, const int& day, 
		const int& month, const int& year, std::string name)
	{
		this->name = name;
		this->eventTime.setTime(minute, hour);
		this->eventDay.setDate(day, month, year);
	}

	void showEvent()
	{
		std::cout << "Event: " << this->name << " occurs ";
		eventDay.showDate();
		std::cout << " at ";
		eventTime.showTime();
		std::cout << std::endl;
	}
};


class Account
{
	std::string bank_name;
	std::string account_no;

};

class Customer
{
	std::string name;
	std::string surname;

	Account ** account;
};

//association
class Doctor;

class Patient
{

	bool hasIllness;

	void addDoctor(const Doctor& doctor)
	{
		this->hasIllness = true;
	}
};


// Dependency

class A
{
public:
	bool getResult()
	{
		return true;
	}
};

class B
{
public:
	B()
	{
		A a;

		if (a.getResult())
			std::cout << "Objrect Created" << std::endl;
		else
			std::cout << "Objrect d9d not Created" << std::endl;

	}
};

// Inheritance
/*
class Person
{
public:
	Person()
	{
		std::cout << "Constructor Person" << std::endl;
	}

	~Person()
	{
		std::cout << "Destructor Person" << std::endl;
	}
};

class Student :public Person
{
public:
	Student()
	{
		std::cout << "Constructor Student" << std::endl;
	}

	~Student()
	{
		std::cout << "Destructor Student" << std::endl;
	}
};
*/

class Person
{
	std::string name;
public:
	Person():name("")
	{
		std::cout << "Constructor Person" << std::endl;
	}

	Person(const std::string& name)
	{
		std::cout << "Constructor with param Person" << std::endl;
		this->name = name;
	}

	void showPerson()
	{
		std::cout << "Name: " << this->name << std::endl;
	}

	~Person()
	{
		std::cout << "Destructor Person" << std::endl;
	}
};

class Student :protected Person
{
	double avgScore;
public:
	Student():avgScore(0.0)
	{
		std::cout << "Constructor Student" << std::endl;
	}

	Student(const std::string& name, const double& avgScore):Person(name)
	{
		std::cout << "Constructor with param Student" << std::endl;
		this->avgScore = avgScore;
	}

	void showStudent()
	{
		showPerson();
		std::cout << "Average score: " << this->avgScore << std::endl;
	}
	~Student()
	{
		std::cout << "Destructor Student" << std::endl;
	}
};

//class A {
//private:
//	int a;
//protected:
//	int b;
//public:
//	int c;
//	A() {
//
//	}
//	void setA(int a, int b, int c) {
//		this->a = a;
//		this->b = b;
//		this->c = c;
//	}
//	void showA() {
//		cout << "a : " << a << " b : " << b << " c : " << c << endl;
//	}
//};
//
//class B : public A {
//private :
//	int d;
//public:
//	void setB(int d) {
//		setA(10, 20, 30);
//		this->d = d;
//	}
//	void showB() {
//		showA();
//		cout << c << endl;//public
//		cout << b << endl;//protected
//		//cout << a << endl;//inaccessible - private
//		cout << "d : "<<d << endl;
//	}
//};
//
//
//class C :protected A {
//private:
//	int d;
//public:
//	void setC(int d) {
//		setA(10, 20, 30);
//		this->d = d;
//	}
//
//	void showC() {
//		showA();
//		cout << c << endl;//protected
//		cout << b << endl;//protected
//		//cout << a << endl;//inaccesible private
//		cout << "d : " << d<<endl;
//	}
//};
//
//
//class D :private A {
//	int d;
//public:
//	D() {
//
//	}
//	A::b;
//	void setD(int d) {
//		setA(10, 20, 30);
//		this->d = d;
//	}
//
//	void showD() {
//		showA();
//		//cout << a << endl;//private inaccessible
//		cout << b << endl;//private - field
//		cout << c << endl;//private - field
//		cout << "d : " << d << endl;
//	}
//};
void main()
{
	//Person p1;

	Student s1("Elgun", 85);

	s1.showStudent();
	//Event e(30, 21, 8, 12, 2020, "Christmas");
	//e.showEvent();
	//Product p(Product::ProductType::FANCY, Product::ProductBoxType::BAG, "iphone 11 pro max");
	// scope resolution ::
	//List::Node* first = new List::Node;
	//List::Node* second = new List::Node;
	//List::Node* third = new List::Node;
	//List* list = new List;
}
