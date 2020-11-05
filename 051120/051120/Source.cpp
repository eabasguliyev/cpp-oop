#include <iostream>
#include <assert.h>
#include <cmath>

class Int
{
	int num;
public:
	Int() :num(0) {}

	Int(int value)
	{
		setValue(value);
	}

	Int operator+(const Int & a)
	{
		Int result(a.getValue() + this->getValue());

		return result;
	}
	Int operator * (const Int& other)
	{
		Int result(other.getValue() * this->getValue());
		return result;
	}

	Int operator^(const Int& other)
	{
		Int temp(std::pow(this->getValue(), other.getValue()));
		return temp;
	}
	/*Int operator-(const Int& other)
	{
		Int result(other.getValue() - this->getValue());

		return result;
	}*/

	Int operator/(const Int& other)
	{
		assert(other.getValue() && "second element must be greater than zero");

		Int result(this->getValue() / other.getValue());

		return result;
	}

	Int operator%(const Int& other)
	{
		assert(other.getValue() && "second element must be greater than zero");
		Int result(this->getValue() % other.getValue());

		return result;
	}
	Int& operator++()
	{
		this->num++;
		return *this;
	}

	Int operator++(int)
	{
		Int temp = *this;
		this->num++;

		return temp;
	}

	Int& operator--()
	{
		this->num--;
		return *this;
	}

	Int operator--(int)
	{
		Int temp = *this;

		this->num--;

		return temp;
	}

	Int& operator+=(const Int& other)
	{
		this->num += other.getValue();
		return *this;
	}
	bool operator>(const Int & other)
	{
		return this->getValue() > other.getValue();
	}
	bool operator>=(const Int& other)
	{
		return this->getValue() >= other.getValue();
	}

	bool operator<(const Int& other)
	{
		return this->getValue() < other.getValue();
	}
	bool operator<=(const Int& other)
	{
		return this->getValue() <= other.getValue();
	}

	bool operator==(const Int& other)
	{
		return this->getValue() == other.getValue();
	}
	int getValue() const {
		return num;
	}

	void setValue(int num)
	{
		this->num = num;
	}


	void showValue()
	{
		std::cout << "Data: " << getValue() << std::endl;
	}
};

Int operator-(const Int& first, const Int& second)
{
	Int result(first.getValue() - second.getValue());

	return result;
}


class Vector
{
private:
	int* data;
	int size;
public:
	Vector() :data(nullptr), size(0) {}

	Vector(int * data, int size)
	{
		setSize(size);
		setData(data);
	}
	void setSize(int size)
	{
		assert(size && "size must be greater than zero");
		this->size = size;
	}


	int* getData() const
	{
		return data;
	}
	int getSize() const
	{
		return size;
	}

	int operator[](int index) const
	{
		assert(index >= 0 && index < this->getSize());
		return this->data[index];
	}
	void setData( int* data)
	{
		assert(data && "Null error");
		this->data = data;
		data = nullptr;
	}

	void print() const
	{
		for (size_t i = 0, length = getSize(); i < length; i++)
		{
			std::cout << (*this)[i] << ' ';
		}
		std::cout << std::endl;
	}

	bool operator>(const Vector& other)
	{
		return this->getSize() > other.getSize();
	}

	bool operator<(const Vector& other)
	{
		return this->getSize() < other.getSize();
	}

	bool operator>=(const Vector& other)
	{
		return this->getSize() >= other.getSize();
	}

	bool operator<=(const Vector& other)
	{
		return this->getSize() <= other.getSize();
	}

	int search(int value)
	{
		for (size_t i = 0, length = getSize(); i < length; i++)
		{
			if (data[i] == value)
				return i;
		}
		return -1;
	}

	void sort(bool reverse = false)
	{
		if (reverse) 
		{
			for (size_t i = 0, length = getSize(); i < length - 1; i++)
			{
				bool swapped = false;

				for (size_t j = 0; j < length - 1; j++)
				{
					if (data[j] > data[j + 1])
					{
						int temp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = temp;
						if (!swapped)
							swapped = true;
					}
				}

				if (!swapped)
					return;
			}
		}
		else
		{
			for (size_t i = 0, length = getSize(); i < length - 1; i++)
			{
				bool swapped = false;

				for (size_t j = 0; j < length - 1; j++)
				{
					if (data[j] < data[j + 1])
					{
						int temp = data[j + 1];

						data[j + 1] = data[j];
						data[j] = temp;
						if (!swapped)
							swapped = true;
					}
				}
				if (!swapped)
					return;
			}
		}
	}

	void pop(int index = -1) {
		// gondermese sonuncu, gonderse index.

		int new_size = getSize() - 1;
		int* new_data = new int[new_size];
		if (new_data)
		{
			if (index != -1)
			{
				for (size_t i = 0, j = 0; i < new_size + 1; i++)
				{
					if (index != i)
					{
						new_data[j++] = data[i];
					}
				}
			}
			else
			{
				for (size_t i = 0; i < new_size; i++)
				{
					new_data[i] = data[i];
				}

			}

			delete[] data;
			this->data = new_data;
			new_data = nullptr;
			this->size = new_size;
		}
	}
	
	void pushFirst(int value)
	{
		int new_size = getSize() + 1;
		int *new_data = new int[new_size];

		if (new_data)
		{
			new_data[0] = value;
			for (size_t i = 0, j = 1; i < getSize(); i++)
			{
				new_data[j++] = data[i];
			}

			delete[] this->data;
			this->data = new_data;
			new_data = nullptr;
			this->size = new_size;
		}
	}

	void pushLast(int value)
	{
		int new_size = getSize() + 1;
		int* new_data = new int[new_size];

		if (new_data)
		{
			new_data[new_size - 1] = value;
			for (size_t i = 0, j = 0; i < getSize(); i++)
			{
				new_data[j++] = data[i];
			}

			delete[] this->data;
			this->data = new_data;
			new_data = nullptr;
			this->size = new_size;
		}
	}

	void insertByIndex(int value, int index)
	{
		int new_size = getSize() + 1;
		int* new_data = new int[new_size];

		if (new_data)
		{
			//99
			//6
			//2 8 1 7 6 9 12
			for (int i = 0; i < index; i++)
			{
				new_data[i] = data[i];
			}

			new_data[index] = value;

			for (int i = index + 1; i < new_size; i++)
			{
				new_data[i] = data[i-1];
			}

			delete[] this->data;
			this->data = new_data;
			new_data = nullptr;
			this->size = new_size;
		}
	}
	~Vector()
	{
		delete[] data;
	}
};
int main()
{
	int size = 5;
	int size2 = 4;
	int* data = new int[size] {3,8,1,7,6};
	//int* data2 = new int[size2] {1, 2, 3, 4};
	Vector vector(data, size);
	/*Vector vector2(data2, size2);

	if (vector > vector2)
		std::cout << "Vector1 > vector2";
	else
		std::cout << "Vector1 > vector2";
	vector.print();
	std::cout << vector[3] << std::endl;*/

	//std::cout << vector.search(6) << std::endl;

	//vector.sort(true);

	vector.print();
	vector.pop(0);
	vector.print();
	vector.pushFirst(2);
	vector.print();
	vector.pushLast(9);
	vector.print();
	vector.pushLast(12);
	vector.sort();
	vector.print();

	vector.insertByIndex(99, 6);
	vector.print();
	/*Int a(6);
	Int b(5);

	a += a;
	a.showValue();
	b.showValue();

	Int c = a - b;

	c.showValue();
	if (a > b)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;*/
	/*Int c = a % b;

	c.showValue();


	std::cout << (a++).getValue() << std::endl;

	a.showValue();

	std::cout << (b--).getValue() << std::endl;

	b.showValue();*/
}