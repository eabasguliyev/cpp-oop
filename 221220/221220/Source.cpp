#include <iostream>
#include <string>
#include <time.h>

namespace Time
{
	std::string getDate()
	{
		time_t now(time(0));
		tm new_time;
		localtime_s(&new_time, &now);
		return std::to_string(new_time.tm_mday) + '/' + std::to_string(new_time.tm_mon + 1) + '/' +
			std::to_string(new_time.tm_year + 1900) + ' ' + std::to_string(new_time.tm_hour) + ':' + std::to_string(new_time.tm_min);
	}
}

class Person
{
	std::string name;
	std::string surname;
	size_t age;
	std::string speciality;
	std::string sendVoteDateTime;

public:
	Person() :name(""), surname(""), age(0), speciality(""),
		sendVoteDateTime("") {}

	Person(const std::string& name, const std::string& surname, const size_t& age, const std::string& speciality)
	{
		setName(name);
		setSurname(surname);
		setAge(age);
		setSpeciality(speciality);
		setVotedDateTime();
	}

	void setName(const std::string& name) { this->name = name; }
	std::string getName() const { return this->name; }
	void setSurname(const std::string& surname) { this->surname = surname; }
	std::string getSurame() const { return this->surname; }
	void setSpeciality(const std::string& speciality) { this->speciality = speciality; }
	std::string getSpeciality() const { return this->speciality; }
	void setAge(const size_t& age) { this->age = age; }
	size_t getAge() const { return this->age; }
	void setVotedDateTime(){ this->sendVoteDateTime = Time::getDate(); }
	std::string getVotedDateTime() const { return this->sendVoteDateTime; }

};

class President
{
	std::string name;
	std::string country;
	size_t workPractise;
public:
	President() : name(""), country(""), workPractise(0) {}

	President(const std::string& name, const std::string& country, const size_t& workPractise)
	{
		setName(name);
		setCountry(country);
		setWorkPractise(workPractise);
	}

	void setName(const std::string& name) { this->name = name; }
	std::string getName() const { return this->name; }
	void setCountry(const std::string& country) { this->country = country; }
	std::string getCountry() const { return this->country; }
	void setWorkPractise(const size_t& workPractise) { this->workPractise = workPractise; }
	size_t getWorkPractise() const { return this->workPractise; }
};

template <typename T>
class SharedPointer
{
	T* address;
	size_t* count;

public:
	SharedPointer() : address(NULL), count(NULL) {}
	explicit SharedPointer(T* address) :address(address), count(new size_t(1)) {}
	SharedPointer(const SharedPointer& other): address(other.address),
		count(other.count)
	{
		(*count)++;
	}
	SharedPointer& operator=(const SharedPointer& other)
	{
		if (this->count != NULL)
		{
			(*this->count)--;
			if (*this->count == 0)
			{
				delete this->address;
				delete this->count;
			}
		}

		this->address = other.address;
		this->count = other.count;
		(*this->count)++;
		return *this;
	}
	SharedPointer& operator=(T* other)
	{
		if (this->count != NULL)
		{
			(*this->count)--;
			if (*this->count == 0)
			{
				delete this->address;
				delete this->count;
			}
		}

		this->count = new size_t(1);
		this->address = other;

		return *this;
	}
	~SharedPointer()
	{
		if (this->count != NULL)
		{
			(*this->count)--;
			if (*this->count == 0)
			{
				delete this->address;
				delete this->count;
			}
		}
	}

	T* get() const { return this->address; }

	T& operator*() const { return *get(); };

	T* operator->() const { return get(); }
};

void main()
{
	
}

/*
class President{​​​​}​​​​;name ,country,workPractise
class Person {​​​​name,surname,age,speciality,sendVoteDateTime
}​​​​;
Presidentle Person arasindaki elaqeni ele qurunki ,person prezidente ses versin ve hemen prezident seslerini person terefinden hemen sayini gosterile bilsin .
sendVote eden kimi fayla bununla bagli melumatlar yazilsin ki , sesle bagli melumatlar yazilsin.
void main() {​​​​
President *presidentA=new President;
Person a;
a.sendVote(presidentA);



Person b;
b.sendVote(presidentA);
cout<<a->getVoteCount();//2



President* presidentB = new President;
Person a2;
a2.sendVote(presidentB);



Person b2;
b2.sendVote(presidentB);
cout << b2->getVoteCount();//2
//Person ve President
//Her bir Person ses gondere biler prezidente
//amma presidentde vote count gorunmur
//yalniz person adindan vote count u gostere bilersiniz
/*
President *president=new President;
Person a;
a.sendVote(president);



Person b;
b.sendVote(president);
cout<<a->getVoteCount();
*/
//template <typename T>
//class SharedPointer
//{
//	T* address;
//	size_t* count;
//
//public:
//	SharedPointer() : address(NULL), count(NULL) {}
//	explicit SharedPointer(T* address) :address(address), count(new size_t(1)) {}
//	SharedPointer(const SharedPointer& other): address(other.address),
//		count(other.count)
//	{
//		(*count)++;
//	}
//	SharedPointer& operator=(const SharedPointer& other)
//	{
//		if (this->count != NULL)
//		{
//			(*this->count)--;
//			if (*this->count == 0)
//			{
//				delete this->address;
//				delete this->count;
//			}
//		}
//
//		this->address = other.address;
//		this->count = other.count;
//		(*this->count)++;
//		return *this;
//	}
//	SharedPointer& operator=(T* other)
//	{
//		if (this->count != NULL)
//		{
//			(*this->count)--;
//			if (*this->count == 0)
//			{
//				delete this->address;
//				delete this->count;
//			}
//		}
//
//		this->count = new size_t(1);
//		this->address = other;
//
//		return *this;
//	}
//	~SharedPointer()
//	{
//		if (this->count != NULL)
//		{
//			(*this->count)--;
//			if (*this->count == 0)
//			{
//				delete this->address;
//				delete this->count;
//			}
//		}
//	}
//
//	T* get() const { return this->address; }
//
//	T& operator*() const { return *get(); };
//
//	T* operator->() const { return get(); }
//};
//
//class Student
//{
//public:
//	std::string name;
//	int age;
//
//	Student(const std::string& name, const int& age)
//		:name(name), age(age) {}
//};
//void main()
//{
//	/*int* a = new int(42);
//
//	int* b = a;
//
//	int* c = a;
//	std::cout << "a: " << *a << std::endl;
//	std::cout << "b: " << *b << std::endl;
//
//	delete a;
//	std::cout << "deleted a" << std::endl;
//	delete b;
//	std::cout << "deleted b" << std::endl;
//	delete c;
//	std::cout << "deleted c" << std::endl;*/
//
//	// Smart pointers:
//		//1. Shared pointer
//		//2. Unique poitner
//		//3. Weak pointer
//
//	//1. shared pointer
//	/*std::shared_ptr<int>a(new int(42));
//	std::shared_ptr<int>a2(a);*/
//
//	//SharedPointer<int> a(new int(42));
//	//SharedPointer<int> b(new int(30));
//	//b = a;
//	/*std::cout << "a: " << *a << std::endl;
//	std::cout << "a -> " << a.get() << std::endl;
//	std::cout << "b: " << *b << std::endl;
//	std::cout << "b -> " << b.get() << std::endl;*/
//	//SharedPointer<int>* c = new SharedPointer<int>(new int(42));
//	//delete c;
//	//delete b;
//	//delete a;
//	//SharedPointer<int> b = a;
//	/*std::shared_ptr<int>c(new int(42));
//	std::shared_ptr<int>d(c);*/
//	
//	SharedPointer<Student> s1(new Student("Elgun", 20));
//	SharedPointer<Student> s2(s1);//new Student("Resul", 19));
//
//	std::cout << "Student name: " << s1->name << std::endl;
//	std::cout << "Student age: " << s1->age << std::endl;
//	std::cout << std::endl;
//
//	std::cout << "Student name: " << s2->name << std::endl;
//	std::cout << "Student age: " << s2->age << std::endl;
//}