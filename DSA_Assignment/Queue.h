#pragma once
typedef int ItemType;

/** ADT queue - Pointer-based implementation. */
class Queue
{
private:
	struct Node
	{
		ItemType item;
		Node    *next;
	};
	
	Node *frontNode;
	Node *backNode;
	
public:
   Queue();
   ~Queue();

   bool isEmpty() const;
   bool enqueue(const ItemType& item);
   bool dequeue();
   bool dequeue(ItemType& item);
   void getFront(ItemType& item) const;

};