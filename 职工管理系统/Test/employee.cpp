#include <iostream>
#include <string>
#include "employee.h"
#include "WorkerClass.h"



//��ʼ����Ϣ
Employee::Employee(int id,std::string name,int dId)
{
	this->m_DeptId = dId;
	this->m_Name = name;
	this->m_Id = id;
}

//��ʾ������Ϣ
void Employee::showInfo()
{
	std::cout << "ְ����ţ� " << this->m_Id
		<< "\tְ��������	" << this->m_Name
		<< "\t��λ��	��ɾ��������" << this->m_DeptId << std::endl;

}


//��ø�λ����
std::string Employee::getDepName()
{
	return std::string("Ա��");
}
