#pragma once
#include <iostream>
#include <string>
#include "WorkerClass.h"


class Manager :public Worker
{
public:

	Manager(int id, std::string name, int dId);

	//显示个人信息
	void showInfo();


	//获得岗位名称
	std::string getDepName();

};
