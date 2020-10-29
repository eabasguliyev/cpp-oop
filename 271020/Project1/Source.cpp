#include <iostream>

//struct Test
//{
//	int data1;
//	int data2;
//};
//
//
//class MyTest
//{
//public:
//	int data1;
//	int data2;
//};

class MyClass
{
private:
	int data1;
	int data2;
public:
	void Initial(int d1, int d2)
	{
		data1 = d1;
		data2 = d2;
	}

	void ShowData()
	{
		std::cout << "Data1: " << data1 << std::endl;
		std::cout << "Data2: " << data2 << std::endl;
	}
};

class Product
{
private:
	char* name;
	double price;
	double discount;
public:
	Product()
	{
		name = _strdup("");
		price = 0;
		discount = 0;
		//std::cout << "I am default constructor" << std::endl;
	}

	Product(const char* n, double p, double d)
	{
		name = _strdup(n);
		price = p;
		discount = d;
	}
	void SetData(const char* n, double p, double d)
	{
		name = _strdup(n);
		price = p;
		discount = d;
	}
	void ShowData()
	{
		std::cout << "Product: " << name << std::endl;
		std::cout << "Price: " << price << " USD" << std::endl;
		std::cout << "Discount: " << discount << " %" << std::endl;
		std::cout << "Price with discount: " << GetPriceWithDiscount() << std::endl;
	}

	double GetPriceWithDiscount()
	{
		return price - (price * discount) / 100;
	}
};
// access modifier - public, private, protected;

class Student
{
private:
	char* name;
	char* surname;
	unsigned short birth_year;
	char* group_no;
	char* special;

private:
	short Get_Age(unsigned short birth_year)
	{
		return 2020 - birth_year;
	}
public:
	Student()
	{
		name = _strdup("");
		surname = _strdup("");
		birth_year = 0;
		group_no = _strdup("");
		special = _strdup("");
	}
	Student(const char * student_name, const char * student_surname, unsigned short student_birth_year, const  char* student_group_no, const char * student_special)
	{
		name = _strdup(student_name);
		surname = _strdup(student_surname);
		birth_year = student_birth_year;
		group_no = _strdup(student_group_no);
		special = _strdup(student_special);
	}

	void ShowData()
	{
		std::cout << "Student name: " << name << std::endl;
		std::cout << "Student surname: " << surname << std::endl;
		std::cout << "Student age: " << Get_Age(birth_year) << std::endl;
		std::cout << "Student group_no: " << group_no << std::endl;
		std::cout << "Student special: " << special << std::endl;
	}

};

class Teacher
{
private:
	char* name;
	char* surname;
	unsigned short birth_year;
	char* special;
	unsigned short groups_size;
	char** groups;

private:
	short Get_Age(unsigned short birth_year)
	{
		return 2020 - birth_year;
	}

public:
	Teacher()
	{
		name = _strdup("");
		surname = _strdup("");
		birth_year = 0;
		special = _strdup("");
		groups[0] = _strdup("");
	}
	Teacher(const char* teacher_name, const char* teacher_surname, unsigned short teacher_birth_year, const  char** teacher_groups, const unsigned short t_groups_size, const char* teacher_special)
	{
		name = _strdup(teacher_name);
		surname = _strdup(teacher_surname);
		birth_year = teacher_birth_year;
		special = _strdup(teacher_special);

		groups_size = t_groups_size;

		groups = new char* [groups_size];

		for (size_t i = 0; i < groups_size; i++)
		{
			groups[i] = _strdup(teacher_groups[i]);
		}
	}

	void ShowData()
	{
		std::cout << "Teacher name: " << std::endl;
	}
};


class Box
{
private:
	double length;
	double hight;
	double breadth;

public:

	Box()
	{
		length = 0;
		hight = 0;
		breadth = 0;
	}

	Box(double l, double h, double b)
	{
		length = l;
		hight = h;
		breadth = b;
	}
	double GetVolume();
};


double Box::GetVolume()
{
	return length * hight * breadth;
}

// get area;

class Circle
{
private:
	double radius;
public:
	Circle()
	{
		radius = 0;
	}
	Circle(double r)
	{
		radius = r;
	}
	void ShowArea();
	void ShowLength();
	double GetArea();
	double GetLength();
};

const double PI = 3.14;

double Circle::GetArea()
{
	return PI * (radius * radius);
}
void Circle::ShowLength()
{
	std::cout << "Length: " << GetLength() << std::endl;
}
void Circle::ShowArea()
{
	std::cout << "Area: " << GetArea() << std::endl;
}

double Circle::GetLength()
{
	return PI * 2 * radius;
}


// accessor 
class Rect
{
	char color[20];
	double length;
	double width;

public:
	Rect()
	{
		strcpy_s(color, "");
		length = 0;
		width = 0;
	}

	Rect(const char * c, double l, double w)
	{
		SetColor(c);
		SetLength(l);
		SetWidth(w);
	}

	void ShowData()
	{
		std::cout << "Color: " << GetColor() << std::endl;
		std::cout << "Length: " << GetLength() << std::endl;
		std::cout << "Width: " << GetWidth() << std::endl;
	}

	char* GetColor()
	{
		return color;
	}

	void SetColor(const char * c)
	{
		if (strlen(c) >= 3)
			strcpy_s(color, c);
		else
		{
			std::cout << "Color data is incorrect" << std::endl;
			
			if (!(strlen(color) >= 3))
			{
				strcpy_s(color, "");
			}
		}
	}

	double GetLength()
	{
		return length;
	}

	void SetLength(double l)
	{
		if (l > 0)
			length = l;
		else
		{
			std::cout << "Length must be positive" << std::endl;
			length = 0;
		}
	}

	double GetWidth()
	{
		return width;
	}

	void SetWidth(double w)
	{
		if (w > 0)
			width = w;
		else
		{
			std::cout << "Length must be positive" << std::endl;
			width = 0;
		}
	}

	~Rect()
	{
		std::cout << "destructor" << std::endl;
	}
};
int main()
{

	Rect r("Red", 5, 6);

	r.ShowData();
	r.SetColor("Green");
	r.ShowData();

	r.ShowData();
	//Circle c(5);

	////c.ShowArea();

	//std::cout << c.GetArea() << std::endl;

	//std::cout << c.GetLength() << std::endl;
	/*Box b(10, 20, 30);

	std::cout << "Volume: " << b.GetVolume() << " cube" << std::endl;*/
	/*
	Product phone("Iphone", 560, 10);

	phone.ShowData();*/

	/*Student student("Elgun", "Abasquliyev", 2000, "FA_19", "Programmer");

	student.ShowData();*/
	/*int size = 3;
	char** groups = new char* [5];*/


}