#include<iostream>
#include <string>
#include "Robot.h"
using namespace std;

#ifndef BULLDOZER_H
#define BULLDOZER_H

class Bulldozer : public Robot{	//derived from robot class
public:
Bulldozer();
Bulldozer (int newStrength , int newHit);
string getType() ;
int getDamage();



};


#endif



