#ifndef WORD_H
#define WORD_H

class Word : public std::string
{
public:
	Word();
	~Word();
	Word &operator =(char *s);
	friend std::istream &operator >> (std::istream in, Word &word_);
};

#endif WORD_H