#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include "speaker.h"

class SpeechManager
{
public:
	SpeechManager();

	void showMenu();

	void exitSystem();

	void InitSpeech();

	void createSpeaker();

	void startSpeech();

	void speechDraw();

	//比赛
	void speechContest();

	void showScore();

	void SaveRecord();
	
	void loadRecrod();

	void showRecord();

	void clearRecord();

	~SpeechManager();

	std::vector<int>v1;

	std::vector<int>v2;

	std::vector<int>victory;

	std::map<int, Speaker>mSpeaker;

	std::map<int, std::vector<std::string>>mRecord;

	bool fileIsEmpty;

	int mImdex; 			//比赛轮数

};