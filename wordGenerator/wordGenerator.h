#ifndef WORDGENERATOR_H
#define WORDGENERATOR_H

#include <vector> 

class wordGenerator
{
private:
	std::vector<std::string> dictionary_;
	// статус словаря
	bool status;
	unsigned int counterLine(const char *fileName);
public:
	wordGenerator();
	~wordGenerator();
	//unsigned int counterLine(const char *fileName);
	//bool Load(const char *fileName, unsigned int numOfLine);
	bool Load(const char* fileName);
	std::string GetWord(void);
};

#endif