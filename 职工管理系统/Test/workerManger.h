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

	//�˵�
	void showMenu();

	//��ʾְ����Ϣ
	void show_Emp();

	//�˳�
	void exitSystem();


	//���ְ��
	void Add_Emp();



	//��¼ְ������
	int m_EmpNum;


	//ְ������ָ��
	Worker** m_EmpArray;


	//д���ļ�
	void save();


	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ��е�����
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ�������ڷ�������λ�ã������ڷ���-1��
	int IsExist(int id);

	//�޸�
	void Mod_Emp();


	//����
	void Find_Emp();


	//����	
	void Sort_Emp();



	//�����ļ�
	void Clean_File();



	~workerManger();



};