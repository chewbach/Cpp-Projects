#include<iostream>
#include<string>
#include"Robot.h"
using namespace std;

#ifndef HUMANIC_H
#define HUMANIC_H

class Humanic : public Robot{		//abstract class derived from Robot class
public:
Humanic();
Humanic(int newType,int newStrength,int newHit);
virtual string getType() = 0;		//pure virtual function
virtual int getDamage() = 0;		//pure virtual function




};
#endif
