#include<iostream>
#include<string>
using namespace std;
#ifndef ROBOT_H
#define ROBOT_H

class Robot {			//abstract class

public:

Robot();
Robot(int newType,int newStrength,int newHit);


int get_type() const;
int get_strength() const;
int get_hitpoint() const;

virtual int getDamage() = 0;		//pure virtual function
virtual string getType() = 0; 	//pure virtual function



private:
int type;
int strength;
int hitpoint;
};
#endif
