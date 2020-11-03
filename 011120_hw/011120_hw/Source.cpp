#include <iostream>
#include <assert.h>

class Debtor
{
	int id;
	char* name;
	char* surname;
	char* work_address;
	double salary;
	char* phone_number;
	bool has_late_payment;
	char* live_address;
	double debt;

	static int current_id;

	/*Debtor class (debtor-borclu)
id,name,surname,work_address,salary,phone_number
//hasLatePayment,live_address,debt
//showDebtor*/
public:

	// default constructor
	Debtor() :id{ 0 }, name{ nullptr }, surname{ nullptr }, work_address{ nullptr }, 
		salary{ 0 }, phone_number{ nullptr }, has_late_payment{ 0 }, live_address{ nullptr }, debt{ 0 }{}

	// parametric constructors
	Debtor(const char* name, const char* surname, const char* work_address, double salary,
		const char* phone_number, bool has_late_payment, const char* live_address, double debt)
		: Debtor(name, surname, work_address, salary, phone_number, has_late_payment, live_address)
	{
		setDebt(debt);
	}

	Debtor(const char* name, const char* surname, const char* work_address, double salary,
		const char* phone_number, bool has_late_payment, const char* live_address)
		: Debtor(name, surname, work_address, salary, phone_number, has_late_payment)
	{
		setLiveAddress(live_address);
	}

	Debtor(const char* name, const char* surname, const char* work_address, double salary,
		const char* phone_number, bool has_late_payment)
		: Debtor(name, surname, work_address, salary, phone_number)
	{
		setLatePaymentStatus(has_late_payment);
	}

	Debtor(const char* name, const char* surname, const char* work_address, double salary,
		const char* phone_number)
		: Debtor(name, surname, work_address, salary)
	{
		setPhoneNumber(phone_number);
	}

	Debtor(const char* name, const char* surname, const char* work_address, double salary)
		: Debtor(name, surname, work_address)
	{
		setSalary(salary);
	}

	Debtor(const char* name, const char* surname, const char* work_address)
		: Debtor(name, surname)
	{
		setWorkAddress(work_address);
	}

	Debtor(const char* name, const char* surname)
		: Debtor(name)
	{
		setSurname(surname);
	}

	Debtor(const char* name)
	{
		setName(name);
		setID(++Debtor::current_id);
	}


	// copy constructor
	Debtor(const Debtor &debtor)
	{
		this->setID(debtor.id);
		this->setName(debtor.name);
		this->setSurname(debtor.surname);
		this->setWorkAddress(debtor.work_address);
		this->setSalary(debtor.salary);
		this->setPhoneNumber(debtor.phone_number);
		this->setLatePaymentStatus(debtor.has_late_payment);
		this->setLiveAddress(debtor.live_address);
		this->setDebt(debtor.debt);
	}
	static int getCurrentID()
	{
		return current_id;
	}

	int getID()
	{
		return id;
	}

	void setID(int id)
	{
		assert(id >= 0 && "ID must be greater than or equal to one!");
		this->id = id;
	}

	const char* getName()
	{
		return name;
	}

	void setName(const char* name)
	{
		assert(name && "NULL ERROR!");
		assert(strlen(name) >= 2 && "Minimum name length is two characters!");
		this->name = _strdup(name);
	}

	const char* getSurname()
	{
		return surname;
	}

	void setSurname(const char* surname)
	{
		assert(surname && "NULL ERROR!");
		assert(strlen(surname) >= 2 && "Minimum surname length is two characters!");
		this->surname = _strdup(surname);
	}

	const char* getWorkAddress()
	{
		return work_address;
	}

	void setWorkAddress(const char* work_address)
	{
		assert(surname && "NULL ERROR");
		this->work_address = _strdup(work_address);
	}

	double getSalary()
	{
		return salary;
	}
	
	void setSalary(double salary)
	{
		assert(salary > 0 && "Salary must be greater than zero");
		this->salary = salary;
	}

	const char* getPhoneNumber()
	{
		return phone_number;
	}
	
	void setPhoneNumber(const char* phone_number)
	{
		assert(phone_number && "NULL ERROR!");
		this->phone_number = _strdup(phone_number);
	}

	bool getLatePaymentStatus()
	{
		return has_late_payment;
	}

	void setLatePaymentStatus(bool has_late_payment)
	{
		this->has_late_payment = has_late_payment;
	}

	const char* getLiveAddress()
	{
		return live_address;
	}

	void setLiveAddress(const char* live_address)
	{
		assert(live_address && "NULL ERROR!");
		this->live_address = _strdup(live_address);
	}

	double getDebt()
	{
		return debt;
	}

	void setDebt(double debt)
	{
		assert(debt > 0 && "Debt must be greater than zero");
		this->debt = debt;
	}

	void showDebtor()
	{
		const char* name = getName();
		const char* surname = getSurname();
		const char* work_address = getWorkAddress();
		const char* phone_number = getPhoneNumber();
		const char* live_address = getLiveAddress();

		std::cout << "Debtor ID: " << getID() << std::endl;

		if(name)
			std::cout << "Debtor name: " << name << std::endl;

		if(surname)
			std::cout << "Debtor surname: " << surname << std::endl;

		if(work_address)
			std::cout << "Debtor work address: " << work_address << std::endl;

		std::cout << "Debtor salary: " << getSalary() << std::endl;

		if(phone_number)
			std::cout << "Debtor phone number: " << phone_number << std::endl;

		std::cout << "Debtor late payment status: ";

		if (getLatePaymentStatus())
			std::cout << "True" << std::endl;
		else
			std::cout << "False" << std::endl;

		if(live_address)
			std::cout << "Debtor live address: " << live_address << std::endl;

		std::cout << "Debtor debt: " << getDebt() << std::endl;
	}

	~Debtor()
	{
		delete[] name;
		delete[] surname;
		delete[] work_address;
		delete[] phone_number;
		delete[] live_address;
	}
};

int Debtor::current_id = 0;

/*Bank class 
bank_name
debtors
butun borclulari gostermek,
borcu 1000 den yuxari olanlari gostermek
gecikmesi olanlari gostermek
KECHDIYIMIZ HER SHEY ISTIFADE OLUNSUN
STATIC ID,MAXCOUNT  VE  ASSERT */


class Bank
{
	char* bank_name;
	Debtor* debtors;

private:
	void setDebtors(Debtor* debtors)
	{
		assert(debtors && "NULL ERROR!");

		size_t debtor_count = Debtor::getCurrentID();

		this->debtors = new Debtor[debtor_count];

		if (debtors)
		{
			for (size_t i = 0; i < debtor_count; i++)
			{
				copyDebtor(this->debtors[i], debtors[i]);
			}
		}
	}
public:

	Bank() :bank_name{ nullptr }, debtors{ nullptr }{}

	Bank(const char* bank_name, Debtor* debtors)
	{
		setBankName(bank_name);
		setDebtors(debtors);
	}

	const Debtor* getDebtors()
	{
		return debtors;
	}
	void setBankName(const char* bank_name)
	{
		assert(bank_name && "NULL ERROR!");
		this->bank_name = _strdup(bank_name);
	}

	const char* getBankName()
	{
		return bank_name;
	}

	void showBankInfo()
	{
		const char* bank_name = getBankName();
		size_t debtor_count = Debtor::getCurrentID();
		std::cout << "Bank name: ";
		if (bank_name)
			std::cout << bank_name << std::endl;
		else
			std::cout << "none" << std::endl;

		std::cout << "Debtor count: ";

		if (debtor_count)
			std::cout << debtor_count << std::endl;
		else
			std::cout << 0 << std::endl;

	}
	void showDebtors()
	{
		if (debtors)
		{
			size_t debtor_count = Debtor::getCurrentID();
			for (size_t i = 0; i < debtor_count; i++)
			{
				std::cout << "-----------------------------------------" << std::endl;
				debtors[i].showDebtor();
			}
		}
		else
			std::cout << "There is not debtor!" << std::endl;
	}

	void showDebtorsCustom(int debt = 1000)
	{
		if (debtors)
		{
			size_t debtor_count = Debtor::getCurrentID();
			bool printed = false;
			for (size_t i = 0; i < debtor_count; i++)
			{
				if (debtors[i].getDebt() > debt)
				{
					std::cout << "-----------------------------------------" << std::endl;
					debtors[i].showDebtor();
					printed = true;
				}
			}

			if (!printed)
				std::cout << "No one owes more than $ " << debt << std::endl;
		}
		else
			std::cout << "There is not debtor!" << std::endl;
	}

	void showLatePaymentDebtors()
	{
		if (debtors)
		{
			size_t debtor_count = Debtor::getCurrentID();

			bool printed = false;

			for (size_t i = 0; i < debtor_count; i++)
			{
				if (debtors[i].getLatePaymentStatus())
				{
					std::cout << "-----------------------------------------" << std::endl;
					debtors[i].showDebtor();
					printed = true;
				}
			}

			if (!printed)
				std::cout << "No debtor with overdue payments" << std::endl;
		}
		else
			std::cout << "There is no debtors!" << std::endl;
	}

	void copyDebtor(Debtor& new_debtor, Debtor& old_debtor)
	{
		new_debtor.setID(old_debtor.getID());
		new_debtor.setName(old_debtor.getName());
		new_debtor.setSurname(old_debtor.getSurname());
		new_debtor.setWorkAddress(old_debtor.getWorkAddress());
		new_debtor.setSalary(old_debtor.getSalary());
		new_debtor.setPhoneNumber(old_debtor.getPhoneNumber());
		new_debtor.setLatePaymentStatus(old_debtor.getLatePaymentStatus());
		new_debtor.setLiveAddress(old_debtor.getLiveAddress());
		new_debtor.setDebt(old_debtor.getDebt());
	}
	
	bool AddDebtor(Debtor & debtor)
	{
		size_t new_debtor_count = Debtor::getCurrentID();

		Debtor* new_debtors = new Debtor[new_debtor_count];

		if (new_debtors)
		{
			if (new_debtor_count - 1)
			{
				for (size_t i = 0; i < new_debtor_count - 1; i++)
				{
					copyDebtor(new_debtors[i], debtors[i]);
				}
				delete[] debtors;
			}

			copyDebtor(new_debtors[new_debtor_count - 1], debtor);

			debtors = new_debtors;

			return true;
		}
		return false;
	}

	~Bank()
	{
		delete[] bank_name;
		delete[] debtors;
	}
};

/*Bank class
bank_name
debtors
butun borclulari gostermek,
borcu 1000 den yuxari olanlari gostermek
gecikmesi olanlari gostermek
KECHDIYIMIZ HER SHEY ISTIFADE OLUNSUN
STATIC ID,MAXCOUNT  VE  ASSERT */
int main()
{
	Debtor d1("George", "Williams", "4289 Trails End Road Fort Lauderdale, FL 33301",
		2000, "+1 954-374-1329", false, "1606 Kenwood Place Deerfield Beach, FL 33441", 500);

	Debtor d2("Denna", "Taylor", "104 Memory Lane Freeport, IL 61032", 
		3500, "+1 815-890-2909", true, "3593 Hillside Drive Broussard, LA 70518", 18000);

	Debtor d3("Mary", "Jenkins", "4953 Elsie Drive Mount Vernon, SD 57363", 
		500, "+1 605-236-0156", true, "1546 Bedford Street Wallingford, CT 06492", 4500);

	d1.showDebtor();
	std::cout << std::endl;
	d2.showDebtor();
	std::cout << std::endl;
	d3.showDebtor();
	std::cout << std::endl;
	Debtor* debtors = new Debtor[3]{ d1, d2, d3 };

	Bank bank("Bank of America", debtors);

	//d4.showDebtor();
	/*Debtor d4("Travis", "Gans", "2802 Bates Brothers Road Columbus, OH 43204",
		5000, "+1 614-276-5947", false, "735 Meadowview Drive Harrisonburg, VA 22801", 2750);*/

	std::cout << std::endl;

	bank.showBankInfo();


	std::cout << std::endl;

	bank.AddDebtor(d4);

	bank.showDebtors();
	

}
/*
Debtor class (debtor-borclu)
id,name,surname,work_address,salary,phone_number
//hasLatePayment,live_address,debt
//showDebtor
Bank class 
bank_name
debtors
butun borclulari gostermek,
borcu 1000 den yuxari olanlari gostermek
gecikmesi olanlari gostermek
KECHDIYIMIZ HER SHEY ISTIFADE OLUNSUN
STATIC ID,MAXCOUNT  VE  ASSERT .
*/