#include <iostream>
#include <Windows.h>
#include <assert.h>

class Worker
{
	size_t id;
	std::string name;
	std::string surname;
	unsigned short age;
	unsigned short page_count;
public:
	static size_t current_id;
	Worker() :id(0), name(""), surname(""), age(0), page_count(0) {}

	Worker(const std::string& name, const std::string& surname, short age, short page_count)
	{
		setName(name);
		setSurname(surname);
		setAge(age);
		setPageCount(page_count);
		setID(++current_id);
	}

	void setID(size_t id)
	{
		this->id = id;
	}

	size_t getID() const
	{
		return this->id;
	}
	Worker(const Worker& worker)
	{
		setID(worker.getID());
		setName(worker.name);
		setSurname(worker.surname);
		setAge(worker.age);
		setPageCount(worker.page_count);
	}

	Worker & operator=(const Worker& worker)
	{
		setID(worker.getID());
		setName(worker.name);
		setSurname(worker.surname);
		setAge(worker.age);
		setPageCount(worker.page_count);
		
		return *this;
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

	void setSurname(const std::string& surname)
	{
		assert(!surname.empty() && "Name is blank!");
		this->surname = surname;
	}

	std::string getSurname() const
	{
		return this->surname;
	}

	void setAge(short age)
	{
		assert(age > 16 && "Age must be greater than 16");
		this->age = age;
	}

	unsigned short getAge() const
	{
		return this->age;
	}

	void setPageCount(short page_count)
	{
		assert(page_count > 0 && "Page count must be greater than zero");
		this->page_count = page_count;
	}

	unsigned short getPageCount() const
	{
		return this->page_count;
	}

	void show()
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Worker id: " << getID() << std::endl;
		std::cout << "Worker name: " << getName() << std::endl;
		std::cout << "Worker surname: " << getSurname() << std::endl;
		std::cout << "Worker age: " << getAge() << std::endl;
		std::cout << "Worker page count: " << getPageCount() << std::endl;
	}
};

size_t Worker::current_id = 0;

class WorkerQueue
{
	Worker* workers;
	size_t capacity; // max ola bilecek worker sayi
	size_t count; // toplam worker sayi
	size_t front; // siradaki birinci
	size_t rear; // hal hazirki

public:
	WorkerQueue()
	{
		this->workers = nullptr;//new Worker[size];
		this->capacity = 0;
		this->count = 0;
		this->front = 0;
		this->rear = 0;
	}
	WorkerQueue(int size)
	{
		this->workers = new Worker[size];
		this->capacity = size;
		this->count = 0;
		this->front = 0;
		this->rear = 0;
	}

	WorkerQueue(const WorkerQueue& wq)
	{
		setCount(wq.getCount());
		setCapacity(wq.getCapacity());
		setRear(wq.getRear());
		setWorkers(wq);
	}

	WorkerQueue& operator=(const WorkerQueue& wq)
	{
		setCount(wq.getCount());
		setCapacity(wq.getCapacity());
		setRear(wq.getRear());
		setWorkers(wq);

		return *this;
	}

	void setWorkers(const WorkerQueue& wq)
	{
		size_t length = getSize();
		this->workers = new Worker[length];
		for (size_t i = 0; i < length; i++)
		{
			this->workers[i] = wq.workers[i];
		}
	}

	void setCount(size_t count)
	{
		this->count = count;
	}
	size_t getCount() const { return this->count; }
	void setRear(size_t rear)
	{
		this->rear = rear;
	}
	size_t getRear() const { return this->rear; }
	void setCapacity(size_t capacity)
	{
		this->capacity = capacity;
	}
	size_t getCapacity() const { return this->capacity; }

	Worker& peek()
	{
		return workers[front];
	}

	void enqueue(Worker& worker)
	{
		assert(!isFull() && "Capacity is full!");
		this->workers[rear] = worker;
		rear++;
		count++;
	}

	Worker dequeue()
	{
		assert(!isEmpty() && "Queue is empty!");

		Worker deleted = workers[front];

		size_t new_size = getSize() - 1;

		auto tmp = new Worker[new_size];

		if (tmp != nullptr)
		{
			for (size_t i = 0; i < new_size; i++)
			{
				tmp[i] = workers[i + 1];
			}
			

			delete[] workers;

			this->count = new_size;

			this->workers = tmp;

			rear--;
		}

		return deleted;
	}
	size_t getSize() const { return count; }

	bool isFull() { return getSize() == this->capacity; }
	
	bool isEmpty() { return getSize() == 0; }


	~WorkerQueue()
	{
		if (workers != nullptr)
		{
			delete[] workers;
			workers = nullptr;
		}
	}
};

class Printer
{
	WorkerQueue* worker_queue;
public:
	
	Printer() :worker_queue(nullptr) {}

	Printer(const WorkerQueue* worker_queue)
	{
		setWorkerQueue(worker_queue);
	}

	void start()
	{
		while (!worker_queue->isEmpty())
		{
			Worker rear = worker_queue->dequeue();
			std::cout << "Worker " << rear.getName() << "'s papers was printed." << std::endl;
			Sleep(500);
		}
	}

	void setWorkerQueue(const WorkerQueue* worker_queue)
	{
		this->worker_queue = new WorkerQueue(*worker_queue);
	}

	~Printer()
	{
		if (this->worker_queue != nullptr)
		{
			delete this->worker_queue;
			this->worker_queue = nullptr;
		}
	}
};

void main()
{

	Worker w1("Elgun", "Abasquliyev", 20, 14);
	Worker w2("Sanan", "Mammadov", 19, 20);
	Worker w3("Arifali", "Baghirli", 19, 12);
	Worker w4("Amin", "Aliyev", 19, 15);
	Worker w5("Resul", "Osmanli", 19, 16);

	WorkerQueue * wq = new WorkerQueue(5);

	//w1.show();

	wq->enqueue(w1);
	wq->enqueue(w2);
	wq->enqueue(w3);
	wq->enqueue(w4);
	wq->enqueue(w5);

	//for (size_t i = 0; !wq->isEmpty(); i++)
	//{
	//	std::cout << wq->dequeue().getName() << std::endl;
	//}

	Printer printer;

	printer.setWorkerQueue(wq);

	printer.start();

	delete wq;
}