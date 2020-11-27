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

	Train(const std::string& name, Node<T>* head, Node<T>* tail)
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

	void setHead(Node<T>* head)
	{
		assert(head != NULL && "Head cant be null");
		this->head = head;
	}

	void setTail(Node<T>* tail)
	{
		assert(tail != NULL && "Tail cant be null");
		this->tail = tail;
	}

	void forwardTraverse()
	{
		Node<T>* tmp = head;

		while (tmp != NULL)
		{
			std::cout << "++++++++++++++++++++++++++++++++++++++\n";
			tmp->current->wagonInfo();
			tmp->current->showProducts();
			tmp = tmp->next;
		}
	}

	void backwardTraverse()
	{
		Node<Product>* tmp = tail;

		while (tmp != NULL)
		{
			std::cout << "++++++++++++++++++++++++++++++++++++++\n";
			tmp->current->wagonInfo();
			tmp->current->showProducts();
			tmp = tmp->prev;
		}
	}

	void addFront(const Wagon<T> & data)
	{
		Node<T>* new_node = new Node<T>;
		new_node->current = new Wagon<T>(data);
		new_node->prev = NULL;
		new_node->next = this->head;

		if (this->head == NULL)
		{
			this->tail = new_node;
		}
		else
		{
			this->head->prev = new_node;
		}


		this->head = new_node;
	}

	void addEnd(const Wagon<T>& data)
	{
		Node<T>* new_node = new Node<T>;
		new_node->current = new Wagon<T>(data);

		new_node->next = NULL;
		new_node->prev = this->tail;
		
		if (this->tail == NULL)
		{
			this->head = new_node;
		}
		else
		{
			this->tail->next = new_node;
		}

		this->tail = new_node;
	}

	void addAfter(Node<T>* node, const Wagon<T>& data)
	{
		if (node == NULL)
			return;
		
		Node<T>* new_node = new Node<T>;
		new_node->current = new Wagon<T>(data);
		new_node->prev = node;
		

		if (node->next == NULL)
		{
			this->tail = new_node;
			this->tail->next = NULL;
		}
		else
		{
			new_node->next = node->next;
			new_node->next->prev = new_node;
		}
		node->next = new_node;
	}

	Node<T>* getNode(size_t index) const
	{
		if (this->head == NULL)
			return NULL;

		Node<T>* tmp = this->head;
		size_t counter = 0;


		while (counter < index && tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}

		if (counter != index)
			return NULL;

		return tmp;
	}

	//getWagonByNo("vaqon nomresi")//vaqon qaytarsin
	//showProductsByNo("vaqon nomresi")//butun productlar gorunsun
	//	deleteWagonByNo("vaqon nomresi")
	//	updateSpeedByNo("vaqon nomresi", 250)
	//	updateCountryByNo("vaqon nomresi", "Azerbaijan")

	void showProductsByNo(const std::string& no)
	{
		if (this->head == NULL)
			return;

		Node<T>* node = getWagonByNo(no);

		if (node)
			node->current->showProducts();
		else
			std::cout << "There is no wagon associated this no -> " << no << std::endl;
	}

	Node<T>* getWagonByNo(const std::string &no)
	{
		Node<T>* tmp = this->head;

		while (tmp != NULL)
		{
			if (tmp->current->getNo() == no)
			{
				return tmp;
			}
			tmp = tmp->next;
		}

		return NULL;
	}

	void deleteWagonByNo(const std::string &no)
	{
		if (this->head == NULL)
			return;

		Node<T>* node = getWagonByNo(no);

		if (node == NULL)
			return;
		else if (node->prev == NULL)
		{
			this->head = node->next;
			this->head->prev = NULL;
		}
		else if (node->next == NULL)
		{
			this->tail = node->prev;
			this->tail->next = NULL;
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}

		delete node;
		node = NULL;
	}

	void updateSpeedByNo(const std::string& no, double speed)
	{
		if (this->head == NULL)
			return;

		Node<T>* node = getWagonByNo(no);

		if (node == NULL)
			return;

		node->current->speed = speed;
	}

	void updateCountryByNo(const std::string& no, const std::string& country)
	{
		if (this->head == NULL)
			return;

		Node<T>* node = getWagonByNo(no);

		if (node == NULL)
			return;

		node->current->country = country;
	}
};


void main()
{
	Product p1("iphone", "Apple", 1000, 5);
	Product p2("A7", "Samsung", 800, 10);
	Product p3("Xiaomi MI", "Xiaomi", 600, 15);
	//p1.productInfo();
	//p2.productInfo();
	//p3.productInfo();


	Wagon<Product> w1("100", "Azerbaijan", 100);

	//w1.wagonInfo();

	w1.addProduct(p1);
	//w1.getProduct().productInfo();

	w1.addProduct(p2);
	//w1.getProduct().productInfo();

	w1.addProduct(p3);
	//w1.getProduct().productInfo();

	Product p4("Airpods", "Apple", 400, 5);
	Product p5("Galaxy buds", "Samsung", 240, 6);
	Product p6("Mi band 4", "Xiaomi", 50, 8);
	//p4.productInfo();
	//p5.productInfo();
	//p6.productInfo();


	Wagon<Product> w2("101", "Azerbaijan", 100);

	//w2.wagonInfo();

	w2.addProduct(p4);
	//w2.getProduct().productInfo();

	w2.addProduct(p5);
	//w2.getProduct().productInfo();

	w2.addProduct(p6);
	//w2.getProduct().productInfo();

	/*std::cout << "Deleted!" << std::endl;
	while (!w1.isEmpty())
	{
		w1.deleteProduct().productInfo();
	}*/


	/*std::cout << std::endl;
	std::cout << "Products listed: " << std::endl;
	w1.showProducts();
	w1.wagonInfo();*/


	Train<Product> tr;

	Node<Product>* first = new Node<Product>;
	first->current = new Wagon<Product>(w1);
	first->prev = NULL;
	first->next = NULL;

	Node<Product>* second = new Node<Product>;
	second->current = new Wagon<Product>(w2);
	second->prev = first;
	second->prev->next = second;
	second->next = NULL;


	tr.setHead(first);
	tr.setTail(second);

	Product p7("iphone 12 pro", "Apple", 1000, 5);
	Product p8("Galaxy SM20", "Samsung", 500, 6);
	Product p9("Redmi", "Xiaomi", 300, 8);
	//p4.productInfo();
	//p5.productInfo();/
	//p6.productInfo();


	Wagon<Product> w3("102", "Azerbaijan", 100);

	//w2.wagonInfo();

	w3.addProduct(p7);
	//w2.getProduct().productInfo();

	w3.addProduct(p8);
	//w2.getProduct().productInfo();

	w3.addProduct(p9);
	//w2.getProduct().productInfo();

	tr.addFront(w3);

	Product p10("Iphone SE", "Apple", 600, 5);
	Product p11("Galaxy Tab S6 Lite", "Samsung", 650, 6);
	Product p12("Mi band 5", "Xiaomi", 65, 8);
	//p4.productInfo();
	//p5.productInfo();
	//p6.productInfo();


	Wagon<Product> w4("103", "Azerbaijan", 100);

	//w2.wagonInfo();

	w4.addProduct(p10);
	//w2.getProduct().productInfo();

	w4.addProduct(p11);
	//w2.getProduct().productInfo();

	w4.addProduct(p12);
	//w2.getProduct().productInfo();


	tr.addEnd(w4);


	Product p14("Iphone SE", "Apple", 600, 5);
	Product p15("Galaxy Tab S6 Lite", "Samsung", 650, 6);
	Product p16("Mi band 5", "Xiaomi", 65, 8);
	//p4.productInfo();
	//p5.productInfo();
	//p6.productInfo();


	Wagon<Product> w5("104", "Azerbaijan", 100);

	//w2.wagonInfo();

	w5.addProduct(p14);
	//w2.getProduct().productInfo();

	w5.addProduct(p15);
	//w2.getProduct().productInfo();

	w5.addProduct(p16);
	//w2.getProduct().productInfo();

	tr.addAfter(tr.getNode(3), w5);

	/*Node<Product>* tmp = tr.getNode(0);
	tr.deleteNode(tmp);*/
	//tr.forwardTraverse();
	//tr.backwardTraverse();

	//tr.showProductsByNo("102");

	//tr.deleteWagonByNo("104");

	tr.forwardTraverse();
}