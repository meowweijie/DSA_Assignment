#include "stdafx.h"
#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
	frontNode = NULL;
	backNode = NULL;
}

Queue::~Queue()
{
}

bool Queue::isEmpty() const
{
	if (frontNode == NULL)
		return true;
	else
		return false;
}
 bool Queue::enqueue(const ItemType& item)
 {
	 // Creating the node
	 Node* node = new Node();
	 node->item = item;
	 node->next = NULL;

	 // Adding it to the back of the queue
	 if (!isEmpty())
		 backNode->next = node;
	 else
		 frontNode = node;

	 backNode = node;
	 return true;
 }

 bool Queue::dequeue()
 {
	 if (!isEmpty())
	 {
		 Node* temp = frontNode;
		 if (frontNode == backNode)
		 {
			 frontNode = NULL;
			 backNode = NULL;
		 }
		 else
			 frontNode = frontNode->next;
		 // Deleting the node
		 temp->next = NULL;
		 delete(temp);
		 return true;
	 }
	 else
		 return false;
 }

 bool Queue::dequeue(ItemType& item)
 {
	 if (!isEmpty())
	 {
		 Node* temp = frontNode;
		 if (frontNode == backNode)
		 {
			 frontNode = NULL;
			 backNode = NULL;
		 }
		 else
		 {
			 frontNode = frontNode->next;
			 item = temp->item;
		 }
		 // Deleting the node
		 temp->next = NULL;
		 delete(temp);
		 return true;
	 }
	 else
		 return false;
 }

 ItemType Queue::getFront()
 {
	 if (!isEmpty())
		 return frontNode->item;
 }

 void Queue::DisplayQueue()
 {
	 Node* node = frontNode;
	 while (true)
	 {
		 cout << "Value in the node: " << node->item << endl;
		 if (node->next != NULL)
			 node = node->next;
		 else
			 break;
	 }
 }



