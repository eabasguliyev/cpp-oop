#include <iostream>



class Point
{
	double m_x, m_y;

public:
	Point()
	{
		m_x = 0.0;
		m_y = 0.0;
	}

	Point(double x, double y)
	{
		SetX(x);
		SetY(y);
	}
	void SetX(double x)
	{
		m_x = x;
	}

	double GetX()
	{
		return m_x;
	}

	void SetY(double y)
	{
		m_y = y;
	}

	double GetY()
	{
		return m_y;
	}

	void ShowData()
	{
		std::cout << "Point -> x : " << GetX() << std::endl;
		std::cout << "Point -> y : " << GetY() << std::endl;
	}
};

class Counter
{
private:

	size_t m_min = 0;
	size_t m_max = 0;
	size_t m_current = 0;

	void SetCurrent(int current)
	{
		if (current >= 0)
			m_current = current;
	}
public:

	Counter()
	{
		m_min = 0;
		m_max = 0;
		m_current = 0;
	}
	Counter(int min, int max)
	{
		SetMin(min);
		SetMax(max);
		SetCurrent(min);
	}

	void SetMin(int min)
	{
		if (min >= 0)
			m_min = min;
		else
			std::cout << "Min value must be positive!\n";
	}
	size_t GetMin()
	{
		return m_min;
	}

	void SetMax(int max)
	{
		if (max >= 0)
			m_max = max;
		else
			std::cout << "Max value must be positive!\n";
	}
	size_t GetMax()
	{
		return m_max;
	}

	size_t GetCurrent()
	{
		return m_current;
	}

	void Increment()
	{
		m_current++;
		if (m_current == m_max)
m_current = 0;
	}
};

class Student
{
	char m_name[20]{};
	char m_surname[20]{};
	unsigned short m_age = 0;
	char m_group_no[15]{};
	char m_speciality[20]{};
	char m_city[20]{};

public:
	void ShowInfo();

	Student()
	{
		strcpy_s(m_name, "");
		strcpy_s(m_surname, "");
		strcpy_s(m_group_no, "");
		strcpy_s(m_speciality, "");
		strcpy_s(m_city, "");
		m_age = 0;
	}
	Student(const char* name, const char* surname, short age, const char* group_no, const char* speciality, const char* city)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetGroupNo(group_no);
		SetSpeciality(speciality);
		SetCity(city);
	}

	void SetName(const char* name)
	{
		if (strlen(name) >= 2)
		{
			strcpy_s(m_name, name);
		}
		else
		{
			std::cout << "Name must be contain minimum two characters\n";
		}
	}

	const char* GetName()
	{
		return m_name;
	}

	void SetSurname(const char* surname)
	{
		if (strlen(surname) >= 2)
		{
			strcpy_s(m_surname, surname);
		}
		else
		{
			std::cout << "Surname must be contain minimum two characters\n";
		}
	}

	const char* GetSurname()
	{
		return m_surname;
	}

	void SetAge(short age)
	{
		if (age >= 3)
		{
			m_age = age;
		}
		else
			std::cout << "Age must be greater than or equal to three\n";
	}

	unsigned short GetAge()
	{
		return m_age;
	}

	void SetGroupNo(const char* group_no)
	{
		if (strlen(group_no) >= 2)
			strcpy_s(m_group_no, group_no);
		else
			std::cout << "Length of group no characters must be greater than one\n";
	}

	const char* GetGroupNo()
	{
		return m_group_no;
	}

	void SetSpeciality(const char* speciality)
	{
		if (strlen(speciality) >= 2)
			strcpy_s(m_speciality, speciality);
		else
			std::cout << "Speciality name must be containt minimum two characters\n";
	}

	const char* GetSpeciality()
	{
		return m_speciality;
	}

	void SetCity(const char* city)
	{
		if (strlen(city) >= 2)
			strcpy_s(m_city, city);
		else
			std::cout << "City name must be containt minimum two characters\n";
	}

	const char* GetCity()
	{
		return m_city;
	}

	~Student()
	{
		std::cout << "Destructor process completed!\n";
	}
};

void Student::ShowInfo()
{
	std::cout << "Name: " << GetName() << std::endl;
	std::cout << "Surname: " << GetSurname() << std::endl;
	std::cout << "Age: " << GetAge() << std::endl;
	std::cout << "Group No: " << GetGroupNo() << std::endl;
	std::cout << "Speciality: " << GetSpeciality() << std::endl;
	std::cout << "City: " << GetCity() << std::endl;
}

int main()
{
	// exercise 1
	/*
	Point class yazilsin
	1.x, y fieldleri olsun ve her bir field uchun getter setterler yazilsin,
	constructor parametric, default
	ShowData method yazilsin
	*/
	/*Point p(4.5, 7.8);

	p.ShowData();

	p.SetX(6);

	p.ShowData();

	p.SetY(12);

	p.ShowData();*/

	// exercise 2
	/*
	Counter c(0,100);//min,max,currentData
	c.increment();
	cout<<getCurrent();//1
	c.increment();
	cout<<getCurrent();//2
	2.Rəqəmsal sayğac məhdud diapazonlu dəyişəndir. Onun tam qiyməti təyin edilmiş maksimum qiymət həddinə
	 (məsələn, k 0-100 diapazonunda qiymət alır) çatdığı zaman sıfırlanır.
	Bu cür sayğacın parametri kimi rəqəmsal saatı, kilometrölçən sayğacı nümunə göstərmək olar.
	 Bu cür sayğac üçün sinfi təyin edin. Maksimal və minimal qiymətlərin verilməsini,
	sayğacın qiymətinin 1 vahid artırılmasını, cari qiymətin qaytarılmasını təmin edin.
	*/
	/*Counter c(0,100);

	for (size_t i = 0; i < 101; i++)
	{
		std::cout << "Min : " << c.GetMin() << std::endl;
		std::cout << "Max : " << c.GetMax() << std::endl;
		std::cout << "Current : " << c.GetCurrent() << std::endl;
		c.Increment();
		std::cout << "Current : " << c.GetCurrent() << std::endl;
	}*/

	//exercise 3
	/*
	3. Tələbələr qrupunu əks etdirən sinif təyin edin.
	Student name,surname,age,group_no,speciality,city
	Tələbə həmçinin uyğun sinif vasitəsilə reallaşdırılır.
	*/
	/*Student s1("elgun", "abasquliyev", 20, "FSDA_3914_AZ", "Computer Engineer", "Baku");

	std::cout << "Name: " << s1.GetName() << std::endl;
	std::cout << "Surname: " << s1.GetSurname() << std::endl;

	s1.SetName("L");
	std::cout << "Name: " << s1.GetName() << std::endl;
	std::cout << "Surname: " << s1.GetSurname() << std::endl;


	s1.ShowInfo();
	
	std::cout << std::endl;

	s1.SetAge(2);
	s1.ShowInfo();*/
}