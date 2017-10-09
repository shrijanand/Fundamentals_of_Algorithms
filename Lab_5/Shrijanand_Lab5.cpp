
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

string Naive_Approach(vector<int> Arr, int sum)
{
	string index;

	for (int i = 0; i < Arr.size(); i++)
	{
		for (int j = i + 1; j < Arr.size(); j++)
		{
			if (Arr[i] + Arr[j] == sum)
			{
				string number = "(";
				number += to_string(Arr[i]);
				number += ", ";
				number += to_string(Arr[j]);
				number += ") ";
				index += number;
			}
		}
	}

	return index;
}

string Hashmap_Dictionary(vector<int> Arr, int sum)
{
	unordered_map<int, int> Mapping;
	unordered_map<int, int>::iterator iterate;
	string numbers;

	for (int i = 0; i < Arr.size(); i++)
	{
		Mapping.insert(pair<int, int>(i, Arr[i]));
	}

	for (int j = 0; j < Mapping.size(); j++)
	{

		int index = sum - Mapping.find(j)->second;
		size_t repeat = numbers.find(to_string(index));

		if (repeat != std::string::npos)
		{
			continue;
		}
		else
		{
			iterate = Mapping.find(index);
			if (iterate != Mapping.end())
			{
				if (index == Mapping.find(j)->second || index == 0)
				{
					continue;
				}
				else
				{
					string letters = "(";
					letters += to_string(Arr[j]);
					letters += ", ";
					letters += to_string(index);
					letters += ") ";
					numbers += letters;
				}
			}
		}
	}

	return numbers;
}

int Index_Column_Converter(string index)
{
	int column = 0;
	for (int i = 0; i < index.size(); i++)
	{
		column = column * 26 + index[i] - 64;
	}

	return column;
}

string Column_Index_Converter(int column)
{
	string idx;
	while (column > 0)
	{
		idx = (char)(65 + (column - 1) % 26) + idx;
		column = (column - 1) / 26;
	}

	return idx;
}

string printVector(vector<int> vec)
{
	string letters;
	letters += " [";
	for (int i = 0; i < vec.size(); i++)
	{
		letters += to_string(vec[i]);
		if (i < 9)
		{
			letters += ",";
		}
	}
	letters += "] ";

	return letters;
}

void Testing_CodeLab_5()
{
	cout << "==================================" << endl;
	cout << "           PART 1-A               " << endl;
	cout << "==================================" << endl << endl;

	vector<int> Test_Array;
	Test_Array.push_back(1);
	Test_Array.push_back(2);
	Test_Array.push_back(3);
	Test_Array.push_back(4);
	Test_Array.push_back(5);
	Test_Array.push_back(6);
	Test_Array.push_back(7);
	Test_Array.push_back(8);
	Test_Array.push_back(9);
	Test_Array.push_back(10);
	cout << endl << " Testing Array: " << printVector(Test_Array) << endl << endl;

	cout << "     Sum     " << "    " << "     Nums     " << endl;
	cout << "=============" << "    " << "==============" << endl << endl;
	cout << "      4" << "            " << Naive_Approach(Test_Array, 4) << endl;
	cout << "      9" << "            " << Naive_Approach(Test_Array, 9) << endl;
	cout << "     12" << "            " << Naive_Approach(Test_Array, 12) << endl;
	cout << "     19" << "            " << Naive_Approach(Test_Array, 19) << endl;
	cout << endl;
	cout << "==================================" << endl << endl;

	cout << endl;
	cout << "==================================" << endl;
	cout << "           PART 1-B               " << endl;
	cout << "==================================" << endl << endl;

	cout << "     Sum     " << "    " << "     Nums     " << endl;
	cout << "=============" << "    " << "==============" << endl << endl;
	cout << "      4" << "            " << Hashmap_Dictionary(Test_Array, 4) << endl;
	cout << "      9" << "            " << Hashmap_Dictionary(Test_Array, 9) << endl;
	cout << "     12" << "            " << Hashmap_Dictionary(Test_Array, 12) << endl;
	cout << "     19" << "            " << Hashmap_Dictionary(Test_Array, 19) << endl;
	cout << endl;
	cout << "==================================" << endl << endl;

	cout << endl;
	cout << "==================================" << endl;
	cout << "            PART 2 & 3            " << endl;
	cout << "          Testing 1 to 50         " << endl;
	cout << "==================================" << endl << endl;

	cout << "    Index    " << "    " << "    Column    " << endl;
	cout << "=============" << "    " << "==============" << endl << endl;

	for (int i = 1; i <= 50; i++)
	{
		string letters = Column_Index_Converter(i);
		int index = Index_Column_Converter(letters);
		cout << "        " << letters << "       " << "           " << index << endl;
	}
}

int main()
{
	cout << "==================================" << endl;
	cout << "Fundamentals of Algorithms" << endl;
	cout << "Lab 5 - Shrijanand Chintapatla" << endl;
	cout << "==================================" << endl << endl;

	Testing_CodeLab_5();

	cout << endl;
	cout << "==================================" << endl << endl;

	return 0;
}