#include <iostream>
#include "workerManger.h"
#include "employee.h"
#include "boos.h"
#include "manager.h"
#include "WorkerClass.h"


int main()
{
	int choice;
	while (true)
	{
		workerManger wm;
		wm.showMenu();
		std::cout << "请输入你的选择" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0:      //退出系统
			wm.exitSystem();
			break;
		case 1:		//增加职工
			wm.Add_Emp();
			break;
		case 2:		//显示职工
			wm.show_Emp();
			break;
		case 3:		//删除职工
			wm.Del_Emp();
			break;
		case 4:		//修改职工
			wm.Mod_Emp();
			break;
		case 5:		//查找职工
			wm.Find_Emp();
			break;
		case 6:		//排序职工
			wm.Sort_Emp();
			break;
		case 7:		//清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");	//清屏
			break;
		}
	}
	return 0;
}