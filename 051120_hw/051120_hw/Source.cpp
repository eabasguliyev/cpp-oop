#include <iostream>
#include <assert.h>

class Time
{
	short hour;
	short minute;

private:
	
	void increment()
	{
		minute++;
		if (minute == 60)
		{
			minute = 0;

			hour++;

			if (hour == 24)
			{
				hour = 0;
			}
		}
	}

	void decrement()
	{
		minute--;
		if (minute < 0)
		{
			minute = 59;
			
			hour--;

			if (hour < 0)
			{
				hour = 23;
			}
		}
	}
public:

	//default constructor
	Time() :hour(0), minute(0) {}

	// parametric constructor
	Time(short hour, short minute)
	{
		setHour(hour);
		setMinute(minute);
	}

	// copy constructor

	Time(const Time& t)
	{
		setHour(t.getHour());
		setMinute(t.getMinute());
	}

	// copy assignment
	Time& operator=(const Time& t)
	{
		setHour(t.getHour());
		setMinute(t.getMinute());
		return *this;
	}

	Time& operator++()
	{
		increment();
		return *this;
	}
	Time operator++(int)
	{
		Time t = *this;
		increment();
		return t;
	}

	Time& operator--()
	{
		decrement();
		return *this;
	}

	Time operator--(int)
	{
		Time t = *this;
		decrement();
		return t;
	}

	bool operator>(const Time& t2)
	{
		if (this->getHour() == t2.getHour())
		{
			if (this->getMinute() > t2.getMinute())
				return true;
		}
		else
		{
			if (this->getHour() > t2.getHour())
				return true;
		}
		return false;
	}

	bool operator<(const Time& t2)
	{
		if (this->getHour() == t2.getHour())
		{
			if (this->getMinute() < t2.getMinute())
				return true;
		}
		else
		{
			if (this->getHour() < t2.getHour())
				return true;
		}
		return false;
	}

	bool operator>=(const Time& t2)
	{
		if (this->getHour() == t2.getHour())
		{
			if (this->getMinute() >= t2.getMinute())
				return true;
		}
		else
		{
			if (this->getHour() >= t2.getHour())
				return true;
		}
		return false;
	}

	bool operator<=(const Time& t2)
	{
		if (this->getHour() == t2.getHour())
		{
			if (this->getMinute() <= t2.getMinute())
				return true;
		}
		else
		{
			if (this->getHour() <= t2.getHour())
				return true;
		}
		return false;
	}

	bool operator==(const Time& t2)
	{
		if (this->getHour() == t2.getHour() && this->getMinute() == t2.getMinute())
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Time& t2)
	{
		if (this->getHour() != t2.getHour())
		{
			return true;
		}
		else
		{
			if (this->getMinute() != t2.getMinute())
			{
				return true;
			}
			return false;
		}
	}
	void setHour(short hour)
	{
		assert(hour >= 0 && hour < 24 && "Hour range is 0-24.");
		this->hour = hour;
	}

	void setMinute(short minute)
	{
		assert(minute >= 0 && minute < 60 && "Minute range is 0-60.");
		this->minute = minute;
	}

	short getHour() const
	{
		return hour;
	}

	short getMinute() const
	{
		return minute;
	}


	void showTime()
	{
		std::cout << getHour() << " : " << getMinute() << std::endl;
	}
};

class Student
{
	size_t student_id;
	char* fullname;
	unsigned short age;
	int score;
	int bonus;

public:
	static size_t current_id;

	Student() :student_id(0), fullname(nullptr), age(0), score(0), bonus(0) {}

	Student(const char* fullname, short age, int score, int bonus):Student(fullname, age, score)
	{
		setBonus(bonus);
	}

	Student(const char* fullname, short age, int score) :Student(fullname, age)
	{
		setScore(score);
	}

	Student(const char* fullname, short age) :Student(fullname)
	{
		setAge(age);
	}

	explicit Student(const char* fullname)
	{
		setFullname(fullname);
		setID(++current_id);
	}

	Student(const Student &s2)
	{
		setID(s2.getStudentID());
		setFullname(s2.getFullname());
		setAge(s2.getAge());
		setScore(s2.getScore());
		setBonus(s2.getBonus());
	}

	Student& operator=(const Student& s2)
	{
		setID(s2.getStudentID());
		setFullname(s2.getFullname());
		setAge(s2.getAge());
		setScore(s2.getScore());
		setBonus(s2.getBonus());

		return *this;
	}

	void setID(size_t id)
	{
		this->student_id = id;
	}

	size_t getCurrentID() const
	{
		return current_id;
	}

	size_t getStudentID() const
	{
		return student_id;
	}

	void setFullname(const char* fullname)
	{
		assert(fullname && "NULL ERROR!");
		size_t length = strlen(fullname) + 1;
		this->fullname = new char[length];

		strcpy_s(this->fullname, length, fullname);
	}

	const char* getFullname() const
	{
		return fullname;
	}

	void setAge(short age)
	{
		assert(age > 0 && "Age must be greater than zero");
		this->age = age;
	}

	short getAge() const
	{
		return age;
	}

	void setScore(int score)
	{
		assert(score >= 0 && "Score must be positive number!");
		this->score = score;
	}

	int getScore() const
	{
		return score;
	}

	void setBonus(int bonus)
	{
		assert(bonus >= 0 && "Bonus must be positive number!");
		this->bonus = bonus;
	}

	int getBonus() const
	{
		return bonus;
	}

	bool operator>(const Student s2)
	{
		if (this->getScore() > s2.getScore())
			return true;
		return false;
	}

	bool operator>=(const Student& s2)
	{
		if (this->getScore() >= s2.getScore())
			return true;
		return false;
	}

	bool operator<(const Student& s2)
	{
		if (this->getScore() < s2.getScore())
			return true;
		return false;
	}

	bool operator<=(const Student& s2)
	{
		if (this->getScore() <= s2.getScore())
			return true;
		return false;
	}

	bool operator==(const Student& s2)
	{
		if (this->getScore() == s2.getScore())
			return true;
		return false;
	}

	bool operator!= (const Student & s2)
	{
		if (this->getScore() != s2.getScore())
			return true;
		return false;
	}

	int operator++()
	{
		this->bonus++;
		return this->bonus;
	}

	int operator++(int)
	{
		int temp = this->bonus;
		this->bonus++;

		return temp;
	}

	int operator--()
	{
		if(bonus > 0)
			this->bonus--;
		return this->bonus;
	}

	int operator--(int)
	{
		int temp = this->bonus;
		if(bonus > 0)
			this->bonus--;
		return temp;
	}

	void print() const
	{
		const char* fullname = getFullname();
		std::cout << "Student id: " << getStudentID() << std::endl;
		std::cout << "Full name: ";

		if (fullname)
			std::cout << fullname << std::endl;
		else
			std::cout << "none" << std::endl;

		std::cout << "Age: " << getAge() << std::endl;
		std::cout << "Score: " << getScore() << std::endl;
		std::cout << "Bonus: " << getBonus() << std::endl;

	}

	~Student()
	{
		delete[] fullname;
	}
};

size_t Student::current_id = 0;

void main()
{
	//exercise 1
	//Time t1(0, 5);
	//Time t2(0, 5);

	//std::cout << std::boolalpha << (t1 > t2) << std::endl;
	//std::cout << std::boolalpha << (t1 >= t2) << std::endl;
	//std::cout << std::boolalpha << (t1 < t2) << std::endl;
	//std::cout << std::boolalpha << (t1 <= t2) << std::endl;
	//std::cout << std::boolalpha << (t1 == t2) << std::endl;
	//std::cout << std::boolalpha << (t1 != t2) << std::endl;
	//t1.showTime();
	//std::cout << (t1--).getMinute() << std::endl;
	//std::cout << (--t1).getMinute() << std::endl;
	//t1.showTime();

	//t1.showTime();
	//std::cout << (t1++).getMinute() << std::endl;
	//std::cout << (++t1).getMinute() << std::endl;
	//t1.showTime();
	

	/*for (size_t i = 0; i < 1441; i++)
	{
		--t1;
		t1.showTime();
	}*/


	/*for (size_t i = 0; i < 1441; i++)
	{
		++t1;
		t1.showTime();
	}*/


	//exercise 2

	/*Student s1("Kate Moore", 20, 240, 7);

	Student s2("Gracie Singh", 23, 400, 20);

	Student s3("Elgun Abasquliyev");

	Student s4;

	s1.print();
	std::cout << std::endl;
	s2.print();
	std::cout << std::endl;
	std::cout << std::boolalpha << (s1 > s2) << std::endl;
	std::cout << std::boolalpha << (s1 >= s2) << std::endl;
	std::cout << std::boolalpha << (s1 < s2) << std::endl;
	std::cout << std::boolalpha << (s1 <= s2) << std::endl;
	std::cout << std::boolalpha << (s1 == s2) << std::endl;
	std::cout << std::boolalpha << (s1 != s2) << std::endl;

	std::cout << s1++ << std::endl;
	std::cout << ++s1 << std::endl;

	std::cout << s2-- << std::endl;
	std::cout << --s2 << std::endl;

	s1.print();
	std::cout << std::endl;
	s2.print();
	std::cout << std::endl;
	s3.print();
	std::cout << std::endl;

	s3++;
	s3.print();

	std::cout << std::endl;
	s4.print();*/
}
