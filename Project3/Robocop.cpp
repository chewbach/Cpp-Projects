#include<iostream>
#include<string>
#include"Humanic.h"
#include"Robocop.h"
using namespace std;


Robocop :: Robocop() : Humanic(){}				//default constructor
Robocop :: Robocop(int newStrength,int newHit) : Humanic(1,newStrength,newHit){	//constructor

}


string Robocop :: getType(){				//return type of robot

    return Humanic :: getType();
}

int Robocop :: getDamage(){				//returns amount of damage this robot
    int damage = Humanic :: getDamage();		//get damage value from Humanic class

    return damage;
}
