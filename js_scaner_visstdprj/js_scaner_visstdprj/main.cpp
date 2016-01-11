#include <iostream>

#include "js_scanner.h"


using namespace std;

int main()
{
	JSChar theChar;
	JSScanner *scanner = new JSScanner;

	scanner->open("c:\\test.js");

	while (1)
	{
		theChar = scanner->get();

		if (theChar.mChar == -1) 
			break;

		cout << theChar.mChar;
	}



	cout << "Hello!" << endl;

	cin.get();

	return 0;


}
