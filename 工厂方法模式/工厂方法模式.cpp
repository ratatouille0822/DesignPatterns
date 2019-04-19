#include "pch.h"
#include <iostream>

#include <string>

using namespace std;

// 工厂模式：用户不生成类的对象，而是由工厂生成，并返回给用户；
// 工厂方法模式： 抽象出抽象工厂；
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

//将工厂抽象出来：

class AbstractFruitFactory
{
public:
	virtual	AbstractFruit* MakeFruit() = 0;
};

class AppleFactory : public AbstractFruitFactory
{
	virtual AbstractFruit* MakeFruit()
	{
		AbstractFruit* apple = new Apple;
		return apple;
	}
};


class PearFactory : public AbstractFruitFactory
{
	virtual AbstractFruit* MakeFruit()
	{
		AbstractFruit* pear = new Pear;
		return pear;
	}
};


class BananaFactory : public AbstractFruitFactory
{
	virtual AbstractFruit* MakeFruit()
	{
		AbstractFruit* banana = new Banana;
		return banana;
	}
};
// 客户端： 生成实例：

void test01()
{
	AbstractFruitFactory* fruit_factory  = new AppleFactory;
	AbstractFruit* fruit = fruit_factory->MakeFruit();
	fruit->EatFruit();
	delete fruit;
	delete fruit_factory;

	//fruit_factory;
	//fruit = fruit_factory.MakeFruit("Pear");
	//fruit->EatFruit();
	//delete fruit;

	//fruit_factory;
	//fruit = fruit_factory.MakeFruit("Banana");
	//fruit->EatFruit();
	//delete fruit;

}

int main()
{
	test01();
    std::cout << "Hello World!\n"; 
}
