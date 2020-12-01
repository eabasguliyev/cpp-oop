#include <iostream>
#include <assert.h>

class Engine
{
	std::string engine_no;
	std::string company;
	double volume;
public:
	Engine() : engine_no(""), company(""), volume(0.0) {}

	Engine(const std::string& engine_no, const std::string& company, const double& volume)
	{
		setEngineNo(engine_no);
		setCompany(company);
		setVolume(volume);
	}

	Engine(const Engine& engine)
	{
		setEngineNo(engine.getEngineNo());
		setCompany(engine.getCompany());
		setVolume(engine.getVolume());
	}

	Engine& operator=(const Engine& engine)
	{
		setEngineNo(engine.getEngineNo());
		setCompany(engine.getCompany());
		setVolume(engine.getVolume());
		return *this;
	}

	void setEngineNo(const std::string& engine_no)
	{
		assert(!engine_no.empty() && "Engine no cant be blank!");
		this->engine_no = engine_no;
	}

	std::string getEngineNo() const { return this->engine_no; }

	void setCompany(const std::string& company)
	{
		assert(!company.empty() && "Company cant be blank!");
		this->company = company;
	}

	std::string getCompany() const { return this->company; }

	void setVolume(const double& volume)
	{
		assert(volume > 0 && "Volume must be greater than zero");
		this->volume = volume;
	}

	double getVolume() const { return this->volume; }

	void show() const
	{
		std::cout << "Engine no: " << getEngineNo() << std::endl;
		std::cout << "Company: " << getCompany() << std::endl;
		std::cout << "Volume: " << getVolume() << std::endl;
	}
};

class Vehicle : public Engine
{
	size_t id;
	std::string model;
	std::string vendor;

public:
	static size_t current_id;
	Vehicle() : id(0), model(""), vendor("") {}


	Vehicle(const std::string& engine_no, const std::string& company, const double& volume,
		const std::string& model, const std::string& vendor):Engine(engine_no, company, volume)
	{
		setModel(model);
		setVendor(vendor);
		setID(++current_id);
	}

	Vehicle(const Vehicle& vehicle)
	{
		setEngineNo(vehicle.getEngineNo());
		setCompany(vehicle.getCompany());
		setVolume(vehicle.getVolume());
		setModel(vehicle.getModel());
		setVendor(vehicle.getVendor());
		setID(vehicle.getID());
	}

	Vehicle& operator=(const Vehicle& vehicle)
	{
		setEngineNo(vehicle.getEngineNo());
		setCompany(vehicle.getCompany());
		setVolume(vehicle.getVolume());
		setModel(vehicle.getModel());
		setVendor(vehicle.getVendor());
		setID(vehicle.getID());

		return *this;
	}

	void setID(const size_t& id)
	{
		assert(id > 0 && "ID must be greater than zero");
		this->id = id;
	}

	size_t getID() const { return this->id; }

	void setModel(const std::string &model)
	{
		assert(!model.empty() && "Model cant be blank!");
		this->model = model;
	}

	std::string getModel() const { return this->model; }

	void setVendor(const std::string& vendor)
	{
		assert(!vendor.empty() && "Vendor cant be blank!");
		this->vendor = vendor;
	}

	std::string getVendor() const { return this->vendor; }

	void show() const
	{
		std::cout << "ID: " << getID() << std::endl;
		std::cout << "Model: " << getModel() << std::endl;
		std::cout << "Vendor: " << getVendor() << std::endl;
		Engine::show();
	}
};

size_t Vehicle::current_id = NULL;

class Car: public Vehicle
{
	bool has_spoiler;

public:
	Car() : has_spoiler(false) {}

	Car(const std::string& engine_no, const std::string& company, const double& volume,
		const std::string& model, const std::string& vendor, const bool& has_spoiler) :
		Vehicle(engine_no, company, volume, model, vendor)
	{
		setSpoilerStatus(has_spoiler);
	}

	Car(const Car& car)
	{
		setEngineNo(car.getEngineNo());
		setCompany(car.getCompany());
		setVolume(car.getVolume());
		setModel(car.getModel());
		setVendor(car.getVendor());
		setID(car.getID());
		setSpoilerStatus(car.getSpoilerStatus());
	}

	Car& operator=(const Car& car)
	{
		setEngineNo(car.getEngineNo());
		setCompany(car.getCompany());
		setVolume(car.getVolume());
		setModel(car.getModel());
		setVendor(car.getVendor());
		setID(car.getID());
		setSpoilerStatus(car.getSpoilerStatus());
		return *this;
	}

	void setSpoilerStatus(const bool& has_spoiler)
	{
		this->has_spoiler = has_spoiler;
	}

	bool getSpoilerStatus() const { return this->has_spoiler; }

	void show() const
	{
		std::cout << "---------------------------------------" << std::endl;
		Vehicle::show();
		std::cout << "Spoiler status: " << std::boolalpha << getSpoilerStatus() << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& out, const Car& car);
};

std::ostream& operator<<(std::ostream& out, const Car& car)
{
	car.show();
	return out;
}

class Ship : public Vehicle
{
	bool has_sail;
public:

	Ship() : has_sail(false) {}

	Ship(const std::string& engine_no, const std::string& company, const double& volume,
		const std::string& model, const std::string& vendor, const bool& has_sail)
		:Vehicle(engine_no, company, volume, model, vendor)
	{
		setSailStatus(has_sail);
	}

	Ship(const Ship& ship)
	{
		setEngineNo(ship.getEngineNo());
		setCompany(ship.getCompany());
		setVolume(ship.getVolume());
		setModel(ship.getModel());
		setVendor(ship.getVendor());
		setID(ship.getID());
		setSailStatus(ship.getSailStatus());
	}

	Ship& operator=(const Ship& ship)
	{
		setEngineNo(ship.getEngineNo());
		setCompany(ship.getCompany());
		setVolume(ship.getVolume());
		setModel(ship.getModel());
		setVendor(ship.getVendor());
		setID(ship.getID());
		setSailStatus(ship.getSailStatus());
		return *this;
	}
	void setSailStatus(const bool& has_sail)
	{
		this->has_sail = has_sail;
	}

	bool getSailStatus() const
	{
		return this->has_sail;
	}

	void show() const
	{
		std::cout << "---------------------------------------" << std::endl;
		Vehicle::show();
		std::cout << "Sail status: " << std::boolalpha << getSailStatus() << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& out, const Ship& ship);
};

std::ostream& operator<<(std::ostream& out, const Ship& ship)
{
	ship.show();
	return out;
}

class Airplane : public Vehicle
{
	unsigned short engine_count;
	unsigned short passengers_capacity;

public:
	Airplane() :engine_count(0), passengers_capacity(0) {}
	Airplane(const std::string& engine_no, const std::string& company, const double& volume,
		const std::string& model, const std::string& vendor, const short& engine_count,
		const short& passengers_capacity) :Vehicle(engine_no, company, volume, model, vendor)
	{
		setEngineCount(engine_count);
		setPassengersCapacity(passengers_capacity);
	}


	Airplane(const Airplane& airplane)
	{
		setEngineNo(airplane.getEngineNo());
		setCompany(airplane.getCompany());
		setVolume(airplane.getVolume());
		setModel(airplane.getModel());
		setVendor(airplane.getVendor());
		setID(airplane.getID());
		setEngineCount(airplane.getEngineCount());
		setPassengersCapacity(airplane.getPassengersCapacity());
	}

	Airplane & operator=(const Airplane& airplane)
	{
		setEngineNo(airplane.getEngineNo());
		setCompany(airplane.getCompany());
		setVolume(airplane.getVolume());
		setModel(airplane.getModel());
		setVendor(airplane.getVendor());
		setID(airplane.getID());
		setEngineCount(airplane.getEngineCount());
		setPassengersCapacity(airplane.getPassengersCapacity());
		return *this;
	}

	void setEngineCount(const short& engine_count)
	{
		assert(engine_count > 0 && "Engine count must be greater than zero");
		this->engine_count = engine_count;
	}

	unsigned short getEngineCount() const { return this->engine_count; }

	void setPassengersCapacity(const short & passengers_capacity)
	{
		assert(engine_count >= 0 && "Passenger capacity must be positive value");
		this->passengers_capacity = passengers_capacity;
	}

	unsigned short getPassengersCapacity() const { return this->passengers_capacity; }

	void show() const
	{
		std::cout << "---------------------------------------" << std::endl;
		Vehicle::show();
		std::cout << "Engine count: " << getEngineCount() << std::endl;
		std::cout << "Passenger capacity: " << getPassengersCapacity() << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& out, const Airplane& airplane);
};

std::ostream& operator<<(std::ostream& out, const Airplane& airplane)
{
	airplane.show();
	return out;
}

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
	bool isEmpty() { return size == 0; }
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

// car ship airplane uchun cout overload et.
class WareHouse
{
	Stack<Car>* cars;
	Stack<Ship>* ships;
	Stack<Airplane>* airplanes;
public:
	WareHouse()
	{
		this->cars = new Stack<Car>;
		this->ships = new Stack<Ship>;
		this->airplanes = new Stack<Airplane>;
	}

	void showAllVehicle()
	{
		showCars();
		showShips();
		showAirplanes();
	}

	void addCar(const Car& car)
	{
		this->cars->push(car);
	}

	void addShip(const Ship& ship)
	{
		this->ships->push(ship);
	}

	void addAirplane(const Airplane& airplane)
	{
		this->airplanes->push(airplane);
	}

	void showCars()
	{
		if (cars->isEmpty())
		{
			std::cout << "There is no car in Warehouse!" << std::endl;
			return;
		}

		while (!cars->isEmpty())
		{
			std::cout << cars->pop() << std::endl;
		}
	}

	void showShips()
	{
		if (ships->isEmpty())
		{
			std::cout << "There is no ship in Warehouse!" << std::endl;
			return;
		}
		while (!ships->isEmpty())
		{
			std::cout << ships->pop() << std::endl;
		}
	}

	void showAirplanes()
	{
		if (airplanes->isEmpty())
		{
			std::cout << "There is no airplane in Warehouse!" << std::endl;
			return;
		}

		while (!airplanes->isEmpty())
		{
			std::cout << airplanes->pop() << std::endl;
		}
	}

	~WareHouse()
	{
		delete cars;
		delete ships;
		delete airplanes;
	}
};


void main()
{
	WareHouse wh;

	Car audi("ADB105412", "Audi", 400, "Audi A4", "Audi", false);
	Car bmw("BMT15451", "BMW", 500, "BMW F10", "BMW", true);
	
	Ship battleship("BAT1545", "Battleship", 8000, "Battleship", "USS", false);
	Ship schooner("SCH4542", "Schooner", 1500, "Schooner", "Bristol Yachts", true);
	
	Airplane boeing777("BO104654", "Boeing", 5000, "Boeing 777", "Boeing Commercial Airplanes", 4, 368);

	wh.addCar(audi);
	wh.addCar(bmw);

	wh.addShip(battleship);
	wh.addShip(schooner);


	wh.addAirplane(boeing777);

	wh.showAllVehicle();
}