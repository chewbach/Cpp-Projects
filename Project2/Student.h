#include<iostream>

using namespace std;


#ifndef STUDENT_H
#define STUDENT_H

namespace PA3{
class Course;
class Student{
    public:

    Student();
    Student(string _name,string _id);
    ~Student();
    string get_name();
    string get_id();
    void set_courses(string crs_name,string crs_code);
    void print_courses_get_from_student();
    bool check_student_register_course(string course_name,string course_code);
    void drop_selected_student_from_a_course(int choice);
    int get_used();
    void remove_deleted_course(string course_name,string course_code);
   string selected_name(int choice);
   string selected_id(int choice);


    private:
    string name;
    string id;
    Course **course = nullptr;
    int capacity = 10;
    int used = 0;
    void store_course(Course *address);

};
}
#endif
