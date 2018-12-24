#include <iostream>
#include "Task.h"
#include "ReferenceBook.h"
#include <string>

using namespace std;

int main() {
	cout << "Base task" << endl;

	string str1;
	string str2;
	cout << "Please enter first string ";
	cin >> str1;
	cout << "Please enter second string ";
	cin >> str2;
	cout << " Is strigs equal: " << base_task(str1, str2) << endl;


	cout << endl << "Add task" << endl;

	string with = "Hello, my little friend*";
	string without = "Hello, my little friend";
	printPart_add_task(with);
	printPart_add_task(without);


	cout << endl << "Add Hard task" << endl;

	ReferenceBook rb;

	string k1 = "Oleh Shkalikov";
	string v1_1 = "KB12222608";	
	string v1_2 = "PC13525689";

	string k2 = "Oleh Halikov";
	string v2 = "0971864353";

	rb.AddData(k1, v1_1);
	rb.AddData(k1, v1_2);
	rb.AddData(k2, v2);

	cout << "Reference Book keys" << endl << endl;
	auto keys = rb.GetAllKey();
	for (auto it = keys.cbegin(); it != keys.cend(); ++it)
		cout << *it << endl;

	cout << endl << "Value for any Oleh Shkalikov" << endl;
	auto values = rb.GetDataFor(k1);
	for (auto it = values.cbegin(); it != values.cend(); ++it)
		cout << *it << endl;

	cout << endl << "Value for Oleh Halikov" << endl;
	values = rb.GetDataFor(k2);
	for (auto it = values.cbegin(); it != values.cend(); ++it)
		cout << *it << endl;
	
	rb.RemoveData(k1, v1_2);
	keys = rb.GetAllKey();
	cout << endl << "All keys after remove concrete" << endl;
	for (auto it = keys.cbegin(); it != keys.cend(); ++it)
		cout << *it << endl;

	rb.AddData(k1, v1_2);
	keys = rb.GetAllKey();
	cout << endl << "All keys after add" << endl;
	for (auto it = keys.cbegin(); it != keys.cend(); ++it)
		cout << *it << endl;

	rb.RemoveAllDataWithKey(k1);
	keys = rb.GetAllKey();
	cout << endl << "All keys after remove all with key" << endl;
	for (auto it = keys.cbegin(); it != keys.cend(); ++it)
		cout << *it << endl;

	system("pause");
	return 0;
}