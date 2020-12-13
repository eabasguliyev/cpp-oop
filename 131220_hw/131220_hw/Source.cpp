//#include <iostream>
////#include <Windows.h>
////#include "Foo.h"
////#include "Qoo.h"
//
//namespace std
//{
//	void myBestMethod()
//	{
//		std::cout << "I am additional method in standart namespace\n";
//	}
//}
//using namespace std;
////Namespaces
////using namespace Figures;
//
//namespace Figures {
//
//	void doSomething()
//	{
//		std::cout << "I do something" << std::endl;
//	}
//	class Figure
//	{
//
//	};
//
//	class Rectangle : public Figure
//	{
//
//	};
//
//	class Circle : public Figure
//	{
//
//	};
//}
//
//// Global namespace
//// Nested Namespace
//
//namespace Database
//{
//	namespace DatabaseConnection
//	{
//		typedef class TcpClienResponse
//		{
//		public:
//			static void connect()
//			{
//				std::cout << "I connected to DB successfully" << std::endl;
//			}
//		} TCR;
//	}
//}
//
//namespace DC = Database::DatabaseConnection; // alias
//
//#define start {
//#define end }
//
////namespace Database::DatabaseConnection // nested namespace extension stuff c++17
////{
////
////}
//
//using namespace Figures;
//void main()
//{
//	//start
//		// problem 1
//		//Figures::Rectangle r;
//		//Figures::Circle c;
//		//Rectangle r;
//		// problem 2
//		//int cout = 1;s
//
//	//Foo::doSomething();
//		//Qoo::doSomething();
//
//	//std::myBestMethod();
//		//myBestMethod();
//	//Database::DatabaseConnection::connect();
//	//DC::connect();
//		//Database::DatabaseConnection::TcpClienResponse::connect();
//	//DC::TcpClienResponse::connect();
////	DC::TCR::connect();
////end
//
//	//Figures::doSomething();
//
//	//Rectangle r;
//	//doSomething();
//}

#include <iostream>
#include "ECommerce.h"
// E-Bazar-App



void main()
{
	ECommerce::start();
}