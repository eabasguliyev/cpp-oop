#include <iostream>

//example 1

/*class Base
{
public:
	virtual void whatIsMyShape() = 0;
};*/

class Figure//:public Base // abstract classdan abstract class toretmek olar.
{
protected:
	double area;
public:
	virtual void whatIsMyShape() = 0;// pure virtual - abstract class olur
	virtual void calculateArea() = 0;

	double getArea() const
	{
		return this->area;
	}
};

class Rectangle:public Figure
{
	double length;
	double width;
public:

	Rectangle(double length, double width) : length(length), width(width) {}

	void whatIsMyShape() override
	{
		std::cout << "My shape is Rectangular!" << std::endl;
	}

	void calculateArea() override
	{
		area = length * width;
	}
};

class Circle : public Figure
{
	double radius;
public:
	Circle(double radius) : radius(radius)
	{

	}
	void whatIsMyShape() 
	{
		std::cout << "My shape is Circle!" << std::endl;
	}

	void calculateArea() override
	{
		area = radius * radius * 3.144;
	}
};


class Square :public Rectangle
{
public:
	Square(double side) : Rectangle(side, side) {}
};


//example 2
class Animal
{
protected:
	std::string name;

public:
	Animal(const std::string& name) : name(name) {}

	const std::string& getName() const
	{
		return name;
	}

	virtual void speak() = 0; // pure virtual

	virtual ~Animal() = 0
	{
		std::cout << "Destructor Animal" << std::endl;
	}
};

void Animal::speak() {
	std::cout << "I cry as all animal" << std::endl;
}

class DragonFly :public Animal
{
public:
	DragonFly(const std::string& name) : Animal(name) {}

	void speak() override;
};

void DragonFly::speak()
{
	Animal::speak();
}

class Pig :public Animal
{
public:
	Pig(const std::string& name) : Animal(name) {}

	void speak() override
	{
		Animal::speak();
		std::cout << "I cry also as pig" << std::endl;
	}
};

//example 3
class AbstractDatabase
{
public:
	virtual std::string getByID(int id) = 0;
	virtual void deleteByID(int id) = 0;
	virtual void add(int id, std::string data) = 0;
	virtual void updateByID(int id, std::string data) = 0;
};

class OracleDB:public AbstractDatabase
{
	std::string getByID(int id) override
	{
		std::cout << "Get from Oracle Database" << std::endl;
		return "";
	}

	void deleteByID(int id)override
	{
		std::cout << "Deleted from Oracle Database" << std::endl;
	}

	void add(int id, std::string data)override
	{
		std::cout << "Added to Oracle Database" << std::endl;
	}

	void updateByID(int id, std::string data)override
	{
		std::cout << "Updated from Oracle Database" << std::endl;
	}
};
class MSSql : public AbstractDatabase
{
	std::string getByID(int id) override
	{
		std::cout << "Get from MSSql Database" << std::endl;
		return "";
	}

	void deleteByID(int id)override
	{
		std::cout << "Deleted from MSSql Database" << std::endl;
	}

	void add(int id, std::string data)override
	{
		std::cout << "Added to MSSql Database" << std::endl;
	}

	void updateByID(int id, std::string data)override
	{
		std::cout << "Updated from MSSql Database" << std::endl;
	}
};
class MongoDB : public AbstractDatabase
{
	std::string getByID(int id) override
	{
		std::cout << "Get from MongoDB Database" << std::endl;
		return "";
	}

	void deleteByID(int id)override
	{
		std::cout << "Deleted from MongoDB Database" << std::endl;
	}

	void add(int id, std::string data)override
	{
		std::cout << "Added to MongoDB Database" << std::endl;
	}

	void updateByID(int id, std::string data)override
	{
		std::cout << "Updated from MongoDB Database" << std::endl;
	}
};


class Website
{
	std::string url;
	AbstractDatabase* _db;
public:
	//dependencie injecting
	void setDatabase(AbstractDatabase* _db)
	{
		this->_db = _db;
	}

	void makeSomeThing()
	{
		_db->getByID(7);
		//some big codes
		//some big codes
		//some big codes
		//some big codes
		_db->updateByID(8, "New data");
		//some big codes
		//some big codes
		//some big codes
		_db->deleteByID(7);
	}

	void showSite()
	{
		std::cout << "Some html codes" << std::endl;
	}

	void setUrl(const std::string& url)
	{
		this->url = url;
	}

	void deleteDB()
	{
		delete this->_db;
		this->_db = nullptr;
	}
};


void main()
{
	AbstractDatabase* oracleDB = new OracleDB;
	Website facebook;

	facebook.setDatabase(oracleDB);

	facebook.deleteDB();
	AbstractDatabase* mssqlDB = new MSSql;
	facebook.setDatabase(mssqlDB);
	facebook.deleteDB();
	facebook.setDatabase(new MongoDB);
	 
	facebook.setUrl("https://www.facebook.com");
	facebook.makeSomeThing();
	facebook.showSite();
}


//example 4

class Musician
{
protected:
	std::string name;
	std::string instrument;

public:
	Musician() = delete;
	Musician(std::string name, std::string instrument) :name(name), instrument(instrument) {}

	virtual void perform() = 0
	{
		std::cout << "Sazina qurban... Sozune qurban, babat ..." << std::endl;
	}

	virtual ~Musician() = 0
	{
		std::cout << "Pure virtual destructor" << std::endl;
	}
};

class Guitarist : public Musician
{
	std::string nickname;

public:

	Guitarist() = delete;

	Guitarist(std::string name, std::string instrument, std::string nickname) :
		Musician(name, instrument)
	{
		this->nickname = nickname;
	}

	void perform() override
	{
		std::cout << "I play guitar!" << std::endl;
	}
};

class Pionist :public Musician
{
	std::string type;

public:
	Pionist() = delete;

	Pionist(std::string name, std::string instrument, std::string type) :
		Musician(name, instrument)
	{
		this->type = type;
	}

	void perform() override
	{
		std::cout << "Ohh great piano sounds!" << std::endl;
	}
};

class Ashiq :public Musician {
	bool isEloglu;
public:
	Ashiq() = delete;

	Ashiq(std::string name, std::string instrument) :Musician(name, instrument)
	{
		this->isEloglu = false;
	}


	void perform() override
	{
		Musician::perform();
	}
};

class Band
{
	Musician** musicians;
	size_t count;
public:
	Band()
	{
		this->count = 0;
	}

	
	void addMusician(Musician* musician)
	{
		size_t newCount = this->count + 1;
		auto newMusicians= new Musician * [newCount];

		if (newMusicians  != NULL)
		{
			if (this->count)
			{
				for (size_t i = 0; i < this->count; i++)
				{
					newMusicians[i] = this->musicians[i];
				}
				delete[] this->musicians;
			}

			newMusicians[this->count] = musician;

			this->count = newCount;

			this->musicians = newMusicians;
			newMusicians = nullptr;
		}
	}

	void start()
	{
		for (size_t i = 0; i < this->count; i++)
		{
			musicians[i]->perform();
		}
	}
};

/*void main()
{

	Band stars;

	stars.addMusician(new Guitarist("Jordon", "guitarBBGTR", "John"));
	stars.addMusician(new Guitarist("Anderson", "guitarBBGTR", "Arn"));
	stars.addMusician(new Ashiq("Shemkir", "sazBBGTR"));
	stars.addMusician(new Pionist("Arif", "piano123", "xususi piano"));


	stars.start();
	/*Animal* dragon = new DragonFly("Bomba Ejdaha");
	Animal* pig = new Pig("Bomba Donuz");
	//Animal* animal = new Animal("Bomba heyvan");

	dragon->speak();
	
	//Figure* f1 = new Figure; //error
	Figure* f2 = new Rectangle(10, 5);
	Figure* f3 = new Circle(3);
	Figure* f4 = new Square(10);

	Figure** figures = new Figure * [3]{f2, f3, f4 };
	
	for (size_t i = 0; i < 3; i++)
	{
		figures[i]->whatIsMyShape();

		figures[i]->calculateArea();

		std::cout << "Area: " <<  figures[i]->getArea() << std::endl;
}*/