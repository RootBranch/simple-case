#include <iostream>
#include <string>
#include "boos.h"
#include "WorkerClass.h"



//��ʼ����Ϣ
Boos::Boos(int id, std::string name, int dId)
{
	this->m_DeptId = dId;
	this->m_Name = name;
	this->m_Id = id;
}

//��ʾ������Ϣ
void Boos::showInfo()
{
	std::cout << "ְ����ţ� " << this->m_Id
		<< "\tְ��������	" << this->m_Name
		<< "\t��λ��	�·�����" << this->m_DeptId << std::endl;

}


//��ø�λ����
std::string Boos::getDepName()
{
	return std::string("�ϰ�");
}
