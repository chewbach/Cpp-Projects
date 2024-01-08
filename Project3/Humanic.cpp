#include<iostream>
#include<string>
#include "Humanic.h"
#include "Robot.h"
using namespace std;

Humanic :: Humanic () : Robot() {}				//default constructor

Humanic :: Humanic(int newType,int newStrength,int newHit) : Robot(newType,newStrength,newHit){}	//constructor 

string Humanic :: getType()										//get type of robot
{
switch (get_type())
{
case 0: return "optimusprime";
case 1: return "robocop";
}
return "unknown";
}

int Humanic :: getDamage(){					// Returns amount of damage this robot
    int damage;
    damage = Robot :: getDamage();				//getRobot  damage value from robot class 
    //humanic robots have a 10% chance of inflicting a tactical nuke attack which is an additional 50 damage points.
    int random = rand() % 10 + 1;				//Choose random numbers from 1 to 10		
    if(random == 1){						//This method was used because the probability of random number being 1 is 10%.
        damage +=50;						//add extra 50 point to damage
    cout << getType() << " attacks extra 50 points!" << endl; 
    }

    

    return damage;
}
