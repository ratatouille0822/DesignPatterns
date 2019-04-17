#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

//开闭原则： 对扩展开放，对修改关闭，增加功能通过增加代码来实现，而不是去修改代码

//例： 计算器： 增加功能通过增加代码实现

class AbstractCalculator
{
public:
	virtual int getResult() = 0;
	virtual void setOperand(int a, int b) = 0;
};

class PlusCalculator : public AbstractCalculator
{
public:
	void setOperand(int a, int b)
	{
		this->a = a;
		this->b = b;

	}
	virtual int getResult()
	{
		return this->a + this->b;
	}
private:
	int a;
	int b;
};

class MinusCalculator : public AbstractCalculator
{
public:
	void setOperand(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual int getResult()
	{
		return this->a - this->b;
	}
private:
	int a;
	int b;
};

class MultiplyCalculator : public AbstractCalculator
{
public:
	void setOperand(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual int getResult()
	{
		return this->a * this->b;
	}
private:
	int a;
	int b;
};

class DevideCalculator : public AbstractCalculator
{
public:
	void setOperand(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual int getResult()
	{
		return this->a / this->b;
	}
private:
	int a;
	int b;
};

void test01()
{
	//实现加法：
	AbstractCalculator* calculator = new PlusCalculator;
	calculator->setOperand(10, 20);
	int result = calculator->getResult();
	delete calculator;

	//若实现其他方法，需要重新new对象；

	cout << result << endl;
}

int main()
{
	test01();
    std::cout << "Hello World!\n"; 
}

