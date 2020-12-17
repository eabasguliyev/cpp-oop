#include <iostream> // left showpos boolalpha
#include <iomanip> //setw
#include <sstream>

void main()
{
	//std::cout << "Hello world" << std::endl;
	//std::cout << std::showpos << 5 << std::endl;

	/*std::cout << std::boolalpha;
	std::cout << true << std::endl;

	std::cout << std::noboolalpha;
	std::cout << true << std::endl;*/

	//std::cout << "|" << std::setw(5) << std::left << 1 << "|" << std::endl;

	//std::stringstream os;

	//os << "12 15 17 Hello 19 World and Programmers\nToday is happy day" << std::endl;

	//os.str("Hello world and Programmers");

	//std::string data = os.str();
	//std::string data;

	/*while (1)
	{
		std::string tmp;

		os >> tmp;

		if (tmp == "")
			break;
		data.append(tmp);
		data.append(" ");
	}


	std::cout << data << std::endl;*/

	/*std::getline(os, data);

	std::cout << data << std::endl;

	std::getline(os, data);

	std::cout << data << std::endl;*/

	/*int data;

	os >> data;

	std::cout << data << std::endl;

	os >> data;

	std::cout << data << std::endl;

	os >> data;

	std::cout << data << std::endl;

	os >> data;

	std::cout << data << std::endl;

	os >> data;

	std::cout << data << std::endl;*/

	/*std::string data;
	while (1)
	{
		std::string tmp;

		os >> tmp;
		int a = 0;
		try
		{
			a = std::stoi(tmp);
		}
		catch (const std::exception&)
		{

		}

		if (tmp == "")
			break;

		std::cout << a << std::endl;
	}


	std::cout << data << std::endl;*/

	/*std::stringstream os;
	os << "Ramiz 21 Ismayil 23" << std::endl;

	std::string name1;
	int age1;
	std::string name2;
	int age2;

	os >> name1 >> age1 >> name2 >> age2;

	std::cout << "1) Name : " << name1 << " Age : " << age1 << std::endl;
	std::cout << "2) Name : " << name2 << " Age : " << age2 << std::endl;*/


	/*std::stringstream os;


	os << "HelloHelloHelloHelloHelloHelloHelloHelloHelloHello" << std::endl;

	std::string data;

	os >> data;

	std::cout << data << std::endl;*/

	/*std::stringstream os;


	os << "12 22 32 42 52" << std::endl;

	int s[5];

	for (size_t i = 0; i < 5; i++)
	{
		os >> s[i];

		std::cout << s[i] << " ";
	}std::cout << std::endl;*/

	/*std::stringstream os;
	os << "Hello World,and Programmers" << std::endl;

	std::string value;*/

	/*os.seekg(5, std::ios::beg);

	os >> value;

	std::cout << value << std::endl;*/

	/*os.seekg(-12, std::ios::end);

	os >> value;

	std::cout << value << std::endl;*/

	/*std::stringstream os;

	os << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum." << std::endl;

	std::string message;
	while (!os.eof())
	{
		std::string tmp;
		os >> tmp;
		
		tmp.append(" ");

		message.append(tmp);
	}

	std::cout << message << std::endl;*/
	// ishlemir yeniden yoxla
	/*std::stringstream os;
	std::string value;

	for (size_t i = 0; i < 4; i++)
	{
		std::cin >> value;
		os << value;
	}

	while (!os.eof())
	{
		os >> value;
		std::cout << value << ' ';
	}std::cout << std::endl;*/ 
}