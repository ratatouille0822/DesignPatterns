#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Singleton
{
public:
	static Singleton* instance()
	{
		return singleton_pointer;
	}
	void print_texts(string text)
	{
		cout << text << endl;
		cnt++;
	}
	void get_cnt()
	{
		cout << cnt << endl;
	}

private:
	static Singleton* singleton_pointer;
	static int cnt ;

	Singleton()
	{

	}
	
	Singleton(const Singleton& singleton_instance)
	{

	}
	
	~Singleton()
	{

	}
};

Singleton* Singleton::singleton_pointer = new Singleton;
int Singleton::cnt = 0;

void test01()
{
	Singleton* singleton_printer = Singleton::instance();
	singleton_printer->print_texts("hello1");
	singleton_printer->get_cnt();
	singleton_printer->print_texts("hello2");
	singleton_printer->get_cnt();

}

int main()
{
	test01();
    std::cout << "Hello World!\n"; 
}

