#pragma once
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#ifndef MYARRAY_H
#define MYARRAY_H


class MyArray {
public:
	MyArray();
	MyArray* operator[](int i);
	//int operator[](int i);
	explicit MyArray(int capacity);
	void SetData(int pos, int val);
	int GetData(int pos);
	void PushBack(int val);
	int GetLength();
	void PrintArray();
	~MyArray();
private:
	int mCapacity; //����һ�������ɶ��ٸ�Ԫ��
	int mSize; //��ǰ�ж��ٸ�Ԫ��
	int* pAdress; //ָ��洢���ݵĿռ�
};

#endif