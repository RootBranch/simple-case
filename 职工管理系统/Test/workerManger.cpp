#include "workerManger.h"

workerManger::workerManger()
{
	//1.文件不存在
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	if (!ifs.is_open())
	{
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组为空
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//初始化记录的人
		this->m_EmpNum = 0;
		//初始化数组
		this->m_EmpArray = NULL;
		//初始化文件为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.当文件存在,并且记录数据
	int num = this->get_EmpNum();
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//将文件中的数据存在数组中
	this->init_Emp();

}

//统计文件中的人数
int workerManger::get_EmpNum()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);//打开文件 读

	int id;
	std::string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数变量
		num++;
	}
	return num;

}


void workerManger::exitSystem()
{
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);
}


//释放空间
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
	std::cout << "***** 欢迎使用职工管理系统 ****" << std::endl;
	std::cout << "******* 0.退出管理系统 ********" << std::endl;
	std::cout << "******* 1.增加职工信息 ********" << std::endl;
	std::cout << "******* 2.显示职工信息 ********" << std::endl;
	std::cout << "******* 3.删除离职职工 ********" << std::endl;
	std::cout << "******* 4.修改职工信息 ********" << std::endl;
	std::cout << "******* 5.查找职工信息 ********" << std::endl;
	std::cout << "******* 6.按照编号排序 ********" << std::endl;
	std::cout << "******* 7.清除所有文档 ********" << std::endl;
	std::cout << "*******************************" << std::endl;
	std::cout << std::endl;
}


void workerManger::Add_Emp()
{
	std::cout << "添加的人数: " << std::endl;

	int addNum = 0;
	std::cin >> addNum;
	if (addNum == 0)
	{
		std::cout << "数据有误" << std::endl;
	}
	else
	{
		this->m_FileIsEmpty = false;

		int newSize = this->m_EmpNum + addNum; //新空间人数

		//开辟新空间

		Worker** newSpace = new Worker * [newSize];
		//将原来空间下的数据拷贝到新空间

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据

		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			std::string name;//职工姓名
			int dSelect;//部门选择

			std::cout << "请输入第 " << i + 1 << "个职工的编号：" << std::endl;
			std::cin >> id;


			std::cout << "请输入第 " << i + 1 << "个职工的姓名：" << std::endl;
			std::cin >> name;


			std::cout << "请选择该职工的岗位" << std::endl;
			std::cout << "1.普通职工" << std::endl;
			std::cout << "2.经理" << std::endl;
			std::cout << "3.老板" << std::endl;
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
			//将创建职工职责，保存到数组中

			newSpace[this->m_EmpNum + i] = worker;

		}

		//释放原有的空间

		delete[]this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//保存到文件中

		this->save();

		//提示添加成功
		std::cout << "成功添加：" << addNum << std::endl;
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


//初始化员工
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
		if (dId == 1)  //普通职工
		{
			worker = new Employee(id, name, dId);

		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//老板
		{
			worker = new Boos(id, name, dId);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();//关闭文件

}

void workerManger::show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		std::cout << "文件为空或者不存在" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}


//删除职工
void workerManger::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "ERROR" << std::endl;
		return;
	}
	else
	{
		std::cout << "输入编号" << std::endl;
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



//判断职工是否存在，如果存在返回所在位置，不存在返回-1，
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



//修改
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
		std::cout << "输入编号" << std::endl;
		std::cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			delete this->m_EmpArray[index];
			std::string name;//职工姓名
			int dSelect;//部门选择

			std::cout << "请输入职工的编号：" << std::endl;
			std::cin >> id;


			std::cout << "请输入职工的姓名：" << std::endl;
			std::cin >> name;


			std::cout << "请选择该职工的岗位" << std::endl;
			std::cout << "1.普通职工" << std::endl;
			std::cout << "2.经理" << std::endl;
			std::cout << "3.老板" << std::endl;
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


//查找
void workerManger::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "ERROR" << std::endl;
	}
	else
	{
		int choice;
		std::cout << "请输入查找方式" << std::endl;
		std::cout << "1.按编号查询" << std::endl;
		std::cout << "2.按名字查询" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			int id;
			std::cout << "请输入要查询人员的编号" << std::endl;
			std::cin >> id;
			int index = this->IsExist(id);
			if (index == -1)
			{
				std::cout << "查询失败" << std::endl;
				return;
			}
			else
			{
				std::cout << "查询成功" << std::endl;
				this->m_EmpArray[index]->showInfo();
			}
		}
		else if (choice == 2)
		{
			std::string name;
			std::cout << "请输入要查询人员的名字" << std::endl;
			std::cin >> name;
			int ret = -1;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					ret = i;
					std::cout << "查询成功" << std::endl;
					break;
				}
			}
			if (ret == -1)
			{
				std::cout << "查询失败" << std::endl;
			}
			else
			{
				this->m_EmpArray[ret]->showInfo();
			}
		}
		else
		{
			std::cout << "输入错误" << std::endl;
		}
	}
	system("pause");
	system("cls");
}


//排序	
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
		std::cout << "请输入要选择的排序方式" << std::endl;
		std::cout << "1.按职工号进行升序" << std::endl;
		std::cout << "2.按职工号进行降序" << std::endl;
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
			std::cout << "排序成功" << std::endl;
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
			std::cout << "排序成功" << std::endl;
			this->save();
			this->show_Emp();
		}
		else
		{
			std::cout << "没有这个选项" << std::endl;
		}
	}
}




//清理文件
void workerManger::Clean_File()
{
	std::cout << "确定要清空文件吗" << std::endl;
	std::cout << "1.确定" << std::endl;
	std::cout << "2.返回" << std::endl;
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
		std::cout << "清空成功"<<std::endl;
	}
	else if (choice == 2)
	{

	}
	else
	{
		std::cout << "没有这个选项" << std::endl;
	}
	system("pause");
	system("cls");
}


