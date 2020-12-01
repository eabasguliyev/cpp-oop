#include <iostream>
#include <assert.h>
// person
// worker
// bird color name
// feathers lelek
// flying birds flying speed, max high

// non flying run speed

/*
class Person
{
	std::string name;
	unsigned short age;
public:
	Person() :name(""), age(0) {}

	Person(const std::string& name, short age)
	{
		setName(name);
		setAge(age);
	}
	void setName(const std::string& name)
	{
		this->name = name;
	}

	std::string getName() const { return this->name; }
	unsigned short getAge() const { return this->age; }
	void setAge(const short& age)
	{
		this->age = age;
	}

	int getBirthYear() const {
		return 2020 - this->getAge();
	}
	void show() const
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Age: " << age << std::endl;
	}
};

class Employee : public Person
{
	size_t id;
	size_t salary;
public:
	Employee() : id(0), salary(0) {}

	Employee(const std::string& name, const short& age,const int& id, const size_t& salary):Person(name, age)
	{
		setSalary(salary);
		setID(id);
	}

	void setID(const size_t & id)
	{
		this->id = id;
	}

	size_t getID() const { return this->id; }

	void setSalary(const size_t& salary)
	{
		this->salary = salary;
	}

	size_t getSalary() const {
		return this->salary;
	}

	//overriding
	void show() const
	{
		std::cout << "ID: " << getID() << std::endl;
		Person::show();
		//std::cout << "Birth year: " << getBirthYear() << std::endl;
		std::cout << "Salary: " << getSalary() << std::endl;
	}
};

class BasketballPlayer: protected Person
{
	size_t id;
	std::string team;
	float game_score;

public:

	BasketballPlayer() : team(""), game_score(0.0) {}
	BasketballPlayer(const std::string& name, const short& age,
		const std::string& team, const float& game_score) :Person(name, age)
	{
		setTeam(team);
		setGameScore(game_score);
	}

	void setID(const size_t& id)
	{
		this->id = id;
	}

	size_t getID() const { return this->id; }

	void setTeam(const std::string& team)
	{
		this->team = team;
	}

	void setGameScore(const float& game_score)
	{
		this->game_score = game_score;
	}
	void show()
	{
		Person::show();
		std::cout << "Birth year: " << getBirthYear() << std::endl;
		std::cout << "Team: " << this->team << std::endl;
		std::cout << "Game score: " << this->game_score << std::endl;
	}
};

class SuperVisor : protected Employee {
private:
	std::string department;
	int employees_id[5];

public:
	SuperVisor(const std::string& name, const int& age, const int& id,
		const int& salary, const std::string& department)
		: Employee(name, age, id, salary)
	{
		setDepartment(department);
		setEmployeesID();
	}
	
	void setDepartment(const std::string & department)
	{
		this->department = department;
	}

	std::string getDepartment() const { return this->department; }

	void setEmployeesID()
	{
		for (size_t i = 0; i < 5; i++)
		{
			this->employees_id[i] = i + 1000;
		}
	}


	void show() const
	{
		Employee::show();

		std::cout << "Department: " << getDepartment() << std::endl;

		for (size_t i = 0; i < 5; i++)
		{
			std::cout << i + 1 << ") Employee id: " << employees_id[i] << std::endl;
		}
	}
};
*/

//Flying - Bird
//None - Flying Bird

//Flying
//Robin
//Swallow

//None Flying
//Ostrich
//Penguin

//show methods
//Bird string color,bool hasFeathers

//FlyingBird flyingspeed,maxHigh
//UnFlyingBird runspeed

class Bird
{
	std::string name;
	std::string color;
	bool has_feathers;
	size_t lay_eggs;

public:
	Bird() : name(""), color(""), has_feathers(false), lay_eggs(0) {}

	Bird(const std::string& name, const std::string& color, const bool& has_feathers,
		const int& lay_eggs)
	{
		setName(name);
		setColor(color);
		setFeathers(has_feathers);
		setLayEggs(lay_eggs);
	}

	void setName(const std::string& name)
	{
		assert(!name.empty() && "Name cant be blank!");
		this->name = name;
	}

	std::string getName() const { return this->name; }
	void setColor(const std::string& color)
	{
		assert(!color.empty() && "Name cant be blank!");
		this->color = color;
	}

	std::string getColor() const { return this->color; }

	void setFeathers(const bool& has_feathers)
	{
		this->has_feathers = has_feathers;
	}

	bool getFeathers() const { return this->has_feathers; }

	void setLayEggs(int lay_eggs)
	{
		assert(lay_eggs >= 0 && "Lay eggs must be positive value");
		this->lay_eggs = lay_eggs;
	}
	
	size_t getLayEggs() const { return this->lay_eggs; }
	void show() const
	{
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Color: " << getColor() << std::endl;
		std::cout << std::boolalpha << getFeathers() << std::endl;
		std::cout << "Lay eggs: " << getLayEggs() << std::endl;
	}
};

class FlyingBirds: public Bird
{
	double flying_speed;
	double max_high;
public:
	FlyingBirds() : flying_speed(0), max_high(0) {}

	FlyingBirds(const std::string& name, const std::string& color, const bool & has_feathers,
		const int & lay_eggs, const double& flying_speed, const double& max_high)
		:Bird(name, color, has_feathers, lay_eggs)
	{
		setFlyingSpeed(flying_speed);
		setMaxHigh(max_high);
	}

	void setFlyingSpeed(const double& speed)
	{
		this->flying_speed = speed;
	}

	double getFlyingSpeed() const { return this->flying_speed; }
	void setMaxHigh(const double& high)
	{
		this->max_high = high;
	}

	double getMaxHigh() const { return this->max_high; }

	void show() const
	{
		Bird::show();
		std::cout << "Flying speed:" << getFlyingSpeed() << std::endl;
		std::cout << "Max high: " << getMaxHigh() << std::endl;
	}
};

class NonFlyingBird:public Bird
{
	double run_speed;
public:
	NonFlyingBird() : run_speed(0) {}

	NonFlyingBird(const std::string& name, const std::string& color, const bool& has_feathers,
		const int& lay_eggs, const double& run_speed):Bird(name, color, has_feathers, lay_eggs)
	{
		setRunSpeed(run_speed);
	}

	void setRunSpeed(const double& run_speed)
	{
		this->run_speed = run_speed;
	}

	double getRunSpeed() const
	{
		return this->run_speed;
	}

	void show() const
	{
		Bird::show();
		std::cout << "Run speed: " << getRunSpeed() << std::endl;
	}
};

class Robin: public FlyingBirds
{
	unsigned short average_life_span;
	bool sing;
public:
	Robin() : average_life_span(0), sing(false) {}

	Robin(const std::string& name, const std::string& color, const bool& has_feathers,
		const int& lay_eggs, const double& flying_speed, const double& max_high,
		const short& average_life_span, const bool& sing) :FlyingBirds(name, color, has_feathers,
			lay_eggs, flying_speed, max_high)
	{
		setAverageLifeSpan(average_life_span);
		setSing(sing);
	}

	void setAverageLifeSpan(const short& average_life_span)
	{
		this->average_life_span = average_life_span;
	}

	unsigned short getAverageLifeSpan() const
	{
		return this->average_life_span;
	}

	void setSing(const bool& sing)
	{
		this->sing = sing;
	}

	bool getSing() const
	{
		return this->sing;
	}

	void show() const
	{
		FlyingBirds::show();
		std::cout << "Average life span: " << getAverageLifeSpan() << std::endl;
		std::cout << "Sing: " << std::boolalpha << getSing() << std::endl;
	}
};

class Swallow : public FlyingBirds
{
	unsigned short average_life_span;
public:
	Swallow() : average_life_span(0){}

	Swallow(const std::string& name, const std::string& color, const bool& has_feathers,
		const int& lay_eggs, const double& flying_speed, const double& max_high,
		const short& average_life_span) :FlyingBirds(name, color, has_feathers,
			lay_eggs, flying_speed, max_high)
	{
		setAverageLifeSpan(average_life_span);
	}

	void setAverageLifeSpan(const short& average_life_span)
	{
		this->average_life_span = average_life_span;
	}

	unsigned short getAverageLifeSpan() const
	{
		return this->average_life_span;
	}

	void show() const
	{
		FlyingBirds::show();
		std::cout << "Average life span: " << getAverageLifeSpan() << std::endl;
	}
};

class Penguin : public NonFlyingBird
{
	unsigned short average_life_span;
public:
	
};

class Kiwi : public NonFlyingBird
{
public:

};


class SMS {
public:
	int id;
	std::string text;
	std::string number;

	SMS()
	{
		std::cout << "SMS default constructor" << std::endl;
		id = 1;
		text = "Hello Babe";
		number = "+9940556451245";
	}

	friend std::ostream& operator<<(std::ostream& out, const SMS& obj);
};

std::ostream& operator<<(std::ostream& out, const SMS& obj)
{
	out << obj.id << std::endl;
	out << obj.text << std::endl;

	return out;
}

class Email {
public:
	int id;
	std::string text;
	std::string toEmail;

	Email()
	{
		std::cout << "Email default constructor" << std::endl;
		id = 1;
		text = "Hello Babe";
		toEmail = "info@gmail.com";
	}

	friend std::ostream& operator<<(std::ostream& out, const Email& obj);
};

std::ostream& operator<<(std::ostream& out, const Email& obj)
{
	out << obj.id << std::endl;
	out << obj.text << std::endl;

	return out;
}

class MessageService : public SMS, public Email
{
	std::string company_name;

public:
	MessageService()
	{
		company_name = "Babat shirket";
	}

	void show(const bool & service)
	{
		if(service)
			std::cout << "Text SMS" << SMS::text << std::endl;
		else
			std::cout << "Text Email" << Email::text << std::endl;
	}
};


class ElectronicDevice
{
public:
	ElectronicDevice()
	{
		std::cout << "Electronic device default constructor" << std::endl;
	}
};

class Printer : virtual public ElectronicDevice
{
public:
	Printer()
	{
		std::cout << "Printer default constructor" << std::endl;
	}
};

class Scanner : virtual public ElectronicDevice
{
public:
	Scanner()
	{
		std::cout << "Scanner default constructor" << std::endl;
	}
};

class Copier : public Printer, public Scanner
{
public:
	Copier()
	{
		std::cout << "Copier default constructor" << std::endl;
	}
};

class A
{
public:
	A()
	{
		std::cout << "Default constructor A" << std::endl;
	}
};

class B : virtual public A
{

};

class C : virtual public A
{

};

class D : public B, public C
{

};


void main()
{
	//Copier c;

	D d;

	/*
	//Person p;
	//Person p2("Elgun", 20);

	//Employee e;
	//Employee e2("Elgun", 20, 1, 2000);

	////e2.Person::show();
	////e2.show();

	//BasketballPlayer bp("Lebron James", 35, "Laker", 960);
	//bp.show();

	/*SuperVisor sp("Elgun", 20, 1, 2000, "IT Department");

	sp.show();*/

}