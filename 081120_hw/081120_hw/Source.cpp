#include <iostream>
#include <assert.h>

class Fraction
{
	double numerator;
	double denominator;

private:
	double GCD(double num1, double num2)
	{
		if (num1 == 0)
			return num2;

		double remainder;
		int result;
		double second;
		if (num1 < num2)
		{
			result = num2 / num1;
			remainder = num2 - (result * num1);
			second = num1;
		}
		else
		{
			result = num1 / num2;
			remainder = num1 - (result * num2);
			second = num2;
		}

		return GCD(remainder, second);
	}
public:
	Fraction() :numerator(0), denominator(0) {}

	Fraction(double numerator, double denominator)
	{
		setNumerator(numerator);
		setDenominator(denominator);
	}

	Fraction(const Fraction& frac)
	{
		setNumerator(frac.getNumerator());
		setDenominator(frac.getDenominator());
	}

	Fraction& operator=(const Fraction& frac)
	{
		setNumerator(frac.getNumerator());
		setDenominator(frac.getDenominator());

		return *this;
	}

	Fraction& operator+(const Fraction& second)
	{
		if (this->denominator == second.denominator)
		{
			setNumerator(this->numerator + second.numerator);
		}
		else
		{
			double denominator = this->denominator * second.denominator;
			this->numerator *= second.denominator;
			double second_numerator = this->denominator * second.numerator;
			setNumerator(this->numerator + second_numerator);
			setDenominator(denominator);
		}
		return *this;
	}

	Fraction& operator-(const Fraction& second)
	{
		if (this->denominator == second.denominator)
		{
			setNumerator(this->numerator - second.numerator);
		}
		else
		{
			double denominator = this->denominator * second.denominator;
			this->numerator *= second.denominator;
			double second_numerator = this->denominator * second.numerator;
			setNumerator(this->numerator - second_numerator);
			setDenominator(denominator);
		}
		return *this;
	}

	Fraction& operator*(const Fraction& second)
	{
		setNumerator(this->numerator * second.numerator);
		setDenominator(this->denominator * second.denominator);
		return *this;
	}

	Fraction& operator/(const Fraction& second)
	{
		setNumerator(this->numerator * second.denominator);
		setDenominator(this->denominator * second.numerator);
		return *this;
	}
	
	Fraction& operator++()
	{
		this->numerator++;
		this->denominator++;
		return *this;
	}
	
	Fraction* operator++(int)
	{
		Fraction* temp = new Fraction(this->numerator, this->denominator);
		this->numerator++;
		this->denominator++;
		return temp;
	}

	Fraction& operator--()
	{
		this->numerator--;
		this->denominator--;
		return *this;
	}

	Fraction& operator--(int)
	{
		Fraction* temp = new Fraction(this->numerator, this->denominator);
		this->numerator--;
		this->denominator--;
		return *temp;
	}

	void setNumerator(double numerator)
	{
		this->numerator = numerator;
	}

	double getNumerator() const
	{
		return numerator;
	}

	void setDenominator(double denominator)
	{
		assert(denominator && "Denominator must be non-zero value");
		this->denominator = denominator;
	}

	void reduce()
	{
		double divisor = GCD(this->numerator, this->denominator);

		if (divisor != 1)
		{
			setNumerator(this->numerator / divisor);
			setDenominator(this->denominator / divisor);
		}
	}

	double getDenominator() const
	{
		return denominator;
	}

	friend std::ostream& operator<<(std::ostream& out, Fraction& frac);

	friend std::istream& operator>>(std::istream& in, Fraction& frac);
	~Fraction()
	{
		std::cout << "Fraction deleted from stack" << std::endl;
	}
};


std::ostream& operator <<(std::ostream& out, Fraction& frac)
{
	frac.reduce();
	out << frac.getNumerator();

	if(frac.getDenominator() != 1)
		out << " / " << frac.getDenominator();

	return out;
}

std::istream& operator>>(std::istream& in, Fraction& frac)
{
	double numerator, denominator;
	std::cout << "Enter fraction numerator: ";

	in >> numerator;

	frac.setNumerator(numerator);

	std::cout << "Enter fraction denominator: ";

	in >> denominator;

	frac.setDenominator(denominator);

	return in;
}
class Computer
{
	size_t computer_id;
	char* model;
	char* vendor;
	double cpu_hz;
	unsigned short ram;
	unsigned short core;
	char* videocard;
	char* monitor;
	double disk_size;
	bool isSSD;
	double price;

public:
	static size_t current_id;

	Computer() :computer_id(0), model(nullptr), vendor(nullptr), cpu_hz(0.0), ram(0), core(0),
		videocard(nullptr), monitor(nullptr), disk_size(0.0), isSSD(false), price(0.0) {}

	Computer(const char* model, const char* vendor, double cpu_hz, short ram, short core,
		const char* videocard, const char* monitor, double disk_size, bool isSSD, double price) :
		Computer(model, vendor, cpu_hz, ram, core, videocard, monitor, disk_size, isSSD)
	{
		setPrice(price);
	}

	Computer(const char* model, const char* vendor, double cpu_hz, short ram, short core,
		const char* videocard, const char* monitor, double disk_size, bool isSSD) :
		Computer(model, vendor, cpu_hz, ram, core, videocard, monitor, disk_size) 
	{
		setSSD(isSSD);
	}

	Computer(const char* model, const char* vendor, double cpu_hz, short ram, short core,
		const char* videocard, const char* monitor, double disk_size) :
		Computer(model, vendor, cpu_hz, ram, core, videocard, monitor)
	{
		setDiskSize(disk_size);
	}

	Computer(const char* model, const char* vendor, double cpu_hz, short ram, short core,
		const char* videocard, const char* monitor) :
		Computer(model, vendor, cpu_hz, ram, core, videocard)
	{
		setMonitor(monitor);
	}

	Computer(const char* model, const char* vendor, double cpu_hz, short ram, short core,
		const char* videocard) :
		Computer(model, vendor, cpu_hz, ram, core)
	{
		setVideoCard(videocard);
	}

	Computer(const char* model, const char* vendor, double cpu_hz, short ram, short core) :
		Computer(model, vendor, cpu_hz, ram)
	{
		setCoreCount(core);
	}

	Computer(const char* model, const char* vendor, double cpu_hz, short ram) :
		Computer(model, vendor, cpu_hz)
	{
		setRamSize(ram);
	}

	Computer(const char* model, const char* vendor, double cpu_hz) :
		Computer(model, vendor)
	{
		setCpuSpeed(cpu_hz);
	}

	Computer(const char* model, const char* vendor) :
		Computer(model)
	{
		setVendor(vendor);
	}


	explicit Computer(const char* model)
	{
		setModel(model);
		setComputerID(++current_id);
	}

	Computer(const Computer& computer)
	{
		setComputerID(computer.getComputerID());
		setModel(computer.getModel());
		setVendor(computer.getVendor());
		setCpuSpeed(computer.getCpuSpeed());
		setRamSize(computer.getRamSize());
		setCoreCount(computer.getCoreCount());
		setVideoCard(computer.getVideoCard());
		setMonitor(computer.getMonitor());
		setDiskSize(computer.getDiskSize());
		setSSD(computer.getSSD());
		setPrice(computer.getPrice());
	}

	Computer& operator=(const Computer& computer)
	{
		setComputerID(computer.getComputerID());
		setModel(computer.getModel());
		setVendor(computer.getVendor());
		setCpuSpeed(computer.getCpuSpeed());
		setRamSize(computer.getRamSize());
		setCoreCount(computer.getCoreCount());
		setVideoCard(computer.getVideoCard());
		setMonitor(computer.getMonitor());
		setDiskSize(computer.getDiskSize());
		setSSD(computer.getSSD());
		setPrice(computer.getPrice());
		return *this;
	}

	void setComputerID(size_t id)
	{
		this->computer_id = id;
	}

	size_t getComputerID() const
	{
		return computer_id;
	}

	void setModel(const char* model)
	{
		assert(model && "Null Error!");
		size_t length = strlen(model) + 1;
		this->model = new char[length];
		strcpy_s(this->model, length, model);
	}

	const char* getModel() const
	{
		return model;
	}

	void setVendor(const char* vendor)
	{
		assert(vendor && "Null Error!");
		size_t length = strlen(vendor) + 1;
		this->vendor = new char[length];
		strcpy_s(this->vendor, length, vendor);
	}

	const char* getVendor() const
	{
		return vendor;
	}

	void setCpuSpeed(double cpu_hz)
	{
		assert(cpu_hz > 0 && "Cpu Hz must be greater than zero");
		this->cpu_hz = cpu_hz;
	}

	double getCpuSpeed() const
	{
		return cpu_hz;
	}

	void setRamSize(short ram)
	{
		assert(ram > 0 && "Ram size must be greater than zero");
		this->ram = ram;
	}

	unsigned short getRamSize() const
	{
		return ram;
	}

	void setCoreCount(short core)
	{
		assert(core > 0 && "Core count must be greater than zero");
		this->core = core;
	}

	unsigned short getCoreCount() const
	{
		return core;
	}

	void setVideoCard(const char* videocard)
	{
		assert(videocard && "Null Error!");
		size_t length = strlen(videocard) + 1;
		this->videocard = new char[length];
		strcpy_s(this->videocard, length, videocard);
	}

	const char* getVideoCard() const
	{
		return videocard;
	}

	void setMonitor(const char* monitor)
	{
		assert(monitor && "Null Error!");
		size_t length = strlen(monitor) + 1;
		this->monitor = new char[length];
		strcpy_s(this->monitor, length, monitor);
	}

	const char* getMonitor() const
	{
		return monitor;
	}

	void setDiskSize(double disk_size)
	{
		assert(disk_size > 0 && "Disk size must be greater than zero");
		this->disk_size = disk_size;
	}

	double getDiskSize() const
	{
		return disk_size;
	}

	void setSSD(bool isSSD)
	{
		this->isSSD = isSSD;
	}

	bool getSSD() const
	{
		return isSSD;
	}

	void setPrice(double price)
	{
		assert(price > 0 && "Price must be greater than zero");
		this->price = price;
	}

	double getPrice() const
	{
		return price;
	}

	friend std::ostream& operator << (std::ostream& out, const Computer& computer);

	friend std::istream& operator>>(std::istream& in, Computer& computer);

	void * operator new(size_t size)
	{
		return malloc(size);
	}

	void* operator new[](size_t size)
	{
		return malloc(size);
	}
	
	void operator delete(void*  computer)
	{
		free(computer);
	}

	void operator delete[](void* computer)
	{
		free(computer);
	}

	~Computer()
	{
		delete[] model;
		delete[] vendor;
		delete[] videocard;
		delete[] monitor;
	}
};

size_t Computer::current_id = 0;

std::ostream &operator << (std::ostream& out, const Computer& computer)
{
	const char* model = computer.getModel();
	const char* vendor = computer.getVendor();
	const char* videocard = computer.getVideoCard();
	const char* monitor = computer.getMonitor();

	out << "-------------------------------------------" << std::endl;
	out << "Computer ID: " << computer.getComputerID() << std::endl;
	out << "Model: ";
	if (model)
		out << model << std::endl;
	else
		out << "none" << std::endl;

	out << "Vendor: ";

	if (vendor)
		out << vendor << std::endl;
	else
		out << "none" << std::endl;

	out << "Ram: " << computer.getRamSize() << " gb" << std::endl;
	out << "Cpu Speed (hz): " << computer.getCpuSpeed() << " hz" << std::endl;
	out << "Core: " << computer.getCoreCount() << std::endl;
	out << "Videocard: ";
	if (videocard)
		out << videocard << std::endl;
	else
		out << "none" << std::endl;

	out << "Monitor: ";
	if (monitor)
		out << monitor << std::endl;
	else
		out << "none" << std::endl;

	out << "Disk size: " << computer.getDiskSize() << " gb" << std::endl;
	out << "SSD: ";

	if (computer.getSSD())
		std::cout << "exist" << std::endl;
	else
		std::cout << "none" << std::endl;

	out << "Price: $ " << computer.getPrice() << std::endl;
	return out;
}

std::istream&operator>>(std::istream& in, Computer& computer)
{
	computer.setComputerID(++Computer::current_id);
	char* buff = new char[50];
	std::cout << "Computer model: ";

	in.getline(buff, 50);

	computer.setModel(buff);

	std::cout << "Computer vendor: ";

	in.getline(buff, 50);

	computer.setVendor(buff);

	double buff2;

	std::cout << "Computer ram: ";

	in >> buff2;

	computer.setRamSize(buff2);

	std::cout << "Computer cpu speed: ";

	in >> buff2;
	
	computer.setCpuSpeed(buff2);

	std::cout << "Computer cpu core count: ";

	in >> buff2;

	computer.setCoreCount(buff2);

	std::cout << "Computer videocard: ";

	in.ignore();
	in.getline(buff, 50);

	computer.setVideoCard(buff);

	std::cout << "Computer monitor: ";

	in.getline(buff, 50);

	computer.setMonitor(buff);

	std::cout << "Computer disk size: ";

	in >> buff2;

	computer.setDiskSize(buff2);

	std::cout << "Computer sss (yes/no): ";
	in.ignore();
	in.getline(buff, 50);

	if (strcmp(buff, "yes") == 0)
		computer.setSSD(true);
	else
		computer.setSSD(false);

	std::cout << "Computer price: $";

	in >> buff2;

	computer.setPrice(buff2);

	delete[] buff;

	in.ignore();
	return in;
}

class ComputerStore
{
	size_t store_id;
	char* store_name;
	char* store_address;
	size_t computer_count;
	Computer* computers;
	
public:
	static size_t current_id;
	ComputerStore() :store_name(nullptr), store_address(nullptr), computers(nullptr) {}

	ComputerStore(const char* store_name, const char* store_address, const Computer* computers, int computer_count)
		:ComputerStore(store_name, store_address)
	{
		setComputerCount(computer_count);
		setComputers(computers);
	}

	ComputerStore(const char* store_name, const char* store_address)
		:ComputerStore(store_name)
	{
		setStoreAddress(store_address);
	}

	ComputerStore(const char* store_name)
	{
		setStoreName(store_name);
		setStoreID(++current_id);
	}

	ComputerStore(const ComputerStore& store)
	{
		setStoreID(store.getStoreID());
		setStoreName(store.getStoreName());
		setStoreAddress(store.getStoreAddress());
		setComputerCount(store.getComputerCount());
		setComputers(store.getComputers());
	}

	ComputerStore& operator = (const ComputerStore& store)
	{
		setStoreID(store.getStoreID());
		setStoreName(store.getStoreName());
		setStoreAddress(store.getStoreAddress());
		setComputerCount(store.getComputerCount());
		setComputers(store.getComputers());

		return *this;
	}

	void setStoreID(size_t id)
	{
		this->store_id = id;
	}

	size_t getStoreID() const
	{
		return store_id;
	}
	void setComputers(const Computer* computers)
	{
		assert(computers && "Null Error!");

		size_t length = getComputerCount();
		this->computers = new Computer[length];

		if (this->computers)
		{
			for (size_t i = 0; i < length; i++)
			{
				this->computers[i] = computers[i];
			}
		}
	}

	void setComputerCount(int computer_count)
	{
		assert(computer_count > 0 && "Computer count must be greater than zero");
		this->computer_count = computer_count;
	}

	size_t getComputerCount() const
	{
		return computer_count;
	}

	Computer* getComputers() const
	{
		return computers;
	}

	void setStoreName(const char* store_name)
	{
		assert(store_name && "Null Error!");
		size_t length = strlen(store_name) + 1;
		this->store_name = new char[length];
		strcpy_s(this->store_name, length, store_name);
	}

	const char* getStoreName() const
	{
		return store_name;
	}

	void setStoreAddress(const char* store_address)
	{
		assert(store_address && "Null Error!");
		size_t length = strlen(store_address) + 1;
		this->store_address = new char[length];
		strcpy_s(this->store_address, length, store_address);
	}

	const char* getStoreAddress() const
	{
		return store_address;
	}

	bool addComputer(const Computer & computer)
	{
		assert(&computer && "Null Error!");

		size_t new_size = getComputerCount() + 1;

		Computer* new_computers = new Computer[new_size];

		if (new_computers)
		{
			for (size_t i = 0; i < new_size - 1; i++)
			{
				new_computers[i] = computers[i];
			}
			
			new_computers[new_size - 1] = computer;

			setComputerCount(new_size);
			
			if (computers)
				delete[] computers;

			computers = new_computers;
			new_computers = nullptr;
			return true;
		}
		return false;
	}

	bool delComputer(int id)
	{
		assert(id > 0 && "ID must be greater than zero");

		if (computers)
		{
			size_t new_size = getComputerCount() - 1;
			Computer* new_computers = new Computer[new_size];

			if (new_computers)
			{
				for (size_t i = 0, length = new_size + 1, j = 0; i < length; i++)
				{
					if (computers[i].getComputerID() != id)
					{
						new_computers[j++] = computers[i];
					}
				}
				delete[] computers;

				computers = new_computers;
				new_computers = nullptr;

				setComputerCount(new_size);
				return true;
			}
		}
		else
			std::cout << "There is no computer" << std::endl;
		return false;
	}

	friend std::ostream& operator << (std::ostream& out, const ComputerStore& store);
	friend std::istream& operator >> (std::istream& in, ComputerStore& store);
	~ComputerStore()
	{
		delete[] store_name;
		delete[] store_address;
		delete[] computers;
	}
};

size_t ComputerStore::current_id = 0;
std::ostream& operator << (std::ostream& out, const ComputerStore& store)
{
	const char* store_name = store.getStoreName();

	const char* store_address = store.getStoreAddress();

	out << "Store id: " << store.getStoreID() << std::endl;

	out << "Name: ";

	if (store_name)
		out << store_name << std::endl;
	else
		out << "none" << std::endl;

	out << "Address: ";

	if (store_address)
		out << store_address << std::endl;
	else
		out << "none" << std::endl;

	if (store.computer_count)
	{
		for (size_t i = 0; i < store.computer_count; i++)
		{
			out << store.computers[i] << std::endl;
		}
	}
	else
		out << "There is no computer" << std::endl;

	return out;
}
std::istream& operator >> (std::istream& in, ComputerStore& store)
{
	Computer computer;

	in >> computer;

	store.addComputer(computer);

	return in;
}

void main()
{
	//exercise 1

	/*Fraction f1(28, 2);
	Fraction f2(4, 18);

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	Fraction f3 = f1 + f2;

	std::cout << f3 << std::endl;

	Fraction f4;

	std::cin >> f4;

	std::cout << f4 << std::endl;

	Fraction* f5 = f4++;
	std::cout << *f5 << std::endl;
	delete f5;

	std::cout << f4 << std::endl;*/
	//exercise 2
	/*ComputerStore store2("My Store", "Baku");


	std::cout << store2 << std::endl;

	for (size_t i = 0, length = 2; i < length; i++)
	{
		std::cin >> store2;
	}
	
	std::cout << store2 << std::endl;*/

	/*Computer* asus = new Computer("VivaBook 15", "Asus", 2.7, 4, 2,
		"Intel UHD Graphics", "15.6 FHD 1920 * 1080", 128,true, 449.66);
	
	Computer* asus2 = new Computer("VivaBook 15", "Asus", 2.7, 8, 2,
		"Intel UHD Graphics", "15.6 FHD 1920 * 1080", 128,true, 479.0);

	Computer* asus3 = new Computer("VivaBook 15", "Asus", 2.7, 8, 2,
		"Intel UHD Graphics", "15.6 FHD 1920 * 1080", 512, true, 599.0);

	Computer* computers = new Computer[2]{ *asus, *asus2};

	ComputerStore store("My Store", "Baku", computers, 2);


	std::cout << store << std::endl;

	store.addComputer(*asus3);

	std::cout << store << std::endl;

	std::cout << "++++++++++++++++++++++++++++\n";


	Computer* asus4 = new Computer("VivaBook 15", "Asus", 2.7, 8, 2,
		"Intel UHD Graphics", "15.6 FHD 1920 * 1080", 1024, false, 450.0);

	store.addComputer(*asus4);

	std::cout << store << std::endl;

	std::cout << "++++++++++++++++++++++++++++\n";
	store.delComputer(2);
	store.delComputer(4);
	std::cout << store << std::endl;*/
	//std::cout << *asus << std::endl;

	//std::cout << *asus2 << std::endl;

	//std::cout << *asus3 << std::endl;

	//Computer* asus4 = new Computer();;

	//std::cin >> *asus4;

	//std::cout << *asus4;

	//Computer asus5;

	//std::cin >> asus5;

	//std::cout << asus5;


}