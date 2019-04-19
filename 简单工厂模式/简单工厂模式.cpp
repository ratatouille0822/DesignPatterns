#include "pch.h"
#include <iostream>

#include <string>

using namespace std;

// 工厂模式：用户不生成类的对象，而是由工厂生成，并返回给用户；
// 简单工厂模式只有一个工厂，工厂类集合了所有的功能，并不符合开闭原则和单一功能原则；

class AbstractFruit
{
public:
	virtual void EatFruit() = 0;
};

class Apple : public AbstractFruit
{
public:
	virtual void EatFruit()
	{
		cout << "Eat Apple" << endl;
	}
};


class Pear : public AbstractFruit
{
public:
	virtual void EatFruit()
	{
		cout << "Eat Pear" << endl;
	}
};


class Banana : public AbstractFruit
{
public:
	virtual void EatFruit()
	{
		cout << "Eat Banana" << endl;
	}
};

class FruitFactory
{
public:

	AbstractFruit* fruit;

	AbstractFruit* MakeFruit(string name)
	{
		if (name == "Apple")
		{
			this->fruit = new Apple;
		}
		else if (name == "Pear")
		{
			this->fruit = new Pear;
		}
		else if (name == "Banana")
		{
			this->fruit = new Banana;
		}

		return fruit;
	}


};

// 客户端： 生成实例：

void test01()
{
	FruitFactory fruit_factory;
	AbstractFruit* fruit = fruit_factory.MakeFruit("Apple");
	fruit->EatFruit();
	delete fruit;

	fruit_factory;
	fruit = fruit_factory.MakeFruit("Pear");
	fruit->EatFruit();
	delete fruit;

	fruit_factory;
	fruit = fruit_factory.MakeFruit("Banana");
	fruit->EatFruit();
	delete fruit;

}

int main()
{
	test01();
    std::cout << "Hello World!\n"; 
}


























