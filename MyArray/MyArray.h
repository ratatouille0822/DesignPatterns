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
	int mCapacity; //数组一共可容纳多少个元素
	int mSize; //当前有多少个元素
	int* pAdress; //指向存储数据的空间
};

#endif