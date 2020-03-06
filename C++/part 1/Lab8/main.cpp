#include <iostream>
#include <fstream>
#include "LinkedText.h"

#include <algorithm>

using namespace std;

int main() {
	std::fstream file;
	file.open("text.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);	

	LinkedText text;	
	text.AddLine("Linerg#rgfghgs 1");
	text.Write(cout);
	cout << endl;

	text.AddLine("Liine 2");
	text.Write(cout);
	cout << endl;

	text.AddLine("Liine 3");
	text.Write(cout);
	cout << endl;	

	cout << *std::next(text.begin(), 1);

	text.CopyLine(std::next(text.begin(), 2), std::next(text.begin(), 1));
	text.Write(cout);
	cout << endl;	

	text.CopyLine(text.begin(), std::next(text.begin(), 3));
	text.Write(cout);
	cout << endl;

	text.RemoveLine(text.begin()+3);
	text.Write(cout);
	cout << endl;

	auto iter = text.begin();
	iter += 2;
	cout << *iter << std::endl;

	cout << text.GetSize() << std::endl;
	text.SetName("Test text");
	text.Write(file);
	file.seekg(std::ios::beg);

	cout << "Text name: " << text.GetName() << endl;
	text.Write(cout);

	LinkedText text2;	
	text2.Load(file);	
	cout << "Text2 name: " << text2.GetName() << endl;
	text2.Write(cout);	

	number i = 0, j = 0;
	text2.FindLetter('Z', i, j);
	cout << "First contains of letter Z" << endl << "Row " << i << " Column " << j << endl;	
	cout << "Row which contains maximum count letter i: " << std::endl << *text2.GetLineWithMaxLetterContains('i') << endl;		

	LinkedText text3;
	text3.Load(cin);
	text3.Write(cout);
	

	file.close();
	system("pause");
	return 0;
}