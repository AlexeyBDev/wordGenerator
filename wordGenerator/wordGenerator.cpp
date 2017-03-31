#include <vector>
#include <fstream>
#include <iostream>
#include <ctime>
#include <locale>

using namespace std;

#include "wordGenerator.h"



wordGenerator::wordGenerator()
{
	status = false;
	srand(time(0));
}


wordGenerator::~wordGenerator()
{
	dictionary_.clear();
	status = false;
}

unsigned int wordGenerator::counterLine(const char* fileName)
{
	ifstream dataFile;
	unsigned int numOfLine = 0;
	dataFile.open(fileName);
	if (!dataFile.is_open()) {
		std::cerr << "File not found!!!" << std::endl;
		return numOfLine;
	}
	else
	{
		while (dataFile.ignore(numeric_limits<streamsize>::max(), '\n'))
		{
			if (!dataFile.eof()) // если в конце последней строки '\n', иначе не нужно
				++numOfLine;
		}
		dataFile.close();
		return numOfLine;
	}
}


bool wordGenerator::Load(const char* fileName)
{
	ifstream dataFile;
	unsigned int counter = 0;
	unsigned int numLine = counterLine(fileName);
	char buf[256];
	dataFile.open(fileName);
	if (!dataFile.is_open()) {
		std::cerr << "File not found!!!" << std::endl;
		return false;
	}
	else
	{
		dictionary_.resize(numLine + 1);
		while (counter <= numLine)
		{
			dataFile.getline(buf, sizeof buf);
			dictionary_[counter] = buf;
			++counter;
		}
		dataFile.close();
		status = true;
		return true;
	}
}

//bool wordGenerator::Load(const char* fileName, unsigned int numOfLine)
//{
//	setlocale(LC_ALL, "Russian");
//	ifstream dataFile;
//	unsigned int counter = 0;
//	char buf[256];
//	dataFile.open(fileName);
//	if (!dataFile.is_open()) {
//		std::cerr << "File not found!!!" << std::endl;
//		return false;
//	}
//	else
//	{
//		dictionary_.resize(numOfLine + 1);
//		while (counter <= numOfLine)
//		{
//			dataFile.getline(buf, sizeof buf);
//			dictionary_[counter] = buf;
//			++counter;
//		}
//		dataFile.close();
//		status = true;
//		return true;
//	}
//}

string wordGenerator::GetWord()
{
	if (status == false) return "non";
	else
	{
		//srand(time(0)); // автоматическая рандомизация
		unsigned int numWord = 1 + rand() % dictionary_.size();
		return dictionary_[numWord];
	}
}
