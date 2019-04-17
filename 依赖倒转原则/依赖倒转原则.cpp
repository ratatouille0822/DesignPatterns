#include "pch.h"
#include <iostream>
#include <string>

#define 这是一段有问题的代码


using namespace std;

#ifndef 这是一段有问题的代码
/* 这段代码的问题：
	1. BankWorker 类的功能过多，不符合单一功能原则 -----> 将被拆分；
	2. 共有三个层，客户端依赖中间层，中间层依赖底层（Bankworker类） ------> 重新规划结构；
 */
class BankWorker
{
public:
	void DepositeService()
	{
		cout << "The bank worker did deposite business " << endl;
	}
	void WithdrawService()
	{
		cout << "The bank worker did withdrwa business" << endl;
	}
};
// 中间层：面向客户端和底层，向客户端提供业务和员工的接口：

void DoDepositeBussiness(BankWorker* bank_worker)
{
	bank_worker->DepositeService();
}

void DoWithdrawBussiness(BankWorker* bank_worker)
{
	bank_worker->WithdrawService();
}

// 客户端：
void test01()
{
	BankWorker* liu_bei = new BankWorker;
	DoDepositeBussiness(liu_bei);
	DoWithdrawBussiness(liu_bei);
	delete liu_bei;

}
#endif

#ifdef 这是一段有问题的代码
/*
	修改后的代码：

	加入中间抽象层，一切业务从中间抽象层接口；
	将原本BankWorker类的业务按照单一功能拆分，方便以后添加新功能，复合单一功能原则；

*/
class AbstractBankWorker
{
public:
	virtual void Service() = 0;
};

class DepositeService : public AbstractBankWorker
{
	virtual void Service()
	{
		cout << "The bank worker did deposite business " << endl;
	}
};


class WithdrawService : public AbstractBankWorker
{
	virtual void Service()
	{
		cout << "The bank worker did deposite business " << endl;
	}
};

// 中间层：

void ProvideService(AbstractBankWorker* abstract_bank_worker)
{
	abstract_bank_worker->Service();
}

// 调用：
void test02()
{
	AbstractBankWorker* worker = new WithdrawService();
	ProvideService(worker);
	delete worker;

	AbstractBankWorker* another_worker = new DepositeService();
	ProvideService(another_worker);
	delete another_worker;
}
#endif
int main()
{
	//test01();
	test02();
    std::cout << "Hello World!\n"; 
	return 0;
}




















