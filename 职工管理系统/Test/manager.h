#pragma once
#include <iostream>
#include <string>
#include "WorkerClass.h"


class Manager :public Worker
{
public:

	Manager(int id, std::string name, int dId);

	//��ʾ������Ϣ
	void showInfo();


	//��ø�λ����
	std::string getDepName();

};
