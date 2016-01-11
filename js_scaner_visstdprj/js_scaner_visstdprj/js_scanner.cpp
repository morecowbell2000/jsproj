#include "js_scanner.h"

#include <iostream>
#include <fstream>

JSScanner::JSScanner()
{
	mBuffer = NULL;
	mLength = 0;
	mIndex = 0;
}

JSScanner::~JSScanner()
{
	delete []mBuffer;
}


int 
JSScanner::open(const std::string &i_fileName)
{
	mFileName = i_fileName;


	std::ifstream is(mFileName, std::ifstream::binary);
	if (is) 
	{
		// get length of file:
		is.seekg(0, is.end);
		mLength = is.tellg();
		is.seekg(0, is.beg);

		mBuffer = new char[mLength];

		std::cout << "Reading " << mLength << " characters... ";
		// read data as a block:
		is.read(mBuffer, mLength);

		if (is)
			std::cout << "all characters read successfully.";
		else
			std::cout << "error: only " << is.gcount() << " could be read";
		is.close();
	}



	return 0;
}


JSChar 
JSScanner::get()
{

	JSChar theChar;
	theChar.mChar = -1;
	if (mBuffer == NULL || mIndex >= mLength)
		return theChar;


	theChar.mLineIndex = 33;
	theChar.mColumnIndex = 22;
	theChar.mChar = mBuffer[mIndex++];
	return theChar ;
}

