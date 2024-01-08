#include <iostream>
#include <string>
#include "SchoolManagerSystem.h"
using namespace std;
namespace PA3{
SchoolManagerSystem ::SchoolManagerSystem()		//default constructor
{		
    std = new Student*[student_capacity];		//create dynamic Student objects
    crs = new Course*[course_capacity];		//create dynamic Course objects
}

SchoolManagerSystem :: ~SchoolManagerSystem(){
    delete [] std;
    delete [] crs;
}
void SchoolManagerSystem ::main_menu()		//main menu function have main functions
{

    int choice;

    cout << "Main_menu" << endl;			//creat main menu
    cout << "0 exit" << endl;
    cout << "1 student" << endl;
    cout << "2 course" << endl;
    cout << "3 list_all_students" << endl;
    cout << "4 list_all_courses" << endl;

    cin >> choice;
    if(cin.fail()){                     //If the input is not an integer value, it returns to the main menu.
         cin.clear();                   
        cin.ignore(10000, '\n');
        main_menu();
    }
    
    else{

    switch (choice){					//swich statemant for calling selected functions
       case 0:
       exit(1);
       break;
       case 1:						//menu student
       menu_student();
       break;
       case 2:						//menu course
       menu_course();
       break;
       case 3:
       list_all_students();				//list all students
       break;
       case 4:
       list_all_courses();				//list all courses
       break;
       default:
       main_menu();
        break;
       
    }
    }
    
}


void SchoolManagerSystem ::menu_student()		//student_menu
{
    cout << "0 up" << endl;
    cout << "1 add_student" << endl;
    cout << "2 select_student" << endl;
    int choice;
    cin >> choice;
    if(cin.fail()){
                                //If the input is not an integer value, it returns to the main menu.
        cin.clear();                   
        cin.ignore(10000, '\n');
         menu_student(); 
    }
    if (choice == 0)					//main menu
    {
        main_menu();
    }
    else if (choice == 1)				//add student
    {

        add_student();

    }
    else if (choice == 2)				//select student
    {
        select_student();
    }
    else{
        menu_student();
    }
}





void SchoolManagerSystem ::add_student()
{
    string full;					
    string _name;
    string _id;
    int i;

    cin.ignore();
    getline(cin, full);				//get name,surname and id using a single string.
							//There should be a line space between them.(Example input : Joe Satriani 0000)
    for (i = 0; i < full.length(); i++)		//find id from the full string
    {
        if (isdigit(full[i]))				//if full have an digit at string ,loop will stop
            break;
    }
    if(full[i-1]!=' '){				//if user enter single element (Example input : joe) program will return menu.
        menu_student();				//if not used the program will give run time error
    }
    _name = full.substr(0, i - 1);			//Extract full name(name + surname) from string 
    string temp_id = full.substr(i, full.length());	//Extract id from string
    _id = temp_id;

    Student *temp = new Student(_name,_id);		//create an temp object for create Student object
    store_student(temp);				//send address of object store student function
    menu_student();					//return menu
}

void SchoolManagerSystem :: store_student(Student* address){		//this function have temp object address for add actual address
    if(number_of_students>=student_capacity){				//check if capacity of program full
        student_capacity+=10;						//If the capacity is full, increase the capacity by 10.
        Student **temp = new Student*[student_capacity];		//create temp dynamic objects for store old objects elements
        for(int i = 0;i<student_capacity-10;i++){			//copy elements temp object
            temp[i] = std[i];
        }
        delete [] std;							//delete old dynamic object array
        std = temp;							//Sync temp objects with std objects.
    }
    std[number_of_students++] = address;				//std hold address of object.
  
   
}

void SchoolManagerSystem ::select_student()				//select student
{
    string full;
    string _name;
    string _id;
    int i, j;
    
    cin.ignore();
    getline(cin, full);						//get name,surname and id using a single string.

    for (i = 0; i < full.length(); i++)				//find id from the full string
    {
        if (isdigit(full[i]))						//if full have an digit at string ,loop will stop
            break;
    }
     if(full[i-1]!=' '){						//if user enter single element (Example input : joe) program will return menu.
        menu_student();							//if not used the program will give run time error
    }
    _name = full.substr(0, i - 1);					//Extract full name(name + surname) from string
    string temp_id = full.substr(i, full.length());			//Extract id from string
    _id = temp_id;
    int control = 0;
    int pos=-1;
    for (i = 0; i <number_of_students; i++)				//check objects one by one. 
    {
        if (std[i]->get_name() == _name && std[i]->get_id() == _id)	//If program find object with same name and id then selected student will be that student.
        {
            pos = i;							//pos hold selected student index  
            control = 1;						//if student found control will be 1
            break;
        }
    }
    if(control == 1){							//if student exist,run selected student menu
    select_student_menu(pos);}
    
    else{								//if student does not exist,program will return student menu
        menu_student();
    }
    
}

void SchoolManagerSystem :: select_student_menu(int pos){		//selected student menu
    int i,j;
    cout << "0 up" << endl;
    cout << "1 delete_student" << endl;
    cout << "3 add_selected_student_to_a_course" << endl;
    cout << "4 drop_selected_student_from_a_course" << endl;

    int choose;
    cin >> choose;
    if(cin.fail()){
                                //If the input is not an integer value, it returns to the main menu.
        cin.clear();                   
        cin.ignore(10000, '\n');
         select_student_menu(pos);
    }
    

    if (choose == 0)							//returns to menu
    {
        menu_student();						
    }
    else if (choose == 1)							//deletes student
    {
        Student **tmp_std = new Student*[student_capacity];		//create a temp dynamic object array
        for (i = 0, j = 0; i < number_of_students; i++)		
        {
            if (i != pos)						//Except for the element to be deleted, the other elements are copied to the temporary object.
            {
                tmp_std[j++] = std[i];
            }
           
        }
        for(int k=0;k<number_of_course;k++){				//This function deletes a student from crs objects  if a student is deleted.
            crs[k]->remove_deleted_students(std[pos]->get_name(),std[pos]->get_id());	
        }
       
         delete[] std;							//delete objects
            std = tmp_std;						//copy temp objects to std objects
        number_of_students = number_of_students - 1;			//if a student deleted,total student number must decrease.

            menu_student();
    }

    else if(choose == 3){
        add_students_to_course(pos);
    }

    else if(choose == 4){
        drop_student_from_course(pos);
    }
    else{
        select_student_menu(pos);
    }
}



void SchoolManagerSystem :: menu_course(){				//menu course
    cout<<"0 up"<<endl;
    cout<<"1 add_course"<<endl;
    cout<<"2 select course"<<endl;
    int choice;
    cin>>choice;
    if(cin.fail()){
                                //If the input is not an integer value, it returns to the  menu.
        cin.clear();                   
        cin.ignore(10000, '\n');
         menu_course();
    }


    if(choice == 0){							//return main menu
        main_menu();
    }

    else if(choice == 1){							//add course
        add_course();
    }

    else if(choice == 2){							//select course
        select_course();
    }
    else{
        menu_course();
    }
}

void SchoolManagerSystem :: add_course(){
    string full;
    string _course_name;
    string _code;
    cin.ignore();
    getline(cin,full);							//get course_name and course_code using a single string.
    int i;
    for(i=0;i<full.length();i++){					//find space character from string
        if(full[i]==' ')
            break;
    }
     if(full[i]!=' '){							//if user enter single element (Example input : cse241) program will return menu course
        menu_course();							//if not used the program will give run time error
    }
    _code = full.substr(0,i);						//Extract course code from string
    

    _course_name = full.substr(i+1,full.length());			//Extract course name from string
    
    Course *temp = new Course (_course_name,_code);			//create an temp object for create Course object
    store_course(temp);						//send address of object store student function
    
    menu_course();							//return menu

}


void SchoolManagerSystem :: store_course(Course *address){		//this function have temp object address for add actual address
        if(number_of_course>=course_capacity){			//check if capacity of dynamic object array full
            course_capacity+=10;					//If the capacity is full, increase the capacity by 10.
        Course **temp = new Course*[course_capacity];		//create temp dynamic objects for store old objects elements
        for(int i = 0;i<course_capacity-10;i++){			//copy elements to temp object
            temp[i] = crs[i];
        }
        delete [] std;							//delete old dynamic object array
        crs = temp;
        }
        crs[number_of_course++] = address;				//crs hold address of object.
}


void SchoolManagerSystem :: select_course(){				//select course
    string full;							
    string _course_name;
    string _code;
    cin.ignore();
    getline(cin,full);							//get course code and name as a string
    int i,j;
    int choice;
    for(i=0;i<full.length();i++){
        if(full[i]==' ')
            break;
    }
     if(full[i]!=' '){
        menu_course();
    }
    _code = full.substr(0,i);						//Extract code of course from string
    

    _course_name = full.substr(i+1,full.length());			//Extract name of course from string
    int pos=-1;
    for (i = 0; i <number_of_course; i++)				
    {
        if (crs[i]->get_course_name() == _course_name && crs[i]->get_code() == _code)	//If program find object with same name and code then selected course will be that course.
        {
            pos = i;							//pos hold selected course index
            break;
        }
    }

    if(pos==-1){                            //If there is no such selection, the program will stop running.

        menu_course();
    }

    select_course_menu(pos);
    
}

void SchoolManagerSystem :: select_course_menu(int pos){        //select course menu
    cout<<"0 up"<<endl;
    cout<<"1 delete_course"<<endl;
    cout<<"2 list_students_to_selected_course"<<endl;
    int choice,i,j;
    cin>>choice;
    if(cin.fail()){
                                //If the input is not an integer value, it returns to the  menu.
        cin.clear();                   
        cin.ignore(10000, '\n');
         select_course_menu(pos);
    }
    switch(choice){
        case 0:
            menu_course();						//return menu
            break;
        case 1:
        {
            Course **tmp_crs = new Course*[course_capacity];		//create a temp dynamic object array
        for (i = 0, j = 0; i < number_of_course; i++)
        {
            if (i != pos)
            {
                tmp_crs[j++] = crs[i];				//Except for the element to be deleted, the other elements are copied to the temporary object.
            }
           
        }

         for(int k=0;k<number_of_students;k++){			//This function deletes a course from std objects  if a course is deleted.
            std[k]->remove_deleted_course(crs[pos]->get_course_name(),crs[pos]->get_code());
        }
         delete[] crs;							//delete crs
            crs = tmp_crs;						//copy temp objects to crs objects
        number_of_course = number_of_course - 1;			//If an element deleted from crs,number of course must decreases.
       
            menu_course();						//return menu
        break;
        }

        case 2:
        crs[pos]->print_student_get_course();				//print students that gets selected course 
        main_menu();							//return menu
        break;

        default:
        select_course_menu(pos);
        break;

    }

}

void SchoolManagerSystem :: add_students_to_course(int pos){		//add students to a course
    cout<<"0 up"<<endl;
    int k = 1;
    int m = 1;
    int counter = 0;
    Course ** temp = new Course*[number_of_course];			//create a temp dynamic object array
    for(int i = 0 ;i<number_of_course;i++){
    
        if(std[pos]->check_student_register_course(crs[i]->get_course_name(),crs[i]->get_code())){	//print registerable course
            
        cout<<k<<" "<<crs[i]->get_code()<<" "<<crs[i]->get_course_name()<<endl;
        temp[k-1] = crs[i]; 
       }
        


       else{
           k=k-1;
           counter++;
       }
       k++;
       
    }
    int choice;
    
    cin>>choice;

    if(cin.fail()){
                                //If the input is not an integer value, it returns to the  menu.
        cin.clear();                   
        cin.ignore(10000, '\n');
         add_students_to_course(pos);
    }
   
    if(choice == 0){							//return menu
        select_student_menu(pos);
    }
    else if(choice > 0 && choice <= number_of_course){			
        for(int i = 0;i<number_of_course;i++){
        if(crs[i]==temp[choice-1]){					//find course index that temp objects hold
            crs[i]->set_students(std[pos]->get_name(),std[pos]->get_id());	//if course find,add student to course.
            break;
        }
    }
    std[pos]->set_courses(temp[choice-1]->get_course_name(),temp[choice-1]->get_code());	//add selected student to selected course
    select_student_menu(pos);									//return menu
    }
    else{
        add_students_to_course(pos);
    }

    
    delete [] temp;						//delete temp object
}


void SchoolManagerSystem :: list_all_students(){		//print all students

        for(int i = 0 ; i<number_of_students;i++){
            cout<<std[i]->get_name()<<" "<<std[i]->get_id()<<endl;
        }

        main_menu();
}

void SchoolManagerSystem :: list_all_courses(){		//print all courses
        for(int i=0;i<number_of_course;i++){
            cout<<crs[i]->get_code()<<" "<<crs[i]->get_course_name()<<endl;
        }
        main_menu();
}

void SchoolManagerSystem :: drop_student_from_course(int pos){	//drop a student from selected course
     string a;
     string b;
     int k=0;
     cout<<"0 up"<<endl;
     std[pos]->print_courses_get_from_student();			//print all getting courses
    int choice;
    cin>>choice;
    if(cin.fail()){
                                //If the input is not an integer value, it returns to the  menu.
        cin.clear();                   
        cin.ignore(10000, '\n');
         drop_student_from_course(pos);
    }
    if(choice == 0){

        select_student_menu(pos);					//return menu
    }
   
    else if(choice>0 && choice <=std[pos]->get_used()){
        
         a = std[pos]->selected_name(choice);
     for(int k=0;k<number_of_course;k++){				//This function deletes a student from crs objects  if a course drop
            if(crs[k]->get_course_name()==a){           //find course in dynamic objects
            crs[k]->remove_deleted_students(std[pos]->get_name(),std[pos]->get_id());   //if finded,delete from selected course
            }
        }
        
      
        std[pos]->drop_selected_student_from_a_course(choice);	//remove a course from a student
    	 
  
    select_student_menu(pos);
    }
    else{
        drop_student_from_course(pos);
    }

}

}
