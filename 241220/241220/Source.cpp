#include <iostream>
#include <vector> 
#include <list>
#include <time.h>

class Iterator
{
	int* ptr;
public:
	Iterator() : ptr(NULL) {}
	Iterator(int* ptr) : ptr(ptr) {}

	int& operator*() {
		return *this->ptr;
	}

	Iterator& operator++()
	{
		//ptr++;
		//ptr = ptr->next;
		//ptr = ptr->right;
		return *this;
	}

	Iterator operator++(int)
	{
		ptr++;
		return ptr;
	}

	bool operator!=(const Iterator& other)
	{
		return this->ptr != other.ptr;
	}

	bool operator==(const Iterator& other)
	{
		return this->ptr == other.ptr;
	}
	
};
class Array
{
	int size;
	int* data;
public:
	Array(int size) : size(size)
	{
		data = new int[size] {};
		for (size_t i = 0; i < size; i++)
		{
			data[i] = rand() % 30;
		}
	}

	Iterator begin() const
	{
		return Iterator(data);
	}

	Iterator end() const
	{
		return Iterator(data + size);
	}
};
class Car
{
	std::string model;
	int year;
public:
	Car(const std::string& model, const int& year) :
		model(model), year(year) {}

	void show() const
	{
		std::cout << "+++++++++++++++++++" << std::endl;
		std::cout << "Model: " << model << std::endl;
		std::cout << "Year: " << year << std::endl;
	}
};


void main()
{

	/*std::vector<Car>cars;
	cars.push_back(Car("Mercedes", 2010));
	cars.push_back(Car("Bmw", 2005));
	cars.push_back(Car("Audi", 2020));


	for (auto car : cars)
	{
		car.show();
	}*/

	//srand(time(NULL));
	//custom iterator class

	/*Array myArray(30);

	for (auto item : myArray)
	{
		std::cout << item << ' ';
	}std::cout << std::endl;

	for (auto i = myArray.begin(); i != myArray.end(); i++)
	{
		std::cout << *i << ' ';
	}std::cout << std::endl;*/
	// vector == array

	//std::vector<int>v1(10); // birbasa size vermek.
	//std::vector<int>v2;
	//std::vector<int>v3 = { 1,2,3,4,5 };

	//std::cout << v1.size() << std::endl;
	//std::cout << v2.size() << std::endl;
	//std::cout << v3.size() << std::endl;
	//std::cout << v3[0] << std::endl;
	//std::cout << v3.at(1) << std::endl;

	/*std::vector<int> v;

	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i + 1000);
	}

	for (size_t i = 0, length = v.size(); i < length; i++)
	{
		std::cout << v[i] << ' ';
	}std::cout << std::endl;

	std::cout << "Capacity: " << v.capacity() << std::endl;

	v.clear();

	v.pop_back();

	if (v.empty())
		std::cout << "Vector is empty" << std::endl;
	else
	{
		for (size_t i = 0, length = v.size(); i < length; i++)
		{
			std::cout << v[i] << ' ';
		}
	}std::cout << std::endl;

	std::cout << "Capacity: " << v.capacity() << std::endl;
	v.shrink_to_fit();
	std::cout << "Capacity: " << v.capacity() << std::endl;

	v.erase(v.cend() - 3);
	v.erase(v.cbegin() + 3);

	if (v.empty())
		std::cout << "Vector is empty" << std::endl;
	else
	{
		for (size_t i = 0, length = v.size(); i < length; i++)
		{
			std::cout << v[i] << ' ';
		}
	}std::cout << std::endl;

	v.insert(v.begin() + 3, 1003);
	v.insert(v.end() - 2, 1006);

	if (v.empty())
		std::cout << "Vector is empty" << std::endl;
	else
	{
		for (size_t i = 0, length = v.size(); i < length; i++)
		{
			std::cout << v[i] << ' ';
		}
	}std::cout << std::endl;

	v.insert(v.end(), { 1009,1010,1011,1012 });

	if (v.empty())
		std::cout << "Vector is empty" << std::endl;
	else
	{
		for (size_t i = 0, length = v.size(); i < length; i++)
		{
			std::cout << v[i] << ' ';
		}
	}std::cout << std::endl;

	std::vector<int> v2;
	v2.assign(v.begin(), v.end());

	if (v.empty())
		std::cout << "Vector is empty" << std::endl;
	else
	{
		for (size_t i = 0, length = v.size(); i < length; i++)
		{
			std::cout << v2[i] << ' ';
		}
	}std::cout << std::endl;

	if (v.empty())
		std::cout << "Vector is empty" << std::endl;
	else
	{
		for (size_t i = 0, length = v.size(); i < length; i++)
		{
			std::cout << v[i] << ' ';
		}
	}std::cout << std::endl;

	std::vector<int> v3{ 100 };

	std::cout << v3[0] << std::endl;
*/

	//list == double linked list

	/*std::list<int> l;

	l.assign(v.begin(), v.end());

	for (auto i = l.begin(); i != l.end(); i++)
	{
		std::cout << *i << ' ';
	}std::cout << std::endl;*/

	/*for (size_t i = 0; i < 10; i++)
	{
		l.push_back(i + 1000);
	}

	for (auto i = l.begin(); i != l.end(); i++)
	{
		std::cout << *i << ' ';
	}std::cout << std::endl;*/


	/*for (std::list<int>::iterator i = l.begin(); i != l.end(); i++)
	{
		std::cout << *i << ' ';
	}std::cout << std::endl;*/

	/*for (auto item : l)
	{
		std::cout << item << ' ';
	}std::cout << std::endl;*/


	//std::vector<int >::iterator myIterator;
}