// BSTDemo.cpp


#include "stdafx.h"
#include "BST.h"
#include<iostream>

using namespace std;

void displayMenu();

int main()
{
	BST bst;
	ItemType target;

	int dataArray[8] = { 7, 2,8,6,9,3,4,5 };

	for (int i=0; i<8; i++)
	{
		bst.insert(dataArray[i]);
	}

	int option = 1;

	while (option != 0)
	{
	  displayMenu();
	  cin >> option;

	  if (option == 1)	// display items
	  {
		  bst.inorder();
		  //cout << "Postorder:" << endl;
		  //bst.postorder();
		  //cout << "Preorder:" << endl;
		  //bst.preorder();
	  }
	  else	  
	  if (option == 2)	// search item
	  {
		  cout << "Enter a number to search : " ;
		  cin >> target;
		  BinaryNode* p = bst.search(target);
		  if (p != NULL)
		  {
			  cout << "Found" << endl;
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
			  cout << "Not found" << endl;
	  }
	  else
	  if (option == 3)	// add item
	  {
		  int n;
		  cout << "Enter a number to add : " ;
		  cin >> n;
		  bst.insert(n);
	  }
	  else
	  if (option == 4)	// delete item
	  {
		  int n;
		  cout << "Enter a number to delete : " ;
		  cin >> n;
		  bst.remove(n);
	  }
	  else
	  if (option == 5)	// display number of items
	  {
		  int n = bst.countNodes();
		  cout << "Number of items: " << n << endl;
	  }
		 	  
	  else
	  if (option == 6)	// display height
	  {
		  int n = bst.getHeight();
		  cout << "Height of tree: " << n << endl;
	  }

	  else
	  if (option == 7)	// check if tree is balanced
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
   cout << "Binary Search Tree Demo \n";
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



