// DSA_Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BST.h"
#include<iostream>

using namespace std;


int main0()
{
	BST bst;

	int dataArray[10] = { 55, 28, 87, 32, 90, 16, 45, 79, 66, 37 };
	cout << "Github Test" << endl;
	cout << "Github Test 2" << endl;
	for (int i = 0; i<10; i++)
	{
		cout << i << ". " << endl;
		bst.insert(dataArray[i]);
	}

	system("PAUSE");
    return 0;
}

