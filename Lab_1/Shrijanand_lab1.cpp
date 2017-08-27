#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "==================================" << endl;
	cout << "Fundamentals of Algorithms" << endl;
	cout << "Lab 1 - Shrijanand Chintapatla" << endl;
	cout << "==================================" << endl << endl;

	int number_names;
	cout << "How many names would you like to sort? : ";
	cin >> number_names;
	string *Names = new string[number_names];

	for (int i = 0; i < number_names; i++)
	{
		cout << "Enter the name: ";
		cin >> Names[i];
	}
	cout << endl;

	cout << "**** Printing unsorted array ****" << endl;
	for (int i = 0; i < number_names; i++)
	{
		cout << Names[i] + " ";
	}
	cout << endl << endl;

	for (int j = 0; j < number_names; j++)
	{
		for (int i = 0; i < number_names - 1; i++)
		{
			if (Names[i] > Names[i + 1])
			{
				string temp;
				temp = Names[i];
				Names[i] = Names[i + 1];
				Names[i + 1] = temp;
			}
		}
	}
	cout << "**** Printing sorted array ****" << endl;
	for (int i = 0; i < number_names; i++)
	{
		cout << Names[i] + " ";
	}
	cout << endl << endl;
	cout << "==================================" << endl << endl;
	return 0;
}
