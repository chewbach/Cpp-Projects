#include<iostream>

using namespace std;
#ifndef COURSE_H
#define COURSE_H
namespace PA3{
class Student;
class Course{

public:


    Course();
    Course(string _course_name,string _code);
    ~Course();
    string get_course_name();
    string get_code();
    void set_students(string _name,string _id);
    void  print_student_get_course();
    void remove_deleted_students(string student_name,string student_id);
    


private:

    string course_name;
    string code;
    Student **student = nullptr;
    int capacity = 10;
    int used = 0;
    void store_student(Student *address);

};
}
#endif
