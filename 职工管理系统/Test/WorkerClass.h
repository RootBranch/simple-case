#pragma once
#include <iostream>
#include <string>

class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;


	//��ø�λ����
	virtual std::string getDepName() = 0;


	int m_Id;
	std::string m_Name;
	int m_DeptId;
};