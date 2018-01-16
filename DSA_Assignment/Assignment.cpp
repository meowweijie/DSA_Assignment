
#include "stdafx.h"
#include "BST.h"
#include<iostream>
#include <string>

using namespace std;


void Menu();
void CreateTree(int);

BST bst;

int main()
{
	bst = BST();
	cout << "Hello and Welcome to this cool program!" << endl;
	// Creates the tree
	cout << "Enter a number to create the tree: ";
	int num;
	cin >> num;
	CreateTree(num);

	int choice;
	while (true) 
	{
		Menu();
		cout << "Select a function: ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter the value you want to search: ";
			int search;
			cin >> search;
			bst.search(search);
			cout << "\n"; // Formattinh after bst.search();
		}
		else if (choice == 2)
		{
			cout << "Enter a value to add into the tree: ";
			int value;
			cin >> value;
			bst.insert(value);
		}
		else if (choice == 3)
		{
			cout << "Enter a value to remove from the tree: ";
			int value;
			cin >> value;
			bst.remove(value);
		}
		else if (choice == 4)
		{
			cout << "The values of the tree in ascending order are ~" << endl;
			bst.inorder();
			cout << "\n"; // Formatting after bst.inorder();
		}
		else if (choice == 5)
		{

		}
		else if (choice == 6)
		{

		}
		else if (choice == 0)
			break;
	}


	// Below is the end of the program
	system("PAUSE");
	return 0;
}

void Menu()
{
	cout << "----------------------------------------" << endl;
	cout << "[1] Search for a value" << endl;
	cout << "[2] Add a value" << endl;
	cout << "[3] Remove a value" << endl;
	cout << "[4] Display values in ascending order" << endl;
	cout << "[5] Display the value of a node" << endl;
	cout << "[6] Display the entire tree" << endl;
	cout << "[0] Exit" << endl;
	cout << "-----------------------------------------" << endl;
}

void CreateTree(int number)
{
	int total = number;
	int counter = 1;
	while (total > 0)
	{
		bst.insert(counter);
		total -= counter;
		++counter;
	}
}
