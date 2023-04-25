#include <iostream>
#include "MyArry.hpp"


void printIntArry(MyArry<int>p)
{
	for (int i = 0; i < p.getSize(); i++)
	{
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;
}

void test01()
{
	MyArry<int>p(5);
	for (int i = 0; i < 5; i++)
	{
		p.Push_Back(i);
	}
	printIntArry(p);

}

int main()
{
	test01();
	return 0;
}