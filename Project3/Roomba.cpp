#include<iostream>
#include <string>
#include "Roomba.h"
#include "Robot.h"
using namespace std;

Roomba :: Roomba() : Robot(){}			//default constructor

Roomba :: Roomba(int newStrength,int newHit) : Robot(2,newStrength,newHit){}	//constructor

string Roomba :: getType(){			//return robot type
    return Robot :: getType();
}

int Roomba :: getDamage(){			//Returns amount of damage this robot
    int total_damage = 0; 			
    for(int i=0;i<2;i++){			//roomba robots are very fast, so they get to attack twice.
    total_damage+=Robot :: getDamage();	//find the total damage from two attacks
   
    }

    return total_damage;
    
}
