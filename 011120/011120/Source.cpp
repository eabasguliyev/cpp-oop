#include <iostream>
#include <assert.h>


void demo()
{
	static int data = 10;
	++data;

	std::cout << data << std::endl;
}

class Airplane {
	int m_id;
	char* model;
	char* color;
	int engines;
	int capacity;
	
	Airplane() :m_id(0), model(nullptr), color(nullptr), engines(0),
		capacity(0)
	{}
public:
	static int id;
	static int max_count;
	Airplane(const char* model, const char* color, const int engines,
		const int capacity)
	{
		assert(id < max_count);
		this->m_id = ++id;
	}

	static int getCurrentID()
	{
		return id;
	}
	void showAirplane()
	{
		std::cout << "---------------------" << std::endl;
		std::cout << "Airplane id: " << m_id << std::endl;
		std::cout << this->id << std::endl;
	}
};

int Airplane::id = 0;
int Airplane::max_count = 10;


class Product
{
	int id = 0;
	const char* name;
	const char* company;
	const char* description;
	double price;
	double discount;

public:
	static int ID;


	Product(const char* name, const char* company, const char* description,
		const int price, const int discount):
		Product(name, company, description, price)
	{

		setDiscount(discount);
	}

	Product(const char* name, const char* company, const char* description,
		const int price) :
		Product(name, company, description)
	{

		setPrice(price);
	}
	Product(const char* name, const char* company, const char* description) :
		Product(name, company)
	{
		setDescription(description);
	}

	Product(const char* name, const char* company) :
		Product(name)
	{

		setCompany(company);
	}

	Product(const char* name) :Product()
	{
		setName(name);
	}

	Product() {
		this->id = ID++;
	};
	static int getCurrentProductID()
	{
		return ID;
	}
	
	void setName(const char * name)
	{
		assert(name && strlen(name));
		this->name = _strdup(name);
	}

	void setCompany(const char* company)
	{
		assert(company && strlen(company));

		this->company = _strdup(company);
	}

	void setPrice(const int price)
	{
		assert(price > 0);
		this->price = price;
	}

	void setDiscount(const int discount)
	{
		assert(discount >= 0);
		this->discount = discount;
	}

	void setDescription(const char* description)
	{
		assert(description && strlen(description));
		this->description = _strdup(description);
	}

	double getPriceWithDiscount() {
		return price - ((price * discount) / 100);
	}

	const char* getName()
	{
		return name;
	}

	const char* getDescription()
	{
		return description;
	}

	const char* getCompany()
	{
		return company;
	}

	double getPrice()
	{
		return price;
	}

	double getDiscount()
	{
		return discount;
	}

	void showProduct()
	{
		const char* name = getName();
		const char* company = getCompany();
		const char* description = getDescription();
		size_t discount = getDiscount();
		
		if (name)
			std::cout << "Product name: " << name << std::endl;

		if (company)
			std::cout << "Product company: " << company << std::endl;

		if(description)
			std::cout << "Product description: " << description << std::endl;

		std::cout << "Product price: " << getPrice() << std::endl;

		if (discount)
		{
			std::cout << "Product discount: " << discount << std::endl;
			std::cout << "Product price with discount: " <<
				getPriceWithDiscount() << std::endl;
		}
	}
};

//int Product::ID = 0;

class Store {
	int product_count = 0;
	Product* products;
	int store_id;
	void deleteOldData()
	{
		if (product_count)
		{
			delete[] products;
			products = nullptr;
		}
	}
public:
	static int ID;

	Store()
	{
		store_id = ID++;
	}
	static int getCurrentStoreID()
	{
		return ID;
	}

	int getStoreID()
	{
		return store_id;
	}
	bool addProduct(Product & product)
	{
		size_t product_count = this->product_count + 1;

		Product* products = new Product[product_count];

		if (products)
		{
			if (this->product_count)
			{
				for (size_t i = 0; i < this->product_count; i++)
				{
					products[i].setName(this->products[i].getName());
					products[i].setCompany(this->products[i].getCompany());
					products[i].setDescription(this->products[i].getDescription());
					products[i].setPrice(this->products[i].getPrice());
					products[i].setDiscount(this->products[i].getDiscount());
				}
				deleteOldData();
			}

			products[this->product_count].setName(_strdup(product.getName()));
			products[this->product_count].setCompany(_strdup(product.getCompany()));
			products[this->product_count].setDescription(_strdup(product.getDescription()));
			products[this->product_count].setPrice(product.getPrice());
			products[this->product_count].setDiscount(product.getDiscount());

			this->products = products;
			this->product_count = product_count;

			return true;
		}
		return false;
	}
	void showProducts()
	{
		if (product_count)
		{
			for (size_t i = 0; i < product_count; i++)
			{
				std::cout << "-------------------------------------\n";
				products[i].showProduct();
			}
		}
	}
};

//int Store::ID = 0;

class User
{
	char* username;
	char* password;

public:
	User() = default;

	User(const char * username, const char * password)
	{
		this->username = _strdup(username);
		this->password = _strdup(password);
	}

	void showUser()
	{
		std::cout << "Username: " << username << std::endl;
		std::cout << "Password: " << password << std::endl;
	}

	void showUsername(User user)
	{
		std::cout << "Username: " << user.username << std::endl;
	}
	
	User& getNewUser()
	{
		User a("nodata", "nodata");
		return a;
	}
	~User()
	{
		std::cout << "User : " << username << " was deleted" << std::endl;
	}
};


class Point {

public:
	int x;
	int y;
	int* z;

	Point() = default;

	Point(const Point& old)
	{
		std::cout << "Copy constructor works" << std::endl;

		x = old.x;
		y = old.y;
		z = new int;
		*z = *(old.z);
		
	}
	Point(const int x, const int y, const int z)
	{
		this->x = x;
		this->y = y;
		this->z = new int;
		*(this->z) = z;
	}

	void showData()
	{
		std::cout << "X: " << x << std::endl;
		std::cout << "Y: " << y << std::endl;
		std::cout << "Z: " << *z << std::endl;
	}

	~Point()
	{
		delete z;
	}
};




class Worker {
	int id;
	char* name;
	char* surname;
	int age;
	double salary;
	char* speciality;

public:
	static int ID;
	static int max_count;

	Worker(const Worker& old)
	{
		//assert(ID < max_count && "Our office is full");
		this->id = old.id;
		setName(old.name);
		setSurname(old.surname);
		setAge(old.age);
		setSpeciality(old.speciality);
		setSalary(old.salary);
	}
	Worker(const char* name, const char* surname, int age, double salary,
		const char* speciality) :Worker(name, surname, age, salary)
	{
		setSpeciality(speciality);
	}
	Worker(const char* name, const char* surname, int age, double salary)
		:Worker(name, surname, age)
	{
		setSalary(salary);
	}
	Worker(const char* name, const char* surname, int age)
		:Worker(name, surname)
	{
		setAge(age);
	}

	Worker(const char* name, const char* surname)
		:Worker(name)
	{
		setSurname(surname);
	}

	Worker(const char* name)
		:Worker()
	{
		assert(ID < max_count && "Our office is full");
		this->id = ID++;
		setName(name);
	}

	Worker() {
		
	}

	const char* getName()
	{
		return name;
	}
	void setName(const char* name)
	{
		assert(name && strlen(name));
		this->name = _strdup(name);
	}
	const char* getSurname()
	{
		return surname;
	}

	void setSurname(const char* surname)
	{
		assert(surname && strlen(surname));
		this->surname = _strdup(surname);
	}
	const char* getSpeciality()
	{
		return speciality;
	}

	void setSpeciality(const char* speciality)
	{
		assert(speciality && strlen(speciality));
		this->speciality = _strdup(speciality);
	}
	int getAge()
	{
		return age;
	}

	void setAge(int age)
	{
		assert(age > 0);
		this->age = age;
	}

	double getSalary()
	{
		return salary;
	}

	void setSalary(double salary)
	{
		assert(salary > 0);
		this->salary = salary;
	}

	static int getCurrentID()
	{
		return ID;
	}

	void setMyId(int id)
	{
		assert(id >= 0);
		this->id = id;
	}
	int getID()
	{
		return id;
	}
	void showWorker()
	{
		std::cout << "--------------------------------------\n";
		std::cout << "ID: " << this->id << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Surname: " << getSurname() << std::endl;
		std::cout << "Age: " << getAge() << std::endl;
		std::cout << "Speciality: " << getSpeciality() << std::endl;
		std::cout << "Salary: " << getSalary() << std::endl;
	}

	~Worker()
	{
		delete[] name;
		name = nullptr;
		delete[] surname;
		surname = nullptr;
		delete[] speciality;
		speciality = nullptr;
	}
};

int Worker::ID = 0;
int Worker::max_count = 10;

class Office {
	char* name;
	Worker* workers;
public:
	Office(const char* name, Worker* workers) {
		setName(name);
		setWorkers(workers);
	}

	void setWorkers(Worker* workers)
	{
		this->workers = workers;
		/*this->workers = new Worker[Worker::getCurrentID()];
		for (size_t i = 0; i < Worker::getCurrentID(); i++)
		{
			this->workers[i] = workers[i];
		}*/
	}

	Worker* getWorkers()
	{
		return workers;
	} 

	char* getName()
	{
		return name;
	}
	void setName(const char* name)
	{
		this->name = _strdup(name);
	}

	void showAll()
	{
		for (size_t i = 0; i < Worker::getCurrentID(); i++)
		{
			workers[i].showWorker();
		}
	}

	void addWorker(Worker & worker)
	{
		int count = Worker::getCurrentID();

		Worker * newWorkers = new Worker[count];

		if (newWorkers)
		{
			//birinci
			for (size_t i = 0; i < count; i++)
			{
 				newWorkers[i] = workers[i];
			}
			
			newWorkers[count - 1] = worker;
			this->workers = newWorkers;
			newWorkers = nullptr;

			//ikinci
			/*if (count - 1)
			{
				for (size_t i = 0; i < count - 1; i++)
				{
					newWorkers[i].setMyId(workers[i].getID());
					newWorkers[i].setName(workers[i].getName());
					newWorkers[i].setSurname(workers[i].getSurname());
					newWorkers[i].setAge(workers[i].getAge());
					newWorkers[i].setSpeciality(workers[i].getSpeciality());
					newWorkers[i].setSalary(workers[i].getSalary());
				}
				
				delete[] workers;
			}

			newWorkers[count - 1].setMyId(worker.getID());
			newWorkers[count - 1].setName(worker.getName());
			newWorkers[count - 1].setSurname(worker.getSurname());
			newWorkers[count - 1].setAge(worker.getAge());
			newWorkers[count - 1].setSpeciality(worker.getSpeciality());
			newWorkers[count - 1].setSalary(worker.getSalary());

			this->workers = newWorkers;
			newWorkers = nullptr;*/
		}

		/*int count = Worker::getCurrentID();
		auto new_workers = new Worker[count];

		if (workers)
		{
			if (count - 1)
			{
				for (size_t i = 0; i < count - 1; i++)
				{
					new_workers[i].setName(workers[i].getName());
					new_workers[i].setSurname(workers[i].getSurname());
					new_workers[i].setAge(workers[i].getAge());
					new_workers[i].setSalary(workers[i].getSalary());
					new_workers[i].setSpeciality(workers[i].getSpeciality());
				}

				delete[] workers;
			}

			new_workers[count].setName(worker.getName());
			new_workers[count].setSurname(worker.getSurname());
			new_workers[count].setAge(worker.getAge());
			new_workers[count].setSalary(worker.getSalary());
			new_workers[count].setSpeciality(worker.getSpeciality());

			workers = new_workers;
		}*/

	}
	~Office()
	{
		delete[] name;
		delete[] workers;
	}

};


void main()
{

	Worker w1("John", "Johnlu", 22, 1200, "Graphic-Designer");

	std::cout << &w1 << std::endl;
	w1.showWorker();
	//Worker w2 = w1; // same as Worker w2(w1) <-- copy constructor

	Worker w2("Mike", "Mikeli", 25, 1000, "Programmer");
	w2.showWorker();
	Worker w3("Leyla", "Memmedova", 22, 1200, "IT-Specialist");
	w3.showWorker();
	
	//std::cout << Worker::getCurrentID() << std::endl;

	std::cout << "\nWorker lists\n";
	Worker* workers = new Worker[3]{ w1, w2, w3 };
	
	Worker w4("Ilahe", "Seyidova", 26, 1400, "Cybersec");

	Office office("Gilan holding", workers);

	std::cout << "After adding new worker" << std::endl;
	office.addWorker(w4);

	std::cout << Worker::getCurrentID() << std::endl;
	office.showAll();

	/*for (size_t i = 0; i < 3; i++)
	{
		workers[i].showWorker();
	}*/
	
	//std::cout << Worker::getCurrentID() << std::endl;

	//Worker w4("Ilahe", "Seyidova", 26, 1400, "Cybersec");

	
	//Office office("Gilan holding", workers);

	
	//office.showAll();


	/*Point a(10, 20, 30);
	Point b(a);

	
	a.showData();

	b.showData();*/

	/*User u1("adam", "12345");
	u1.showUser();

	User u2("john", "john123");
	u2.showUser();

	u2.getNewUser();*/
	//u1.showUsername(u2);
	/*std::cout << Product::getCurrentProductID() << std::endl;

	Product p1("car", "Disney", "toy", 45, 10);

	p1.showProduct();

	Product p2("macbook air", "apple", "laptop", 3000, 0);

	p2.showProduct();
	std::cout << Product::getCurrentProductID() << std::endl;


	std::cout << std::endl;
	Store store;

	std::cout << store.getStoreID() << std::endl;

	store.addProduct(p1);

	store.addProduct(p2);

	store.showProducts();

	Store store2;
	std::cout << store2.getStoreID() << std::endl;*/
}