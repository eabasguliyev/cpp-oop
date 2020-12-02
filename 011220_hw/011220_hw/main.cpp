#include <iostream>
#include <assert.h>


class Person
{
	std::string name;
	std::string surname;
	unsigned short age;

public:
	Person() :name(""), surname(""), age(0) {}

	Person(const std::string& name, const std::string& surname, const short& age)
	{
		setName(name);
		setSurname(surname);
		setAge(age);
	}

	Person(const Person& person)
	{
		setName(person.getName());
		setSurname(person.getSurname());
		setAge(person.getAge());
	}

	Person& operator=(const Person& person)
	{
		setName(person.getName());
		setSurname(person.getSurname());
		setAge(person.getAge());
		return *this;
	}

	void setName(const std::string& name)
	{
		assert(!name.empty() && "Name can't be blank!");
		this->name = name;
	}

	std::string getName() const { return this->name; }

	void setSurname(const std::string& surname)
	{
		assert(!surname.empty() && "Surname can't be blank!");
		this->surname = surname;
	}

	std::string getSurname() const { return this->surname; }

	void setAge(const short& age)
	{
		assert(age > 0 && "Age must be greater than zero");
		this->age = age;
	}

	unsigned short getAge() const { return this->age; }

	void show() const
	{
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Surname: " << getSurname() << std::endl;
		std::cout << "Age: " << getAge() << std::endl;
	}
};

class Fighter
{
	std::string fight_power;
	std::string weapon;

public:

	Fighter() :fight_power(""), weapon("") {}

	Fighter(const std::string& fight_power, const std::string& weapon)
	{
		setFightPower(fight_power);
		setWeapon(weapon);
	}

	Fighter(const Fighter& fighter)
	{
		setFightPower(fighter.getPower());
		setWeapon(fighter.getWeapon());
	}

	Fighter & operator=(const Fighter& fighter)
	{
		setFightPower(fighter.getPower());
		setWeapon(fighter.getWeapon());
		return *this;
	}

	void setFightPower(const std::string& fight_power)
	{
		assert(!fight_power.empty() && "Fight power can't be blank!");
		this->fight_power = fight_power;
	}

	std::string getPower() const { return this->fight_power; }

	void setWeapon(const std::string& weapon)
	{
		assert(!weapon.empty() && "Weapon can't be blank!");
		this->weapon = weapon;
	}

	std::string getWeapon() const { return this->weapon; }

	bool attack()
	{
		return true;
	}

	void show() const
	{
		std::cout << "Fight power: " << getPower() << std::endl;
		std::cout << "Weapon: " << getWeapon() << std::endl;
	}
};

class Commander :public Person
{
	double army_work_practise;
	unsigned short victory_count;
	std::string army_no;

public:
	Commander() :army_work_practise(0.0), victory_count(0), army_no("") {}

	Commander(const std::string& name, const std::string& surname, const short& age,
		const double & army_work_practise, const short & victory_count, const std::string & army_no):
		Person(name, surname, age)
	{
		setArmyWorkPractise(army_work_practise);
		setVictoryCount(victory_count);
		setArmyNo(army_no);
	}

	Commander(const Commander& commander)
	{
		setName(commander.getName());
		setSurname(commander.getSurname());
		setAge(commander.getAge());
		setArmyWorkPractise(commander.getArmyWorkPractise());
		setVictoryCount(commander.getVictoryCount());
		setArmyNo(commander.getArmyNo());
	}

	Commander&operator=(const Commander& commander)
	{
		setName(commander.getName());
		setSurname(commander.getSurname());
		setAge(commander.getAge());
		setArmyWorkPractise(commander.getArmyWorkPractise());
		setVictoryCount(commander.getVictoryCount());
		setArmyNo(commander.getArmyNo());
		return *this;
	}

	void setArmyWorkPractise(const double& army_work_practise)
	{
		assert(army_work_practise >= 0 && "Army work practise must be positive value!");
		this->army_work_practise = army_work_practise;
	}

	double getArmyWorkPractise() const { return this->army_work_practise; }

	void setVictoryCount(const short& victory_count)
	{
		assert(victory_count >= 0 && "Victory count must be positive value!");
		this->victory_count = victory_count;
	}

	unsigned short getVictoryCount() const { return this->victory_count; }

	void setArmyNo(const std::string& army_no)
	{
		assert(!army_no.empty() && "Army no can't be blank!");
		this->army_no = army_no;
	}

	std::string getArmyNo() const { return this->army_no; }

	void show() const 
	{
		Person::show();
		std::cout << "Army work practise: " << getArmyWorkPractise() << std::endl;
		std::cout << "Victoru count: " << getVictoryCount() << std::endl;
		std::cout << "Army no: " << getArmyNo() << std::endl;
	}
};

class Soldier :public Person, public Fighter
{
	size_t id;

public:

	Soldier() : id(0) {}

	Soldier(const std::string& name, const std::string& surname, const short& age,
		const std::string& fight_power, const std::string& weapon, const int& id):
		Person(name, surname, age), Fighter(fight_power, weapon)
	{
		setID(id);
	}

	Soldier(const Soldier& soldier)
	{
		setName(soldier.getName());
		setSurname(soldier.getSurname());
		setAge(soldier.getAge());
		setFightPower(soldier.getPower());
		setWeapon(soldier.getWeapon());
		setID(soldier.getID());
	}

	Soldier& operator=(const Soldier& soldier)
	{
		setName(soldier.getName());
		setSurname(soldier.getSurname());
		setAge(soldier.getAge());
		setFightPower(soldier.getPower());
		setWeapon(soldier.getWeapon());
		setID(soldier.getID());

		return *this;
	}

	void setID(const int& id)
	{
		assert(id > 0 && "ID must be greater than zero!");
		this->id = id;
	}

	size_t getID()const { return this->id; }

	void show() const
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "ID: " << getID() << std::endl;
		Person::show();
		Fighter::show();
	}

	friend std::ostream& operator<<(std::ostream& out, const Soldier& soldier)
	{
		soldier.show();
		return out;
	}
};

template <class T>
class Stack
{
	T* data;
	size_t size;
public:
	Stack() : data(nullptr), size(0) {}
	void push(T value)
	{
		size_t N = this->size + 1;
		T* tmp = new T[N];
		if (tmp != nullptr)
		{
			if (N - 1)
			{
				for (size_t i = 0; i < N - 1; i++)
				{
					tmp[i] = this->data[i];
				}
				delete[] this->data;
			}
			tmp[N - 1] = value;
			this->size++;
			this->data = tmp;
		}
	}
	T pop()
	{
		T deleted;
		if (!isEmpty())
		{
			size_t N = this->size - 1;
			T* tmp = new T[N];
			if (tmp != nullptr)
			{
				deleted = data[N];
				for (size_t i = 0; i < N; i++)
				{
					tmp[i] = data[i];
				}
				delete[] this->data;
				this->data = tmp;
				this->size--;
			}
		}
		return deleted;
	}
	bool isEmpty() const { return size == 0; }
	T& peek() const
	{
		return data[size - 1];
	}
	T getSize() const
	{
		return this->size;
	}
	inline void clear()
	{
		if (this->data != nullptr)
		{
			delete[] this->data;
			this->data = nullptr;
			this->size = 0;
		}
	}
	~Stack()
	{
		clear();
	}
};

class Tank : public Fighter
{
	std::string tank_name;
	Stack<Soldier> soldiers;

public:
	Tank() : tank_name("") {
	}

	Tank(const std::string& fight_power, const std::string& weapon, const std::string& tank_name):
		Fighter(fight_power, weapon)
	{
		setTankName(tank_name);
	}

	Tank(const Tank& tank)
	{
		setFightPower(tank.getPower());
		setWeapon(tank.getWeapon());
		setTankName(tank.getTankName());
	}

	Tank& operator=(const Tank& tank)
	{
		setFightPower(tank.getPower());
		setWeapon(tank.getWeapon());
		setTankName(tank.getTankName());
		return *this;
	}
	void setTankName(const std::string& tank_name)
	{
		assert(!tank_name.empty() && "Tank name can't be blank!");
		this->tank_name = tank_name;
	}

	std::string getTankName() const { return this->tank_name; }

	void addSoldier(const Soldier& soldier)
	{
		soldiers.push(soldier);
	}

	bool isEmpty() { return soldiers.isEmpty(); }
	
	Soldier getLastSoldier()
	{
		return soldiers.pop();
	}

	void show()
	{
		std::cout << "Tank name: " << getTankName() << std::endl;
		Fighter::show();

		while (!soldiers.isEmpty())
		{
			std::cout << soldiers.pop() << std::endl;
		}
	}
};

class MilitaryAircraft : public Fighter
{
	std::string aircraft_name;
	Stack<Soldier> soldiers;

public:
	MilitaryAircraft() : aircraft_name("") {}

	MilitaryAircraft(const std::string& fight_power, const std::string& weapon, const std::string& aircraft_name) :
		Fighter(fight_power, weapon)
	{
		setAircraftName(aircraft_name);
	}

	MilitaryAircraft(const MilitaryAircraft& aircraft)
	{
		setFightPower(aircraft.getPower());
		setWeapon(aircraft.getWeapon());
		setAircraftName(aircraft.getAircraftName());
	}

	MilitaryAircraft& operator=(const MilitaryAircraft& aircraft)
	{
		setFightPower(aircraft.getPower());
		setWeapon(aircraft.getWeapon());
		setAircraftName(aircraft.getAircraftName());
		return *this;
	}
	void setAircraftName(const std::string& aircraft_name)
	{
		assert(!aircraft_name.empty() && "Aircraft name can't be blank!");
		this->aircraft_name = aircraft_name;
	}

	std::string getAircraftName() const { return this->aircraft_name; }

	void addSoldier(const Soldier& soldier)
	{
		soldiers.push(soldier);
	}

	bool isEmpty() { return soldiers.isEmpty(); }

	Soldier getLastSoldier()
	{
		return soldiers.pop();;
	}

	void show()
	{
		std::cout << "Tank name: " << getAircraftName() << std::endl;
		Fighter::show();

		while (!soldiers.isEmpty())
		{
			std::cout << soldiers.pop() << std::endl;
		}
	}
};

class MilitaryShip: public Fighter
{
	std::string ship_name;
	Stack<Soldier> soldiers;

public:
	MilitaryShip() : ship_name(""){}

	MilitaryShip(const std::string& fight_power, const std::string& weapon, const std::string& ship_name) :
		Fighter(fight_power, weapon)
	{
		setShipName(ship_name);
	}

	MilitaryShip(const MilitaryShip& ship)
	{
		setFightPower(ship.getPower());
		setWeapon(ship.getWeapon());
		setShipName(ship.getShipName());
	}

	MilitaryShip& operator=(const MilitaryShip& ship)
	{
		setFightPower(ship.getPower());
		setWeapon(ship.getWeapon());
		setShipName(ship.getShipName());
		return *this;
	}

	void setShipName(const std::string& ship_name)
	{
		assert(!ship_name.empty() && "Ship name can't be blank!");
		this->ship_name = ship_name;
	}

	std::string getShipName() const { return this->ship_name; }

	void addSoldier(const Soldier& soldier)
	{
		soldiers.push(soldier);
	}

	bool isEmpty() { return soldiers.isEmpty(); }

	Soldier getLastSoldier()
	{
		return soldiers.pop();
	}

	void show()
	{
		std::cout << "Tank name: " << getShipName() << std::endl;
		Fighter::show();

		while (!soldiers.isEmpty())
		{
			std::cout << soldiers.pop() << std::endl;
		}
	}
};


class Army
{
	Commander commander;
	Stack<Soldier> soldiers;
	Stack<Tank> tanks;
	Stack<MilitaryAircraft> aircrafts;
	Stack<MilitaryShip> ships;

public:

	Army() {}

	void show()
	{
		commander.show();
	}
};


void main()
{
	Soldier soldier;

	std::cout << soldier << std::endl;
}