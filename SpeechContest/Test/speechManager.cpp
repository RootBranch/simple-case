#include "speechManager.h"
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <fstream>

using namespace std;

SpeechManager::SpeechManager()
{
	this->InitSpeech();

	this->createSpeaker();

	this->loadRecrod();
}



void SpeechManager::showMenu()
{
	std::cout << "**********************************" <<std::endl;
	std::cout << "******** 欢迎参加演讲比赛 ********" << std::endl;
	std::cout << "******** 1. 开始演讲比赛 *********" << std::endl;
	std::cout << "******** 2. 查看往届记录 *********" << std::endl;
	std::cout << "******** 3. 清空比赛记录 *********" << std::endl;
	std::cout << "******** 0. 退出比赛程序 *********" << std::endl;
	std::cout << "**********************************" << std::endl;
}


void SpeechManager::InitSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->mSpeaker.clear();
	this->mImdex = 1;

	this->mRecord.clear();
}


void SpeechManager::createSpeaker()
{
	std::string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		std::string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.mName = name;
		
		for (int j = 0; j < 2; j++)
		{
			sp.mScore[j] = 0;
		}
		
		this->v1.push_back(i + 10001);

		this->mSpeaker.insert(std::make_pair(i + 10001, sp));
	}

}

void SpeechManager::exitSystem()
{
	std::cout << "程序即将退出" << std::endl;
	system("pause");
	exit(0);
}

void SpeechManager::startSpeech()
{
	//第一轮

	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示晋级结果
	this->showScore();
	//第二轮
	this->mImdex++;
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示晋级结果
	this->showScore();
	//4.保存分数
	this->SaveRecord();

	this->InitSpeech();

	this->createSpeaker();

	this->loadRecrod();

	cout << "本届比赛完成" << endl;
	system("pause");
	system("cls");
}


void SpeechManager::speechDraw()
{
	std::cout << "第" << this->mImdex << "轮" << std::endl;
	if (this->mImdex == 1)
	{
		//一轮
		random_shuffle(v1.begin(), v1.end());
		for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		//二轮
		for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "----------------------" << std::endl;
	system("pause");
	std::cout << std::endl;
}

//比赛
void SpeechManager::speechContest()
{
	std::cout << "第" << this->mImdex << "轮比赛正是开始" << endl;

	multimap<double, int, greater<double>>groupScore;

	int num = 0;

	vector<int>vSrc;//比赛选手
	if (this->mImdex == 1)
	{
		vSrc = v1;
	}
	else
	{
		vSrc = v2;
	}
	for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); it++)
	{
		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.0;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0);
		double avg = sum / double(d.size());

		this->mSpeaker[*it].mScore[this->mImdex - 1] = avg;

		groupScore.insert(make_pair(avg, *it));
	
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次如下" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号:" << it->second << " 姓名" << this->mSpeaker[it->second].mName
					<< " 成绩: " << this->mSpeaker[it->second].mScore[this->mImdex - 1] << endl;
			}

			int count = 0;

			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->mImdex == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					victory.push_back((*it).second);
				}
			}

			groupScore.clear();
		}
	}
	cout << "第" << this->mImdex << "轮比赛完毕" << endl;

}

void SpeechManager::showScore()
{
	cout << "----------------------" << this->mImdex << "轮晋级的信息" << endl;
	vector<int>v;
	v = this->mImdex == 1 ? v2 : victory;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "Id:	" << *it << " Name: " << this->mSpeaker[*it].mName << " Score: "
			<< this->mSpeaker[*it].mScore[this->mImdex - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->showMenu();

}

void SpeechManager::SaveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++)
	{
		ofs << *it << "," << this->mSpeaker[*it].mScore[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "Finished" << endl;
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecrod()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{	
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;

	ifs.putback(ch);

	string date;
	int index = 0;

	while (ifs >> date)
	{
		vector<string>v;

		int pos = -1;
		int start = 0;


		while (true)
		{
			pos = date.find(",", start);

			if (pos == -1)
			{
				break;
			}
			string temp = date.substr(start, pos - start);
			v.push_back(temp);
			
			start = pos + 1;
		}

		this->mRecord.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	//for (map<int, vector<string>>::iterator it = mRecord.begin(); it != mRecord.end(); it++)
	//{
	//	cout << it->first << "冠军Id: " << it->second[0]<<" Score: "<< it->second[1] << endl;
	//}
}

void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或者不存在" << endl;	
		return;
	}
	for (int i = 0; i < this->mRecord.size(); i++)
	{
		cout << "第" << i + 1 << "届 "
			<< "冠军Id:" << this->mRecord[i][0] << " 得分: " << this->mRecord[i][1] << " "<<endl
			<< "亚军Id:" << this->mRecord[i][2] << " 得分: " << this->mRecord[i][3] << " "<<endl
			<< "季军Id:" << this->mRecord[i][4] << " 得分: " << this->mRecord[i][5] << " "<<endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "是否确定要清空" << endl;
	cout << "1.Yes" << endl;
	cout << "2.No" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->InitSpeech();

		this->createSpeaker();

		this->loadRecrod();
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}


SpeechManager::~SpeechManager()
{

}