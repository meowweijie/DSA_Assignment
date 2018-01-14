// BST.cpp

#include "stdafx.h"
#include <iostream>
#include <iomanip>  //setw
using namespace std;

#include <cstddef>  // for NULL
#include <new>      // for bad_alloc
#include "BST.h"

// constructor
BST::BST()
{
	root = NULL;
}

// search an item in the binary search tree
BinaryNode* BST::search(ItemType target)
{
	return search(root, target);
}

BinaryNode* BST::search(BinaryNode* t, ItemType target)
{
	if (t == NULL)	// item not found
		return NULL;
	else
	{
		if (t->item == target)	// item found
			return t;
		else
		if (target < t->item)	// search in left subtree
		   return search(t->left, target);  
		else // search in right subtree
		   return search(t->right, target);  
	}
}

// insert an item to the binary search tree
void BST::insert(ItemType item)
{
	insert(root, item);
}

void BST::insert(BinaryNode* &t, ItemType item)
{
	
	if (t == NULL)	//Insert the node at the empty location
	{
		BinaryNode *newNode = new BinaryNode;
		newNode->item = item;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->height = 0;
		t = newNode;

		
	}
	else if (item < t->item)
	{
		insert(t->left, item);  // insert in left subtree

		// AVL Code
		// Check the Balance factor
		if (getBalance(t) == 2)		// Unbalanced
		{
			// Left heavy
			if (item < t->left->item)
			{
				// Rotate Right
				t = rightRotate(t);
			}
			// Left heavy > Right heavy
			else
			{
				// Rotate Left > Rotate Right
				t = leftRightRotate(t);
			}
		}


	}
	else if (item > t->item)
	{
		insert(t->right, item); // insert in right subtree

		// AVL Code
		// Check the Balance factor
		if (getBalance(t) == 2)		// Unbalanced
		{
			// Right heavy
			if (item > t->right->item)
			{
				// Rotate Left
				t = leftRotate(t);
			}
			// Right heavy > Left heavy
			else
			{
				// Rotate Right > Rotate Left
				t = rightLeftRotate(t);
			}
		}

	}
	// else if duplicate
	else
	{
		cout << "Number already exists, cannot be inserted." << endl;
	}

	// Set the height
	t->height = max(height(t->left), height(t->right)) + 1;


}

// delete an item from the binary search tree
void BST::remove(ItemType target)
{
	remove(root, target);
}

void BST::remove(BinaryNode* &t, ItemType target)
{
	// search for the node to be deleted

	// To track the parent node of the node to be deleted
	BinaryNode* temp;
	// To track the parent node to be balanced
	//BinaryNode* temp2 = NULL;

	//Element not found
	if (t == NULL)
		cout << "Target element not found!" << endl;

	//Searching for the element
	else if (target < t->item)
	{
		remove(t->left, target);
	}
	else if (target > t->item)
	{
		remove(t->right, target);
	}

	//FOUND
	else if (target == t->item)
	{
		// -----------------------  case 1 : node is a leaf ------------------------
		if (t->left == NULL && t->right == NULL)
		{
			temp = t;
			t = NULL;
			free(temp);
		}

		// -----------------------  case 2 : node has only 1 child  ----------------
		// node has a right child
		else if (t->left == NULL)
		{
			temp = t->right;
			t = t->right;
			free(temp);
		}
		// node has a left child
		else if (t->right == NULL)
		{
			temp = t->left;
			t = t->left;
			free(temp);
		}

		// -----------------------  case 3 : node has 2 children  ------------------
		else if (t->left && t->right)
		{
			// find the successor ( rightmost child in the node�s left subtree)
			BinaryNode* successor = t->left;
			while (successor->right != NULL)
				successor = successor->right;
			// replace the node�s item with that of the successor
			int n = successor->item;
			// delete the successor (either case 1 or case 2)
			remove(t, n);
			// replace the node�s item with that of the successor
			t->item = n;

		}
	}
	

	// Check if t = NULL
	if (t == NULL)
		return;

	// Update height
	t->height = max(height(t->left), height(t->right)) + 1;

	// If node is unbalanced
	if (!isBalanced(t))
	{
		// Right heavy
		if ((height(t->left) - height(t->right)) < -1)
		{
			// For checking balance
			temp = t->right;

			// right right case
			if ((height(temp->left)-height(temp->right)) <= 0)
				t = leftRotate(t);
			// right left case
			else
				t = rightLeftRotate(t);
		}
		else if ((height(t->left) - height(t->right)) > 1)
		{
			// For checking balance
			temp = t->left;

			// left left case
			if ((height(temp->left) - height(temp->right)) >= 0)
				t = rightRotate(t);
			// left right case
			else
				t = leftRightRotate(t);
		}
	
		
	}
}

// traverse the binary search tree in inorder
void BST::inorder()
{
	if ( isEmpty() )
		cout << "No item found" << endl;
	else
		inorder(root);
}

void BST::inorder(BinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);
		cout << t->item <<" " << t->height<< endl;
		inorder(t->right);
	}
}
// traverse the binary search tree in preorder
void BST::preorder()
{
	if ( isEmpty() )
		cout << "No item found" << endl;
	else
		preorder(root);
}

void BST::preorder(BinaryNode* t)
{
	if (t != NULL)
	{
		cout << t->item << endl;
		preorder(t->left);
		preorder(t->right);
	}
}

// traverse the binary search tree in postorder
void BST::postorder()
{
	if ( isEmpty() )
		cout << "No item found" << endl;
	else
		postorder(root);
}

void BST::postorder(BinaryNode* t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout << t->item << endl;
	}
}



// compute the height of the binary search tree
int BST::getHeight()
{
	return getHeight(root);
}

int BST::getHeight(BinaryNode* t)
{
	if (t == NULL)
		return 0;	//No height
	else
	{
		return 1 + max(getHeight(t->left), getHeight(t->right));

	}
		
}

// count the number of nodes in the binary search tree
int BST::countNodes()
{
	return countNodes(root);
}

int BST::countNodes(BinaryNode* t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + countNodes(t->left) + countNodes(t->right);
}

// check if the binary search tree is balanced
bool BST::isBalanced()
{
	return isBalanced(root);
}

bool BST::isBalanced(BinaryNode *t)
{
	if (t != NULL)
	{
		int leftHeight = getHeight(t->left);	// height of left sub-tree

		int rightHeight = getHeight(t->right);	// height of right sub-tree

		bool isBalancedNode = (abs(leftHeight - rightHeight) <= 1);

		return (isBalancedNode && isBalanced(t->left) && isBalanced(t->right));
		
	}
	else
		return true;
}

// check if the binary search tree is empty
bool BST::isEmpty()
{
	return (root == NULL);
}


// MAX function
int BST::max(int a, int b)
{
	return (a > b) ? a : b;
}

// get Balance factor
int BST::getBalance(BinaryNode *t)
{
	if (t != NULL)	// Get the balance factor of the node.
	{
		return abs(getHeight(t->left) - getHeight(t->right));

	}
	else
		return 0;		// Invalid
}

// height function
// return height value of a particular node
int BST::height(BinaryNode *t)
{
	if (t == NULL)
		return 0;	//No height
	else
	{
		return t->height;
	}
}

// AVL Rotation code
// Right Rotation
BinaryNode* BST::rightRotate(BinaryNode* &t)
{
	BinaryNode* u = t->left;
	t->left = u->right;		// In case u->right has a node
	u->right = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	u->height = max(height(u->left), t->height) + 1;
	return u;
}

// Right-Left Rotation
BinaryNode* BST::rightLeftRotate(BinaryNode* &t)
{
	t->right = rightRotate(t->right);
	return leftRotate(t);
}

// Left Rotation
BinaryNode* BST::leftRotate(BinaryNode* &t)
{
	BinaryNode* u = t->right;
	t->right = u->left;
	u->left = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	u->height = max(height(t->right), t->height) + 1;
	return u;
}

// Left-Right Rotation
BinaryNode* BST::leftRightRotate(BinaryNode* &t)
{
	t->left = leftRotate(t->left);
	return rightRotate(t);
}
