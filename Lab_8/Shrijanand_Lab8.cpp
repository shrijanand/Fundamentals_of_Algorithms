#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

int main() 
{
	cout << "==================================" << endl;
	cout << "Fundamentals of Algorithms" << endl;
	cout << "Lab 8 - Shrijanand Chintapatla" << endl;
	cout << "==================================" << endl << endl;

	int max_length_per_line;

	cout << "Kindly enter Maximum length of characters in a input_line: ";
	cin >> max_length_per_line;
	cout << endl;
	cout << "==================================" << endl << endl;

	vector <string> all_words;
	string each_line;
	string current_word = "";

	ifstream file("inputfile.txt");

	if (file.fail()) 
	{
		cout << "Error." << endl << "File doesn't exist." << endl;
		exit(1);
	}

	if (file.peek() == std::ifstream::traits_type::eof()) 
	{
		cout << "Error." << endl << "Input file is empty." << endl;
		exit(1);
	}

	while (!file.eof()) 
	{
		getline(file, each_line);
		istringstream splitLine(each_line);

		while (splitLine >> current_word) 
		{
			all_words.push_back(current_word);
		}
	}
	file.close();

	int cost_for_words[all_words.size()][all_words.size()];

	for (int i = 0; i < all_words.size(); i++) 
	{
		cost_for_words[i][i] = max_length_per_line - all_words[i].length();

		for (int j = i + 1; j < all_words.size(); j++) 
		{
			cost_for_words[i][j] = cost_for_words[i][j - 1] - all_words[j].length() - 1;
		}
	}

	for (int i = 0; i < all_words.size(); i++) 
	{
		for (int j = i; j < all_words.size(); j++) 
		{
			if (cost_for_words[i][j] < 0) 
			{
				cost_for_words[i][j] = INT_MAX;
			}
			else 
			{
				cost_for_words[i][j] = pow(cost_for_words[i][j], 2);
			}
		}
	}

	int minimum_cost_for_words[all_words.size()];
	int solution[all_words.size()];

	for (int i = all_words.size() - 1; i >= 0; i--) 
	{
		minimum_cost_for_words[i] = cost_for_words[i][all_words.size() - 1];
		solution[i] = all_words.size();
		for (int j = all_words.size() - 1; j > i; j--) 
		{
			if (cost_for_words[i][j - 1] == INT_MAX) 
			{
				continue;
			}
			if (minimum_cost_for_words[i] > minimum_cost_for_words[j] + cost_for_words[i][j - 1]) 
			{
				minimum_cost_for_words[i] = minimum_cost_for_words[j] + cost_for_words[i][j - 1];
				solution[i] = j;
			}
		}
	}


	int i = 0;
	int j;
	ofstream output;
	output.open("outputfile.txt");

	do {
		j = solution[i];
		for (int k = i; k < j; k++) 
		{
			output << all_words[k];
			output << " ";
		}
		output << "\n";
		i = j;
	} while (j < all_words.size());

	output.close();

	cout << endl;
	cout << "==================================" << endl << endl;

	return 0;
}