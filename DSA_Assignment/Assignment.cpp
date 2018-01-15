
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
