#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class HungrySingleton
{
public:
	static HungrySingleton* instance()
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
	static HungrySingleton* singleton_pointer;
	static int cnt ;

	HungrySingleton()
	{
		cout << "HungrySingleton has been constructed" << endl;
	}
	
	HungrySingleton(const HungrySingleton& singleton_instance)
	{

	}
	
	~HungrySingleton()
	{

	}
};

HungrySingleton* HungrySingleton::singleton_pointer = new HungrySingleton;
int HungrySingleton::cnt = 0;

//Test 01 是饿汉式单例；
void test01()
{
	HungrySingleton* singleton_printer = HungrySingleton::instance();
	singleton_printer->print_texts("hello1");
	singleton_printer->get_cnt();
	singleton_printer->print_texts("hello2");
	singleton_printer->get_cnt();

}

class LazySingleton
{
public:
	static LazySingleton* GetInstance()
	{
		lazy_singleton_instance = new LazySingleton;
		return lazy_singleton_instance;
	}
private:
	LazySingleton()
	{
		cout << "A lazy singleton has been constructed" << endl;
	}
	LazySingleton(const LazySingleton& lazy_singleton_instance)
	{

	}
	static LazySingleton* lazy_singleton_instance;
};

LazySingleton* LazySingleton::lazy_singleton_instance = NULL;

//测试懒汉模式：
void test02()
{
	LazySingleton* p1 = LazySingleton::GetInstance();

}


int main()
{
    std::cout << "-------------->Main() started here<----------------\n"; 
	test01();
	test02();
}

