#include <iostream>
#include <math.h>
#include <assert.h>

class Test
{
public:
	virtual void show()
	{

	}

	virtual ~Test() = 0;
};

class Test2 :public Test
{
	//avtomatik destructor override olunur
};

enum StatusCodes
{
	NotFound = 404,
	BadRequest = 303,
	ServerError = 500
};

class A
{

};


void doSomething()
{
	//throw (-1);

	//throw (false);

	//throw(1.5);

	//throw 100;

	throw "Heyyy this is error";
}

void boo(int a)
{
	//assert(a != 1 && "Hey error");
	if (a == 1)
	{
		throw 1;
	}
	else if (a == 2)
	{
		throw 21u;
	}
	else
	{
		throw "Hey error";
	}
}

//void main()
//{
	//throw (-1);

	//throw "Heyy error";

	//throw A();


	/*try {
		doSomething();
	}
	catch (int ex)
	{
		std::cout << "Int error has occured!" << std::endl;
		std::cout << "Error code: " << ex << std::endl;
	}
	catch (bool)
	{
		std::cout << "Bool error has occured!" << std::endl;
	}
	catch (double)
	{
		std::cout << "Double error has occured!" << std::endl;
	}
	catch (const char* ex)
	{
		std::cout << "Char error has occured!" << std::endl;
		std::cout << "Error text: " << ex << std::endl;
	}
	std::cout << "Program continued!" << std::endl;*/	

	/*while (1)
	{
		int number = 0;

		std::cout << "Number: ";
		std::cin >> number;

		try
		{
			if (number < 0)
			{
				throw "Number should be more than zero";
			}
			std::cout << sqrt(number) << std::endl;
		}
		catch (const char* ex)
		{
			std::cout << "Error: " << ex << std::endl;
		}
	}*/


	/*int number1 = 0;
	int number2 = 0;
	
	std::cin >> number1;
	std::cin >> number2;


	try
	{
		std::cout << number1 / number2;
	}
	catch (...)
	{

	}*/

	/*try
	{
		boo(1);
	}
	catch (int ex)
	{
		std::cout << "Int error" << std::endl;
	}
	catch (const char* ex)
	{
		std::cout << "Char * error" << std::endl;
	}
	catch (...)
	{
		std::cout << "Simple error" << std::endl;
	}*/

	/*while (true)
	{
		int number1 = 0;
		std::cout << "Number 1: ";
		std::cin >> number1;

		int number2 = 0;
		std::cout << "Number 2: ";
		std::cin >> number2;

		try
		{
			if (number2 == 0)
				throw "You can not divide by zero";

			std::cout << "Result: " << number1 / number2 << std::endl;
		}
		catch (const char* ex)
		{
			std::cout << "Error: " << ex << std::endl;
		}
	}*/
//}


#include <iostream>
class HDD
{
private:
	class File
	{
	private:
		double file_size = 0;
	public:
		std::string file_name;
		std::string content;

		double getFileSize() const { return this->file_size; }

		File(const std::string& filename, const std::string& content = "")
		{
			this->file_name = filename;
			this->content = content;
			this->file_size = content.length();
		}

		void setFileSize(size_t size)
		{
			this->file_size = size;
		}
	};
	
	File** files;
	size_t count;
	double current_size;
public:
	static double capacity;

	HDD() :files(NULL), count(0), current_size(0) {}
	File* getFile(const std::string& file_name)
	{
		//eger file yoxdursa error atsin // ex : bele bir fayl movcud deyil

		for (size_t i = 0; i < this->count; i++)
		{
			if (file_name == files[i]->file_name)
			{
				return files[i];
			}
		}
		
		throw "File doesn't exist!";
	}

	bool isExists(const std::string& file_name)
	{
		//eger varas true or false

		for (size_t i = 0; i < this->count; i++)
		{
			if (file_name == files[i]->file_name)
			{
				return true;
			}
		}

		return false;
	}

	void createFile(const std::string& file_name, const std::string& content = "")
	{
		//1. eger fayl varsa error at, yeni fayli movcuddur
		//2. eger fayl yoxdursa ve hdd doludursa error at, disk doludur.

		if (isExists(file_name))
			throw "File is exist!";
		else if (this->current_size + content.length() >= capacity)
			throw "HDD is full!";

		size_t new_size = this->count + 1;
		
		auto new_files = new File * [new_size];

		if (new_files != NULL)
		{
			if (new_size - 1)
			{
				for (size_t i = 0; i < new_size - 1; i++)
				{
					new_files[i] = this->files[i];
				}

				delete[] this->files;
			}

			File* new_file = new File(file_name, content);

			if (new_file != NULL)
			{
				new_files[new_size - 1] = new_file;
			}
			else
				throw "New file didn't created!";

			this->count = new_size;
			this->files = new_files;
			this->current_size += new_file->getFileSize();
		}
		else
			throw "Files can't copied!";
	}

	void setFileContent(const std::string& file_name, const std::string& content)
	{
		//1. eger fayl yoxdursa error at
		//2. eger fayl varsa ve disk doludursa error.
		if (!isExists(file_name))
			throw "File isn't exist!";

		File *file = getFile(file_name);

		size_t new_size = content.length();

		size_t current_size = file->getFileSize();

		if (new_size > current_size)
			if (this->current_size + new_size - current_size >= capacity)
				throw "HDD is full!";
		
		file->setFileSize(new_size);
		file->content = content;

		this->current_size = (this->current_size - current_size) + new_size;

	}

	void deleteFileContent(const std::string& file_name)
	{
		//1. eger fayl yoxdursa error at
		if (!isExists(file_name))
			throw "File isn't exist!";

		File* file = getFile(file_name);

		this->current_size -= file->getFileSize();
		file->setFileSize(0);

		file->content = "";
	}
};

double HDD::capacity = 2 * 1024 * 1024;


class Operation
{
public:
	Operation() = delete;

	static void controlPC();
};

void Operation::controlPC()
{
	HDD hdd;

	try
	{
		hdd.createFile("newtext.txt", "Hello world");
		hdd.createFile("newtext.txt", "Hello world");
	}
	catch (const char* ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}


	try
	{
		hdd.setFileContent("newtext.txt", "Hello world");
		hdd.setFileContent("newtext2.txt", "Hello world");
	}
	catch (const char* ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}

	try
	{
		hdd.deleteFileContent("newtext.txt");
		hdd.deleteFileContent("newtext2.txt");
	}
	catch (const char* ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}
};


void main()
{
	Operation::controlPC();
}