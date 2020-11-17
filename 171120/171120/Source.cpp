#include <iostream>
#include <assert.h>
#include <string>


class Test {
	char* data;
public:
	Test() :data(nullptr) {}

	Test(const char* data) { setData(data); }

	void setData(const char* data)
	{
		assert(data && "NULL ERROR");
		size_t length = strlen(data) + 1;

		this->data = new char[length];

		strcpy_s(this->data, length, data);

	}
};


class User
{
	std::string username;
	std::string password;
	std::string phone_number;

public:
	User() :username(""), password("") {}

	User(const std::string& user, const std::string& pass, const std::string & phone_number)
	{
		setUsername(user);
		setPassword(pass);
		setPhoneNumber(phone_number);
	}

	/*User(const User& user)
	{
		setUsername(user.getUsername());
		setPassword(user.getPhoneNumber());
		setPhoneNumber(user.password);
	}

	User & operator=(const User& user)
	{
		setUsername(user.getUsername());
		setPassword(user.getPhoneNumber());
		setPhoneNumber(user.password);

		return *this;
	}*/
	void setUsername(const std::string& user)
	{
		assert(!(user.empty()) && "Username is blank");
		this->username = user;
	}

	const std::string& getUsername() const
	{
		return username;
	}

	void setPhoneNumber(const std::string& phone_number)
	{
		assert(!(phone_number.empty()) && "Username is blank");
		this->phone_number = phone_number;
	}

	const std::string& getPhoneNumber() const
	{
		return phone_number;
	}

	void setPassword(const std::string& pass)
	{
		assert(!(pass.empty()) && "Username is blank");
		this->password = pass;
	}

	const std::string& getPassword() const
	{
		return password;
	}

	void show()
	{
		std::cout << "Username: " << getUsername() << std::endl;
		std::string stars(this->password.length(), '*');
		std::cout << "Password: " << stars << std::endl;
	}
};

class Database
{
	User** users;
	size_t user_count;

public:
	Database() : users(nullptr), user_count(0) {}

	Database(size_t user_count, User** users)
	{
		setUserCount(user_count);
		setUsers(users);
	}

	void setUserCount(size_t user_count)
	{
		assert(user_count && "User count must be greater than zero");
		this->user_count = user_count;
	}

	size_t getUserCount() const
	{
		return user_count;
	}

	void setUsers(User** users)
	{
		if (user_count)
		{
			this->users = new User * [user_count];

			for (size_t i = 0; i < user_count; i++)
			{
				this->users[i] = users[i];
			}
		}
	}

	User* getUserByUsername(std::string username)
	{
		for (size_t i = 0; i < user_count; i++)
		{
			if (users[i]->getUsername() == username)
			{
				return users[i];
			}
		}
		return nullptr;
	}

	bool sign_in(std::string username, std::string password)
	{
		assert(!username.empty()  && "Username is blank!");
		assert(!password.empty() && "Username is blank!");

		for (size_t i = 0; i < user_count; i++)
		{
			auto user = getUserByUsername(username);

			if (user)
			{
				if (user->getPassword() == password)
					return true;
			}
			return false;
		}
	}

	bool sign_up(const std::string username, const std::string password, const std::string phone_number)
	{
		assert(!username.empty() && "Username is blank!");
		assert(!password.empty() && "Username is blank!");

		auto user = getUserByUsername(username);

		if (!user)
		{
			size_t new_count = user_count + 1;
			auto new_users = new User * [new_count];

			if (new_users)
			{
				for (size_t i = 0; i < user_count; i++)
				{
					new_users[i] = users[i];
				}

				new_users[user_count] = new User(username, password, phone_number);


				setUserCount(new_count);
				users = new_users;

				return true;
			}
			
		}

		return false;
	}

	void showDB()
	{
		for (size_t i = 0; i < user_count; i++)
		{
			users[i]->show();
		}
	}

	~Database()
	{
		for (size_t i = 0; i < user_count; i++)
		{
			delete[] users[i];
		}
		delete[] users;
	}
};
void main()
{
	User *user1 = new User("test", "test", "+994454512154");
	User *user2 = new User("elgun", "elgun", "+9941245464");

	//user1->show();
	User** users = new User * [2]{ user1, user2 };
	Database db;

	db.setUserCount(2);
	db.setUsers(users);

	std::string username;
	std::string password;


	/*std::cout << "Login page" << std::endl;

	std::cout << "Username: ";
	std::cin >> username;


	std::cout << "Password: ";
	std::cin >> password;


	if (db.sign_in(username, password))
	{
		std::cout << "Logged in" << std::endl;
	}
	else
	{
		std::cout << "Wrong username or password!" << std::endl;
		}*/
	std::cout << "Register page" << std::endl;

	std::cout << "Username: ";
	std::cin >> username;


	std::cout << "Password: ";
	std::cin >> password;

	std::string phone_number;
	std::cout << "Phone number: ";
	std::cin >> phone_number;

	if (db.sign_up(username, password, phone_number))
	{
		std::cout << "Account created" << std::endl;
	}
	else
	{
		std::cout << "Username is taken" << std::endl;
	}


	db.showDB();

	std::cout << "Login page" << std::endl;

	std::cout << "Username: ";
	std::cin >> username;


	std::cout << "Password: ";
	std::cin >> password;


	if (db.sign_in(username, password))
	{
		std::cout << "Logged in" << std::endl;
	}
	else
	{
		std::cout << "Wrong username or password!" << std::endl;
	}
	/*std::string text = "Hello world";

	std::cout << text << std::endl;
	std::cout << text.length() << std::endl;
	std::cout << text.size() << std::endl;
	std::cout << text.max_size() << std::endl;
	std::cout << text.capacity() << std::endl;*/


	//std::string str(1, 'A');

	//std::cout << str << std::endl;


	//std::cout << "1.Capacity: " << str.capacity() << std::endl;

	//str.resize(10);

	//std::cout << str << std::endl;

	//std::cout << "2.Capacity: " << str.capacity() << std::endl;
	//
	//
	//str.shrink_to_fit(); // capacityni azaldir

	//std::cout << str << std::endl;

	//std::cout << "3.Capacity: " << str.capacity() << std::endl;

	//str.reserve(143); // capacityni artirir

	//std::cout << str << std::endl;
	//std::cout << "4.Capacity: " << str.capacity() << std::endl;

	/*size_t capacity = str.capacity();
	for (size_t i = 0; i < 150; i++)
	{
		str.reserve(i);
		if (capacity != str.capacity())
		{
			capacity = str.capacity();

			std::cout << str << std::endl;
			std::cout << i << ".Capacity: " << str.capacity() << std::endl;
		}
	}*/

	//std::string text = "Happy programmers day!";

	//std::cout << "Text: " << text << std::endl;
	//std::cout << "Capacity: " << text.capacity() << std::endl;

	//std::cout << "After clear" << std::endl;
	//text.clear();
	//std::cout << "Text: " << text << std::endl;
	//text.shrink_to_fit();
	//std::cout << "Capacity: " << text.capacity() << std::endl;

	//if (text.empty())
	//	std::cout << "No data\n";
	//else
	//	std::cout << "There is data\n";

	/*
	std::string text = "Hello babe";
	text += " , bye bye";

	std::cout << text << std::endl;

	std::string text2 = "Hi all";

	std::string text3 = "How are u?";

	std::string text4 = text2 + text3;

	std::cout << text4 << std::endl;*/

	//std::string text = "Happy programmer day!";
	//
	//for (size_t i = 1, length = text.length() + 1; i < length; i++)
	//{
	//	//std::cout << text[i] << std::endl;
	//	std::cout << text.at(i - 1);
	//}
	//std::cout << std::endl;

	/*std::cout << text << std::endl;
	text.front() = 'J';
	text.back() = '.';
	std::cout << text << std::endl;

	std::cout << text.front() << std::endl;
	std::cout << text.back() << std::endl;*/

	/*std::cout << text << std::endl;

	text.append(" Sept 13");

	std::cout << text << std::endl;


	text.insert(text.begin() + 5, 'A');

	std::cout << text << std::endl;
	std::cout << text.size() << std::endl;
	
	text.erase(5, 1);
	std::cout << text.size() << std::endl;
	std::cout << text << std::endl;

	text.replace(10, 1, "A");
	std::cout << text << std::endl;*/


	/*std::cout << text << std::endl;
	text.push_back('W');
	std::cout << text << std::endl;*/

	//std::string text1 = "Salam";
	//std::string text2 = "Salam";

	/*std::cout << std::boolalpha << (text1 == text2) << std::endl;

	text1.front() = 's';
	std::cout << std::boolalpha << (text1 == text2) << std::endl;
	text1.front() = 'S';

	std::cout << text1.compare(text2) << std::endl;*/

	/*std::cout << text1 << std::endl;
	text1.assign("Hello");

	std::cout << text1 << std::endl;*/

	//std::string text = "Happy programmers day!";
	//std::cout << text.find('z') << std::endl; // return value > size = tapilmayib
	//std::cout << text.find_first_of("programmers") << std::endl;

	//std::cout << text.find("programmers") << std::endl;

	
}