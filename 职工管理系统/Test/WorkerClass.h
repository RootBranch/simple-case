#pragma once
#include <iostream>
#include <string>

class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;


	//获得岗位名称
	virtual std::string getDepName() = 0;


	int m_Id;
	std::string m_Name;
	int m_DeptId;
};