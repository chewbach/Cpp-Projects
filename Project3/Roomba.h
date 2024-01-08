#include<iostream>
#include <string>
#include "Robot.h"
using namespace std;

#ifndef ROOMBA_H
#define ROOMBA_H

class Roomba : public Robot{			//derived from Robot class
public:

Roomba();
Roomba(int newStrength,int newHit);
string getType();
int getDamage();



};
#endif
