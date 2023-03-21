#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Student.h"

#include <iostream>
using namespace std;

class LinkedList
{
public:
	class Node
	{
	public:
		Node(Student);

		Student data;
		Node* next;
	};
public:
	Node* head;

	void add(Student);
	void print();
	Node* searchById(string);
	void sort();
	void deleteStudent(string);
	void manageGrade();
	void regCourse();
	bool isEmpty();
	void deleteCourse(string id);
	void printCourse(Student*);
	void printToFile();
	
	LinkedList();
};

#endif