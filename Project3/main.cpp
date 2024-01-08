#include<iostream>
#include<string>
#include"Robot.h"
#include"Bulldozer.h"
#include"Roomba.h"
#include"Humanic.h"
#include"Optimusprime.h"
#include"Robocop.h"

using namespace std;

void match(Robot &r1,Robot &r2){	//match function organizes competition between 2 robot classes
    int hp1 = r1.get_hitpoint();	//hitpoint for r1 object
    int hp2 = r2.get_hitpoint();	//hitpoint for r2 object
    

while(1){
    
    double damage_first_object = r1.getDamage();	//total damage in round that applied from r1 to r2
    hp2 = hp2-damage_first_object;			//damage dealt is subtracted from the hitpoint
   
    if(hp2<=0){					//If either r1 or r2 has a hitpoint of 0 or lower, the winner will be determined.
        cout<<r1.getType()<<" win the match!";
        break;
    }
   
    double damage_second_object = r2.getDamage();	//total damage in round that applied from r2 to r1
    hp1 = hp1-damage_second_object;			//damage dealt is subtracted from the hitpoint
    
    if(hp1<=0){					//If either r1 or r2 has a hitpoint of 0 or lower, the winner will be determined.
        cout<<r2.getType()<<" win the match!";
        break;
    }
    
}

}

int main(){

    srand(time(NULL));

    //create inherited objects	
    Robot *p = new Bulldozer (15,210);		//İmportant note : Since the created object belongs to the class with the same name, no extra type is taken.
    Robot *n = new Robocop(20,130);			//The type is default assigned to the constructor for Bulldozer,Roomba,Optimusprime,Robocop classes.
    Robot *q = new Roomba(10,200);			//So insteade of Robot *ptr = new Derived_class_name(type,strengt,hp) ,I used new Derived_class_name(strength,hp)
    Robot *m = new Optimusprime(15,170);		//but base class have type.So an object can created like this : Robot * ptr = new Robot (type,strength,hp);
    
  
    
    match(*n,*q);					//do match between two robots
  
    return 0;
}
