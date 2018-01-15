// BSTDemo.cpp


#include "stdafx.h"
#include "BST.h"
#include<iostream>

using namespace std;

void displayMenu();
BST CreateTree(int, BST);

void notmain()
{
	BST bst;
	ItemType target;

	cout << "Hello and Welcome to this cool program!" << endl;
	// Creates the tree
	cout << "Enter a number to create the tree: ";
	int num;
	cin >> num;
	bst = CreateTree(num, bst);

	int option = 1;

	while (option != 0)
	{
		displayMenu();
		cin >> option;
		
		
		// display items
		if (option == 1)	
		{
			bst.inorder();
			
		}
		// search item
		else
			if (option == 2)	
			{
				cout << "Enter a number to search : ";
				cin >> target;
				BinaryNode* p = bst.search(target);
				if (p != NULL)
				{

					cout << "[Item Found!]" << endl;
					cout << "Item:" << p->item << endl;
					if (p->left == NULL)
						cout << "Left NULL" << endl;
					else
						cout << "Left:" << p->left->item << endl;
					if (p->right == NULL)
						cout << "Right NULL" << endl;
					else
						cout << "Right:" << p->right->item << endl;
				}
				else
					cout << "[Item Not found!]" << endl;
			}
			// add item
			else
				if (option == 3)	
				{
					int n;
					cout << "Enter a number to add : ";
					cin >> n;
					bst.insert(n);
				}
				// delete item
				else
					if (option == 4)	
					{
						int n;
						cout << "Enter a number to delete : ";
						cin >> n;
						bst.remove(n);
					}
					// display number of items
					else
						if (option == 5)		
						{
							int n = bst.countNodes();
							cout << "Number of items: " << n << endl;
						}
						// display height	
						else
						if (option == 6)		
						{
							int n = bst.getHeight();
							cout << "Height of tree: " << n << endl;
						}
						// check if tree is balanced
						else
						if (option == 7)	
						{
							bool n = bst.isBalanced();
							if (n)
							{
								cout << "Balanced? YES" << endl;
							}
							else
							{
								cout << "Balanced? NO" << endl;
							}
						}

						else
						if (option == 0)
							cout << "Bye! \n";
						else
							cout << "Sorry. You have entered an invalid option. \n";

	}


}

void displayMenu()
{
	cout << endl;
	cout << "Binary Search Tree (AVL) \n";
	cout << "--------------------------------\n";
	cout << "1 Display all the items in order\n";
	cout << "2 Search for an item \n";
	cout << "3 Add a new item \n";
	cout << "4 Delete an item \n";
	cout << "5 Display total number of items \n";
	cout << "6 Display the height \n";
	cout << "7 Check if tree is balanced \n";
	cout << "0 Exit \n";
	cout << "--------------------------------\n";
	cout << "Enter option : ";
}

BST CreateTree(int number, BST bst)
{
	int total = 0;
	int counter = 1;
	while (total < number)
	{
		bst.insert(counter);
		total += counter;
		++counter;
	}
	return bst;
}