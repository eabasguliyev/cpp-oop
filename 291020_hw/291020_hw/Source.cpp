#include <iostream>

/*
//Initializer list,Delegeate ,getter, setter,

Product
id,name,description,price,discount
showProduct(),getPriceWithDiscount()

*/

class Product
{
	int id = 0;
	char* name = nullptr;
	char* description = nullptr;
	double price = 0;
	double discount = 0;

public:
	Product() :id(0),name(nullptr), description(nullptr), price(0), discount(0)
	{

	}

	Product(const int id, const char * name, const char * description, const double price, const double discount)
		:Product(id, name, description, price)
	{
		setDiscount(discount);
	}

	Product(const int id, const char* name, const char* description, const double price)
		:Product(id, name, description)
	{
		setPrice(price);
	}

	Product(const int id, const char* name, const char* description)
		:Product(id, name)
	{
		setDescription(description);
	}
	
	Product(const int id, const char* name)
		:Product(id)
	{
		setName(name);
	}

	Product(const int id)
	{
		setID(id);
	}
	
	void setID(const int id)
	{
		if (id > 0)
		{
			this->id = id;
		}
	}

	int getID()
	{
		return id;
	}

	void setName(const char* name)
	{
		if (name && strlen(name))
		{
			this->name = _strdup(name);
		}
	}

	const char* getName()
	{
		return name;
	}

	void setDescription(const char* description)
	{
		if (description && strlen(description))
		{
			this->description = _strdup(description);
		}
	}

	const char* getDescription()
	{
		return description;
	}

	void setPrice(const double price)
	{
		if (price > 0)
		{
			this->price = price;
		}
	}
	
	double getPrice()
	{
		return price;
	}

	void setDiscount(const double discount)
	{
		if (discount > 0)
		{
			this->discount = discount;
		}
	}

	double getDiscount()
	{
		return discount;
	}

	void showProduct()
	{
		const char* name = getName();
		const char* description = getDescription();
		double discount = getDiscount();
		std::cout << "Product ID: " << getID() << std::endl;
		if(name)
			std::cout << "Product name: " << name << std::endl;
		if(description)
			std::cout << "Product description: " << description << std::endl;
		std::cout << "Product price: " << getPrice() << std::endl;
		std::cout << "Product discount: " << discount << std::endl;

		if (discount)
			std::cout << "Product with discount: " << GetPriceWithDiscount() << std::endl;
	}


	double GetPriceWithDiscount()
	{
		return price - ((price * discount) / 100);
	}

	~Product()
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
		if (description)
		{
			delete[] description;
			description = nullptr;
		}
	}
};


/*Stock{
   char*address;
   Product*array
   showStock()
   
   Product getProduct(int id);
   void AddProduct(const Product p);
}*/

class Stock
{
	char* address = nullptr;
	int product_count = 0;
	Product* products = nullptr;

private:
	void deleteOldData()
	{
		if (product_count)
		{
			delete[] products;
			products = nullptr;
		}
	}
public:
	Stock()
	{

	}
	void showStock()
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

	Product getProduct(int id)
	{
		if (id > 0)
		{
			for (size_t i = 0; i < product_count; i++)
			{
				if (products[i].getID() == id)
				{
					return products[i];
				}
			}
		}
	}

	bool addProduct(Product &product)
	{
		size_t product_count = this->product_count + 1;

		Product* products = new Product[product_count];

		if (products)
		{
			if (this->product_count)
			{
				for (size_t i = 0; i < this->product_count; i++)
				{
					products[i].setID(this->products[i].getID());
					products[i].setName(this->products[i].getName());
					products[i].setDescription(this->products[i].getDescription());
					products[i].setPrice(this->products[i].getPrice());
					products[i].setDiscount(this->products[i].getDiscount());
				}
				deleteOldData();
			}

			products[this->product_count].setID(product.getID());
			products[this->product_count].setName(_strdup(product.getName()));
			products[this->product_count].setDescription(_strdup(product.getDescription()));
			products[this->product_count].setPrice(product.getPrice());
			products[this->product_count].setDiscount(product.getDiscount());

			this->products = products;
			this->product_count = product_count;

			return true;
		}
		return false;
	}
};

int main()
{
	Product p1(1,"Milk", "none" , 4.30, 5);

	p1.showProduct();

	std::cout << std::endl;

	Product p2(2, "Coca-Cola", "none", 2, 0);

	p2.showProduct();

	std::cout << std::endl;

	Product p3(3);
	p3.showProduct();

	Stock stock;

	std::cout << "-----------------------------\n";
	stock.addProduct(p1);
	stock.showStock();

	std::cout << "-----------------------------\n";

	stock.addProduct(p2);
	stock.showStock();

	std::cout << "-----------------------------\n";


	stock.addProduct(p3);
	stock.showStock();
	std::cout << "-----------------------------\n";

	p1.showProduct();

	std::cout << "-----------------------------\n";

	p2.showProduct();

	std::cout << "-----------------------------\n";

	p3.showProduct();
}