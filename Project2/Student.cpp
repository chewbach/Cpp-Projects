#include<iostream>
#include"Student.h"
#include"SchoolManagerSystem.h"
using namespace std;

namespace PA3{
Student :: Student(){					//default constructor
    name = "";
    id = "";
    course = new Course*[capacity];
}

Student :: Student(string _name,string _id){		//constructor
    name = _name;
    id = _id;
    course = new Course*[capacity];
}

string Student :: get_name(){				//getter for name

    return name;
}

string Student :: get_id(){				//getter for id
    return id;
}

void Student :: set_courses(string crs_name,string crs_code){	//create an object
      
    Course * temp = new Course(crs_name,crs_code);			//create an temp object for create Course object
     store_course(temp);						//send address of object store course function
    
}

void Student :: store_course(Course *address){			//this function have temp object address for add actual address
    if(used>=capacity){
        capacity = capacity + 10;
        Course **temp = new Course*[capacity];
         for(int i = 0;i<capacity-10;i++){
            temp[i] = course[i];
        }
        delete [] course;
        course = temp;
    }
    
    course[used++]=address;
  
}






Student :: ~Student(){							//destructor

    delete [] course;
}

bool Student :: check_student_register_course(string course_name,string course_code){	//checks if the student is enrolled in the course
    bool check = true;
    
    for(int i = 0; i<used;i++){
        if(course[i]->get_code() == course_code && course[i]->get_course_name() == course_name){
            check = false;
            break;
        }
    }
    return check;
}


void Student :: print_courses_get_from_student(){						//print courses gets from stundent

    for(int i=0;i<used;i++){
        cout<<i+1<<" "<<course[i]->get_code()<<" "<<course[i]->get_course_name()<<endl;
}

}


void Student :: drop_selected_student_from_a_course(int choice){				//drop a student from selected course
   


    if(choice>0 && choice <=used+1){
        Course ** temp = new Course *[capacity];
        int j,i;
        for (i = 0, j = 0; i < used; i++)
        {
            if (i != choice-1)
            {
                temp[j++] = course[i];
            }
           
        }
        	
        
        
        delete [] course;
        course = temp;
        used = used-1;
    }

}

int Student :: get_used(){									//getter for used
    return used;
}

void Student :: remove_deleted_course(string course_name,string course_code){		//	remove deleted course if student gets that course

    int i,j;
        Course **temp = new Course*[capacity];
        for( i=0,j=0;i<used;i++){
            if(course_name != course[i]->get_course_name() && course_code !=  course[i]->get_code()){
                temp[j++] = course[i];
            }
        }

        delete [] course;
        course = temp;
        used = used-1;


}

string Student :: selected_name(int choice){
    return (course[choice-1]->get_course_name());
}
}
