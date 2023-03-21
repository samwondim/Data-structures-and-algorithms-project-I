#include "Course.h"
#include <iomanip>

#include <iostream>
using namespace std;

Course::Course(string title, string id, int credit_hr)
{
	setTitle(title);
	setCreditHr(credit_hr);
	setId(id);
}

Course::Course()
{
}

void Course::setId(string id)
{
	this->id = id;
}

string Course::getId() const
{
	return this->id;
}

void Course::setTitle(string title)
{
	this->title = title;
}

void Course::setCreditHr(int credit_hr)
{
	this->credit_hr = credit_hr;
}

int Course::getCreditHr() const
{
	return credit_hr;
}

string Course::getTitle() const
{
	return title;
}

void Course::setGrade(Grade gr)
{
	this->gr = gr;
}

Course::Grade::Grade()
{
	gradeValue = "Null";
	result = 0;
}

Course::Grade::Grade(float result)
{
	this->result = result;
	if (result >= 90 && result <= 100) setGradeValue("A+");
	else if (result <= 89 && result >= 84) setGradeValue("A");
	else if (result <= 83 && result >= 80) setGradeValue("A-");
	else if (result <= 79 && result >= 75) setGradeValue("B+");
	else if (result <= 74 && result >= 68) setGradeValue("B");
	else if (result <= 67 && result >= 65) setGradeValue("B-");
	else if (result <= 60 && result >= 50) setGradeValue("C");
	else setGradeValue("F");
}

Course::Grade Course::getGrade() const
{
	return gr;
}

string Course::Grade::getGradeValue() const
{
	return gradeValue;
}

void Course::Grade::setGradeValue(string gradeValue)
{
	this->gradeValue = gradeValue;
}

void Course::Grade::setResult(float result)
{
	this->result = result;
}

float Course::Grade::getResult() const
{
	return result;
}

void Course::printData()
{
	for (int i = 0; i < 61; i++) cout << "-";
	cout << endl;

	cout << "|" << setw(15) << getTitle() << setw(5) << "|" <<
		setw(15) << getId() << setw(5) << "|" << setw(15) << getCreditHr() << setw(5) << "|" << endl;
}