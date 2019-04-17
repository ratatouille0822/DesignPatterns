#include "MyArray.h"

using namespace std;

MyArray* MyArray::operator[](int i)
{
	return &MyArray(i);
}

//int MyArray::operator[](int i)
//{
//
//}

MyArray::MyArray()
{
	this->mCapacity = 0;
	this->mSize = 0;
	this->pAdress = new int();
	*this->pAdress = 0;
}

MyArray::MyArray(int capacity)
{
	this->mCapacity = capacity;
	this->mSize = 0;
	this->pAdress = new int[capacity];
	memset(this->pAdress, 0, capacity);
}

void MyArray::SetData(int pos, int val)
{
	if (pAdress == NULL)
	{
		perror("EMPTY ARRAY!\n");
		return;
	}
	if (pos > this->mCapacity - 1 || pos < 0)
	{
		perror("INVALID POS! \n");
		return;
	}
	this->pAdress[pos] = val;
}

int MyArray::GetData(int pos)
{
	if (pos > this->mCapacity - 1 || pos < 0)
	{
		perror("INVALID POS! \n");
		return -1;
	}
	return this->pAdress[pos];
}

void MyArray::PushBack(int val)
{
	this->pAdress = (int*)realloc(this->pAdress, (this->mCapacity + 1)* sizeof(int));
	this->pAdress[mCapacity] = val;
	this->mSize++;
	this->mCapacity++;
}

int MyArray::GetLength()
{
	return this->mSize;
}

void MyArray::PrintArray()
{
	for (int i = 0; i < this->mSize; i++)
		cout << this->pAdress[i] << "->";
	cout << endl;
}
MyArray::~MyArray()
{
	delete[] this->pAdress;
}


	//MyArray();
	//explicit MyArray(int capacity);
	//void SetData(int pos, int val);
	//int GetData(int pos);
	//void PushBack(int val);
	//int GetLength();
	//~MyArray();
