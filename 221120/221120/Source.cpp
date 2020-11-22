#include <iostream>


class CircularQueue
{
	int* data;
	int capacity;
	int front;
	int rear;
	int count;

public:
	CircularQueue() : data(nullptr), capacity(0), front(0), rear(0), count(0) {}

	CircularQueue(int size)
	{
		this->data = new int[size];
		this->capacity = size;
		this->front = 0;
		this->rear = 0;
		this->count = 0;
	}

	void enqueue(int value)
	{
		data[rear] = value;
		++rear;
		++count;
	}

	void dequeue()
	{
		auto temp = new int[getSize()];

		for (size_t i = 0, j = 1, length = getSize() - 1; i < length; i++, j++)
		{
			temp[i] = data[j];
		}

		temp[getSize() - 1] = data[0];

		delete[] data;
		data = temp;
		temp = nullptr;
	}

	int peek()
	{
		return this->data[front];
	}

	int getSize() const
	{
		return this->count;
	}
	bool isFull() { return this->capacity == getSize(); }
	bool isEmpty() { return getSize() == 0; }

	void showQueue() const
	{
		for (size_t i = 0, length = getSize(); i < length; i++)
		{
			std::cout << data[i] << ' ';
		}std::cout << std::endl;
	}
	~CircularQueue()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
};

template<class T>
class PriorityQueue
{
	T* data;
	int capacity;
	int front;
	int rear;
	int count;
public:
	PriorityQueue() {}
	PriorityQueue(int size) {
		data = new T[size];
		capacity = size;
		front = 0;
		rear = 0;
		count = 0;
	}
	
	void enqueue(T value)
	{
		data[rear] = value;
		rear++;
		count++;
	}

	void dequeue()
	{
		int index = getMaxElementIndex();

		if (index != -1)
		{
			int new_size = getSize() - 1;
			auto  tmp = new T[capacity];
			if (tmp != nullptr)
			{
				for (size_t i = 0; i < index; i++)
				{
					tmp[i] = data[i];
				}

				for (size_t i = index, length = getSize() - 1; i < length; i++)
				{
					tmp[i] = data[i + 1];
				}

				delete[] data;

				data = tmp;
				--count;
				--rear;
			}
		}
	}

	int getMaxElementIndex() const
	{
		T max = data[0];
		int maxIndex = -1;

		for (size_t i = 0, length = getSize(); i < length; i++)
		{
			if (max <= data[i])
			{
				max = data[i];
				maxIndex = i;
			}
		}
		
		return maxIndex;
	}
	int peek() const	{ return data[front]; }
	size_t getSize() const { return count; }
	bool isFull() const { return getSize() == capacity; }
	bool isEmpty() const { return getSize() == 0; }
	void showQueue() const
	{
		for (size_t i = 0, length = getSize(); i < length; i++)
		{
			std::cout << data[i] << ' ';
		}std::cout << std::endl;
	}


	T* getData() const
	{
		return data;
	}
	~PriorityQueue()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
	
};

class Node
{
public:
	int data;
	Node* next;
};

class LinkedList
{
public:
	void print_list(Node* n)
	{
		while (1)
		{
			std::cout << n->data << std::endl;
			if (n->next == NULL)
			{
				break;
			}
			n = n->next;
		}
	}

	void push_last(Node* head, int new_data)
	{
		Node* new_node = (Node*)malloc(sizeof(Node));

		new_node->data = new_data;
		new_node->next = NULL;
		while (1)
		{
			if (head->next == NULL)
			{
				head->next = new_node;
				break;
			}
			head = head->next;
		}
	}
	void push_first(Node*& head, int new_data)
	{
		Node* new_node = (Node*)malloc(sizeof(Node));

		new_node->data = new_data;
		new_node->next = head;

		head = new_node;
	}
	
	void insertAfter(Node* prev_node, int new_data)
	{
		if (prev_node == NULL)
		{
			std::cout << "Node cannot be null!\n";
			return;
		}

		Node* new_node = (Node*)malloc(sizeof(Node));

		new_node->data = new_data;
		new_node->next = prev_node->next;
		prev_node->next = new_node;
	}
};

class Worker
{
	std::string name;
	double practice;

public:
	Worker() {}

	Worker(const std::string& name, const double& practice)
	{
		this->name = name;
		this->practice = practice;
	}

	void show()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Practice year: " << practice << std::endl;
	}

	bool operator >=(const Worker& worker)
	{
		if (this->practice >= worker.practice)
			return true;
		return false;
	}

	bool operator <=(const Worker& worker)
	{
		if (this->practice <= worker.practice)
			return true;
		return false;
	}

};
void main()
{
	Node* head = NULL;

	Node* second = NULL;

	Node* third = NULL;


	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 15;
	head->next = second;

	second->data = 30;
	second->next = third;

	third->data = 45;
	third->next = NULL;

	LinkedList lk;

	lk.print_list(head);

	lk.push_last(head, 155);

	std::cout << std::endl;
	lk.print_list(head);

	std::cout << std::endl;

	lk.push_first(head, 200);
	lk.print_list(head);

	lk.insertAfter(third, 99);
	std::cout << std::endl;
	lk.print_list(head);
	/**/
	/*Worker w1("Elgun", 2);
	Worker w2("Elvin", 1.3);
	Worker w3("Resul", 4);
	Worker w4("Abil", 12);

	PriorityQueue<Worker> pq(4);

	pq.enqueue(w1);
	pq.enqueue(w2);
	pq.enqueue(w3);
	pq.enqueue(w4);

	//pq.showQueue();
	while (!pq.isEmpty())
	{
		std::cout << "==========================\n";
		for (size_t i = 0, length = pq.getSize(); i < length; i++)
		{
			pq.getData()[i].show();
		}

		pq.dequeue();
	}*/
	/*PriorityQueue<int> cq(3);

	for (size_t i = 0; !cq.isFull(); i++)
	{
		cq.enqueue(i + 15);
	}

	cq.showQueue();

	cq.dequeue();

	cq.showQueue();

	cq.dequeue();

	cq.showQueue();

	cq.enqueue(7);*/

	/*CircularQueue cq(3);

	for (size_t i = 0; !cq.isFull(); i++)
	{
		cq.enqueue(i + 10);
	}

	//std::cout << cq.peek() << std::endl;
	cq.showQueue();

	cq.dequeue();

	cq.showQueue();

	cq.dequeue();

	cq.showQueue();

	cq.dequeue();

	cq.showQueue();*/
	//std::cout << cq.peek() << std::endl;
}