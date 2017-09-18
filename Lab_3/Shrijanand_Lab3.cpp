#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

string Generate_Series(int n)
{
	if (n == 1)
	{
		return "1";
	}
	if (n == 2)
	{
		return "11";
	}
	string term_string = "11";
	for (int i = 3; i <= n; i++)
	{
		term_string += '$';
		int term_length = term_string.length();
		int count = 1;
		string temp_term = "";
		for (int j = 1; j < term_length; j++)
		{
			if (term_string[j] != term_string[j - 1])
			{
				temp_term += count + '0';
				temp_term += term_string[j - 1];
				count = 1;
			}
			else count++;
		}
		term_string = temp_term;
	}

	return term_string;
}

void Sorting_Merge(string array_to_sort[], int i, int middle, int j) 
{
	string temp[10];
	int left = i;
	int right = j;
	int m = middle + 1;
	int k = left;

	while (left <= middle && m <= right) 
	{
		if (array_to_sort[left].length() == array_to_sort[m].length()) 
		{
			if (array_to_sort[left] <= array_to_sort[m]) 
			{
				temp[k++] = array_to_sort[left++];
			}
			else 
			{
				temp[k++] = array_to_sort[m++];
			}
		}
		else if (array_to_sort[left].length() < array_to_sort[m].length()) 
		{
			temp[k++] = array_to_sort[left++];
		}
		else 
		{
			temp[k++] = array_to_sort[m++];
		}
	}

	while (left <= middle)
	{
		temp[k++] = array_to_sort[left++];
	}

	while (m <= right) 
	{
		temp[k++] = array_to_sort[m++];
	}

	for (int i1 = i; i1 <= j; i1++) 
	{
		array_to_sort[i1] = temp[i1];
	}
}

void Merge_Sort(string array_to_sort[], int i, int j) 
{
	int middle = 0;

	if (i < j) 
	{
		middle = ((i + j) / 2);
		Merge_Sort(array_to_sort, i, middle);
		Merge_Sort(array_to_sort, middle + 1, j);
		Sorting_Merge(array_to_sort, i, middle, j);
	}
}

int main()
{
	cout << "==================================" << endl;
	cout << "Fundamentals of Algorithms" << endl;
	cout << "Lab 3 - Shrijanand Chintapatla" << endl;
	cout << "==================================" << endl << endl;

	cout << "==================================" << endl;
	cout << "             PART 1               " << endl;
	cout << "==================================" << endl << endl;

	string term = Generate_Series(10);
	cout << "The nth term of the Series when n=10 is: " << term << endl;

	cout << endl;
	cout << "==================================" << endl;
	cout << "             PART 2               " << endl;
	cout << "==================================" << endl << endl;

	srand(time(NULL));
	int numbers[10] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	random_shuffle(begin(numbers), end(numbers));

	cout << "Creating array of random numbers between 5(inclusive) and 15(exclusive):" << endl;
	cout << "[";
	for (int i = 0; i < 9; i++)
	{
		cout << numbers[i] << ", ";
	}
	cout << numbers[9] << "]" << endl;
	cout << endl;

	string to_sort[10];
	for (int i = 0; i < 10; i++)
	{
		to_sort[i] = Generate_Series(numbers[i]);
	}

	cout << "Generating nth item in the sequence and storing them in an array: " << endl;
	cout << "[";
	for (int i = 0; i < 9; i++)
	{
		cout << to_sort[i] << ", ";
	}
	cout << to_sort[9] << "]" << endl;

	cout << endl;
	cout << "==================================" << endl;
	cout << "             PART 3               " << endl;
	cout << "==================================" << endl << endl;

    Merge_Sort(to_sort, 0, 9);

	cout << "Sorting Array by Sorting_Merge Sort: " << endl;
	cout << "[";
	for (int i = 0; i < 9; i++)
		cout << to_sort[i] << ", ";
	cout << to_sort[9] << "]" << endl;

	cout << endl;
	cout << "==================================" << endl << endl;

	return 0;
}