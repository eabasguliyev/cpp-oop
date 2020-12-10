#include <iostream>
#include <Windows.h>

//Stack unwinding ( achilmaq )

void func(bool x)
{
	char* pleak = new char[1024]; // stack unwinding address lost. // memory leak
	std::string a = "Hello world";

	if (x)
		throw "Booom!";

	delete[] pleak;
	std::cout << "Pleak deleted!" << std::endl;
}


int& last()
{
	std::cout << "Start last" << std::endl;

	std::cout << "Last throw exception" << std::endl;

	//throw "Hey error in last";

	int x = 10;
	std::cout << "End last" << std::endl;
	return x;
}
int& third()
{
	std::cout << "Start third" << std::endl;
	return last();
	std::cout << "End Third" << std::endl;
}
int& second()
{
	std::cout << "Start second" << std::endl;
	try
	{
		return third();
	}
	catch (double ex)
	{
		std::cout << "Second Error: " << ex << std::endl;
	}
	std::cout << "End Second" << std::endl;
}
int& first()
{
	std::cout << "Start first" << std::endl;
	try
	{
		return second();
	}
	catch (const char* ex)
	{
		std::cout << "First Error: " << ex << std::endl;
	}
	catch (double ex)
	{
		std::cout << "First Error : " << ex << std::endl;
	}

	std::cout << "End first" << std::endl;
}

/*
class Exception
{
protected:
	std::string text;
	std::string source;
	int line;
public:
	Exception(std::string text, std::string source, int line) :text(text), source(source), line(line){}

	const std::string& getMessage() const { return this->text; }

	void printMessage() const
	{
		int i = 0;

		while (i < 8)
		{
			std::cout << "########## Error info ##########" << std::endl;
			std::cout << "Error text: " << text << std::endl;
			std::cout << "Error source: " << source << std::endl;
			std::cout << "Error line: " << line << std::endl;
			Sleep(500);
			system("color 4");
			Sleep(500);
			system("color 7");
			system("CLS");
			i++;
		}
		
	}
};

class OutOfRangeException : public Exception
{
public:
	OutOfRangeException(std::string text, std::string source, int line) :Exception(text, source, line) {}
};

class InvalidArgumentException : public Exception
{
public:
	InvalidArgumentException(std::string text, std::string source, int line) :Exception(text, source, line) {}
};
template<typename T>
class Array
{
private:
	T* data;
	int size;
public:
	int getSIze() const
	{
		return size;
	}

	const T& getData() const
	{
		return data;
	}

	Array<T>& operator=(const Array<T>& other) = delete;
	Array(const Array<T>& other) = delete;

	//T& operator[](int index) throw (OutOfRangeException);
	T& operator[](int index)throw (OutOfRangeException)
	{
		if (index < 0 || index >= size)
			throw OutOfRangeException("Out of range exception", "Source.cpp", 124);

		return data[index];
	}

	Array(int size) throw (InvalidArgumentException)
	{
		if (size < 0 || size > 10000)
			throw InvalidArgumentException("Invalid argument exception: size must be between 0 and 10000",
				"Source.cpp", 133);

		this->size = size;
		this->data = new T[size]{};
	}

	~Array()
	{
		delete[] this->data;
		this->size = 0;
	}
};

*/

class Exception
{
	std::string message;

public:
	Exception(const std::string& message)
	{
		this->message = message;
	}

	std::string getMessage() const { return this->message; }
};
class DatabaseException : public Exception {
public:
	DatabaseException(const std::string& message) : Exception(message) {}
};
class InvalidArgumentException : public Exception {
public:

	InvalidArgumentException(const std::string& message) : Exception(message) {}
};

class UserValidation
{
public:
	static bool checkUsernameLength(const std::string& username)
	{
		return username.length() < 6;
	}

	static bool checkUsernameFirstChar(const std::string& username)
	{
		return islower(username.front());
	}

	static bool checkPasswordLength(const std::string& password)
	{
		return password.length() < 6;
	}

	static bool checkNameLength(const std::string& name)
	{
		return name.length() < 4;
	}
	static bool checkSurnameLength(const std::string& surname)
	{
		return surname.length() < 4;
	}
};

class User
{
	std::string username;
	std::string password;
	std::string name;
	std::string surname;

public:
	User() :username(""), password(""), name(""), surname("") {}

	User(const std::string& username, const std::string& password, const std::string& name,
		const std::string& surname)
	{
		setName(name);
		setSurname(surname);
		setUsername(username);
		setPassword(password);
	}

	User(const User& user)
	{
		setName(user.getName());
		setSurname(user.getSurname());
		setUsername(user.getUsername());
		setPassword(user.getPassword());
	}
	User& operator=(const User& user)
	{
		setName(user.getName());
		setSurname(user.getSurname());
		setUsername(user.getUsername());
		setPassword(user.getPassword());
		return *this;
	}

	User(User&& user)
	{
		setName(user.getName());
		setSurname(user.getSurname());
		setUsername(user.getUsername());
		setPassword(user.getPassword());

		user.setName("");
		user.setSurname("");
		user.setUsername("");
		user.setPassword("");
	}
	User& operator=(User&& user)
	{
		setName(user.getName());
		setSurname(user.getSurname());
		setUsername(user.getUsername());
		setPassword(user.getPassword());

		user.setName("");
		user.setSurname("");
		user.setUsername("");
		user.setPassword("");
		return *this;
	}
	void setUsername(const std::string& username)
	{
		this->username = username;
	}

	std::string getUsername() const { return this->username; }

	void setPassword(const std::string& password)
	{
		this->password = password;
	}

	std::string getPassword() const { return this->password; }

	void setName(const std::string& name)
	{
		this->name = name;
	}

	std::string getName() const { return this->name; }

	void setSurname(const std::string& surname)
	{
		this->surname = surname;
	}

	std::string getSurname() const { return this->surname; }

	void show() const {
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Surname: " << getSurname() << std::endl;
		std::cout << "Username: " << getUsername() << std::endl;
		std::cout << "Password: " << std::string(getPassword().length(), '*') << std::endl;
	}
};

class Database
{
	User** users;
	int user_count;

public:
	void addUser(const User& user) {
		size_t new_size = this->user_count + 1;
		auto new_users = new User * [new_size];

		if (new_users != NULL)
		{
			for (size_t i = 0; i < new_size - 1; i++)
			{
				*new_users[i] = *std::move(users[i]);
			}

			*new_users[new_size - 1] = user;
			setUserCount(new_size);
		}
	}
	User& getUserByUsername(const std::string& username) {
		User user;
		for (size_t i = 0; i < this->user_count; i++)
		{
			if (username == users[i]->getUsername())
			{
				user = *users[i];
				break;
			}
		}

		return user;
	}
	void updateUserByUsername(User& old_user, const User& new_user) {
		if (true)
		{
			old_user = new_user;
		}
	}

	void setUserCount(const size_t count)
	{
		this->user_count = count;
	}

	size_t getUserCount() const { return this->user_count; }
};

class Registration
{
	Database _db;

public:
	Registration(const Database& db)
	{
		this->_db = db;
	}

	void signIn(const std::string& username, const std::string& password)
	{
		// eger bu username'de user yoxdursa exception atsin
		// eger username varsa password yanlishdira exception atsin

		User user = _db.getUserByUsername(username);

		if (user.getUsername() == "")
			throw DatabaseException("There is no account associated this username");
		else if (user.getPassword() != password)
			throw DatabaseException("Your password is wrong!");
	}

	void signUp(const std::string& username, const std::string& password,
		const std::string& name, const std::string& surname)
	{

		//Eger istifadechi varsa hemen usernamede throw DatabaseException
		// //Eger username xarakter sayi 6 dan kichikdirse InvalidArgumentException
		// //Eger username ilk herf kichikdirse InvalidArgumentException
		// //Eger password xarakter sayi 6 dan kichikdirse InvalidArgumentException
		// //Eger name xarakter sayi 4 dan kichikdirse InvalidArgumentException
		// //Eger surname xarakter sayi 4 dan kichikdirse InvalidArgumentException
		User user = _db.getUserByUsername(username);

		if (user.getUsername() != "")
			throw DatabaseException("This username is taken!");

		if (UserValidation::checkUsernameLength(username))
			throw InvalidArgumentException("Username character length must be greater than six");

	}
};

class SystemControl
{
public:
	static void Control()
	{
		//database yarat emeliyyatlar ele

	}
};
void main()
{

	//SystemControl::Control();

	//User user("test", "1234", "test", "test");

	//user.show();
	/*try
	{
		Array<int> obj(10);
		std::cout << obj[-5] << std::endl;
	}
	catch (const Exception& ex)
	{
		//std::cout << ex.getMessage() << std::endl;
		ex.printMessage();
	}*/
	/*catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}*/
	/*catch (const OutOfRangeException& ex)
	{
		std::cout << ex.getMessage() << std::endl;
	}
	catch (const InvalidArgumentException& ex)
	{
		std::cout << ex.getMessage() << std::endl;
	}*/
	/*std::cout << "Main start" << std::endl;
	try
	{
		std::cout << "Data: " << first() << std::endl;
	}
	catch (double ex)
	{
		std::cout << "Main Error: " << ex << std::endl;
	}

	std::cout << "End main" << std::endl;*/
	/*try
	{
		func(true);
	}
	catch (const char* ex)
	{
		std::cout << "Error: " << ex << std::endl;
	}*/
}