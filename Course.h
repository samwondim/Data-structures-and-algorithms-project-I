#ifndef COURSE_H
#define COURSE_H
#include <iostream>

using namespace std;

class Course
{
public:
	class Grade
	{
	public:
		Grade(float);
		Grade();

		string getGradeValue() const;
		void setGradeValue(string);
		
		float getResult() const;
		void setResult(float);

	private:
		string gradeValue;
		float result;
	};

	string getTitle() const;
	void setTitle(string);

	string getId() const;
	void setId(string);

	int getCreditHr() const;
	void setCreditHr(int);

	void setGrade(Grade);
	Grade getGrade() const;

	void printData();

	Course(string title, string id, int credit_hr);
	Course();

private:
	string title;
	string id;
	int credit_hr;
	Grade gr;
};

#endif

