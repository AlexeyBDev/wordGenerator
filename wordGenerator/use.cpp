#include <iostream>
#include <fstream>
#include <locale>
#include <iomanip>
#include <Windows.h>

#include "wordGenerator.h"

#define SIZE_S 18
using namespace std;

int main(int argc, char* argv[])
{
	system("color 1f");
	setlocale(LC_ALL, "Russian");

	ofstream outputFile;
	outputFile.open("outFile.txt", ios::out);
	if (!outputFile.is_open()) {
		cerr << "Output file not open!!!" << endl;
		return 1;
	}

	wordGenerator gen;
	gen.Load("..//DATA//word_rus.txt");
	outputFile << "|" << setw(SIZE_S) << setiosflags(ios::left) << "слово #1" <<
		"|" << setw(SIZE_S) << "слово #2" << "|" << endl;
	for(int i = 0; i < 20; ++i) {
		outputFile << setiosflags(ios::right) << "|" << setw(SIZE_S) << gen.GetWord() <<
			"|" << setw(SIZE_S) << gen.GetWord() << "|" << endl;
	}
	outputFile.close();

	return 0;
}
