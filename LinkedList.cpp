#include "LinkedList.h"
#include "List.h"
#include "Student.h"
#include "Course.h"
#include <iomanip>
#include <iostream>
#include <fstream>

void LinkedList::manageGrade()
{
	std::string id, cnum;

	std::cout << "Enter student id: ";
	std::cin >> id;

	Node* s = searchById(id);
	List list = s->data.getCourse();
	
	if (s == NULL)
	{
		std::cout << std::setw(40) << "No student with id " << id << " exists!\n";
		return;
	}
	
LOOP:
	std::cout << "Enter course number: ";
	std::cin >> cnum;
	
	List::Node* c = list.searchByNo(cnum);
	if (c != NULL)
	{
		float result;
		std::cout << "Enter result: ";
		std::cin >> result;
		
		Course::Grade grade(result);
		
		c->data.setGrade(grade);
		s->data.setCourse(list);
		
		list.printGrade();
	}
	else
	{
		std::cout << "student has not registered to course with course number " << cnum << std::endl;
		goto LOOP;
	}
}

bool LinkedList::isEmpty()
{
	return head == NULL;
}

void LinkedList::regCourse()
{
	std::string id, cname, cnum;
	int cr_hr;
l:
	std::cout << "Enter student Id: ";
	std::cin >> id;
	List list;

	if (searchById(id) == NULL)
	{
		std::cout << "no student with id " << id << " exists! \n";
		goto l;
		return;
	}

	std::cout << "Enter course title: ";
	std::cin >> cname;
	std::cout << "Enter course number: ";
	std::cin >> cnum;
	std::cout << "Enter credit hour: ";
LOOP:
	std::cin >> cr_hr;

	if (cin.fail())
	{
		cout << "Invalid input, please enter an integer!\n";
		cin.clear();
		cin.ignore();
		goto LOOP;
	}

	Course course(cname, cnum, cr_hr);
	Node* s = searchById(id);

	if (s->data.getCourse().isEmpty())
	{
		list.add(course);
		s->data.setCourse(list);
		return;
	}
	s->data.getCourse().add(course);
}

LinkedList::Node::Node(Student data)
{
	this->data = data;
}

void LinkedList::add(Student data)
{
	Node* end = new Node(data);
	
	if (head == NULL)
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

void LinkedList::print()
{
	Node* n = head;

	std::cout << "|" << std::setw(20) << "FIRSTNAME" << std::setw(5) << "|"
		<< std::setw(20) << "LASTNAME" << std::setw(5) << "|" <<
		std::setw(15) << "ID" << std::setw(5) << "|" << std::setw(10) << "SEX" << std::setw(5)
		<< "|" << std::setw(10) << "AGE" << std::setw(2) << "|" << std::endl;

	for (int i = 0; i < 98; i++) cout << "-";
	
	if (isEmpty())
	{
		std::cout << std::endl;
		std::cout << "Record Empty!\n";
		return;
	}
	while (n != NULL)
	{
		std::cout << std::endl;

		std::cout << "|" << std::setw(20) << n->data.getFirstname() << std::setw(5) << "|"
			<< std::setw(20) << n->data.getLastname() << std::setw(5) << "|" <<
			std::setw(15) << n->data.getId() << std::setw(5) << "|" << 
			std::setw(10) << n->data.getSex() << std::setw(5)
			<< "|" << std::setw(10) << n->data.getAge() << 
			std::setw(2) << "|" << std::endl;

		n = n->next;
	}
}

void LinkedList::printToFile()
{
	ofstream f1, fout;

	fout.open("record.txt", ios::out);
	
	f1.open("CourseRecord.txt", ios::app);
	
	f1 << "|" << std::setw(20) << "ID NUMBER" << std::setw(5) << "|" << std::setw(20)
		<< "COURSE TITLE" << std::setw(5) << "|" << std::setw(15) << "COURSE NO" << std::setw(5)
		<< "|" << setw(10) << "CREDIT HR" << std::setw(2) << "|" << std::endl;
	f1.close();

	if (fout.is_open())
	{
		Node* n = head;
		string id;

		fout << "|" << std::setw(20) << "FIRSTNAME" << std::setw(5) << "|"
		<< std::setw(20) << "LASTNAME" << std::setw(5) << "|" <<
		std::setw(15) << "ID" << std::setw(5) << "|" << std::setw(10) << "SEX" << std::setw(5)
		<< "|" << std::setw(10) << "AGE" << std::setw(2) << "|" << std::endl;
		
		for (int i = 0; i < 98; i++) fout << "-";

		if (isEmpty())
		{
			std::cout << std::endl;
			std::cout << "Record Empty!\n";
			return;
		}

		while (n != NULL)
		{
			fout << std::endl;
			fout << "|" << std::setw(20) << n->data.getFirstname() << std::setw(5) << "|"
				<< std::setw(20) << n->data.getLastname() << std::setw(5) << "|" <<
				std::setw(15) << n->data.getId() << std::setw(5) << "|" <<
				std::setw(10) << n->data.getSex() << std::setw(5)
				<< "|" << std::setw(10) << n->data.getAge() <<
				std::setw(2) << "|" << std::endl;
			
			id = n->data.getId();

			n->data.getCourse().printToFile(id);
			n = n->next;
		}
		fout.close();
	}
	else cout << "ERROR OPENING FILE!\n";
}

LinkedList::Node* LinkedList::searchById(string id)
{
	Node* n = head;

	while (n != NULL)
	{
		if (n->data.getId() == id)
		{
			return n;
		}
		n = n->next;
	}
	std::cout << "record not found!" << std::endl;
	return NULL;
}

void LinkedList::deleteStudent(string s_id)
{
	Node* n = head;
	Node* prev = NULL;

	if (n->data.getId() == s_id)
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
		if (n->next->data.getId() == s_id)
		{
			prev = n->next;
			n->next = n->next->next;
			delete prev;
			return;
		}
		n = n->next;
	}
}

void LinkedList::sort()
{
	Node* current, *index;
	
	current = head;
	index = NULL;
	
	string fname, lname,id,sex;
	int age;
	List course;

	while (current != NULL)
	{
		index = current->next;
		while (index != NULL)
		{
			if (current->data.getFirstname() > index->data.getFirstname() || 
				current->data.getLastname() > index->data.getLastname())
			{
				fname = current->data.getFirstname();
				lname = current->data.getLastname();
				id = current->data.getId();
				sex = current->data.getSex();
				age = current->data.getAge();
				course = current->data.getCourse();

				current->data.setFirstname(index->data.getFirstname());
				current->data.setLastname(index->data.getLastname());
				current->data.setId(index->data.getId());
				current->data.setSex(index->data.getSex());
				current->data.setAge(index->data.getAge());
				current->data.setCourse(index->data.getCourse());

				index->data.setFirstname(fname);
				index->data.setLastname(lname);
				index->data.setId(id);
				index->data.setSex(sex);
				index->data.setAge(age);
				index->data.setCourse(course);

			}
			index = index->next;
		}
		current = current->next;
	}
}

LinkedList::LinkedList() : head(NULL)
{
}

void LinkedList::deleteCourse(string id)
{
	string cnum;
	Node *s = searchById(id);
	List list = s->data.getCourse();

	if (s == NULL)
	{
		std::cout << "No student with id " << id << " exists in record!\n";
		return;
	}
	else
	{
		std::cout << "Enter course number: ";
		std::cin >> cnum;
		
		list.deleteNode(cnum);
		s->data.setCourse(list);

		printCourse(&s->data);
	}
}

void LinkedList::printCourse(Student* s)
{
	s->getCourse().print();
}
