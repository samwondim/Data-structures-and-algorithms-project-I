#ifndef STUDENT_H
#define STUDENT_H
#include "Course.h"
#include "List.h"
#include <iostream>

using namespace std;

class Student
{
public:
	Student(string firstname, string lastname, string sex,
		string id, int age);

	Student();
	void setFirstname(string);
	string getFirstname() const;

	void setLastname(string);
	string getLastname() const;

	void setSex(string);
	string getSex() const;

	void setId(string);
	string getId() const;

	void setAge(int);
	int getAge() const;

	List getCourse() const;
	void setCourse(List);

	void printData();

private:
	string firstname;
	string lastname;
	string id;
	string sex;
	int age;
	List courses;
};

#endif

