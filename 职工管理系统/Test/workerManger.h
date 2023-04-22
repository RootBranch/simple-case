#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "WorkerClass.h"
#include "employee.h"
#include "manager.h"
#include "boos.h"
#define FILENAME "empFile.txt"


class workerManger
{
public:

	workerManger();

	//菜单
	void showMenu();

	//显示职工信息
	void show_Emp();

	//退出
	void exitSystem();


	//添加职工
	void Add_Emp();



	//记录职工人数
	int m_EmpNum;


	//职工数组指针
	Worker** m_EmpArray;


	//写入文件
	void save();


	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中的人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在，如果存在返回所在位置，不存在返回-1，
	int IsExist(int id);

	//修改
	void Mod_Emp();


	//查找
	void Find_Emp();


	//排序	
	void Sort_Emp();



	//清理文件
	void Clean_File();



	~workerManger();



};