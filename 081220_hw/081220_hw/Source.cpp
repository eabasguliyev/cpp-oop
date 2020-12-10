#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

class Date
{
	struct dt
	{
		unsigned short second;
		unsigned short minute;
		unsigned short hour;
		unsigned short day;
		unsigned short month;
		unsigned short year;
	};

	dt date;
public:
	void set()
	{
		time_t now(time(0));
		tm newtime;
		localtime_s(&newtime, &now);
		date.year = newtime.tm_year + 1900;
		date.month = newtime.tm_mon + 1;
		date.day = newtime.tm_mday;
		date.hour = newtime.tm_hour;
		date.minute = newtime.tm_min;
		date.second = newtime.tm_sec;
	}

	void show() const
	{
		std::cout << this->date.day << '/' << this->date.month << '/' << this->date.year << ' ';
		std::cout << this->date.hour << ':' << this->date.minute << ':' << this->date.second << std::endl;

	}
};

class Disc
{
private:
	class File
	{
	private:
		double file_size = 0;
		bool hashed;
	public:
		std::string file_name;
		std::string content;
		Date file_created;
		Date last_modified;

		double getFileSize() const { return this->file_size; }

		File(const std::string& filename, const std::string& content = "")
		{
			this->file_name = filename;
			this->content = content;
			this->file_size = content.length();
			this->hashed = false;
		}

		void setFileSize(size_t size)
		{
			this->file_size = size;
		}

		void setHashedStatus(bool status)
		{
			this->hashed = status;
		}

		bool getHashedStatus() const { return this->hashed; }

		void show() const
		{
			std::cout << "File name: " << this->file_name << std::endl;
			std::cout << "File created: "; this->file_created.show();
			std::cout << "Last modified: "; this->last_modified.show();
			std::cout << "File size: " << this->file_size << std::endl;
			std::cout << "File hashed: " << std::boolalpha << this->getHashedStatus() << std::endl;
			std::cout << "File content: " << this->content << std::endl;
		}
	};

	std::string disk_name;
	std::string model;
	File** files;
	size_t count;
	double current_size;
	Date disk_created;
	Date last_modified;

	size_t generateHash(const std::string& content)
	{
		std::hash<std::string > hash;
		return hash(content);
	}
public:
	
	
	static double capacity;

	Disc(const std::string& disk_name, const std::string& model) :files(NULL), count(0), current_size(0) {
		setDiskName(disk_name);
		setModel(model);
		disk_created.set();
		last_modified.set();
	}

	void setDiskName(const std::string& disk_name)
	{
		this->disk_name = disk_name;
	}

	std::string getDiskName() const { return this->disk_name; }

	void setModel(const std::string& model)
	{
		this->model = model;
	}

	std::string getModel() const { return this->model; }

	void hashFile(const std::string& file_name)
	{
		if (!isExists(file_name))
			throw file_name + " isn't exist!";

		File* file = getFile(file_name);

		std::string content = std::to_string(generateHash(file->content));
		size_t new_size = content.length();

		size_t current_size = file->getFileSize();

		if (new_size > current_size)
			if (this->current_size + new_size - current_size >= capacity)
				throw std::string("HDD is full!");

		file->setFileSize(new_size);
		file->content = content;
		file->setHashedStatus(true);
		file->last_modified.set();
		this->last_modified.set();
		this->current_size = (this->current_size - current_size) + new_size;
		readWriteSpeed(new_size);
	}

	virtual void readWriteSpeed(size_t bytes) const = 0;

	File* getFile(const std::string& file_name) throw(std::string)
	{
		//eger file yoxdursa error atsin // ex : bele bir fayl movcud deyil

		for (size_t i = 0; i < this->count; i++)
		{
			if (file_name == files[i]->file_name)
			{
				return files[i];
			}
		}

		throw file_name + " doesn't exist!";
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

	void createFile(const std::string& file_name, const std::string& content = "") throw(std::string)
	{
		//1. eger fayl varsa error at, yeni fayli movcuddur
		//2. eger fayl yoxdursa ve hdd doludursa error at, disk doludur.

		if (isExists(file_name))
			throw file_name + " is exist!";
		else if (this->current_size + content.length() >= capacity)
			throw std::string("HDD is full!");

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
			new_file->file_created.set();
			new_file->last_modified.set();
			this->last_modified.set();
			if (new_file != NULL)
			{
				new_files[new_size - 1] = new_file;
			}
			else
				throw file_name + " didn't created!";

			this->count = new_size;
			this->files = new_files;
			this->current_size += new_file->getFileSize();

			readWriteSpeed(new_file->getFileSize());

			std::cout << "File created -> " << new_file->file_name << std::endl;
		}
		else
			throw std::string("Files can't copied!");
	}

	void setFileContent(const std::string& file_name, const std::string& content) throw(std::string)
	{
		//1. eger fayl yoxdursa error at
		//2. eger fayl varsa ve disk doludursa error.
		if (!isExists(file_name))
			throw file_name + " isn't exist!";

		File* file = getFile(file_name);

		size_t new_size = content.length();

		size_t current_size = file->getFileSize();

		if (new_size > current_size)
			if (this->current_size + new_size - current_size >= capacity)
				throw std::string("HDD is full!");

		file->setFileSize(new_size);
		file->content = content;
		file->last_modified.set();
		this->last_modified.set();

		this->current_size = (this->current_size - current_size) + new_size;
		readWriteSpeed(new_size);
	}

	void deleteFileContent(const std::string& file_name) throw(std::string)
	{
		//1. eger fayl yoxdursa error at
		if (!isExists(file_name))
			throw file_name + " isn't exist!";

		File* file = getFile(file_name);

		this->current_size -= file->getFileSize();
		file->setFileSize(0);

		file->content = "";
		file->last_modified.set();
		this->last_modified.set();
	}

	void deleteFileByFileName(const std::string& file_name)
	{
		if (!isExists(file_name))
			throw file_name + " isn't exist";

		size_t new_size = this->count - 1;

		auto new_files = new File * [new_size];

		if (new_files != NULL)
		{
			size_t file_index = 0;
			for (size_t i = 0, j = 0; i < this->count; i++)
			{
				if (files[i]->file_name != file_name)
					new_files[j++] = files[i];
				else
					file_index = i;
			}

			delete files[file_index];
			delete[] files;
			
			files = new_files;
			this->count = new_size;
			this->last_modified.set();
		}
		else
			throw "Files can't copied!";
	}

	void updateFileName(const std::string& file_name, const std::string& new_file_name)
	{
		if (!isExists(file_name))
			throw file_name + " isn't exist";

		for (size_t i = 0; i < this->count; i++)
		{
			if (files[i]->file_name == file_name)
			{
				files[i]->file_name = new_file_name;
				files[i]->last_modified.set();
				this->last_modified.set();
				return;
			}
		}
	}

	void showAllFiles() const
	{
		for (size_t i = 0; i < this->count; i++)
		{
			std::cout << "######################################" << std::endl;
			this->files[i]->show();
			readWriteSpeed(this->files[i]->getFileSize());
		}
	}

	void showHDDInfo() const
	{
		std::cout << "Disk name: " << getDiskName() << std::endl;
		std::cout << "Model: " << getModel() << std::endl;
		std::cout << "Capacity: " << this->capacity << " bytes" << std::endl;
		std::cout << "Used: " << this->current_size << " bytes" << std::endl;
		std::cout << "Free: " << this->capacity - this->current_size << " bytes" << std::endl;

		std::cout << "Disk created: "; this->disk_created.show();
		std::cout << "Last modified: "; this->last_modified.show();
	}

	virtual ~Disc() = 0 {}
};

double Disc::capacity = 2097152; //bytes


class HDD : public Disc
{
public:

	HDD(const std::string& disk_name, const std::string& model) : Disc(disk_name, model) {}

	void readWriteSpeed(size_t bytes) const
	{
		Sleep(bytes * 10);
	}
};

class SSD : public Disc
{
public:
	SSD(const std::string& disk_name, const std::string& model) : Disc(disk_name, model) {}

	void readWriteSpeed(size_t bytes) const
	{
		Sleep(bytes);
	}
};


class Operation
{
public:
	Operation() = delete;

	static void controlPC();
};

void Operation::controlPC()
{
	HDD hdd("my_disk", "TOSHIBA");

	hdd.showHDDInfo();
	std::cout << "###########################" << std::endl;
	try
	{
		hdd.createFile("first_file.txt", "Hello world");
		hdd.createFile("account.txt", "username: test\npassword: test");
		hdd.createFile("notes.txt", "Some notes...");
	}
	catch (std::string ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}
	
	std::cout << std::endl;

	try
	{
		hdd.getFile("first_file.txt")->show();
		hdd.getFile("first_file2.txt")->show();
	}
	catch (std::string ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}

	std::cout << std::endl;

	hdd.showAllFiles();
	std::cout << std::endl;

	try
	{
		hdd.setFileContent("notes.txt", "Notes updated...");
		hdd.setFileContent("noted.txt", "new file");
	}
	catch (std::string ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}

	std::cout << std::endl;

	hdd.showAllFiles();
	std::cout << std::endl;

	try
	{
		hdd.deleteFileByFileName("account.txt");
		hdd.deleteFileByFileName("account.txt");
	}
	catch (std::string ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}

	std::cout << std::endl;

	hdd.showAllFiles();
	std::cout << std::endl;

	try
	{
		hdd.updateFileName("notes.txt", "important_notes.txt");
		hdd.updateFileName("notes.txt", "important_notes.txt");
	}
	catch (std::string ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}

	std::cout << std::endl;

	hdd.showAllFiles();
	std::cout << std::endl;

	try
	{
		hdd.deleteFileContent("important_notes.txt");
	}
	catch (std::string ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}

	std::cout << std::endl;

	hdd.showAllFiles();
	std::cout << std::endl;

	

	try
	{
		hdd.createFile("account.txt", "username: test\npassword: test1234");
	}
	catch (std::string ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}

	std::cout << std::endl;

	hdd.showAllFiles();
	std::cout << std::endl;

	try
	{
		hdd.hashFile("account.txt");
	}
	catch (std::string ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}
	std::cout << std::endl;

	hdd.showAllFiles();
	std::cout << std::endl;

	hdd.showHDDInfo();
	/*try
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
	}*/
};


void main()
{
	Operation::controlPC();
}