#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Stack
{
private:
	int top_item;
	int length;
	vector <char> stack;

public:
	Stack() 
	{
		top_item = -1;
	}

	void push(char element) 
	{
		stack.push_back(element);
		top_item++;
		length++;
	}

	char pop() 
	{
		char temp = stack[top_item];
		stack.erase(stack.begin() + top_item);
		top_item--;
		length--;
		return temp;
	}

	char top() 
	{
		return stack[top_item];
	}

	bool is_empty() 
	{
		return (top_item == -1);
	}

	int len() 
	{
		return length;
	}
};

class Queue
{
private:
	int last_item;
	int length;
	vector <char> queue;

public:
	Queue() 
	{
		last_item = -1;
	}

	void enqueue(char element) 
	{
		queue.push_back(element);
		last_item++;
		length++;
	}

	char dequeue() 
	{
		char temp = queue[0];
		queue.erase(queue.begin());
		last_item--;
		length--;
		return temp;
	}

	char first() 
	{
		return queue[0];
	}

	bool is_empty() 
	{
		return (last_item == -1);
	}

	int len() 
	{
		return length;
	}
};

bool is_palindrome(string input) 
{
	int length_of_string;
	length_of_string = input.length();

	Stack stack;
	Queue queue;

	for (int i = 0; i < length_of_string; i++) 
	{
		char temp = tolower(input[i]);
		int ascii = int(temp);
		if ((ascii >= 97) && (ascii <= 122)) 
		{
			stack.push(temp);
			queue.enqueue(temp);
		}
	}

	while (!queue.is_empty() || !stack.is_empty()) 
	{
		if (queue.dequeue() != stack.pop()) 
		{
			return false;
		}
	}

	return true;
}

void testing_palindromes() 
{
	string input;
	bool result;

	cout << "\n====== Testing Palindromes! ======" << endl;

	cout << "\nTEST 1\n";
	cout << "======" << endl;
	input = "racecar";
	cout << "Tested Input: " << input << endl;
	result = is_palindrome(input);
	if (result) 
	{
		cout << "The input is a Palindrome!" << endl;
	}
	else 
	{
		cout << "The input is not a Palindrome!" << endl;
	}

	cout << "\nTEST 2\n";
	cout << "======" << endl;
	input = "A man, a plan, a canal: Panama";
	cout << "Tested Input: " << input << endl;
	result = is_palindrome(input);
	if (result)
	{
		cout << "The input is a Palindrome!" << endl;
	}
	else
	{
		cout << "The input is not a Palindrome!" << endl;
	}

	cout << "\nTEST 3\n";
	cout << "======" << endl;
	input = "Huehuehuehuehue";
	cout << "Tested Input: " << input << endl;
	result = is_palindrome(input);
	if (result)
	{
		cout << "The input is a Palindrome!" << endl;
	}
	else
	{
		cout << "The input is not a Palindrome!" << endl;
	}
}

bool test_for_operator(char potential_operator)
{
	if (potential_operator == '+' || potential_operator == '-' || potential_operator == '*' || potential_operator == '/')
	{
		return true;
	}

	return false;
}

int Arithmetic_Operation(char symbol, int a, int b) 
{
	if (symbol == '+')
	{
		return a + b;
	}
	else if (symbol == '-')
	{
		return a - b;
	}
	else if (symbol == '*')
	{
		return a * b;
	}
	else if (symbol == '/')
	{
		return a / b;
	}
	else
	{
		cout << "Whoops! Some error occured!" << endl;
		return -1;
	}
}

bool is_number(char potential_operator) 
{
	if (potential_operator >= '0' && potential_operator <= '9')
	{
		return true;
	}
	return false;
}

int Solving_Arithmetic(string post_fix_string)
{
	Stack solve_stack;

	for (int i = 0; i< post_fix_string.length(); i++) 
	{
		if (post_fix_string[i] == ' ' || post_fix_string[i] == ',')
		{
			continue;
		}

		else if (test_for_operator(post_fix_string[i])) 
		{
			int b = solve_stack.top();
			solve_stack.pop();
			int a = solve_stack.top();
			solve_stack.pop();
			int result = Arithmetic_Operation(post_fix_string[i], a, b);
			solve_stack.push(result);
		}

		else if (is_number(post_fix_string[i])) 
		{
			int operand = 0;
			while (i<post_fix_string.length() && is_number(post_fix_string[i])) 
			{
				operand = (operand * 10) + (post_fix_string[i] - '0');
				i++;
			}
			i--;
			solve_stack.push(operand);
		}
	}
	return solve_stack.top();
}

int order_of_operations(char symbol) 
{
	switch (symbol) 
	{
	case '^': return 3;
	case '/': return 2;
	case '*': return 2;
	case '+': return 1;
	case '-': return 1;
	default: return -1;
	}
}

string Infix_to_Postfix(string infix) 
{
	string postfix_string;
	Stack stack;

	for (int i = 0; i<infix.length(); i++) 
	{
		if (infix[i] == '(') 
		{
			stack.push('(');
		}

		else if (infix[i] == ')') 
		{
			while (!stack.is_empty() && stack.top() != '(')
			{
				char temp = stack.top();
				stack.pop();
				postfix_string = postfix_string + temp + " ";
			}
			if (stack.top() == '(')
			{
				char temp = stack.top();
				stack.pop();
			}
		}

		else if ((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) 
		{
			postfix_string = postfix_string + infix[i] + " ";
		}

		else 
		{
			while (!stack.is_empty() && (order_of_operations(infix[i]) <= order_of_operations(stack.top())))
			{
				char temp = stack.top();
				stack.pop();
				postfix_string = postfix_string + temp + " ";
			}
			stack.push(infix[i]);
		}

	}

	while (!stack.is_empty()) 
	{
		char temp = stack.top();
		stack.pop();
		postfix_string = postfix_string + temp + " ";
	}

	return postfix_string;
}

void Testing_Postfix() 
{
	string input;
	cout << "\n======== Testing Postfix! ========\n";

	cout << "\nTEST 1\n";
	cout << "======" << endl;
	input = "1+2";
	cout << endl;
	cout << "Testing Input: " << input << endl;
	cout << "Output: " << Infix_to_Postfix(input) << ", " << Solving_Arithmetic(Infix_to_Postfix(input)) << endl;

	cout << "\nTEST 2\n";
	cout << "======" << endl;
	input = "4+((3+2)*1)-5";
	cout << endl;
	cout << "Testing Input : " << input << endl;
	cout << "Output: " << Infix_to_Postfix(input) << ", " << Solving_Arithmetic(Infix_to_Postfix(input)) << endl;
}

int main() {
	cout << "==================================" << endl;
	cout << "Fundamentals of Algorithms" << endl;
	cout << "Lab 4 - Shrijanand Chintapatla" << endl;
	cout << "==================================" << endl << endl;

	cout << "==================================" << endl;
	cout << "             PART A               " << endl;
	cout << "==================================" << endl << endl;

	testing_palindromes();

	cout << endl;
	cout << "==================================" << endl;
	cout << "             PART B               " << endl;
	cout << "==================================" << endl << endl;

	Testing_Postfix();

	cout << endl;
	cout << "==================================" << endl << endl;

	return 0;
}