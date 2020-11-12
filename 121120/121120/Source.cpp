#include <iostream>
#include <assert.h>


class Temperature
{
	int celcius;

public:
	Temperature() :celcius(0) {}

	Temperature(int celcius)
	{
		this->celcius = celcius;
	}

	friend int temp(Temperature);
};

int temp(Temperature t)
{
	t.celcius = 42;
	return t.celcius;
}

class A
{
	int a;
public:
	A()
	{
		a = 10;
	}

	friend class B;
};

class B
{
	int b;

public:
	B()
	{
		b = 0;
	}

	void showA(A & data)
	{
		std::cout << "A\'s data " << data.a << std::endl;
	}
};


class Rectangle;

class Square
{
	int side;
public:
	Square(int side)
	{
		this->side = side;
	}

	void showSide()
	{
		std::cout << "Side: " << side << std::endl;
	}
	friend class Rectangle;
};

class Rectangle
{
	int length;
	int width;

public:
	Rectangle() :length(0), width(0) {}
	Rectangle(int length, int width)
	{
		this->length = length;
		this->width = width;
	}

	int getArea()
	{
		return width * length;
	}

	void convert(Square s);
};

void Rectangle::convert(Square s)
{
	width = s.side;
	length = s.side;
}

class Move
{
	int* data;

public:
	Move(int d)
	{
		data = new int(d);
	}

	Move(const Move& move)
	{
		std::cout << "Copy constructor works!\n";
		this->data = new int(*move.data);
	}

	Move(Move&& other)
	{
		data = new int;
		*data = *other.data;
		delete other.data;
		other.data = nullptr;
	}
	void showData()
	{
		if (data)
			std::cout << "Data: " << *this->data << std::endl;
		else
			std::cout << "No data\n" << std::endl;
	}

	~Move()
	{
		delete data;
	}
};

//class Course; name, address, discount, speciality, pricePerMonth
// getPriceWithDiscount(); friend;

class Student
{
	size_t student_id;
	char* name;
	char* surname;

public:
	static size_t current_id;

	Student() : student_id(0), name(nullptr), surname(nullptr) {}

	Student(const char* name, const char* surname)
	{
		setName(name);
		setSurname(surname);
		setID(++current_id);
	}

	Student(const Student& student)
	{
		setID(student.getID());
		setName(student.getName());
		setSurname(student.getSurname());
	}
	Student& operator=(const Student& student)
	{
		setID(student.getID());
		setName(student.getName());
		setSurname(student.getSurname());

		return *this;
	}

	Student(Student&& student)
	{
		setID(student.getID());
		setName(student.getName());
		setSurname(student.getSurname());

		delete[] student.name;
		student.name = nullptr;
		delete[] student.surname;
		student.surname = nullptr;
	}
	void setID(size_t id)
	{
		this->student_id = id;
	}

	size_t getID() const
	{
		return this->student_id;
	}

	void setName(const char* name)
	{
		assert(name && "Null error!");
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}

	const char* getName() const
	{
		return name;
	}

	void setSurname(const char* surname)
	{
		assert(surname && "Null error!");
		size_t length = strlen(surname) + 1;
		this->surname = new char[length];
		strcpy_s(this->surname, length, surname);
	}

	const char* getSurname() const
	{
		return surname;
	}

	friend std::ostream& operator <<(std::ostream& out, const Student& student);
	friend std::istream& operator >>(std::istream& in, Student& student);
	~Student()
	{
		delete[] name;
		delete[] surname;
	}
};

size_t Student::current_id = 0;

std::ostream& operator <<(std::ostream& out, const Student& student)
{
	out << "---------------------------------------" << std::endl;
	out << "Student id: " << student.getID() << std::endl;
	out << "Student name: " << student.getName() << std::endl;
	out << "Student surname: " << student.getSurname() << std::endl;

	return out;
}

std::istream& operator >>(std::istream& in, Student& student)
{
	std::cout << "Enter firstname: ";
	char* buff = new char[50];

	in.getline(buff, 50);

	student.setID(++Student::current_id);
	student.setName(buff);

	std::cout << "Enter surname: ";

	in.getline(buff, 50);

	student.setSurname(buff);

	return in;

}

class Course
{
	char* name;
	char* address;
	double discount;
	char* speciality;
	double pricePerMonth;
	size_t student_count;
	Student* students;

public:
	Course() :name(nullptr), address(nullptr), discount(0), speciality(nullptr),
		pricePerMonth(0), students(nullptr), student_count(0){}

	Course(const char* name, const char* address, double discount, const char* speciality, double pricePerMonth, Student * students, size_t student_count) :
		Course(name, address, discount, speciality, pricePerMonth)
	{
		setStudentCount(student_count);
		setStudents(students);
	}

	
	Course(const char* name, const char* address, double discount, const char* speciality, double pricePerMonth) :
		Course(name, address, discount, speciality)
	{
		setPricePerMonth(pricePerMonth);
	}

	Course(const char* name, const char* address, double discount, const char* speciality) :
		Course(name, address, discount)
	{
		setSpeciality(speciality);
	}

	Course(const char* name, const char* address, double discount) :
		Course(name, address)
	{
		setDiscount(discount);
	}

	Course(const char* name, const char* address) :
		Course(name)
	{
		setAddress(address);
	}

	explicit Course(const char* name)
	{
		setName(name);
	}

	Course(const Course& course)
	{
		setName(course.getName());
		setAddress(course.getAddress());
		setDiscount(course.getDiscount());
		setSpeciality(course.getSpeciality());
		setPricePerMonth(course.getPricePerMonth());
	}

	Course& operator=(const Course& course)
	{
		setName(course.getName());
		setAddress(course.getAddress());
		setDiscount(course.getDiscount());
		setSpeciality(course.getSpeciality());
		setPricePerMonth(course.getPricePerMonth());
		return *this;
	}

	Course(Course&& course)
	{
		setName(course.getName());
		setAddress(course.getAddress());
		setDiscount(course.getDiscount());
		setSpeciality(course.getSpeciality());
		setPricePerMonth(course.getPricePerMonth());
		setStudentCount(course.getStudentCount());
		setStudents(course.getStudents());
		delete[] course.name;
		course.name = nullptr;
		delete[] course.address;
		course.address = nullptr;
		course.discount = 0;
		delete[] course.speciality;
		course.speciality = nullptr;
		course.pricePerMonth = 0;
		course.student_count = 0;
		delete[] course.students;
		course.students = nullptr;
	}

	void setStudentCount(size_t student_count)
	{
		assert(student_count > 0 && "Student count must be greater than zero");
		this->student_count = student_count;
	}

	size_t getStudentCount() const
	{
		return student_count;
	}

	void setStudents(const Student* students)
	{
		assert(students && "Null error");
		this->students = new Student[this->student_count];

		if (this->students)
		{
			for (size_t i = 0; i < this->student_count; i++)
			{
				this->students[i] = students[i];
			}
		}
	}

	void moveStudents(Student&& students)
	{

	}
	Student* getStudents() const
	{
		return students;
	}

	void setName(const char* name)
	{
		assert(name && "Null Error!");
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}

	const char* getName() const
	{
		return name;
	}

	void setAddress(const char* address)
	{
		assert(address && "Null Error!");
		size_t length = strlen(address) + 1;
		this->address = new char[length];
		strcpy_s(this->address, length, address);
	}

	const char* getAddress() const
	{
		return address;
	}

	void setDiscount(double discount)
	{
		assert(discount > 0 && "Discount must be greater than zero");
		this->discount = discount;
	}

	double getDiscount() const
	{
		return discount;
	}

	void setSpeciality(const char* speciality)
	{
		assert(speciality && "Null Error!");
		size_t length = strlen(speciality) + 1;
		this->speciality = new char[length];
		strcpy_s(this->speciality, length, speciality);
	}

	const char* getSpeciality() const
	{
		return speciality;
	}

	void setPricePerMonth(double pricePerMonth)
	{
		assert(pricePerMonth > 0 && "Price must be greater than zero");
		this->pricePerMonth = pricePerMonth;
	}

	double getPricePerMonth() const
	{
		return pricePerMonth;
	}

	friend short getPriceWithDiscount(const Course & course);

	friend std::ostream operator<<(std::ostream& out, const Course& course);
	~Course()
	{
		delete[] name;
		delete[] address;
		delete[] speciality;
	}
};


std::ostream operator<<(std::ostream& out, const Course& course)
{
	/*
	char* name;
	char* address;
	double discount;
	char* speciality;
	double pricePerMonth;
	size_t student_count;
	Student* students;*/

	out << "-----------------------------" << std::endl;
	out << "Name: ";
	
	if (course.getName())
		out << course.getName() << std::endl;
	else
		out << "none" << std::endl;

	out << "Address: ";
	if (course.getAddress())
		out << course.getAddress() << std::endl;
	else
		out << "none" << std::endl;

	
}
short getPriceWithDiscount(const Course& course)
{
	return course.pricePerMonth - ((course.pricePerMonth * course.discount) / 100.0);
}

void main()
{
	
	Move m(20);

	Move m2(std::move(m));

	m.showData();
	m2.showData();
	/*Square s(10);
	Rectangle r;

	r.convert(s);

	std::cout << "Area of rectangle: " << r.getArea() << std::endl;*/
	/*A a;
	B b;

	b.showA(a);*/
}