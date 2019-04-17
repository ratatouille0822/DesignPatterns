#include "pch.h"
#include "MyArray.h"
#include <iostream>

int main()
{
	MyArray my_array_instance_1;
	for (int i = 0; i < 10; i++)
	{
		my_array_instance_1.PushBack(i);
	}
	my_array_instance_1.PrintArray();
	
	MyArray my_array_instance_2[5];
	int a[3];
	MyArray b[5];
	a[0] = 1;

	//b[0] = 0;


	for (int i = 1; i <= 5; i++)
	{
		my_array_instance_2->PushBack(i + 100);
	}

	my_array_instance_2->PrintArray();
	my_array_instance_2->GetData(1);
    std::cout << "Hello World!\n"; 
	return 0;
}
