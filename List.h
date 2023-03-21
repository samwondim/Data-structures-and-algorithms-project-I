#ifndef LIST_H
#define LIST_H
#include "Course.h"
#include <iostream>
using namespace std;

class List
{
public:
	class Node
	{
	public:
		Course data;
		Node* next;

		Node(Course);
		Node();
	};

	Node* head;

	void add(Course);
	void deleteNode(string);
	void print();
	void printGrade();
	Node* searchByNo(string);
	int getMaxSize() const;
	void setMaxSize(int);
	bool isEmpty();
	void printToFile(string);

	List();
private:
	int max_size;
};

#endif

