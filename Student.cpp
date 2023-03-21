#include "Student.h"
#include <iomanip>
#include <iostream>
using namespace std;

Student::Student(string firstname, string lastname, 
	string sex, string id, int age)
{
	setFirstname(firstname);
	setLastname(lastname);
	setSex(sex);
	setId(id);
	setAge(age);
}

void Student::setFirstname(string firstname)
{
	this->firstname = firstname;
}

string Student::getFirstname() const
{
	return firstname;
}

void Student::setLastname(string lastname)
{
	this->lastname = lastname;
}

string Student::getLastname() const
{
	return lastname;
}

void Student::setSex(string sex)
{
	this->sex = sex;
}

string Student::getSex() const
{
	return sex;
}

void Student::setId(string id)
{
	this->id = id;
}

string Student::getId() const
{
	return id;
}

void Student::setAge(int age)
{
	this->age = age;
}

int Student::getAge() const
{
	return age;
}

Student::Student()
{

}

List Student::getCourse() const
{
	return courses;
}

void Student::setCourse(List courses)
{
	this->courses = courses;
}

void Student::printData()
{
	std::cout << "|" << std::setw(20) << "Firstname" << std::setw(5) << "|"
		<< std::setw(20) << "Lastname" << std::setw(5) << "|" <<
		std::setw(15) << "Id" << std::setw(5) << "|" << std::setw(10) << "Sex" << std::setw(5)
		<< "|" << std::setw(10) << "Age" << std::setw(2) << "|" << std::endl;

	for (int i = 0; i < 96; i++) std::cout << "-";
	std::cout << std::endl;
	std::cout << "|" << std::setw(20) << getFirstname() << std::setw(5) << "|"
		<< std::setw(20) << getLastname() << std::setw(5) << "|" <<
		std::setw(15) << getId() << std::setw(5) << "|" << std::setw(10) << getSex() << std::setw(5)
		<< "|" << std::setw(10) << getAge() << std::setw(2) << "|" << std::endl;

}
