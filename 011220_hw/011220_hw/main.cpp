#include <iostream>
#include <assert.h>

class Soldier;
void showSoldiers(Soldier* soldiers, size_t size);

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
	float fight_power;
	std::string weapon;

public:

	Fighter() :fight_power(0.0), weapon("") {}

	Fighter(const float& fight_power, const std::string& weapon)
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

	void setFightPower(const float& fight_power)
	{
		assert(fight_power > 0 && "Fight power must be greater than zero!");
		this->fight_power = fight_power;
	}

	float getPower() const { return this->fight_power; }

	void setWeapon(const std::string& weapon)
	{
		assert(!weapon.empty() && "Weapon can't be blank!");
		this->weapon = weapon;
	}

	std::string getWeapon() const { return this->weapon; }

	void attack()
	{
		std::cout << "Fighter attacked with " << getWeapon() << std::endl;
		std::cout << "Damaged given -> " << getPower() << std::endl;
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
		std::cout << "Victory count: " << getVictoryCount() << std::endl;
		std::cout << "Army no: " << getArmyNo() << std::endl;
	}
};

class Soldier :public Person, public Fighter
{
	size_t id;

public:

	Soldier() : id(0) {}

	Soldier(const std::string& name, const std::string& surname, const short& age,
		const float& fight_power, const std::string& weapon, const int& id):
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
	
};

template <class T>
class Stack
{
	T* data;
	size_t size;
public:
	Stack() : data(nullptr), size(0) {}
	Stack(const Stack& stack)
	{
		this->size = stack.getSize();

		T* tmp = stack.getData();

		this->data = new T[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			data[i] = tmp[i];
		}
	}
	Stack& operator=(const Stack& stack)
	{
		this->size = stack.getSize();

		T* tmp = stack.getData();

		this->data = new T[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			data[i] = tmp[i];
		}
		return *this;
	}
	void push(const T& value)
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
	size_t getSize() const
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

	T* getData() const {
		return this->data;
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

	Tank(const float& fight_power, const std::string& weapon, const std::string& tank_name):
		Fighter(fight_power, weapon)
	{
		setTankName(tank_name);
	}

	Tank(const Tank& tank)
	{
		setFightPower(tank.getPower());
		setWeapon(tank.getWeapon());
		setTankName(tank.getTankName());
		setStack(tank.getStack());
	}

	
	Tank& operator=(const Tank& tank)
	{
		setFightPower(tank.getPower());
		setWeapon(tank.getWeapon());
		setTankName(tank.getTankName());
		setStack(tank.getStack());
		return *this;
	}

	void setStack(const Stack<Soldier>& soldiers)
	{
		this->soldiers = soldiers;
	}

	const Stack<Soldier>& getStack() const
	{
		return soldiers;
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

	Soldier* getSoldiers()
	{
		return soldiers.getData();
	}

	size_t getSoldierCount()
	{
		return soldiers.getSize();
	}

	void show()
	{
		std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "Tank name: " << getTankName() << std::endl;
		Fighter::show();


		showSoldiers(this->getSoldiers(), this->getSoldierCount());
	}
};

class MilitaryAircraft : public Fighter
{
	std::string aircraft_name;
	Stack<Soldier> soldiers;

public:
	MilitaryAircraft() : aircraft_name("") {}

	MilitaryAircraft(const float& fight_power, const std::string& weapon, const std::string& aircraft_name) :
		Fighter(fight_power, weapon)
	{
		setAircraftName(aircraft_name);
	}

	MilitaryAircraft(const MilitaryAircraft& aircraft)
	{
		setFightPower(aircraft.getPower());
		setWeapon(aircraft.getWeapon());
		setAircraftName(aircraft.getAircraftName());
		setStack(aircraft.getStack());
	}

	MilitaryAircraft& operator=(const MilitaryAircraft& aircraft)
	{
		setFightPower(aircraft.getPower());
		setWeapon(aircraft.getWeapon());
		setAircraftName(aircraft.getAircraftName());
		setStack(aircraft.getStack());
		return *this;
	}

	void setStack(const Stack<Soldier>& soldiers)
	{
		this->soldiers = soldiers;
	}

	const Stack<Soldier>& getStack() const
	{
		return soldiers;
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

	Soldier* getSoldiers()
	{
		return soldiers.getData();
	}

	size_t getSoldierCount()
	{
		return soldiers.getSize();
	}

	void show()
	{
		std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "Aircraft name: " << getAircraftName() << std::endl;
		Fighter::show();

		showSoldiers(this->getSoldiers(), this->getSoldierCount());
	}
};

class MilitaryShip: public Fighter
{
	std::string ship_name;
	Stack<Soldier> soldiers;

public:
	MilitaryShip() : ship_name(""){}

	MilitaryShip(const float& fight_power, const std::string& weapon, const std::string& ship_name) :
		Fighter(fight_power, weapon)
	{
		setShipName(ship_name);
	}

	MilitaryShip(const MilitaryShip& ship)
	{
		setFightPower(ship.getPower());
		setWeapon(ship.getWeapon());
		setShipName(ship.getShipName());
		setStack(ship.getStack());
	}

	MilitaryShip& operator=(const MilitaryShip& ship)
	{
		setFightPower(ship.getPower());
		setWeapon(ship.getWeapon());
		setShipName(ship.getShipName());
		setStack(ship.getStack());
		return *this;
	}

	void setStack(const Stack<Soldier>& soldiers)
	{
		this->soldiers = soldiers;
	}

	const Stack<Soldier>& getStack() const
	{
		return soldiers;
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

	Soldier* getSoldiers()
	{
		return soldiers.getData();
	}

	size_t getSoldierCount()
	{
		return soldiers.getSize();
	}

	void show()
	{
		std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "Ship name: " << getShipName() << std::endl;
		Fighter::show();

		showSoldiers(this->getSoldiers(), this->getSoldierCount());
	}
};

class Army
{
	Commander commander;
	Stack<Soldier> soldiers;
	Stack<Tank> tanks;
	Stack<MilitaryAircraft> aircrafts;
	Stack<MilitaryShip> ships;

private:
	template <typename T>
	void showVehicleSoldiers(T* vehicles, size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			vehicles[i].show();
		}
	}

	float calculateSoldiersPower(Soldier * soldiers, size_t size) {
		float sum = 0;
		for (size_t i = 0; i < size; i++)
		{
			sum += soldiers[i].getPower();
		}

		return sum;
	}
	template <typename T>
	float calculateVehiclesPower(T* vehicles, size_t size)
	{
		float sum = 0;

		for (size_t i = 0; i < size; i++)
		{
			sum += (vehicles[i].getPower() + calculateSoldiersPower(vehicles[i].getSoldiers(), vehicles[i].getSoldierCount()));
		}

		return sum;
	}
public:
	Army() {}

	Army(const Commander& commander)
	{
		setCommander(commander);
	}

	float calculateArmyPower()
	{
		float sum = calculateSoldiersPower(soldiers.getData(), soldiers.getSize());
		
		sum += calculateVehiclesPower(tanks.getData(), tanks.getSize());
		sum += calculateVehiclesPower(ships.getData(), ships.getSize());
		sum += calculateVehiclesPower(aircrafts.getData(), aircrafts.getSize());

		return sum;
	}
	void setCommander(const Commander& commander)
	{
		this->commander = commander;
	}

	void addSoldier(const Soldier& soldier)
	{
		this->soldiers.push(soldier);
	}

	void popSoldier()
	{
		this->soldiers.pop();
	}

	Soldier* getSoldiers()
	{
		return this->soldiers.getData();
	}

	void addTank(const Tank& tank)
	{
		this->tanks.push(tank);
	}

	void popTank()
	{
		this->tanks.pop();
	}

	Tank* getTanks()
	{
		return this->tanks.getData();
	}

	void addAircraft(const MilitaryAircraft& aircraft)
	{
		this->aircrafts.push(aircraft);
	}

	void popAircraft()
	{
		this->aircrafts.pop();
	}

	MilitaryAircraft* getAircraft()
	{
		return this->aircrafts.getData();
	}

	void addShip(const MilitaryShip& ship)
	{
		this->ships.push(ship);
	}

	void popShip()
	{
		this->ships.pop();
	}

	MilitaryShip* getShips()
	{
		return this->ships.getData();
	}

	void show()
	{
		commander.show();
		showSoldiers(soldiers.getData(), soldiers.getSize());
		showVehicleSoldiers(tanks.getData(), tanks.getSize());
		showVehicleSoldiers(aircrafts.getData(), aircrafts.getSize());
		showVehicleSoldiers(ships.getData(), ships.getSize());
	}
};

void showSoldiers(Soldier* soldiers, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		soldiers[i].show();
	}
}

void main()
{
	Commander commander("John", "Price", 40, 20, 500, "11");

	Army army(commander);

	Soldier soldier1("A1", "B1", 18, 400, "glock", 1);
	Soldier soldier2("A2", "B2", 19, 500, "glock", 2);
	Soldier soldier3("A3", "B3", 20, 500, "glock", 3);
	Soldier soldier4("A4", "B4", 21, 300, "glock", 4);
	Soldier soldier5("A5", "B5", 22, 200, "glock", 5);
	Soldier soldier6("A6", "B6", 20, 300, "glock", 6);
	Soldier soldier7("A7", "B7", 21, 200, "glock", 7);
	Soldier soldier8("A8", "B8", 19, 100, "glock", 8);
	Soldier soldier9("A9", "B9", 22, 400, "glock", 9);
	Soldier soldier10("A10", "B10", 20, 300, "glock", 10);

	Tank tank(1000, "L30", "C1");

	MilitaryAircraft aircraft(1500, "Hydra 70", "D1");

	MilitaryShip ship(1800, "Naval Artillery", "E1");


	tank.addSoldier(soldier1);
	tank.addSoldier(soldier2);
	aircraft.addSoldier(soldier3);
	aircraft.addSoldier(soldier4);
	ship.addSoldier(soldier5);
	ship.addSoldier(soldier6);

	army.addTank(tank);
	army.addShip(ship);
	army.addAircraft(aircraft);

	army.addSoldier(soldier7);
	army.addSoldier(soldier8);
	army.addSoldier(soldier9);
	army.addSoldier(soldier10);

	//army.getTanks()[0].show();
	army.show();

	std::cout << "Army power: " << army.calculateArmyPower() << std::endl;
	//army.getTanks()[0].getSoldiers()[0].show();

}