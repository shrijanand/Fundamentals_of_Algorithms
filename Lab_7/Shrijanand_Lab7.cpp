#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node 
{
	Node* left;
	Node* right;
	int data;
};

struct Node* Create_Node(int data) 
{
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
};

void Printing_Inorder(Node* root) 
{
	if (root) 
	{
		Printing_Inorder(root->left);
		cout << root->data << " ";
		Printing_Inorder(root->right);
	}
}

void Printing_Preorder(Node* root) 
{
	if (root) 
	{
		cout << root->data << " ";
		Printing_Preorder(root->left);
		Printing_Preorder(root->right);
	}
}

void Printing_Postorder(Node* root) 
{
	if (root) 
	{
		Printing_Postorder(root->left);
		Printing_Postorder(root->right);
		cout << root->data << " ";
	}
}

void Breadth_First_Search(Node* root) 
{
	queue<Node*> Node_Queue;

	if (root) 
	{
		Node_Queue.push(root);
	}

	while (!Node_Queue.empty())
	{
		const Node * const temp_node = Node_Queue.front();
		Node_Queue.pop();
		cout << temp_node->data << " ";
		if (temp_node->left) 
		{
			Node_Queue.push(temp_node->left);
		}
		if (temp_node->right) 
		{
			Node_Queue.push(temp_node->right);
		}
	}
}

void AllRootHelper(Node* root, vector<int> path)
{
	if (root == NULL)
	{
		return;
	}

	if (root->left == NULL && root->right == NULL) 
	{
		for (int i = 0; i<path.size(); i++) 
		{
			cout << path.at(i) << " ";
		}
		cout << root->data << endl;

		return;
	}

	path.push_back(root->data);
	AllRootHelper(root->left, path);
	AllRootHelper(root->right, path);
}

void Roots_to_Leaves(Node* root) 
{
	vector<int> path;
	AllRootHelper(root, path);
}

void SumHelper(Node* root, vector<int> path, int k) 
{
	if (root == NULL)
	{
		return;
	}

	vector<int> sum;

	if (root->left == NULL && root->right == NULL) 
	{
		for (int i = 0; i<path.size(); i++) 
		{
			sum.push_back(path.at(i));
		}
		sum.push_back(root->data);

		int total = 0;
		for (int i = 0; i < sum.size(); i++) 
		{
			total += sum.at(i);
		}

		if (total == k) 
		{
			for (int i = 0; i < sum.size(); i++) 
			{
				cout << sum.at(i) << " ";
			}
		}

		return;
	}

	path.push_back(root->data);
	SumHelper(root->left, path, k);
	SumHelper(root->right, path, k);
}

void Sum_of_Path(Node* root, int k) 
{
	vector<int> path;
	SumHelper(root, path, k);
}

int main() {
	cout << "==================================" << endl;
	cout << "Fundamentals of Algorithms" << endl;
	cout << "Lab 6 - Shrijanand Chintapatla" << endl;
	cout << "==================================" << endl << endl;

	cout << "Generating Tree... " << endl;
	struct Node *root = Create_Node(1);
	root->left = Create_Node(2);
	root->right = Create_Node(3);
	root->left->left = Create_Node(4);
	root->left->right = Create_Node(5);
	root->right->left = Create_Node(6);
	root->right->right = Create_Node(7);
	cout << endl;

	cout << "==================================" << endl;
	cout << "             PART 1               " << endl;
	cout << "==================================" << endl << endl;

	cout << "Printing Inorder: ";
	Printing_Inorder(root);
	cout << endl;
	cout << endl;

	cout << "Printing Preorder: ";
	Printing_Preorder(root);
	cout << endl;
	cout << endl;

	cout << "Printing Postorder: ";
	Printing_Postorder(root);
	cout << endl;
	cout << endl;

	cout << "==================================" << endl;
	cout << "             PART 2               " << endl;
	cout << "==================================" << endl << endl;

	cout << "Printing Breadth First Search: ";
	Breadth_First_Search(root);
	cout << endl;
	cout << endl;

	cout << "==================================" << endl;
	cout << "             PART 3               " << endl;
	cout << "==================================" << endl << endl;

	cout << "Root to leaves path: " << endl;
	Roots_to_Leaves(root);
	cout << endl;

	cout << "Sum equalling to 11: " << endl;
	Sum_of_Path(root, 11);
	cout << endl;
	
	cout << endl;
	cout << "==================================" << endl << endl;

	return 0;
}
