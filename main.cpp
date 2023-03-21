#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

#include "LinkedList.h"
#include "Student.h"
#include "List.h"

using namespace std;

int main()
{
    LinkedList list;
        
    int option;
	
	do
	{
        if (list.isEmpty()) cout << setw(25) << "RECORD IS EMPTY :(\n";
        
        cout << endl;
        cout << setw(54) << "CHOOSE OPTION\n";
        cout << endl;
        cout << setw(54) << "1. Register student" << endl;
        cout << setw(53) << "2. Register course" << endl;
        cout << setw(52) << "3. Search student" << endl;
        cout << setw(51) << "4. Search course" << endl;
        cout << setw(55) << "5. View all students" << endl;
        cout << setw(52) << "6. Delete student" << endl;
        cout << setw(42) << "7. Sort" << endl;
        cout << setw(51) << "8. Delete course" << endl;
        cout << setw(50) << "9. Manage grade" << endl;
        cout << setw(45) << "0. EXIT" << endl << endl;

LOOP:
        cin >> option;

        if (cin.fail())
        {
            cout << "Invalid input, please input an integer\n";
            cin.clear();
            cin.ignore();
        }
        switch (option)
        {
        case 0: goto EXIT;
        case 1: 
        {
            system("cls");
            string fname, lname, id, sex;
            int age;
            
            cout << setw(65) << "STUDENT REGISTERATION CONSOLE" << endl;
            cout << endl;
            cout << "Firstname: ";
            cin >> fname;
            cout << "Lastname: ";
            cin >> lname;
            cout << "Id: ";
            cin >> id;
            cout << "Sex: ";
            cin >> sex;
            cout << "Age: ";
            cin >> age;

            Student student(fname, lname, sex, id, age);
            list.add(student);

            system("cls");
            cout << "successfully registered!\n";
        }
            break;
        case 2:
        {
            system("cls");
            
            cout << setw(65) << "STUDENT-COURSE REGISTERATION CONSOLE" << endl;
            cout << endl;
            
            list.print();
            list.regCourse();

            system("cls");
            
            cout << "succesfull registered!\n";
        }
            break;
        case 3:
        {
            system("cls");
            string id;

            cout << setw(55) << "SEARCH CONSOLE" << endl;
            cout << setw(65) << "Input Id number to display student" << endl;
            cout << endl;

            cout << "Id: ";
            cin >> id;
            
            if (list.searchById(id) == NULL)
            {
                cout << "student with id " << id << " doesn't exist!\n";
            }
            else 
            {
                system("cls");
                list.searchById(id)->data.printData();
            }
        }
            break;
        case 4:
        {
            string id,cnum;
            system("cls");

            cout << setw(25) << "SEARCH COURSE" << endl;
            cout << setw(20) << "First enter student id\n";
            cout << "Id: ";
            cin >> id;
            
            if (list.searchById(id) != NULL)
            {
                cout << "Enter course number: ";
                cin >> cnum;
                system("cls");

                list.searchById(id)->data.getCourse().searchByNo(cnum)->data.printData();
            }
            else
            {
                cout << "Studnet with Id " << id << " doesn't seem to exist in the record :(\n";
            }
        }
        break;
        case 5:
        {
            system("cls");

            cout << setw(75) << "ALL STUDENTS\n";
            
            if (list.isEmpty())
            {
                cout << setw(25) << "RECORD IS EMPTY :(\n";
            }
            else
            {
                list.print();
                list.printToFile();
            }
        }
        break;
        case 6:
        {
            system("cls");
            cout << setw(75) << "DELETE STUDENT\n";

            if (list.isEmpty())
            {
                cout << setw(25) << "RECORD IS EMPTY :(\n";
            }
            else
            {
                list.print();
                cout << endl;

                string id;
                cout << "Enter ID: ";
                cin >> id;

                list.deleteStudent(id);
                system("cls");

            }
        }
        break;
        case 7:
        {
            if (list.isEmpty())
            {
                cout << setw(25) << "RECORD IS EMPTY :(\n";
            }
            else
            {
                list.sort();
                system("cls");
                cout << setw(25) << "SORTED LIST\n";
                list.print();
            }
        }
        break;
        case 8:
        {
            system("cls");
            cout << setw(55) << "DELETE COURSE" << endl;
            list.print();

            string id, cnum;
            cout << "Student ID: ";
            cin >> id;

            if (list.searchById(id) != NULL)
            {
                system("cls");
                list.searchById(id)->data.getCourse().print();
                
                list.deleteCourse(id);
            }
        }
        break;
        case 9:
        {
            system("cls");
            cout << setw(55) << "MANAGE GRADE" << endl;
            
            list.print();
            list.manageGrade();
        }
            break;
        default:
            goto LOOP;
            break;
        }

	} while (option != 0);
    
EXIT:
    system("cls");
    cout << setw(65) << "GOOD BYE!" << endl;
	
    return 0;
}

