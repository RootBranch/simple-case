#pragma once
#include <iostream>
#include <string>
#include "WorkerClass.h"


class Boos :public Worker
{
public:

	Boos(int id, std::string name, int dId);

	//��ʾ������Ϣ
	void showInfo();


	//��ø�λ����
	std::string getDepName();

};
