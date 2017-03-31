#include <string>

#include "Word.h"



Word::Word()
{
}


Word::~Word()
{
}

Word& Word::operator=(char* s) 
{
	std::string(s);
	return *this;
}

std::istream& operator>>(std::istream in, Word& word_)
{
	char buf[256];
	in.getline(buf, sizeof buf);
	word_ = buf;
	return in;
}
