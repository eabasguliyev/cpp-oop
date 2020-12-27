#include <iostream>
#include <vector> 
#include <list>
#include <time.h>
#include <string>


namespace Time
{	
	short getMonth()
	{
		time_t now(time(0));
		tm new_time;
		localtime_s(&new_time, &now);
		return new_time.tm_mon + 1;
	}

	short getYear()
	{
		time_t now(time(0));
		tm new_time;
		localtime_s(&new_time, &now);
		return new_time.tm_year + 1900;
	}
}

class Base
{
	size_t id;

public:
	Base() : id(0) {}
	Base(const size_t& id)
	{
		setID(id);
	}

	void setID(const size_t& id) { this->id = id; }
	size_t getID() const { return this->id; }
};

class Person : public Base
{
	std::string name;
	std::string surname;
	short age;

public:
	Person() : name(""), surname(""), age(0) {}
	Person(const size_t& id, const std::string& name, const std::string& surname, const short& age) : Base(id)
	{
		setName(name);
		setSurname(surname);
		setAge(age);
	}

	void setName(const std::string& name) { this->name = name; }
	std::string getName() const { return this->name; }
	void setSurname(const std::string& surname) { this->surname = surname; }
	std::string getSurname() const { return this->surname; }
	void setAge(const short& age) { this->age = age; }
	short getAge() const { return this->age; }

	virtual ~Person() {}
};

class BankCard : public Base
{
	std::string card_number;
	short pin;
	short exp_month;
	short exp_year;
	size_t balance;
public:
	BankCard() : card_number(""), pin(0), exp_month(0), exp_year(0) {}
	BankCard(const size_t& id, const std::string& card_number, const short& pin, const short& exp_month, const short& exp_year) : Base(id)
	{
		setCardNumber(card_number);
		setPin(pin);
		setExpMonth(exp_month);
		setExpYear(exp_year);
		setBalance(500);
	}

	void setCardNumber(const std::string& card_number) { this->card_number = card_number; }
	std::string getCardNumber() const { return this->card_number; }
	void setPin(const short& pin) { this->pin = pin; }
	short getPin() const { return this->pin; }
	void setExpMonth(const short& exp_month) { this->exp_month = exp_month; }
	short getExpMonth() const { return this->exp_month; }
	void setExpYear(const short& exp_year) { this->exp_year = exp_year; }
	short getExpYear() const { return this->exp_year; }
	void setBalance(const size_t& balance) { this->balance = balance; }
	void increaseBalance(const size_t& amount) { this->balance += amount; }
	size_t getBalance() const { return this->balance; }
	void show() const
	{
		std::cout << "############# Card Detail #############" << std::endl;
		std::cout << "Card id: " << getID() << std::endl;
		std::cout << "Card number: " << getCardNumber() << std::endl;
		std::cout << "Pin: " << getPin() << std::endl;
		std::cout << "Expire date: " << getExpMonth() << '/' << getExpYear() << std::endl;
		std::cout << "Balance: " << getBalance() << std::endl;
	}
};

class Lesson : public Base
{
	std::string name;

public:
	Lesson() : name("") {}
	Lesson(const size_t& id, const std::string& name) : Base(id)
	{
		setName(name);
	}
	void setName(const std::string& name) { this->name = name; }
	std::string getName() const { return this->name; }
};

class Exam : public Base
{
	Lesson lesson;
	short point;

public:
	Exam() :point(0) {}
	Exam(const size_t& id, const Lesson& lesson, const short& point) : Base(id)
	{
		setLesson(lesson);
		setPoint(point);
	}
	void setPoint(const short& point) { this->point = point; };
	short getPoint() const { return this->point; }
	void setLesson(const Lesson& lesson) { this->lesson = lesson; }
	Lesson getLesson() const { return this->lesson; }

};

class IDController
{
	static size_t exam_id;
	static size_t student_id;
	static size_t teacher_id;
	static size_t lesson_id;
	static size_t group_id;
	static size_t card_id;
public:
	static size_t getNewExamID() { return ++exam_id; }
	static size_t getNewStudentID() { return ++student_id; }
	static size_t getNewTeacherID() { return ++teacher_id; }
	static size_t getNewLessonID() { return ++lesson_id; }
	static size_t getNewGroupID() { return ++group_id; }
	static size_t getNewCardID() { return ++card_id; }
};
size_t IDController::exam_id = NULL;
size_t IDController::student_id = NULL;
size_t IDController::teacher_id = NULL;
size_t IDController::lesson_id = NULL;
size_t IDController::group_id = NULL;
size_t IDController::card_id = NULL;

class Student : public Person
{
	std::string speciality;
	short avgScore;
	size_t scolarship; //stipendiya
	BankCard card;
	std::list<Exam> exams;
public:
	Student() : speciality(""), avgScore(0) {}
	Student(const size_t& id, const std::string& name, const std::string& surname, const short& age,
		const std::string& speciality, const size_t& scolarship, const BankCard& card) : Person(id, name, surname, age)
	{
		setSpeciality(speciality);
		setScolarship(scolarship);
		setCard(card);
	}

	void setSpeciality(const std::string& speciality) { this->speciality = speciality; }
	std::string getSpeciality() const { return this->speciality; }
	void setAvgScore(const short& score) { this->avgScore = score; }
	short getAvgScore() const { return this->avgScore; }
	void setScolarship(const size_t& scolarship) { this->scolarship = scolarship; }
	size_t getScolarship() const { return this->scolarship; }
	void setCard(const BankCard& card) { this->card = card; }
	BankCard getCard() const { return this->card; }
	void addExam(const Lesson& lesson, const short& point)
	{
		exams.push_back(Exam(IDController::getNewExamID(), lesson, point));
	}
	Exam& getExamByID(const size_t& id) const
	{
		for (auto i = exams.begin(); i != exams.end(); i++)
		{
			if (id == i->getID())
				return const_cast<Exam&>(*i);
		}
		Exam null; return null;
	}
	void show() const
	{
		std::cout << "########################################" << std::endl;
		std::cout << "ID: " << getID() << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Surname: " << getSurname() << std::endl;
		std::cout << "Age: " << getAge() << std::endl;
		std::cout << "Speciality: " << getSpeciality() << std::endl;
		std::cout << "Scolarship: " << getScolarship() << std::endl;
	}
	void showBalance()
	{
		std::cout << "############ Student card ############" << std::endl;
		std::cout << "Card number: " << card.getCardNumber() << std::endl;
		std::cout << "Balance: " << card.getBalance() << std::endl;
	}
};

class Group : public Base
{
	std::string name;
	std::list<Lesson> lessons;
	std::list<Student> students;

public:
	Group() : name("") {}
	Group(const size_t& id, const std::string& name) : Base(id)
	{
		setName(name);
	}

	void setName(const std::string& name) { this->name = name; }
	std::string getName() const { return this->name; }
	void addLesson(const std::string& name)
	{
		lessons.push_back(Lesson(IDController::getNewLessonID(), name));
	}
	Lesson& getLessonByName(const std::string& name) const
	{
		for (auto i = lessons.begin(); i != lessons.end(); i++)
		{
			if (name == i->getName())
				return const_cast<Lesson&>(*i);
		}
		Lesson null; return null;
	}
	void addStudent(const std::string& name, const std::string& surname, const short& age, const std::string& speciality,
		const size_t scolarship, const BankCard& card)
	{
		students.push_back(Student(IDController::getNewStudentID(), name, surname, age, speciality, scolarship, card));
	}
	Student& getStudentByID(const size_t& id) const
	{
		for (auto i = students.begin(); i != students.end(); i++)
		{
			if (id == i->getID())
				return const_cast<Student&>(*i);
		}
		Student null; return null;
	}
};

class Teacher : public Person
{
	std::list<Group> groups;
	std::string department;
	size_t salary;
	BankCard card;

public:
	Teacher() : department(""), salary(0) {}
	Teacher(const size_t& id, const std::string& name, const std::string& surname, const short& age,
		const std::string& dep, const size_t& salary, const BankCard& card) :Person(id, name, surname, age)
	{
		setDepartment(dep);
		setSalary(salary);
		setCard(card);
	}

	void setDepartment(const std::string& dep) { this->department = dep; }
	std::string getDepartment() const { return this->department; }
	void setSalary(const size_t& salary) { this->salary = salary; }
	size_t getSalary() const { return this->salary; }
	void setCard(const BankCard& card) { this->card = card; }
	BankCard getCard() const { return this->card; }
	void addGroup(const std::string& name)
	{
		groups.push_back(Group(IDController::getNewGroupID(), name));
	}
	Group& getGroupByName(const std::string& name) const
	{
		for (auto i = groups.begin(); i != groups.end(); i++)
		{
			if (name == i->getName())
				return const_cast<Group&>(*i);
		}
		Group null; return null;
	}
	void show() const
	{
		std::cout << "########################################" << std::endl;
		std::cout << "ID: " << getID() << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Surname: " << getSurname() << std::endl;
		std::cout << "Age: " << getAge() << std::endl;
		std::cout << "Department: " << getDepartment() << std::endl;
		std::cout << "Salary: " << getSalary() << std::endl;
	}
	void showBalance() const
	{
		card.show();
	}
};

class University
{
	std::string name;
	std::list<Teacher> teachers;
	std::list<Student> students;
public:
	University() : name("") {}
	University(const std::string& name)
	{
		setName(name);
	}

	void setName(const std::string& name) { this->name = name; }
	std::string getName() const { return this->name; }

	void addTeacher(const std::string& name, const std::string& surname, const short& age, const std::string& dep,
		const size_t& salary, const BankCard& card)
	{
		teachers.push_back(Teacher(IDController::getNewTeacherID(), name, surname, age, dep, salary, card));
	}

	Teacher& getTeacherByID(const size_t& id) const
	{
		for (auto i = teachers.begin(); i != teachers.end(); i++)
		{
			if (id == i->getID())
				return const_cast<Teacher&>(*i);
		}
		Teacher null; return null;
	}

	void addStudent(const std::string& name, const std::string& surname, const short& age, const std::string& speciality,
		const size_t scolarship, const BankCard& card)
	{
		students.push_back(Student(IDController::getNewStudentID(), name, surname, age, speciality, scolarship, card));
	}

	Student& getStudentByID(const size_t& id) const
	{
		for (auto i = students.begin(); i != students.end(); i++)
		{
			if (id == i->getID())
				return const_cast<Student&>(*i);
		}
		Student null; return null;
	}

	size_t getUniversityScore() const
	{
		size_t score = 0;
		for (auto i = students.begin(); i != students.end(); i++)
		{
			score += i->getAvgScore();
		}
		return score;
	}
	void showAllStudents() const
	{
		for (auto i = students.begin(); i != students.end(); i++)
		{
			i->show();
		}
	}
	void showAllTeachers() const
	{
		for (auto i = teachers.begin(); i != teachers.end(); i++)
		{
			i->show();
		}
	}
	int getPayment() const
	{
		size_t total = 0;
		for (auto i = students.begin(); i != students.end(); i++)
		{
			total += i->getScolarship();
		}

		for (auto i = teachers.begin(); i != teachers.end(); i++)
		{
			total += i->getSalary();
		}

		return total;
	}
};

class Bank
{
	std::string name;
	std::list<BankCard> cards;
public:
	static long long CARD_NUMBER;
	Bank() {}

	Bank(const std::string& name)
	{
		setName(name);
	}

	void setName(const std::string& name) { this->name = name; }
	std::string getName() const { return this->name; }
	BankCard createNewCard()
	{
		std::string card_number = std::to_string(++CARD_NUMBER);
		size_t pin = (rand() * rand()) % 10000;
		BankCard card(IDController::getNewCardID(), card_number, pin, Time::getMonth(), Time::getYear());
		cards.push_back(card);
		return card;
	}
	BankCard& getCard(const std::string& card_number) const
	{
		for (auto i = cards.begin(); i != cards.end(); i++)
		{
			if (card_number == i->getCardNumber())
				return const_cast<BankCard&>(*i);
		}
		BankCard null; return null;
	}
};
long long Bank::CARD_NUMBER = 416900000000000;
void main()
{
	srand(time(NULL));
	Bank bank("Kapital Bank");
	BankCard c1 = bank.createNewCard();
	BankCard c2 = bank.createNewCard();
	BankCard c3 = bank.createNewCard();
	BankCard c4 = bank.createNewCard();
	BankCard c5 = bank.createNewCard();

	c1.show();
	c2.show();
	c3.show();
	c4.show();
	c5.show();
	University university("UNEC");
	university.addStudent("Terlan", "Kerimli", 20, "Business Administration", 75, c1);
	university.addStudent("Elshen", "Talibli", 19, "World Economics", 75, c2);
	university.addStudent("Aysun", "Mikayilova", 20, "Business Administration", 128, c3);

	university.addTeacher("Rufet", "Memmedov", 38, "Business", 800, c4);
	university.addTeacher("Zulfiqar", "Memmedov", 38, "Economics", 1000, c5);
	
	std::cout << "All students: " << std::endl;
	university.showAllStudents();
	std::cout << std::endl << "All teachers: " << std::endl;
	university.showAllTeachers();

	std::cout << std::endl <<  "Total: " << university.getPayment() << std::endl;
}
