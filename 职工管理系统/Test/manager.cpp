#include <iostream>
#include <string>
#include "manager.h"
#include "WorkerClass.h"


//初始化信息
Manager::Manager(int id, std::string name, int dId)
{
	this->m_DeptId = dId;
	this->m_Name = name;
	this->m_Id = id;
}

//显示个人信息
void Manager::showInfo()
{
	std::cout << "职工编号： " << this->m_Id
		<< "\t职工姓名：	" << this->m_Name
		<< "\t岗位：	完成老板的任务" << this->m_DeptId << std::endl;

}


//获得岗位名称
std::string Manager::getDepName()
{
	return std::string ("经理");
}
