#include<iostream>
#include<string>
#include"Humanic.h"

using namespace std;

#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

class Optimusprime : public Humanic{			//derived from Humanic class
public:
Optimusprime();
Optimusprime(int newStrength,int newHit);
int getDamage();
string getType();



};




#endif
