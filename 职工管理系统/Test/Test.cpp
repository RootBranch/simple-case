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
		std::cout << "���������ѡ��" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0:      //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1:		//����ְ��
			wm.Add_Emp();
			break;
		case 2:		//��ʾְ��
			wm.show_Emp();
			break;
		case 3:		//ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:		//�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:		//����ְ��
			wm.Find_Emp();
			break;
		case 6:		//����ְ��
			wm.Sort_Emp();
			break;
		case 7:		//����ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls");	//����
			break;
		}
	}
	return 0;
}