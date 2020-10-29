#include <iostream>

/*class Operation
{
	int m_number1 = 0;
	int m_number2 = 0;

public:
	Operation()
	{
		m_number1 = 0;
		m_number2 = 0;
	}

	Operation(int n1, int n2)
	{
		m_number1 = n1;
		m_number2 = n2;
	}

	inline int GetSum()
	{
		return m_number1 + m_number2;
	}


};*/

class Car {
	size_t m_id = 0;
	char* m_model = nullptr;
	char* m_name = nullptr;
	char* m_vendor = nullptr;
	char* m_phone_num = nullptr;
	char* m_engine = nullptr;
	char* m_color = nullptr;
	short m_year = 0;
	double m_gas_hundred = 0;
	double m_gas_custom = 0;
	double m_gas_custom_price = 0;

public:
	Car()
	{
	}

	Car(const int id, const char* model, const char* name, const char* vendor,
		const char * phone_num, const char* engine, const char * color, const short year)
		:Car(id, model, name, vendor, phone_num, engine, color)
	{
		SetYear(year);
	}

	Car(const int id, const char* model, const char* name, const char* vendor,
		const char* phone_num, const char* engine, const char* color)
		:Car(id, model, name, vendor, phone_num, engine)
	{
		SetColor(color);
	}

	Car(const int id, const char* model, const char* name, const char* vendor,
		const char* phone_num, const char* engine)
		:Car(id, model, name, vendor, phone_num)
	{
		SetEngine(engine);
	}

	Car(const int id, const char* model, const char* name, const char* vendor,
		const char* phone_num):Car(id, model, name, vendor)
	{
		SetPhoneNumber(phone_num);
	}

	Car(const int id, const char* model, const char* name, const char* vendor)
		:Car(id, model, name)
	{
		SetVendor(vendor);
	}
	
	Car(const int id, const char* model, const char* name)
		:Car(id, model)
	{
		SetName(name);
	}

	Car(const int id, const char* model):Car(id)
	{
		SetModel(model);
	}

	Car(const int id)
	{
		SetID(id);
	}
	void SetModel(const char* model)
	{
		if (model && strlen(model))
		{
			m_model = _strdup(model);
		}
	}

	const char* GetModel()
	{
		return m_model;
	}

	void SetName(const char* name)
	{
		if (name && strlen(name))
		{
			m_name = _strdup(name);
		}
	}

	const char* GetName()
	{
		return m_name;
	}

	void SetYear(const short year)
	{
		if (year > 0)
		{
			m_year = year;
		}
	}

	unsigned short GetYear()
	{
		return m_year;
	}

	void SetID(const int ID)
	{
		if (ID > 0)
		{
			m_id = ID;
		}
	}

	const size_t GetID()
	{
		return m_id;
	}

	void SetVendor(const char* vendor)
	{
		if (vendor && strlen(vendor))
		{
			m_vendor = _strdup(vendor);
		}
	}

	const char* GetVendor()
	{
		return m_vendor;
	}

	void SetPhoneNumber(const char* phone_number)
	{
		if (phone_number && strlen(phone_number))
		{
			m_phone_num = _strdup(phone_number);
		}
	}

	const char* GetPhoneNumber()
	{
		return m_phone_num;
	}

	void SetEngine(const char* engine)
	{
		if (engine && strlen(engine))
		{
			m_engine = _strdup(engine);
		}
	}

	const char* GetEngine()
	{
		return m_engine;
	}

	void SetColor(const char* color)
	{
		if (color && strlen(color))
		{
			m_color = _strdup(color);
		}
	}

	const char* GetColor()
	{
		return m_color;
	}

	void SetGasHundred(const double gas_hundred)
	{
		if (gas_hundred > 0)
		{
			m_gas_hundred = gas_hundred;
		}
	}

	double GetGasHundred()
	{
		return m_gas_hundred;
	}

	void CalcGasCustom(const int km)
	{
		if(km > 0)
			m_gas_custom = (m_gas_hundred / 100.0) * km;
	}

	double GetCasCustom()
	{
		return m_gas_custom;
	}
	void CalcGasCustomPrice(const int km)
	{
		if(km > 0)
			m_gas_custom_price = m_gas_custom * 1.15;
	}

	double GetCasCustomPrice()
	{
		return m_gas_custom_price;
	}
	void ShowCar()
	{
		if(GetID())
			std::cout << "ID: " << GetID() << std::endl;
		if(GetModel())
			std::cout << "Model: " << GetModel() << std::endl;
		if(GetName())
			std::cout << "Name: " << GetName() << std::endl;
		if (GetVendor())
			std::cout << "Vendor: " << GetVendor() << std::endl;
		if (GetPhoneNumber())
			std::cout << "Phone Number: " << GetPhoneNumber() << std::endl;
		if (GetEngine())
			std::cout << "Engine: " << GetEngine() << std::endl;
		if (GetColor())
			std::cout << "Color: " << GetColor() << std::endl;
		if(GetYear())
			std::cout << "Year: " << GetYear() << std::endl;
	}

	~Car()
	{
		delete[] m_model;
		delete[] m_name;
		delete[] m_color;
		delete[] m_engine;
		delete[] m_phone_num;
		delete[] m_vendor;
	}
};

class Point
{
	int x = 0;
	int y = 0;

public:
	Point()
	{

	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void ShowInfo()
	{
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
	}
};

class Student {
	int id = 0;
	int age = 0;
public:
	Student()
	{

	}
	Student(const int id, const int age)
	{
		this->id = id;
		this->age = age;
	}

	explicit Student(const int age)
	{
		this->age = age;
	}

	void ShowData()
	{
		std::cout << "ID: " << id << std::endl;
		std::cout << "Age: " << age << std::endl;
	}
};


class CarGallery
{
	char* name = nullptr;
	size_t car_counts = 0;
	Car* cars = nullptr;
public:
	CarGallery() :name(nullptr), cars(nullptr), car_counts(0)
	{
		SetName(name);
		SetCars(cars);
		SetCarCount(car_counts);
	}

	CarGallery(const char* name, const Car* cars)
	{

	}
	CarGallery(const char* name)
	{

	}

	void SetCarCount(const int car_counts)
	{
		if (car_counts > 0)
		{
			this->car_counts = car_counts;
		}
	}
	void SetName(const char* name)
	{
		if (name)
		{
			this->name = _strdup(name);
		}
	}

	const char* GetName()
	{
		return name;
	}

	void SetCars(Car * cars)
	{
		this->cars = new Car[car_counts];

		for (size_t i = 0; i < car_counts; i++)
		{
			this->cars[i].SetColor(cars[i]);
 		}
	}

	const Car* GetCars()
	{
		return cars;
	}
}
int main()
{
	/*Student s1(21);
	s1.ShowData();*/
	/*Point p(10, 20);
	p.ShowInfo();

	Point p2(25, 69);
	p2.ShowInfo();*/

	// Car - id, vendor, phonenum, engine, color
	/*Car mercedes("Mercedes", "E-200", 2018);
	
	Car bmw("BMW", "M5", 2020);

	Car audi(2015);
	mercedes.ShowCar();
	std::cout << std::endl;
	bmw.ShowCar();
	std::cout << std::endl;
	audi.ShowCar();

	Car ferrari("Ferrari", "458-Italy");

	ferrari.ShowCar();

	Car bmw2(16, "BMW", "F12", "Brembo", "+99454541345", "V12", "Black", 2015);

	bmw2.ShowCar();

	bmw2.SetGasHundred(65);

	double km = 300;

	bmw2.CalcGasCustom(km);
	bmw2.CalcGasCustomPrice(km);
	std::cout << km << " km : " << bmw2.GetCasCustom() << " lt " << std::endl;
	std::cout << km << " km : " << bmw2.GetCasCustomPrice() << " azn" << std::endl;*/
	/*Operation o(10, 20);

	std::cout << "Su: " << o.GetSum() << std::endl;*/
	return 0;
}