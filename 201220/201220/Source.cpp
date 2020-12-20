#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
void dataWriteToFile(std::string file_name, std::string text)
{
	// out write
	// in read
	// app - append
	std::ofstream fout(file_name, std::ios::app);

	if (fout.is_open())
	{
		fout << text << " ";
	}

	fout.close();
}

std::string getDataFromFile(const std::string& file_name)
{
	std::ifstream fin(file_name, std::ios::in);

	std::string result;

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string tmp;

			fin >> tmp;
			result.append(tmp + ' ');
		}
	}
	else
	{
		throw std::string("This file : " + file_name + " does not exist");
	}

	fin.close();
	return result;
}


//Binary Mode

void writeDataToBinaryFile(const std::string & file_name)
{
	std::ofstream fout(file_name, std::ios_base::binary | std::ios::
	app);

	int arr[5]{ 21, 22, 23, 24, 25 };

	if (fout.is_open())
	{
		fout.write((char*)arr, sizeof(int) * 5);
	}

	fout.close();
}

void readDataFromBinaryFile(const std::string& file_name)
{
	std::ifstream fin(file_name, std::ios::binary);

	if (fin.is_open())
	{
		const int length = 10;
		int arr[length]{};

		fin.read((char*)arr, sizeof(int) * length);

		for (size_t i = 0; i < length; i++)
		{
			std::cout << arr[i] << " ";
		}std::cout << std::endl;
	}
}

namespace Time
{
	std::string getDate()
	{
time_t now(time(0));
tm new_time;
localtime_s(&new_time, &now);
return std::to_string(new_time.tm_mday) + '/' + std::to_string(new_time.tm_mon + 1) + '/' +
std::to_string(new_time.tm_year + 1900) + ' ' + std::to_string(new_time.tm_hour) + ':' + std::to_string(new_time.tm_min);
	}
}

class Applier
{

	std::string name;
	std::string surname;
	std::string speciality;
	std::string text;

public:
	Applier(const std::string& name, const std::string& surname, const std::string& speciality,
		const std::string& text)
	{
		setName(name);
		setSurname(surname);
		setSpeciality(speciality);
		setText(text);
	}

	void setName(const std::string& name) {
		this->name = name;
	}
	void setSurname(const std::string& surname) {
		this->surname = surname;
	}

	void setSpeciality(const std::string& speciality) {
		this->speciality = speciality;
	}
	void setText(const std::string& text) {
		this->text = text;
	}

	std::string getName() const { return this->name; }
	std::string getSurname() const { return this->surname; }
	std::string getSpeciality() const { return this->speciality; }
	std::string getText() const { return this->text; }

	std::string getCv() const
	{
		std::string cv;

		cv.append("Name: " + getName() + '\n');
		cv.append("Surname: " + getSurname() + '\n');
		cv.append("Speciality: " + getSpeciality() + '\n');
		cv.append("Text: " + getText() + '\n');
		return cv;
	}

};

class Company
{
public:
	static void hireUp(const std::string& text)
	{
		std::ofstream fout(std::string("cv.txt"), std::ios_base::app);

		if (fout.is_open())
		{
			fout << text << "Time: " << Time::getDate() << "\n\n";
		}

		fout.close();
	}

	static void showAllCv()
	{
		std::ifstream fin(std::string("cv.txt"));

		std::string allCv;
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				std::string tmp;
				std::getline(fin, tmp);
				allCv.append(tmp + "\n");
			}
		}

		fin.close();

		std::cout << allCv << std::endl;
	}
};


class Worker
{
	std::string name;
	int age;
public:
	Worker() {}
	Worker(const std::string& name, const int& age)
	{
		setName(name);
		setAge(age);
	}

	void setName(const std::string& name)
	{
		this->name = name;
	}
	
	std::string getName() const { return this->name;}

	void setAge(const int& age)
	{
		this->age = age;
	}

	int getAge() const { return this->age; }

	void show() const
	{
		std::cout << "	===== Worker info ====" << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Age:: " << getAge() << std::endl;
	}
};

class JobPosting
{
public:
	std::string companyName;
	Worker** appliers;
	int count = 0;

	JobPosting() {}

	JobPosting(const std::string& name) : companyName(name)
	{

	}

	Worker** getAppliers() const
	{
		return appliers;
	}

	void addApplier(const Worker& a)
	{
		auto newAppliers = new Worker * [count + 1];

		if (newAppliers != NULL)
		{
			for (size_t i = 0; i < count; i++)
			{
				newAppliers[i] = appliers[i];
			}

			newAppliers[count] = new Worker(a);
			++count;

			if (count != 0)
				delete appliers;

			appliers = newAppliers;
		}
	}

	void showAppliers() const
	{
		std::cout << "Company name => " << this->companyName << std::endl;
		for (size_t i = 0; i < count; i++)
		{
			appliers[i]->show();
		}
	}
};


class FileHelper {
public:
	static std::string filename;

	static void Save(JobPosting jp)
	{
		std::ofstream fout(filename, std::ios::app);

		if (fout.is_open())
		{
			fout << jp.companyName << std::endl;
			fout << jp.count << std::endl;

			for (size_t i = 0; i < jp.count; i++)
			{
				fout << jp.appliers[i]->getName() << " " <<
					jp.appliers[i]->getAge() << std::endl;
			}
		}
	}

	static JobPosting getJobPosting()
	{
		JobPosting jp;

		std::ifstream fin(filename);

		if (fin.is_open())
		{
			fin >> jp.companyName;
			int count;
			fin >> count;

			for (size_t i = 0; i < count; i++)
			{
				Worker worker;
				std::string name;
				int age;
				fin >> name;
				worker.setName(name);
				fin >> age;
				worker.setAge(age);
				jp.addApplier(worker);
			}
		}
		return jp;
	}
};

std::string FileHelper::filename = "job.txt";
void main()
{
	Worker w1("John", 21);
	Worker w2("Aysel", 26);
	Worker w3("Gulya", 25);

	JobPosting jp("ITStepMMC");

	jp.addApplier(w1);
	jp.addApplier(w2);
	jp.addApplier(w3);

	//FileHelper::Save(jp);

	FileHelper::getJobPosting().showAppliers();

	/*Applier a("John", "Johnlu", "Designer", "I have 2 years practise,I know AdobeXD,AdobePhotoshop");

	std::cout << a.getCv() << std::endl;

	Company::hireUp(a.getCv());

	Company::showAllCv();*/
}


//void main()
//{
//	/*dataWriteToFile("data.txt", "Hello world");
//	dataWriteToFile("data.txt", ", and programmers.");
//	dataWriteToFile("data.txt", "How are you?");*/
//	/*try
//	{
//		std::cout << getDataFromFile("data123.txt");
//	}
//	catch (const std::string& ex)
//	{
//		std::cout << ex << std::endl;
//	}*/
//	/*writeDataToBinaryFile("arr.bin");
//	readDataFromBinaryFile("arr.bin");*/
//	
//	
//}