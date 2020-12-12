#include <iostream>
#include <time.h>
#include <string>


std::string getDate();
size_t generateHash(const std::string&);

class Exception
{
	std::string message;
	std::string source;
	std::string error_create_time;
	size_t code_line;
public:
	Exception(const std::string& message, const std::string & source, const size_t & code_line)
	{
		this->message = message;
		this->source = source;
		this->code_line = code_line;
		this->error_create_time = getDate();
	}

	std::string getMessage() const { return this->message; }

	void echo() const
	{
		std::cout << "Error create time: " << this->error_create_time << std::endl;
		std::cout << "Source: " << this->source << std::endl;
		std::cout << "Code line: " << this->code_line << std::endl;
		std::cout << "Error: " << this->message << std::endl;
	}
};
class DatabaseException : public Exception {
public:
	DatabaseException(const std::string& message, const std::string& source, const size_t& code_line) : Exception(message, source, code_line) {}
};
class InvalidArgumentException : public Exception {
public:

	InvalidArgumentException(const std::string& message, const std::string& source, const size_t& code_line) : Exception(message, source, code_line) {}
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
	size_t id;
	std::string username;
	std::string password;
	std::string name;
	std::string surname;
	std::string registration_date;
public:
	static size_t current_id;
	User() :username(""), password(""), name(""), surname(""), registration_date("") {}

	User(const std::string& username, const std::string& password, const std::string& name,
		const std::string& surname)
	{
		setName(name);
		setSurname(surname);
		setUsername(username);
		setPassword(password);
		setRegistrationDate(getDate());
		setUserID(++current_id);
	}

	User(const User& user)
	{
		setUserID(user.getUserID());
		setName(user.getName());
		setSurname(user.getSurname());
		setRegistrationDate(user.getRegistrationDate());
		setUsername(user.getUsername());
		setPassword(user.getPassword());
	}
	User& operator=(const User& user)
	{
		setUserID(user.getUserID());
		setName(user.getName());
		setSurname(user.getSurname());
		setRegistrationDate(user.getRegistrationDate());
		setUsername(user.getUsername());
		setPassword(user.getPassword());
		return *this;
	}

	User(User&& user)
	{
		setUserID(user.getUserID());
		setName(user.getName());
		setSurname(user.getSurname());
		setRegistrationDate(user.getRegistrationDate());
		setUsername(user.getUsername());
		setPassword(user.getPassword());

		user.setName("");
		user.setSurname("");
		user.setUsername("");
		user.setPassword("");
	}
	User& operator=(User&& user)
	{
		setUserID(user.getUserID());
		setName(user.getName());
		setSurname(user.getSurname());
		setRegistrationDate(user.getRegistrationDate());
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

	std::string getRegistrationDate() const { return this->registration_date; }

	size_t getUserID() const { return this->id; }

	void setUserID(const size_t& id)
	{
		this->id = id;
	}

	void setRegistrationDate(const std::string& date)
	{
		this->registration_date = date;
	}

	void show() const {
		if (this == NULL)
			throw DatabaseException("There is no account!", "Source.cpp", 190);

		std::cout << "User id: " << getUserID() << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Surname: " << getSurname() << std::endl;
		std::cout << "Registration date: " << getRegistrationDate() << std::endl;
		std::cout << "Username: " << getUsername() << std::endl;
		std::cout << "Password: " << std::string(getPassword().length(), '*') << std::endl;
	}
};

size_t User::current_id = NULL;

class Database
{
	User** users;
	int user_count;

public:

	Database() :users(NULL), user_count(0) {}

	void addUser(const User& user) {
		size_t new_size = this->user_count + 1;
		auto new_users = new User * [new_size];

		if (new_users != NULL)
		{
			for (size_t i = 0; i < new_size - 1; i++)
			{
				new_users[i] = users[i];
			}
			
			User new_user = user;

			new_user.setPassword(std::to_string(generateHash(new_user.getPassword())));
			new_users[new_size - 1] = new User(new_user);
			this->users = new_users;
			setUserCount(new_size);
		}
	}
	User* getUserByUsername(const std::string& username) {
		User *user = NULL;
		for (size_t i = 0; i < this->user_count; i++)
		{
			if (username == users[i]->getUsername())
			{
				user = users[i];
				break;
			}
		}

		return user;
	}
	void updateUserByUsername(User& old_user, const User& new_user) {
		User* user = getUserByUsername(new_user.getUsername());

		if (user != NULL)
			throw DatabaseException("This username is taken!", "Source.cpp", 248);

		if (UserValidation::checkUsernameLength(new_user.getUsername()))
			throw InvalidArgumentException("Username length must be greater than six", "Source.cpp", 251);

		if (UserValidation::checkUsernameFirstChar(new_user.getUsername()))
			throw InvalidArgumentException("Username first caracter must be uppercase!", "Source.cpp", 254);

		if (UserValidation::checkPasswordLength(new_user.getPassword()))
			throw InvalidArgumentException("Password length must be greater than six", "Source.cpp", 257);

		if (UserValidation::checkNameLength(new_user.getName()))
			throw InvalidArgumentException("Name length must be greater than four", "Source.cpp", 260);

		if (UserValidation::checkSurnameLength(new_user.getSurname()))
			throw InvalidArgumentException("Surname length must be greater than four", "Source.cpp", 263);

		if (true)
		{
			old_user = new_user;
		}
	}
	void setUserCount(const size_t count)
	{
		this->user_count = count;
	}

	void deleteUserByID(const int& id)
	{
		if (this->user_count == 0)
			throw DatabaseException("There is no account!", "Source.cpp", 267);

		size_t new_size = this->user_count - 1;

		auto new_users = new User*[new_size];

		if (new_users != NULL)
		{
			int user_id = -1;

			for (size_t i = 0, j = 0; i < this->user_count; i++)
			{
				if (id != this->users[i]->getUserID())
				{
					new_users[j++] = this->users[i];
				}
				else
					user_id = i;
			}

			if (user_id != -1)
			{
				delete this->users[user_id];
				delete[] this->users;
				this->users = new_users;
				setUserCount(new_size);
			}
			else
				delete[] new_users;
		}
		
	}

	size_t getUserCount() const { return this->user_count; }
};

class Registration
{
public:

	Database _db;

	Registration(const Database& db)
	{
		this->_db = db;
	}

	bool signIn(const std::string& username, const std::string& password)
	{
		// eger bu username'de user yoxdursa exception atsin
		// eger username varsa password yanlishdira exception atsin

		User *user = this->_db.getUserByUsername(username);

		if (user == NULL)
			throw DatabaseException("There is no account associated this username", "Source.cpp", 322);
		else if (user->getPassword() != std::to_string(generateHash(password)))
			throw DatabaseException("Your password is wrong!", "Source.cpp", 324);

		return true;
	}

	bool signUp(const std::string& username, const std::string& password,
		const std::string& name, const std::string& surname)
	{
		User* user = _db.getUserByUsername(username);

		if (user != NULL)
			throw DatabaseException("This username is taken!", "Source.cpp", 335);

		if (UserValidation::checkUsernameLength(username))
			throw InvalidArgumentException("Username length must be greater than six", "Source.cpp", 338);

		if (UserValidation::checkUsernameFirstChar(username))
			throw InvalidArgumentException("Username first caracter must be uppercase!", "Source.cpp", 341);

		if (UserValidation::checkPasswordLength(password))
			throw InvalidArgumentException("Password length must be greater than six", "Source.cpp", 344);

		if(UserValidation::checkNameLength(name))
			throw InvalidArgumentException("Name length must be greater than four", "Source.cpp", 347);

		if (UserValidation::checkSurnameLength(surname))
			throw InvalidArgumentException("Surname length must be greater than four", "Source.cpp", 350);

		this->_db.addUser(User(username, password, name, surname));
			
		return true;
	}

	bool deleteAccount(const std::string & username)
	{
		User* user = _db.getUserByUsername(username);

		if (user == NULL)
			throw DatabaseException(std::string("There is no account associated this username: " + username), "Source.cpp", 362);

		try
		{
			this->_db.deleteUserByID(user->getUserID());
		}
		catch (const Exception& ex)
		{
			//std::cout << "Error: " << ex.getMessage() << std::endl;
			ex.echo();
		}

		return true;
	}
};

class SystemControl
{
public:
	static void Control()
	{
		Database db;

		Registration reg(db);

		try
		{
			if (reg.signIn("test", "test"))
				std::cout << "Welcome!" << std::endl;
		}
		catch (const Exception & ex)
		{
			ex.echo();
			//std::cout << "Error: " << ex.getMessage() << std::endl;
		}
		//std::cin.get();
		
		std::cout << std::endl;

		try
		{
			if (reg.signUp("Alexrid", "alex123", "Alex", "Rider"))
				std::cout << "Your account created!" << std::endl;
		}
		catch (const Exception& ex)
		{
			//std::cout << "Error: " << ex.getMessage() << std::endl;
			ex.echo();
		}

		std::cout << std::endl;
		
		try
		{
			if (reg.signIn("Alexrid", "alex123"))
				std::cout << "Welcome!" << std::endl;
		}
		catch (const Exception& ex)
		{
			ex.echo();
			//std::cout << "Error: " << ex.getMessage() << std::endl;
		}


		try
		{
			reg._db.getUserByUsername("Alexrid")->show();
		}
		catch (const Exception& ex)
		{
			ex.echo();
		}

		try
		{
			if (reg.deleteAccount("Alexrid"))
				std::cout << "Account deleted!\n";
		}
		catch (const Exception& ex)
		{
			ex.echo();
			//std::cout << "Error: " << ex.getMessage() << std::endl;
		}

		try
		{
			reg._db.getUserByUsername("Alexrid")->show();
		}
		catch (const Exception& ex)
		{
			ex.echo();
		}
	}
};

void main()
{
	std::cout << getDate() << std::endl;
	SystemControl::Control();
}

std::string getDate()
{
	time_t now(time(0));
	tm new_time;
	localtime_s(&new_time, &now);
	return std::to_string(new_time.tm_mday) + '/' + std::to_string(new_time.tm_mon + 1) + '/' +
		std::to_string(new_time.tm_year + 1900) + ' ' + std::to_string(new_time.tm_hour) + ':' + std::to_string(new_time.tm_min);
}
size_t generateHash(const std::string& content)
{
	std::hash<std::string > hash;
	return hash(content);
}
