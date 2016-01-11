#pragma once

#include <string>


class JSChar
{
public:
	char mChar; 
	int mLineIndex;
	int mColumnIndex;
};



class JSScanner
{
public:
	JSScanner();
	~JSScanner();


	int open(const std::string &i_fileName);

	JSChar get();

private:

	int mIndex;
	int mLength;

	std::string mFileName;
	char *mBuffer;


};
