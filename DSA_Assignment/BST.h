// BST.h

#include "BinaryNode.h"


class BST
{
  private:

	BinaryNode* root;		// root of the BST

  public:
	
    // constructor
    BST();

	// search an item in the binary search tree
	BinaryNode* search(ItemType target);
	BinaryNode* search(BinaryNode* root, ItemType target);

	BinaryNode* normalSearch(ItemType target);
	BinaryNode* normalSearch(BinaryNode* root, ItemType target);

	// insert an item to the binary search tree
	void insert(ItemType item);
	void insert(BinaryNode* &root, ItemType item);

	// delete an item from the binary search tree
	void remove(ItemType target);
	void remove(BinaryNode* &root, ItemType target);

	// traverse the binary search tree in inorder
	void inorder();
	void inorder(BinaryNode* t);

	// traverse the binary search tree in preorder
	void preorder();
	void preorder(BinaryNode* t);

	// traverse the binary search tree in postorder
	void postorder();
	void postorder(BinaryNode* t);

	// traverse the binary search tree level by level
	void levelbylevel(int k);

	// compute the height of the binary search tree
	int getHeight();
	int getHeight(BinaryNode* t);

	// count the number of nodes in the binary search tree
	int countNodes();
	int countNodes(BinaryNode* t);

	// check if the binary search tree is empty
	bool isEmpty();

	// check if the binary search tree is balanced
	bool isBalanced();
	bool isBalanced(BinaryNode *t);


	// Addition for AVL tree
	// max funtion
	int max(int a, int b);

	// gets Balance factor (for the AVL tree rotation)
	int getBalance(BinaryNode *t);

	// height function
	int height(BinaryNode *t);

	//AVL rotation code
	BinaryNode* rightRotate(BinaryNode* &t);
	BinaryNode* rightLeftRotate(BinaryNode* &t);
	BinaryNode* leftRotate(BinaryNode* &t);
	BinaryNode* leftRightRotate(BinaryNode* &t);

	void DisplayTree();

};
