#pragma once
#include <iostream>
#include "WorkerClass.h"

class Employee :public Worker
{
public:

	Employee(int id, std::string name, int dId);

	//��ʾ������Ϣ
	 void showInfo();


	//��ø�λ����
	 std::string getDepName();

};