//������ʦ��ÿλ��ʦ�����ѧ��
//�����������ɼ����������Ϣ
//����ѧ���Գɼ�����
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct Student 
{
	string name;
	int sorce;
	int year;
};

struct Teacher
{
	string name;
	struct Student stu[5];
};

void input_Teacher(struct Teacher stea[], int len)
{
	string m = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		stea[i].name = "Teacher_";
		stea[i].name += m[i];
		for (int j = 0; j < 5; j++)
		{
			stea[i].stu[j].name = "Student_";
			stea[i].stu[j].name += m[j];
			int random = rand() % 61 + 40;
			stea[i].stu[j].sorce = random;
			int random2 = rand() % 6 + 18;
			stea[i].stu[j].year = random2;
		}
	}
}

void in_print(struct Teacher ttea[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "��ʦ����" << ttea[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\tѧ��������" << ttea[i].stu[j].name << "  ѧ���ɼ� " << ttea[i].stu[j].sorce << " ѧ������ " << ttea[i].stu[j].year << endl;
		}
	}
}

void Mysort(struct Teacher stea[],int d)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4-i; j++)
		{
			if (stea[d].stu[j + 1].sorce > stea[d].stu[j].sorce)
				swap(stea[d].stu[j + 1].sorce, stea[d].stu[j].sorce);
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	struct Teacher tea[3];
	int len = sizeof(tea) / sizeof(tea[0]);
	input_Teacher(tea, len);
	for (int i = 0; i < len; i++)
		Mysort(tea,i);
	in_print(tea,len);
	return 0;
}