#include<iostream>
#include <string>
#include "Bulldozer.h"
#include "Robot.h"
using namespace std;


Bulldozer :: Bulldozer() : Robot(){}				//default constructor

Bulldozer :: Bulldozer (int newStrength , int newHit) : Robot(3,newStrength,newHit){	//constructor

}

string Bulldozer :: getType(){			// Returns the robot type
    return Robot :: getType();
}

int Bulldozer :: getDamage(){				// Returns amount of damage this robot
    int damage  = Robot :: getDamage(); 

    return damage;
}

