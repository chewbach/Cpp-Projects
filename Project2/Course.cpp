#include<iostream>
#include "Course.h"
#include"SchoolManagerSystem.h"
using namespace std;
namespace PA3{
Course :: Course(){					//default constructor
    course_name = "";
    code = "";
    student = new Student*[capacity];
}


Course :: Course(string _course_name,string _code){	// constructor
    course_name = _course_name;
    code = _code;
    student = new Student*[capacity];
}

string Course :: get_course_name(){			//getter for course name
    return course_name;
}

string Course :: get_code(){				//getter for course code
    return code;
}

Course :: ~Course(){					//destructor
    delete [] student;
}

void Course :: set_students(string _name,string _id){ //create an object

        Student * temp = new Student (_name,_id);	//create an temp object for create Student object
        store_student(temp);				//send address of object store student function

    }

void Course :: store_student(Student *address){	//this function have temp object address for add actual address
     if(used>=capacity){
        capacity = capacity + 10;
        Student **temp = new Student*[capacity];
         for(int i = 0;i<capacity-10;i++){
            temp[i] = student[i];
        }
        delete [] student;
        student = temp;
    }
    
    student[used++]=address;


}

void Course :: print_student_get_course(){		//print stundet that registered from course
    for(int i=0;i<used;i++){
        cout<<student[i]->get_name()<<" "<<student[i]->get_id()<<endl;
    }
}

void Course :: remove_deleted_students(string student_name,string student_id){	//	remove deleted student if course have that student
        int i,j;
        Student **temp = new Student*[capacity];
        for( i=0,j=0;i<used;i++){
            if(student_name != student[i]->get_name() && student_id !=  student[i]->get_id()){
                temp[j++] = student[i];
            }
        }

        delete [] student;
        student = temp;
        used = used-1;

}
}

  
