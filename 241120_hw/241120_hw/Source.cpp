#include <iostream>
#include <assert.h>

//Product id,name,price,discount,company
class Product
{
	size_t id;
	std::string name;
	std::string company;
	double price;
	double discount;

public:
	static size_t current_id;
	static size_t getCurrentID() { return current_id; }

	//copy constructor
	Product(const Product& other)
	{
		setID(other.getID());
		setName(other.getName());
		setCompany(other.getCompany());
		setPrice(other.getPrice());
		setDiscount(other.getDiscount());
	}

	// copy assigment

	Product& operator=(const Product& other)
	{
		setID(other.getID());
		setName(other.getName());
		setCompany(other.getCompany());
		setPrice(other.getPrice());
		setDiscount(other.getDiscount());
		return *this;
	}

	Product() {}

	Product(const std::string& name, const std::string& company, const double& price,
		const double& discount) : Product(name, company, price)
	{
		setDiscount(discount);
	}

	Product(const std::string& name, const std::string& company, const double& price) :
		Product(name, company)
	{
		setPrice(price);
	}

	Product(const std::string& name, const std::string& company) : Product(name)
	{
		setCompany(company);
	}

	explicit Product(const std::string& name)
	{
		setName(name);
		setID(++current_id);
	}

	void setID(size_t id) { this->id = id; }
	size_t getID() const { return this->id; }
	void setName(const std::string& name) {
		assert(!name.empty() && "Name cant be blank!");
		this->name = name;
	}

	std::string getName() const { return this->name; }

	void setCompany(const std::string& company) {
		assert(!company.empty() && "Company cant be blank!");
		this->company = company;
	}

	std::string getCompany() const { return this->company; }

	void setPrice(const double& price) {
		assert(price > 0 && "Price must be greater than zero");
		this->price = price;
	}

	double getPrice() const { return this->price; }

	void setDiscount(const double& discount) {
		assert(discount >= 0 && "Discount must be positive number!");
		this->discount = discount;
	}

	double getDiscount() const { return this->discount; }

	double getPriceWithDiscount() const {
		return this->price - ((this->price * this->discount) / 100.0);
	}

	void productInfo() const
	{
		std::cout << "----------------------------------\n";
		std::cout << "Product id: " << getID() << std::endl;
		std::cout << "Product name: " << getName() << std::endl;
		std::cout << "Product company: " << getCompany() << std::endl;
		std::cout << "Product price: " << getPrice() << '$' << std::endl;
		std::cout << "Product discount: " << getDiscount() << '%' << std::endl;

		if (getDiscount())
			std::cout << "Product discounted price: " << getPriceWithDiscount() << '$' << std::endl;
	}
};
size_t Product::current_id = NULL;

// stack
template <class T>
class Stack
{
	size_t size;
	T* products;

public:

	Stack() {}

	void push(const Product& product)
	{
		size_t new_size = getSize() + 1;
		T* new_products = new T[new_size];

		if (new_products != NULL)
		{
			// eger evvelki productlar varsa yenisine kochurecek
			if (!isEmpty())
			{
				for (size_t i = 0, length = getSize(); i < length; i++)
				{
					new_products[i] = this->products[i];
				}
				delete[] products;
			}

			new_products[new_size - 1] = product;
			this->products = new_products;
			new_products = NULL;
			setSize(new_size);
		}
	}

	T pop()
	{
		assert(!isEmpty() && "Stack is empty!");

		T tmp = top();
		size_t new_size = getSize() - 1;
		T* new_products = new T[new_size];

		if (new_products != NULL)
		{
			if (!isEmpty())
			{
				for (size_t i = 0; i < new_size; i++)
				{
					new_products[i] = this->products[i];
				}
				delete[] this->products;
			}

			this->products = new_products;
			new_products = NULL;
		}
		else if (!isEmpty())
		{
			delete[] this->products;
			this->products = NULL;
		}

		setSize(new_size);

		return tmp;
	}

	T& top() const {
		assert(!isEmpty() && "Stack is empty!");
		return this->products[getSize() - 1];
	}

	bool isEmpty()const { return getSize() == 0; }

	void erase()
	{
		if (this->products != NULL)
		{
			delete[] this->products;
			this->products = NULL;
			this->size = 0;
		}
	}

	size_t getSize() const { return this->size; };

	void setSize(size_t size) { this->size = size; }

	T* getProducts() const { return this->products; }
	~Stack()
	{
		erase();
	}
};

//Wagon no(string),product_count,speed,country,
//showProducts()
template<class T>
class Wagon
{
	std::string no;
	std::string country;
	double speed;
	Stack<T> products;

public:
	Wagon() {}

	Wagon(const std::string& no, const std::string& country, const double& speed)
	{
		setNo(no);
		setCountry(country);
		setSpeed(speed);
	}

	T deleteProduct() { return this->products.pop(); }

	void addProduct(const T& product) { this->products.push(product); }

	bool isEmpty() { return this->products.isEmpty(); }

	T& getProduct() const { return this->products.top(); }

	void setNo(const std::string& no) {
		assert(!no.empty() && "Wagon no cant be blank!");
		this->no = no;
	}

	std::string getNo() const { return this->no; }

	void setCountry(const std::string& country)
	{
		assert(!country.empty() && "Country cant be blank!");
		this->country = country;
	}
	std::string getCountry() const { return this->country; }

	void setSpeed(const double& speed) {
		assert(speed > 0 && "Speed must be greater than zero");
		this->speed = speed;
	}

	double getSpeed() const { return this->speed; }

	T* getProducts() const { return this->products.getProducts(); }

	size_t getProductCount() const { return this->products.getSize(); }
	void showProducts() const
	{
		T* products = getProducts();
		size_t length = this->products.getSize();

		if (length)
		{
			for (size_t i = 0; i < length; i++)
			{
				products[i].productInfo();
			}
		}
		else
			std::cout << "There is no product!\n";
	}

	void wagonInfo() const
	{
		std::cout << "-------------------------------------------\n";
		std::cout << "Wagon no: " << getNo() << std::endl;
		std::cout << "Country: " << getCountry() << std::endl;
		std::cout << "Speed: " << getSpeed() << " km/s" << std::endl;
		std::cout << "Product count: " << getProductCount() << std::endl;
	}
};

template <typename T>
struct Node
{
	Node<T>* prev;
	Node<T>* next;
	Wagon<T>* current;
};
template <class T>
class Train
{
	std::string name;
	Node<T>* head;
	Node<T>* tail;

public:
	Train() {}

	Train(const std::string& name, const Node<T>* head, const Node<T>* tail)
	{
		setName(name);
		setHead(head);
		setTail(tail);
	}

	void setName(const std::string& name)
	{
		assert(!name.empty() && "Name cant be blank");
		this->name = name;
	}

	std::string getName() const { return this->name; }

	void setHead(const Node<T>* head)
	{
		assert(head == NULL && "Head cant be null");
		this->head = head;
	}

	void setTail(const Node<T>* tail)
	{
		assert(tail == NULL && "Tail cant be null");
		this->tail = tail;
	}
};


void main()
{
	Product p1("iphone", "Apple", 1000, 5);
	Product p2("A7", "Samsung", 800, 10);
	Product p3("Xiaomi MI", "Xiaomi", 600, 15);
	p1.productInfo();
	p2.productInfo();
	p3.productInfo();


	Wagon<Product> w1("100", "Azerbaijan", 100);

	w1.wagonInfo();

	w1.addProduct(p1);
	w1.getProduct().productInfo();

	w1.addProduct(p2);
	w1.getProduct().productInfo();

	w1.addProduct(p3);
	w1.getProduct().productInfo();

	/*std::cout << "Deleted!" << std::endl;
	while (!w1.isEmpty())
	{
		w1.deleteProduct().productInfo();
	}*/


	std::cout << std::endl;
	std::cout << "Products listed: " << std::endl;
	w1.showProducts();
	w1.wagonInfo();
}