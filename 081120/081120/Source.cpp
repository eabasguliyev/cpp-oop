#include <iostream>
#include <assert.h>


/*class Test {
private:
	int data1;
public:
	int data2;
};
class Sample
{
	int length;
	int breadth;
public:
	Sample(int length, int breadth)
	{
		this->length = length;
		this->breadth = breadth;
	}

	friend void calculateArea(Sample s);
};

void calculateArea(Sample s)
{
	std::cout << "Area: " << s.length * s.breadth << std::endl;
}
*/

class Car {
	int* year;
	char* model;
	char* vendor;

public:
	Car() :year(nullptr), model(nullptr), vendor(nullptr) {}

	Car(const int year, const char* model, const char* vendor)
	{
		setYear(year);
		setModel(model);
		setVendor(vendor);
	}

	void setYear(const int year)
	{
		assert(year && "Year must be greather than zero");
		this->year = new int;
		*this->year = year;
	}

	const int* getYear() const
	{
		return year;
	}

	void setModel(const char* model)
	{
		assert(model && "NULL ERROR");
		size_t size = strlen(model) + 1;
		this->model = new char[size];
		strcpy_s(this->model, size, model);
	}
	const char* getModel() const
	{
		return model;
	}

	void setVendor(const char* vendor)
	{
		assert(vendor && "NULL ERROR");
		size_t size = strlen(vendor) + 1;
		this->vendor = new char[size];
		strcpy_s(this->vendor, size, vendor);
	}

	const char* getVendor() const
	{
		return vendor;
	}
	friend void showCar(const Car & car);

	explicit operator int() {
		std::cout << "explicit" << std::endl;
		return *getYear();
	}

	/*operator int() {
		std::cout << "implicit" << std::endl;
		return *getYear();
	}*/

	explicit operator bool()
	{
		if (*getYear() > 2000) return true;
		return false;
	}

	~Car()
	{
		if (year)
		{
			delete year;
			year = nullptr;
		}
		
		if (model)
		{
			delete[] model;
			model = nullptr;
		}
		
		if (vendor)
		{
			delete[] vendor;
			vendor = nullptr;
		}
	}
};

void showCar(const Car & car)
{
	const int* year = car.getYear();
	const char* model = car.getModel();
	const char* vendor = car.getVendor();

	std::cout << "Model: ";
	if (model)
		std::cout << model << std::endl;
	else
		std::cout << "None" << std::endl;

	std::cout << "Vendor: ";
	if (vendor)
		std::cout << vendor << std::endl;
	else
		std::cout << "None" << std::endl;

	std::cout << "Year: ";
	if (year)
		std::cout << *year << std::endl;
	else
		std::cout << "None" << std::endl;
}

class A {
	double data;
public:
	A() :data(0)
	{

	}

	A(double data)
	{
		this->data = data;
	}
	
	void showData()
	{
		std::cout << "Data: " << this->data << std::endl;
	}
	~A()
	{
		std::cout << "Data: " << this->data << " deleted" << std::endl;
	}

	void* operator new(size_t size)
	{
		std::cout << "New operator works!" << std::endl;
		return malloc(size);
	}

	void* operator new[](size_t size)
	{
		std::cout << "New array operator works!" << std::endl;

		/*int countOfObject = (size - 4) / 8;
		if (size > 3)
			return nullptr;*/

		return malloc(size);
	}
	
	void operator delete(void * data)
	{
		std::cout << "Delete operator works" << std::endl;
		free(data);
	}

	void operator delete[](void* data)
	{
		std::cout << "Delete[] operator works" << std::endl;
		free(data);
	}
};


class Student
{
	char* firstname;
	char* lastname;
	double average;
	int age;

public:
	Student() :firstname(nullptr), lastname(nullptr), average(0), age(0) {}

	Student(const char* firstname, const char* lastname, double average, int age)
	{
		setFirstName(firstname);
		setLastName(lastname);
		setAverage(average);
		setAge(age);
	}

	Student(const Student& student)
	{
		setFirstName(student.getFirstName());
		setLastName(student.getLastName());
		setAverage(student.getAverage());
		setAge(student.getAge());
	}

	Student& operator = (const Student& student)
	{
		setFirstName(student.getFirstName());
		setLastName(student.getLastName());
		setAverage(student.getAverage());
		setAge(student.getAge());

		return *this;
	}
	void setFirstName(const char* firstname)
	{
		assert(firstname && "NULL ERROR");
		int length = strlen(firstname) + 1;
		this->firstname = new char[length];
		strcpy_s(this->firstname, length, firstname);
	}

	const char* getFirstName() const
	{
		return firstname;
	}

	void setLastName(const char* lastname)
	{
		assert(lastname && "NULL ERROR");
		int length = strlen(lastname) + 1;
		this->lastname = new char[length];
		strcpy_s(this->lastname, length, lastname);
	}

	const char* getLastName() const
	{
		return lastname;
	}

	void setAverage(double average)
	{
		assert(average > 0 && "Average must be greater than zero");
		this->average = average;
	}

	double getAverage() const
	{
		return average;
	}

	void setAge(double age)
	{
		assert(age > 0 && "Average must be greater than zero");
		this->age = age;
	}

	double getAge() const
	{
		return age;
	}

	friend std::ostream& operator<<(std::ostream& out, const Student& student);
	friend void operator>>(std::istream& in, Student & student);
	~Student()
	{
		if (firstname)
		{
			delete[] firstname;
			firstname = nullptr;
		}
		if (lastname)
		{
			delete[] lastname;
			lastname = nullptr;
		}
	}
};

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	std::cout << "+++++++++++++++++++++++++++++++++++" << std::endl;
	out << "Student firstname: " << student.getFirstName() << std::endl;
	out << "Student lastname: " << student.getLastName() << std::endl;
	out << "Student age: " << student.getAge() << std::endl;
	out << "Student average: " << student.getAverage() << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++" << std::endl;
	return out;
}
void operator>>(std::istream& in, Student& student)
{
	std::cout << "Enter the firstname: ";
	char* buff = new char[100];

	in.getline(buff, 100);

	student.setFirstName(buff);
	
	std::cout << "Enter the lastname: ";
	in.getline(buff, 100);
	student.setLastName(buff);

	std::cout << "Enter age: ";
	int age;
	in >> age;

	student.setAge(age);

	std::cout << "Enter average: ";

	double average;

	in >> average;

	student.setAverage(average);
}

class Group
{
	char* name;
	size_t count;
	Student** students;
public:
	Group() :name(nullptr), count(0), students(nullptr) {}

	Group(const char* name, Student** students, size_t count)
	{
		setName(name);
		setCount(count);
		setStudents(students);
	}

	void setName(const char* name)
	{
		assert(name && "NULL ERROR");
		size_t length = strlen(name) + 1;

		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}
	const char *getName() const
	{
		return name;
	}

	int getCount() const
	{
		return count;
	}

	void setCount(int count)
	{
		assert(count > 0 && "Count must be greater than zero");
		this->count = count;
	}
	Student** getStudents() const
	{
		return students;
	}

	void setStudents(Student** students)
	{
		int count = getCount();
		this->students = new Student * [count];

		for (size_t i = 0; i < count; i++)
		{
			this->students[i] = students[i];
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Group & group);

	void addStudent(Student*& newStudent)
	{
		int c = getCount() + 1;
		Student ** newStudents = new Student * [c];

		if (newStudents)
		{
			for (size_t i = 0; i < c - 1; i++)
			{
				newStudents[i] = students[i];
			}

			newStudents[c - 1] = newStudent;

			students = newStudents;
			setCount(c);
		}
	}
	~Group()
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}

		if (students)
		{
			for (size_t i = 0, length = getCount(); i < length; i++)
			{
				delete[] students[i];
			}
			delete[] students;
			students = nullptr;
		}
	}
};

std::ostream& operator<<(std::ostream& out, const Group& group)
{
	for (size_t i = 0, length = group.getCount(); i < length; i++)
	{
		std::cout << *group.getStudents()[i]<< std::endl;
	}

	return out;
}
void main()
{

	Student *s1 = new Student("Elgun", "Abasquliyev", 68, 20);
	Student *s2 = new Student("Abil", "Yaqublu", 75, 17);

	Student** students = new Student * [2]{ s1, s2 };

	Group g1("FSDM_3914", students, 2);

	std::cout << g1;
	/*Student *s2 = new Student();
	std::cout << *s1 << std::endl;


	std::cout << "Create new student: " << std::endl;

	std::cin >> *s2;

	system("cls");

	std::cout << *s2 << std::endl;*/


	/*A* a = new A[5]{ 1,2,3,4,5 };
	delete[] a;
	a = nullptr;
	std::cout << "Address of a: " << a << std::endl;*/
	/*Car bmw(2000, "M6", "BMW");
	Car ferrari(2015, "La Ferrari", "Ferrari");
	Car maserati(2010, "Granturismo", "Maserati");

	showCar(bmw);
	std::cout << std::endl;
	showCar(ferrari);
	std::cout << std::endl;
	showCar(maserati);
	std::cout << std::endl;

	std::cout << (int)bmw << std::endl;

	std::cout << std::boolalpha << (bool)bmw << std::endl;*/
	//int a = bmw;

	//std::cout << a << std::endl;
	/*Sample s(10, 20);
	calculateArea(s);*/
}