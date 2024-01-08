#include<iostream>
#include<string>
#include"Humanic.h"

using namespace std;

#ifndef ROBOCOP_H
#define ROBOCOP_H


class Robocop : public Humanic {		//derived from Humanic

public:

Robocop();
Robocop(int newStrength,int newHit);
int getDamage();
string getType();




};
#endif
