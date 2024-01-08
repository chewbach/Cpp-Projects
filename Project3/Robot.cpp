#include<iostream>
#include<string>
#include"Robot.h"
using namespace std;

Robot :: Robot():type(3),strength(10),hitpoint(10){			//default constructor
    
}


Robot :: Robot(int newType,int newStrength,int newHit):type(newType),strength(newStrength),hitpoint(newHit){	//constructor for Robot class

}

string Robot :: getType()						//helper function which returns the robot type
{
switch (type)
{
case 0: return "optimusprime";
case 1: return "robocop";
case 2: return "roomba";
case 3: return "bulldozer";
}
return "unknown";
}

int Robot :: get_type()const{					// getter for type
    return type;
}

int Robot :: get_strength()const{				//getter for strength
    return strength;
}

int Robot :: get_hitpoint()const{				//getter for hitpoint
    return hitpoint;
}

int Robot::getDamage()						//Returns amount of damage this robot
{
int damage;

damage = (rand() % strength) + 1;				//find a random damage between 1 and strength
cout << getType() << " attacks for " <<			
damage << " points!" << endl;

return damage;
}











