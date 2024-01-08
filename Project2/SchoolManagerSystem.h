#include<iostream>
#include<string>
#include "Student.h"
#include "Course.h"
using namespace std;

#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

namespace PA3{
class SchoolManagerSystem{

public:

SchoolManagerSystem();
~SchoolManagerSystem();
void main_menu();
void menu_student();
void add_student();
void select_student();
void menu_course();
void add_course();
void select_course();
void select_student_menu(int pos);
void select_course_menu(int pos);
void add_students_to_course(int pos);
void list_all_students();
void list_all_courses();
void drop_student_from_course(int pos);
void delete_(int k,int pos);




private:

 Student ** std = nullptr;		//dynamically created Student object
 int number_of_students = 0;
 int student_capacity = 10;
 void store_student(Student* address); //send address of an object
 Course ** crs = nullptr;		//dynamically created Course object
 int number_of_course = 0;
 int course_capacity = 10;
 void store_course(Course* address);	//send address of an object
};
}
#endif
