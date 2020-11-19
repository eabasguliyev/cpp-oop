#include <iostream>
#include <initializer_list>
#include <assert.h>

template <typename T, int n>
class FixedArray
{
	T arr[n];
	size_t size;

public:
	FixedArray(int a, int b)
	{
		std::cout << "T a, T b" << std::endl;
	}

	FixedArray(std::initializer_list<T> list):size(0)
	{
		for (T element : list)
		{
			arr[size++] = element;
		}
	}


	T& operator[](size_t index)
	{
		return arr[index];
	}

	void show() const
	{
		for (size_t i = 0; i < n; i++)
		{
			std::cout << arr[i] << ' ';
		}std::cout << std::endl;
	}
};

//Data Structure
//Stack, Queue

// Stack - first in last out.
//


// product id, name, orice, discount


class Product
{
	size_t id;
	std::string name;
	double price;
	double discount;

public:
	static size_t current_id;
	Product() :id(0), name(""), price(0), discount(0) {}

	Product(std::string name, double price, double discount)
	{
		setName(name);
		setPrice(price);
		setDiscount(discount);
		this->id = ++current_id;
	}

	void setName(const std::string& name)
	{
		assert(!name.empty() && "Name is blank!");
		this->name = name;
	}

	std::string getName() const
	{
		return this->name;
	}

	void setPrice(double price)
	{
		assert(price > 0 && "Price must be greater than zero");
		this->price = price;
	}

	double getPrice() const
	{
		return this->price;
	}

	void setDiscount(double discount)
	{
		assert(discount >= 0 && "Discount must be positive value");
		this->discount = discount;
	}

	double getDiscount() const
	{
		return discount;
	}

	double getPriceWithDiscount() const
	{
		return price - (price * discount) / 100;
	}

	void show() const
	{
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Price: " << getPrice() << std::endl;
		std::cout << "Discount: " << getDiscount() << std::endl;
		std::cout << "Price with discount: " << getPriceWithDiscount() << std::endl;
	}
};
size_t Product::current_id = 0;
template <class T>
class Stack
{
	T* data;
	size_t size;
public:
	Stack() : data(nullptr), size(0) {}

	Stack(const Stack& other)
	{
		this->size = other.getSize();
		/*if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}*/

		data = new T[size] {};

		for (size_t i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}

	Stack& operator=(const Stack& other)
	{
		this->size = other.getSize();
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}

		data = new int[size] {};

		for (size_t i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
		return *this;
	}

	void push(T value)
	{
		auto data = new T[size + 1];

		if (data != nullptr)
		{
			if (size)
			{
				for (size_t i = 0; i < size; i++)
				{
					data[i] = this->data[i];
				}

				delete[] this->data;
				this->data = nullptr;
			}

			data[size] = value;

			this->data = data;
			data = nullptr;

			this->size++;

		}
	}

	T pop()
	{
		assert(size && "There is no data");
		T value = data[size - 1];

		size_t new_size = size - 1;

		auto data = new T[new_size];

		if (data != nullptr)
		{
			for (size_t i = 0; i < new_size; i++)
			{
				data[i] = this->data[i];
			}

			delete[] this->data;

			this->data = data;
			data = nullptr;

			this->size--;
		}

		return value;
	}

	T peek()
	{
		assert(size && "There is no data");
		return data[size - 1];
	}

	size_t getSize() const
	{
		return this->size;
	}

	void clear()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
			size = 0;
		}
	}

	~Stack()
	{
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
	}
};

//	queque - novbe : FIFO - first in first out

template <class T>
class Queue
{
	T* data;
	int capacity;
	int front;
	int rear; // current
	int count;

public:
	Queue(int size)
	{
		this->data = new T[size];
		this->capacity = size;
		this->front = 0;
		this->rear = 0;
		this->count = 0;
	}


	T peek()
	{
		return data[front];
	}
	void enqueue(T value)
	{
		assert(!isFull() && "Queue is full");

		data[rear++] = value;
		count++;
	}

	void dequeue()
	{
		assert(!isEmpty() && "Queue is empty");
		auto temp = new T[size() - 1];
		for (size_t i = 0, length = count - 1; i < length; i++)
		{
			temp[i] = data[i + 1];
		}

		delete[] data;
		data = temp;
		temp = nullptr;
		count--;
	}

	bool isEmpty()
	{
		return size() == 0;
	}
	int size()
	{
		return count;
	}
	bool isFull()
	{
		return size() == this->capacity;
	}
	~Queue()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
};
/*class Queue
{
	int* data;
	int capacity;
	int front;
	int rear; // current
	int count;

public:
	Queue(int size)
	{
		this->data = new int[size];
		this->capacity = size;
		this->front = 0;
		this->rear = 0;
		this->count = 0;
	}


	int peek()
	{
		return data[front];
	}
	void enqueue(int value)
	{
		assert(!isFull() && "Queue is full");

		data[rear++] = value;
		count++;
	}

	void dequeue()
	{
		assert(!isEmpty() && "Queue is empty");
		auto temp = new int[size() - 1];
		for (size_t i = 0, length = count - 1; i < length; i++)
		{
			temp[i] = data[i + 1];
		}

		delete[] data;
		data = temp;
		temp = nullptr;
		count--;
	}

	bool isEmpty()
	{
		return size() == 0;
	}
	int size()
	{
		return count;
	}
	bool isFull()
	{
		return size() == this->capacity;
	}
	~Queue()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
};*/
void main()
{
	std::string p1_name = "milk";
	std::string p2_name = "cola";;
	Product p1(p1_name, 10, 4);
	Product p2(p2_name, 8, 4);

	Queue<Product> myqueue(2);

	myqueue.enqueue(p1);
	myqueue.enqueue(p2);

	std::cout << "is empty: " << std::boolalpha << myqueue.isEmpty() << std::endl;
	std::cout << "Is full: " << std::boolalpha << myqueue.isFull() << std::endl;

	while (!myqueue.isEmpty())
	{
		myqueue.peek().show();
		myqueue.dequeue();
	}

	std::cout << "is empty: " << std::boolalpha << myqueue.isEmpty() << std::endl;
	std::cout << "Is full: " << std::boolalpha << myqueue.isFull() << std::endl;


	/*Queue<int> myqueue(10);
	for (size_t i = 0;!myqueue.isFull(); i++)
	{
		myqueue.enqueue(i + 10);
	}

	while (!myqueue.isEmpty())
	{
		std::cout << myqueue.peek() << std::endl;
		myqueue.dequeue();
	}*/
	/*FixedArray<int, 5> obj{ 1,2,3,4,5 };

	obj.show();*/

	/*Stack<Product> stock;

	std::string p1_name = "milk";
	std::string p2_name = "cola";;
	Product p1(p1_name, 10, 4);
	Product p2(p2_name, 8, 4);

	stock.push(p1);
	stock.push(p2);
	int size = stock.getSize();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << stock.pop().getName() << std::endl;
	}*/
	/*p1.show();*/

	/*Stack<char> mystack;

	mystack.push('1');
	mystack.push('2');
	mystack.push('3');

	for (size_t i = 0, length = mystack.getSize(); i < length; i++)
	{
		std::cout << mystack.pop() << " last element" << std::endl;
	}*/

}