#pragma once
#include <iostream>
#include "WorkerClass.h"

class Employee :public Worker
{
public:

	Employee(int id, std::string name, int dId);

	//显示个人信息
	 void showInfo();


	//获得岗位名称
	 std::string getDepName();

};