#include <iostream>
#include <string>
#include "manager.h"
#include "WorkerClass.h"


//��ʼ����Ϣ
Manager::Manager(int id, std::string name, int dId)
{
	this->m_DeptId = dId;
	this->m_Name = name;
	this->m_Id = id;
}

//��ʾ������Ϣ
void Manager::showInfo()
{
	std::cout << "ְ����ţ� " << this->m_Id
		<< "\tְ��������	" << this->m_Name
		<< "\t��λ��	����ϰ������" << this->m_DeptId << std::endl;

}


//��ø�λ����
std::string Manager::getDepName()
{
	return std::string ("����");
}
