#include <iostream>

using namespace std;

class AbstractCar
{
public:
	virtual void run() = 0;
};

class VWCars : public AbstractCar
{
	virtual void run()
	{
		cout << "This is VW car" << endl;
	}

};

class ToyotaCars:public AbstractCar
{
	virtual void run()
	{
		cout << "This is Toyota car" << endl;
	}
};

class Person
{
public:
	void set_car(AbstractCar* car)
	{
		this->cars = car;
	}
	void drive()
	{
		this->cars->run();
	}
	AbstractCar* cars;
	~Person()
	{
		
	}

};
int main()
{
	Person person;
	person.set_car(new ToyotaCars);
	person.drive();
	system("pause");
	return 0;
}













