#include <iostream>
#include <assert.h>

class Computer
{
	char* model;
	char* vendor;
	short core_count;
	double cpu_power;
public:

	// copy constructor

	Computer(const Computer& old)
	{
		std::cout << "Copy constructor Works!" << std::endl;
		this->setModel(old.model);
		this->setVendor(old.vendor);
		this->setCoreCount(old.core_count);
		this->setCpuPower(old.cpu_power);
	}

	Computer& operator = (const Computer& old)
	{
		std::cout << "Copy assigment Works!" << std::endl;
		this->setModel(old.model);
		this->setVendor(old.vendor);
		this->setCoreCount(old.core_count);
		this->setCpuPower(old.cpu_power);

		return *this;
	}
	Computer() :model(nullptr), vendor(nullptr), core_count(0), cpu_power(0){}

	Computer(const char* model, const char* vendor, short core_count, double cpu_power)
		:Computer(model, vendor, core_count)
	{
		setCpuPower(cpu_power);
	}
	Computer(const char* model, const char* vendor, short core_count)
		:Computer(model, vendor)
	{
		setCoreCount(core_count);
	}

	Computer(const char* model, const char* vendor)
		:Computer(model)
	{
		setVendor(vendor);
	}

	Computer(const char* model)
	{
		setModel(model);
	}
	void setModel(const char* model)
	{
		assert(model && "NULL ERROR");
		this->model = _strdup(model);
	}

	const char* getModel() const
	{
		return model;
	}

	void setVendor(const char* vendor)
	{
		assert(vendor && "NULL ERROR");
		this->vendor = _strdup(vendor);
	}

	const char* getVendor() const
	{
		return vendor;
	}

	void setCoreCount(short core_count)
	{
		assert(core_count > 0 && "NULL ERROR");
		this->core_count = core_count;
	}
	
	short getCoreCount() const
	{
		return core_count;
	}

	void setCpuPower(double cpu_power)
	{
		assert(cpu_power > 0 && "NULL ERROR");
		this->cpu_power = cpu_power;
	}

	double getCpuPower() const
	{
		return cpu_power;
	}

	void showComputer() const
	{
		const char* model = getModel();
		const char* vendor = getVendor();

		std::cout << "Computer model: ";

		if (model)
			std::cout << model << std::endl;
		else
			std::cout << "none" << std::endl;

		std::cout << "Computer vendor: ";
		if (vendor)
			std::cout << vendor << std::endl;
		else
			std::cout << "none" << std::endl;

		std::cout << "CPU core count: " << getCoreCount() << std::endl;
		std::cout << "CPU power: " << getCpuPower() << " ghz" << std::endl;
	}

	~Computer()
	{
		delete[] model;
		delete[] vendor;
	}
};


class Personal
{
	int id;
	char* fullname;
	char* picture;
	short age;
	bool hasPractise;
	int salaryRequirement;

public:

	static int ID;
	static int MAXCOUNT;
	Personal() :id(0), fullname(nullptr), picture(nullptr), age(0), hasPractise(0), salaryRequirement(0) {}

	Personal(const char* fullname, const char* picture, short age, bool hasPractise, int salaryRequirement)
		:Personal(fullname, picture, age, hasPractise)
	{
		setSalaryRequirement(salaryRequirement);
	}
	Personal(const char* fullname, const char* picture, short age, bool hasPractise)
		:Personal(fullname, picture, age)
	{
		setPractise(hasPractise);
	}

	Personal(const char* fullname, const char* picture, short age)
		:Personal(fullname, picture)
	{
		setAge(age);
	}

	Personal(const char* fullname, const char * picture):Personal(fullname)
	{
		setPicture(picture);
	}

	Personal(const char* fullname)
	{

		assert(ID < MAXCOUNT && "MAX COUNT IS 10");
		setID(++ID);
		setFullName(fullname);

	}


	Personal(const Personal& personal)
	{
		this->setID(personal.id);
		this->setFullName(personal.fullname);
		this->setPicture(personal.picture);
		this->setPractise(personal.hasPractise);
		this->setSalaryRequirement(personal.salaryRequirement);
	}

	Personal& operator = (const Personal& personal)
	{
		this->setID(personal.id);
		this->setFullName(personal.fullname);
		this->setPicture(personal.picture);
		this->setPractise(personal.hasPractise);
		this->setSalaryRequirement(personal.salaryRequirement);

		return *this;
	}
	static short getCurrentID()
	{
		return ID;
	}

	void setID(int id)
	{
		this->id = id;
	}

	int getID() const
	{
		return id;
	}
	void setFullName(const char* fullname)
	{
		assert(fullname && "NULL ERROR");
		this->fullname = _strdup(fullname);
	}

	const char* getFullName() const
	{
		return fullname;
	}

	void setPicture(const char* picture)
	{
		assert(picture && "NULL ERROR");
		this->picture = _strdup(picture);
	}

	const char* getPicture() const
	{
		return picture;
	}

	void setAge(short age)
	{
		assert(age > 0 && "Age must be greater than 0");
		this->age = age;
	}

	short getAge() const
	{
		return age;
	}

	void setPractise(bool hasPractise)
	{
		this->hasPractise = hasPractise;
	}

	bool getPractise() const 
	{
		return this->hasPractise;
	}

	void setSalaryRequirement(int salaryRequirement)
	{
		assert(salaryRequirement > 0 && "Salary must be greater than 0");
		this->salaryRequirement = salaryRequirement;
	}

	int getSalaryRequirement() const
	{
		return salaryRequirement;
	}
	void showPersonal() const
	{
		const char* fullname = getFullName();
		const char* picture = getPicture();

		std::cout << "ID : " << getID() << std::endl;
		std::cout << "Fullname: ";
		if (fullname)
			std::cout << fullname << std::endl;
		else
			std::cout << "none" << std::endl;

		if (picture)
			std::cout << picture << std::endl;
		else
			std::cout << "none" << std::endl;

		std::cout << "Age: " << getAge() << std::endl;

		std::cout << "Status: ";
		if (getPractise() && getSalaryRequirement() < 1000)
			std::cout << "hired" << std::endl;
		else
			std::cout << "none" << std::endl;

	}
	~Personal()
	{
		delete[] fullname;
		delete[] picture;
	}
};

int Personal::ID = 0;
int Personal::MAXCOUNT = 5;


class MyString
{
	char* text;
	size_t length;

private:
	void setLength(size_t length)
	{
		this->length = length;
	}
public:
	MyString() :text(nullptr), length(0) {}

	MyString(const char* text)
	{
		setText(text);
	}

	MyString(const MyString& old_string)
	{
		setText(old_string.getText());
	}

	MyString& operator = (const MyString& old_string)
	{
		setText(old_string.getText());
		return *this;
	}
	void setText(const char* text)
	{
		assert(text && "NULL ERROR!");
		setLength(strlen(text));
		this->text = _strdup(text);
	}

	const char* getText() const
	{
		return this->text;
	}

	size_t getLength()const
	{
		return length;
	}

	void sort(bool reverse = false)
	{
		if (reverse)
		{
			for (size_t i = 0, length = getLength() - 1; i < length; i++)
			{
				bool swapped = false;
				for (size_t k = 0; k < length; k++)
				{
					if (text[k] > text[k + 1])
					{
						swapped = true;

						char temp = text[k];
						text[k] = text[k + 1];
						text[k + 1] = temp;
					}
				}
			}
		}
		else
		{
			for (size_t i = 0, length = getLength() - 1; i < length; i++)
			{
				bool swapped = false;
				for (size_t k = 0; k < length; k++)
				{
					if (text[k] < text[k + 1])
					{
						swapped = true;

						char temp = text[k];
						text[k] = text[k + 1];
						text[k + 1] = temp;
					}
				}
			}
		}
	}

	void append(const char* text)
	{
		size_t new_length = this->getLength() + strlen(text);

		char* temp = new char[new_length + 1]{};

	
			strcpy_s(temp, this->getLength() + 1, this->getText());
			strcpy_s(temp + this->getLength(), strlen(text) + 1, text);

			//delete[] this->text;

			this->text = temp;

			temp = nullptr;

			this->setLength(new_length);

	}
	~MyString()
	{
		//std::cout << (int)text << std::endl;
		delete[] text;
	}
};
int main()
{

	MyString s("elgun");

	std::cout << "Text: " << s.getText() << std::endl;
	std::cout << "Length: " << s.getLength() << std::endl;
	
	s.append("resul");

	//std::cout << "Text: " << s.getText() << std::endl;
	//std::cout << "Length: " << s.getLength() << std::endl;

	//s.sort();

	//std::cout << "Text: " << s.getText() << std::endl;
	//std::cout << "Length: " << s.getLength() << std::endl;

	//s.sort(true);

	//std::cout << "Text: " << s.getText() << std::endl;
	//std::cout << "Length: " << s.getLength() << std::endl;
	/*Personal p1("Elgun Abasquliyev", "C://users//hr//elgun.png", 20, false, 800);
	Personal p2("Elgun Abasquliyev", "C://users//hr//elgun.png", 20, true, 1000);
	Personal p3("Elgun Abasquliyev", "C://users//hr//elgun.png", 20, false, 800);
	Personal p4("Elgun Abasquliyev", "C://users//hr//elgun.png", 20, true, 750);
	Personal p5("Elgun Abasquliyev", "C://users//hr//elgun.png", 20, true, 900);
	Personal p6("Elgun Abasquliyev", "C://users//hr//elgun.png", 20, true, 900);


	p1.showPersonal();
	std::cout << std::endl;

	p2.showPersonal();
	std::cout << std::endl;

	p3.showPersonal();
	std::cout << std::endl;

	p4.showPersonal();
	std::cout << std::endl;

	p5.showPersonal();
	std::cout << std::endl;*/

	/*Computer asus("Rog Strix", "Asus", 8, 4.1);

	asus.showComputer();
	std::cout << std::endl;

	Computer asus2(asus);

	asus2.showComputer();
	std::cout << std::endl;
	Computer hp("Pavilion", "HP", 6, 3.5);

	hp.showComputer();
	std::cout << std::endl;

	Computer az("AZ", "KUR", 2, 2.1);

	az.showComputer();
	std::cout << std::endl;*/
}