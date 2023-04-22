#include "workerManger.h"

workerManger::workerManger()
{
	//1.�ļ�������
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	if (!ifs.is_open())
	{
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������
		this->m_EmpArray = NULL;
		//��ʼ���ļ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.���ļ�����,���Ҽ�¼����
	int num = this->get_EmpNum();
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//���ļ��е����ݴ���������
	this->init_Emp();

}

//ͳ���ļ��е�����
int workerManger::get_EmpNum()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);//���ļ� ��

	int id;
	std::string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//ͳ����������
		num++;
	}
	return num;

}


void workerManger::exitSystem()
{
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0);
}


//�ͷſռ�
workerManger::~workerManger()
{
	if (this->m_EmpArray != NULL)
	{
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete m_EmpArray[i];
				}
			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}


void workerManger::showMenu()
{
	std::cout << "*******************************" << std::endl;
	std::cout << "***** ��ӭʹ��ְ������ϵͳ ****" << std::endl;
	std::cout << "******* 0.�˳�����ϵͳ ********" << std::endl;
	std::cout << "******* 1.����ְ����Ϣ ********" << std::endl;
	std::cout << "******* 2.��ʾְ����Ϣ ********" << std::endl;
	std::cout << "******* 3.ɾ����ְְ�� ********" << std::endl;
	std::cout << "******* 4.�޸�ְ����Ϣ ********" << std::endl;
	std::cout << "******* 5.����ְ����Ϣ ********" << std::endl;
	std::cout << "******* 6.���ձ������ ********" << std::endl;
	std::cout << "******* 7.��������ĵ� ********" << std::endl;
	std::cout << "*******************************" << std::endl;
	std::cout << std::endl;
}


void workerManger::Add_Emp()
{
	std::cout << "��ӵ�����: " << std::endl;

	int addNum = 0;
	std::cin >> addNum;
	if (addNum == 0)
	{
		std::cout << "��������" << std::endl;
	}
	else
	{
		this->m_FileIsEmpty = false;

		int newSize = this->m_EmpNum + addNum; //�¿ռ�����

		//�����¿ռ�

		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ��µ����ݿ������¿ռ�

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//���������

		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			std::string name;//ְ������
			int dSelect;//����ѡ��

			std::cout << "������� " << i + 1 << "��ְ���ı�ţ�" << std::endl;
			std::cin >> id;


			std::cout << "������� " << i + 1 << "��ְ����������" << std::endl;
			std::cin >> name;


			std::cout << "��ѡ���ְ���ĸ�λ" << std::endl;
			std::cout << "1.��ְͨ��" << std::endl;
			std::cout << "2.����" << std::endl;
			std::cout << "3.�ϰ�" << std::endl;
			std::cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boos(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ��ְ�𣬱��浽������

			newSpace[this->m_EmpNum + i] = worker;

		}

		//�ͷ�ԭ�еĿռ�

		delete[]this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//���浽�ļ���

		this->save();

		//��ʾ��ӳɹ�
		std::cout << "�ɹ���ӣ�" << addNum << std::endl;
	}

	system("pause");
	system("cls");

}


void workerManger::save()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << std::endl;

	}
}


//��ʼ��Ա��
void workerManger::init_Emp()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)  //��ְͨ��
		{
			worker = new Employee(id, name, dId);

		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//�ϰ�
		{
			worker = new Boos(id, name, dId);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();//�ر��ļ�

}

void workerManger::show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		std::cout << "�ļ�Ϊ�ջ��߲�����" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�����������
	system("pause");
	system("cls");
}


//ɾ��ְ��
void workerManger::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "ERROR" << std::endl;
		return;
	}
	else
	{
		std::cout << "������" << std::endl;
		int id;
		std::cin >> id;
		int index = IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			save();
		}
		else
		{
			std::cout << "No anser" << std::endl;
		}
	}
	system("pause");
	system("cls");
}



//�ж�ְ���Ƿ���ڣ�������ڷ�������λ�ã������ڷ���-1��
int workerManger::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;

			break;
		}
	}
	return index;
}



//�޸�
void workerManger::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "ERROR" << std::endl;
		return;
	}
	else
	{
		int id;
		std::cout << "������" << std::endl;
		std::cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			delete this->m_EmpArray[index];
			std::string name;//ְ������
			int dSelect;//����ѡ��

			std::cout << "������ְ���ı�ţ�" << std::endl;
			std::cin >> id;


			std::cout << "������ְ����������" << std::endl;
			std::cin >> name;


			std::cout << "��ѡ���ְ���ĸ�λ" << std::endl;
			std::cout << "1.��ְͨ��" << std::endl;
			std::cout << "2.����" << std::endl;
			std::cout << "3.�ϰ�" << std::endl;
			std::cin >> dSelect;
			Worker* worker=NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boos(id, name, dSelect);
				break;
			}
			this->m_EmpArray[index] = worker;
			this->save();
		}
		else
		{
			std::cout << "No anser " << std::endl;
		}
	}
	system("pause");
	system("cls");
}


//����
void workerManger::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "ERROR" << std::endl;
	}
	else
	{
		int choice;
		std::cout << "��������ҷ�ʽ" << std::endl;
		std::cout << "1.����Ų�ѯ" << std::endl;
		std::cout << "2.�����ֲ�ѯ" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			int id;
			std::cout << "������Ҫ��ѯ��Ա�ı��" << std::endl;
			std::cin >> id;
			int index = this->IsExist(id);
			if (index == -1)
			{
				std::cout << "��ѯʧ��" << std::endl;
				return;
			}
			else
			{
				std::cout << "��ѯ�ɹ�" << std::endl;
				this->m_EmpArray[index]->showInfo();
			}
		}
		else if (choice == 2)
		{
			std::string name;
			std::cout << "������Ҫ��ѯ��Ա������" << std::endl;
			std::cin >> name;
			int ret = -1;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					ret = i;
					std::cout << "��ѯ�ɹ�" << std::endl;
					break;
				}
			}
			if (ret == -1)
			{
				std::cout << "��ѯʧ��" << std::endl;
			}
			else
			{
				this->m_EmpArray[ret]->showInfo();
			}
		}
		else
		{
			std::cout << "�������" << std::endl;
		}
	}
	system("pause");
	system("cls");
}


//����	
void workerManger::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "ERROE" << std::endl;
		return;
	}
	else
	{
		int id;
		int choice;
		std::cout << "������Ҫѡ�������ʽ" << std::endl;
		std::cout << "1.��ְ���Ž�������" << std::endl;
		std::cout << "2.��ְ���Ž��н���" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				for (int j = i; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[j];
						this->m_EmpArray[j] = temp;
					}
				}
			}
			std::cout << "����ɹ�" << std::endl;
			this->save();
			this->show_Emp();
		}

		else if (choice == 2)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				for (int j = i; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArray[i]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[j];
						this->m_EmpArray[j] = temp;
					}
				}
			}			
			std::cout << "����ɹ�" << std::endl;
			this->save();
			this->show_Emp();
		}
		else
		{
			std::cout << "û�����ѡ��" << std::endl;
		}
	}
}




//�����ļ�
void workerManger::Clean_File()
{
	std::cout << "ȷ��Ҫ����ļ���" << std::endl;
	std::cout << "1.ȷ��" << std::endl;
	std::cout << "2.����" << std::endl;
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		std::ofstream ofs;
		ofs.open(FILENAME, std::ios::trunc);
		ofs.close();

		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[]this->m_EmpArray;
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		std::cout << "��ճɹ�"<<std::endl;
	}
	else if (choice == 2)
	{

	}
	else
	{
		std::cout << "û�����ѡ��" << std::endl;
	}
	system("pause");
	system("cls");
}


