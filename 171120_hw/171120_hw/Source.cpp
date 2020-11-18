#include <iostream>
#include <assert.h>
#include <random>
#include <time.h>
#include <Windows.h>
#include <conio.h>

enum ARROWKEYS {
	KEY_UP = 72, KEY_DOWN = 80
};

enum MAINMENU {
	LOGIN = 1, SIGNUP, CONFIRMATION, EXIT
};

#define RED 4
#define WHITE 7

template <class T>
class Pair
{
	T *key;
	T* value;

public:
	Pair() :key(nullptr), value(nullptr) {}

	Pair(const T & key, const T & value)
	{
		setKey(key);
		setValue(value);
	}

	/*Pair(const Pair& pair)
	{
		setKey(key);
		setValue(value);
	}

	Pair & operator=(const Pair& pair)
	{
		setKey(key);
		setValue(value);
		return *this;
	}*/

	/*Pair(Pair&& pair) noexcept
	{
		this->key = pair.key;
		this->value = pair.value;
		pair.key.clear();
		pair.value.clear();
	}

	Pair& operator=(Pair&& pair) noexcept
	{
		this->key = pair.key;
		this->value = pair.value;
		pair.key.clear();
		pair.value.clear();
		return *this;
	}*/

	void setKey(const T& key)
	{
		assert(!key.empty() && "Key is blank!");
		this->key = new T(key);
	}

	T getKey() const
	{
		return *this->key;
	}

	void setValue(const T& value)
	{
		//assert(!value.empty() && "Value is blank!");
		this->value = new T(value);
	}
	
	T*getValue() const
	{
		return this->value;
	}

	void show() const
	{
		std::cout << "{ \"" << *this->key << "\" : \"" << *this->value << "\" }" << std::endl;
	}
};

template<class T>
class Container
{
	size_t pair_count;
	Pair<T>** pairs;

public:
	Container() :pair_count(0), pairs(nullptr) {}

	Container(size_t pair_count,  Pair<T>** pairs)
	{
		setPairCount(pair_count);
		setPairs(pairs);
	}

	void setPairCount(size_t pair_count)
	{
		assert(pair_count && "Pair count must be greater than zero");
		this->pair_count = pair_count;
	}

	size_t getPairCount() const
	{
		return this->pair_count;
	}

	void setPairs(Pair<T>** pairs)
	{
		size_t pair_count = getPairCount();

		this->pairs = new Pair<T> * [pair_count];

		if (this->pairs)
		{
			for (size_t i = 0; i < pair_count; i++)
			{
				this->pairs[i] = new Pair<T>(*pairs[i]);
				//*this->pairs[i] = std::move(*pairs[i]);
			}
		}
	}

	Pair<T>** getPairs()const
	{
		return this->pairs;
	}

	void showPairs() const
	{
		if (this->pair_count)
		{
			for (size_t i = 0; i < this->pair_count; i++)
			{
				this->pairs[i]->show();
			}
		}
	}

	T *operator[](size_t index)
	{
		assert(index >= 0 && index < this->pair_count && "Index out of range!");
		return this->pairs[index]->getValue();
	}

	T * operator[](T& key)
	{
		if (this->pair_count)
		{
			for (size_t i = 0; i < this->pair_count; i++)
			{
				if (key == this->pairs[i]->getKey())
				{
					return this->pairs[i]->getValue();
				}
			}

			addPair(key);

			return this->pairs[this->pair_count - 1]->getValue();
		}
	}

	bool addPair(T& key)
	{
		size_t new_pair_count = getPairCount() + 1;
		auto new_pairs = new Pair<T> * [new_pair_count];

		if (new_pairs)
		{
			if (new_pair_count - 1)
			{
				for (size_t i = 0; i < new_pair_count - 1; i++)
				{
					new_pairs[i] = new Pair<T>(*pairs[i]);
				}
			}

			new_pairs[new_pair_count - 1] = new Pair<T>;
			new_pairs[new_pair_count - 1]->setKey(key);
			new_pairs[new_pair_count - 1]->setValue("");

			this->pairs = new_pairs;
			setPairCount(new_pair_count);
			return true;
		}
		return false;
	}
	~Container()
	{
		for (size_t i = 0; i < this->pair_count; i++)
		{
			delete this->pairs[i];
		}
		delete[] this->pairs;
	}
};


class User
{
	bool is_active;
	std::string email;
	std::string username;
	std::string password;
	std::string phone_number;

public:
	User() :is_active(false), email(""), username(""), password(""), phone_number("") {}

	User(const std::string & email, const std::string& user, const std::string& pass, const std::string& phone_number, bool is_active)
	{
		setMail(email);
		setUsername(user);
		setPassword(pass);
		setPhoneNumber(phone_number);
		setStatus(is_active);
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

	void setStatus(bool is_active)
	{
		this->is_active = is_active;
	}

	bool getStatus() const
	{
		return this->is_active;
	}

	void setMail(const std::string& email)
	{
		assert(!email.empty() && "Email is blank!");
		this->email = email;
	}

	std::string getMail() const
	{
		return this->email;
	}
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
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "Username: " << getUsername() << std::endl;
		std::string stars(this->password.length(), '*');
		std::cout << "Password: " << stars << std::endl;
		std::cout << "Phone number: " << getPhoneNumber() << std::endl;
		std::cout << "Account activated: " << std::boolalpha << getStatus() << std::endl;
	}
};

class Database
{
	User** users;
	size_t user_count;
	size_t confirmation_code;
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

	User* getUserByMail(std::string mail)
	{
		for (size_t i = 0; i < user_count; i++)
		{
			if (users[i]->getMail() == mail)
			{
				return users[i];
			}
		}
		return nullptr;
	}

	short sign_in(std::string username, std::string password)
	{
		assert(!username.empty() && "Username is blank!");
		assert(!password.empty() && "Username is blank!");

		for (size_t i = 0; i < user_count; i++)
		{
			auto user = getUserByUsername(username);

			if (user)
			{
				if (user->getPassword() == password)
				{
					if (user->getStatus())
						return 0;
					else
						return 1;
				}
				else
					return -1;
					
			}
			return -2;
		}
	}

	bool sign_up(const std::string email, const std::string username, const std::string password, const std::string phone_number)
	{
		assert(!email.empty() && "Email is blank!");
		assert(!username.empty() && "Username is blank!");
		assert(!password.empty() && "Password is blank!");
		assert(!phone_number.empty() && "Phone number is blank!");

		auto user = getUserByMail(email);
		auto user2 = getUserByUsername(username);

		if (!user && !user2)
		{
			size_t new_count = user_count + 1;
			auto new_users = new User * [new_count];

			if (new_users)
			{
				for (size_t i = 0; i < user_count; i++)
				{
					new_users[i] = users[i];
				}

				new_users[user_count] = new User(email, username, password, phone_number, false);
				
				setUserCount(new_count);
				users = new_users;

				return true;
			}

		}

		return false;
	}

	short activateAccount(std::string  email)
	{
		auto user = getUserByMail(email);
		
		if (user != nullptr)
		{
			if (sendConfirmCode(email))
			{
				short counter = 3;
				size_t code;

				do
				{
					std::cout << "Enter confirmation code: ";
					std::cin >> code;

					if (code == this->confirmation_code)
					{
						user->setStatus(true);
						return 0;
					}

					std::cout << std::endl;
					std::cout << "You can try " << --counter << " more!" << std::endl;
				} while (counter);

				//std::cout << "Confirmation code deleted. Please try later!" << std::endl;
				this->confirmation_code = 0;

				return 1;
			}
			return -1;
		}

		return -2;
	}

	bool sendConfirmCode(std::string user_mail)
	{
		if (true)
		{
			size_t code = rand() * rand();
			
			//sendToMail("user_mail");

			this->confirmation_code = code;

			return true;
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
			delete users[i];
		}
		delete[] users;
	}
};

struct ScreenOptions
{
	char** main_menu = nullptr;
	size_t mm_size = 0;
};
short MainMenu(ScreenOptions&);
void StartScreen();
void destroyData(char** options, size_t size);

void Pause()
{
	std::cout << "Press enter to continue";

	std::cin.ignore();
	std::cin.get();
}

void ConsoleScreenSettings()
{
	HANDLE hConsoleIN = GetStdHandle(STD_INPUT_HANDLE);

	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);


	HWND consoleWindow = GetConsoleWindow();
	MoveWindow(consoleWindow, 500, 58, 895, 518, TRUE);
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);


	CONSOLE_CURSOR_INFO cursor_info = {};

	cursor_info.bVisible = false;
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(hConsoleOUT, &cursor_info);
}

void main()
{
	srand(time(NULL));
	ConsoleScreenSettings();
	//std::cout << "---------------------------------------" << std::endl;
	User* user1 = new User("test@gmail.com", "test", "test", "+99455698754", false);
	User* user2 = new User("elgun@gmail.com", "elgun", "elgun", "+994245423154", true);
	User* user3 = new User("abil@gmail.com", "abil", "abil", "+9947874824654", true);

	User** users = new User * [3]{ user1, user2, user3 };

	Database db(3, users);

	ScreenOptions so;
	bool state = true;
	while (state)
	{
		system("CLS");
		short status = MainMenu(so);

		switch (status)
		{
		case LOGIN:
		{
			system("CLS");
			std::string username, password;
			std::cout << "Login page" << std::endl;

			std::cout << "Username: ";
			std::cin >> username;


			std::cout << "Password: ";
			std::cin >> password;

			short status = db.sign_in(username, password);

			if (status == 0)
			{
				std::cout << "Logged in" << std::endl;
				state = false;
			}
			else if(status == 1)
			{
				std::cout << "Account is deactive. Please confirm account via email." << std::endl;	
			}
			else if(status == -1)
				std::cout << "Wrong username or password!" << std::endl;
			else
				std::cout << "There is no account associated this username -> " << username << std::endl;
			Pause();
			continue;
		}
			break;
		case SIGNUP:
		{
			system("CLS");
			std::string username, password, email, phone_number;
			std::cout << "Register page" << std::endl;

			std::cout << "Email: ";
			std::cin >> email;


			std::cout << "Username: ";
			std::cin >> username;


			std::cout << "Password: ";
			std::cin >> password;

			std::cout << "Phone number: ";
			std::cin >> phone_number;

			if (db.sign_up(email, username, password, phone_number))
			{
				std::cout << "Account created" << std::endl;
				Pause();
			}
			else
			{
				std::cout << "Username is taken" << std::endl;
				Pause();
			}
		}
			break;
		case CONFIRMATION:
		{
			system("CLS");
			std::string email;

			std::cout << "Confirmation page" << std::endl;
			
			std::cout << "Enter email addres:";
			std::cin >> email;

			short status = db.activateAccount(email);
			if (status == 0)
			{
				std::cout << "Account activated. You can login now!" << std::endl;
				Pause();
				continue;
			}
			else if (status == -2)
			{
				std::cout << "There is no account associated this email -> " << email << std::endl;
			}
			else
				std::cout << "Please try later!" << std::endl;

			Pause();
		}
			break;
		case EXIT:
		{
			destroyData(so.main_menu, so.mm_size);
			system("CLS");
			return;
		}
			break;
		default:
			break;
		}
	}

	//db.showDB();


	/*Pair<std::string>* p1 = new Pair<std::string>("apple", "alma");
	Pair<std::string>* p2 = new Pair<std::string>("ball", "top");
	Pair<std::string>* p3 = new Pair<std::string>("task", "tapshiriq");

	p1->show();
	Pair<std::string>** pair_list = new Pair<std::string> * [3]{p1, p2, p3 };

	
	std::cout << "-----------------------" << std::endl;

	Container<std::string> container(3, pair_list);


	for (size_t i = 0; i < 3; i++)
	{
		delete pair_list[i];
		pair_list[i] = nullptr;
	}delete[] pair_list;
	pair_list = nullptr;
	//p1->show();
	std::string key = "home";
	std::cout << *container[key] << std::endl;
	*(container[key]) = "ev";
	std::cout << *container[key] << std::endl;

	key = "task";

	std::cout << *container[key] << std::endl;
	//std::cout << container[key] << std::endl;
	//container.showPairs();
	container.showPairs();

	//container[0]->show();
	*/
}

void PrintMenu(char** options, int size, int selected);

short MenuInputWithKeyboard(char** options, short size, short& selected)
{
	while (true)
	{
		system("CLS");
		PrintMenu(options, size, selected - 1);

		int key = _getch();

		if (key == 224)
		{
			switch (_getch())
			{
			case KEY_UP:
			{
				if (selected > 1)
					selected--;
			}
			break;
			case KEY_DOWN:
			{
				if (selected < size)
					selected++;
			}
			break;
			}
		}
		else if (key == 13)
		{
			return selected;
		}
	}
}

void destroyData(char** options, size_t size)
{
	if (options)
	{
		for (size_t i = 0; i < size; i++)
		{
			delete[] options[i];
		}
		delete[] options;
		options = nullptr;
	}
}

short MainMenu(ScreenOptions& so)
{

	system("CLS");
	static short selected = 1;
	if (so.mm_size == 0)
	{
		so.mm_size = 4;
		so.main_menu = new char* [so.mm_size];
		so.main_menu[0] = _strdup("Login");
		so.main_menu[1] = _strdup("Signup");
		so.main_menu[2] = _strdup("Confirm Account");
		so.main_menu[3] = _strdup("Exit");
	}

	return  MenuInputWithKeyboard(so.main_menu, so.mm_size, selected);
}


void PrintMenu(char** options, int size, int selected)
{
	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordinate = { 50, 10 };
	for (size_t i = 0; i < size; i++)
	{
		SetConsoleCursorPosition(hConsoleOUT, coordinate);
		if (i == selected)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			std::cout << i + 1 << ". " << options[i] << std::endl;;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else
		{
			std::cout << i + 1 << ". " << options[i] << std::endl;;
		}
		coordinate.Y++;
	}
}
