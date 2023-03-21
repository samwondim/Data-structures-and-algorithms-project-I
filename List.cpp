#include "List.h"
#include <iomanip>
#include <iostream>
#include <fstream>

void List::printGrade()
{
	Node* n = head;

	std::cout << "\n";
	system("cls");

	std::cout << "|" << std::setw(15) << "COURSE" << std::setw(5) << "|" << std::setw(15) << "RESULT" << std::setw(5) << "|" 
		<< std::setw(15)
		<< "GRADE" << std::setw(5) << "|\n";
	
	for (int i = 0; i < 60; i++) std::cout << "-";
	std::cout << "\n";

	while (n != NULL)
	{
		std::cout << "|" << std::setw(15) << n->data.getTitle() << std::setw(5) << "|" << std::setw(15)
			<< n->data.getGrade().getResult() << std::setw(5) << "|" << std::setw(15)
			<< n->data.getGrade().getGradeValue() << std::setw(5) << "|\n";
		n = n->next;
	}
	std::cout << std::endl;
}

void List::print()
{
	Node* n = head;
	
	std::cout << "|" << std::setw(15) << "TITLE" << std::setw(5) << "|" << std::setw(20)
		<< "COURSE NUMBER" << std::setw(15) << "CREDIT HOUR" << "|\n";

	while (n != NULL)
	{
		std::cout << "|" << std::setw(15) << n->data.getTitle() << std::setw(5) << "|" << std::setw(20)
			<< n->data.getId() << std::setw(15) << n->data.getCreditHr() << "|\n";
	
		n = n->next;
	}
	std::cout << std::endl;
}

bool List::isEmpty()
{
	return head == NULL;
}

void List::add(Course data)
{
	Node* end = new Node(data);
	if (isEmpty())
	{
		head = end;
		return;
	}

	Node* n = head;
	while (n->next != NULL)
	{
		n = n->next;
	}
	n->next = end;
}

void List::deleteNode(string cNum)
{
	Node* prev = NULL;
	Node* n = head;

	if (isEmpty())
	{
		std::cout << "course list empty" << std::endl;
		return;
	}

	if (n->data.getId() == cNum)
	{
		if (n->next == NULL)
		{
			head = NULL;
			delete n;
			return;
		}
		else
		{
			prev = n->next;
			head = prev;
			delete n;
			return;
		}
	}

	while (n->next != NULL)
	{
		if (n->next->data.getId() == cNum)
		{
			prev = n->next;
			n->next = n->next->next;
			delete prev;
			return;
		}
		n = n->next;
	}
}

List::Node* List::searchByNo(string cNum)
{
	Node* n = head;
	
	while (n != NULL)
	{
		if (n->data.getId() == cNum)
		{	
			return n;
		}
		n = n->next;
	}
	std::cout << "course not found!" << std::endl;
	return NULL;
}

List::Node::Node(Course data)
{
	this->data = data;
	next = NULL;
}

List::Node::Node() :next(NULL)
{
}

List::List() : head(NULL)
{	
}

void List::setMaxSize(int max_size)
{
	this->max_size = max_size;
}

int List::getMaxSize() const
{
	return max_size;
}

void List::printToFile(string id)
{
	ofstream f1,f2;

	f2.open("CourseRecord.txt", ios::app);
	Node* m = head;

	if (f2.is_open())
	{
		while (m != NULL)
		{
			f2 << "|" << std::setw(20) << id << std::setw(5) << "|" << std::setw(20)
				<< m->data.getTitle() << std::setw(5) << "|" << std::setw(15) <<
				m->data.getId() << std::setw(5)
				<< "|" << setw(10) << m->data.getCreditHr() << std::setw(2) << "|" << std::endl;
			m = m->next;
		}
		f2.close();
	}
	else
	{
		cout << "ERROR OPENING FILE CoursesRecord.txt!\n";
	}
}