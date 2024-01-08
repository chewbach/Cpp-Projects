#include<iostream>
#include<string>
#include"Humanic.h"
#include"Optimusprime.h"
using namespace std;

Optimusprime :: Optimusprime() : Humanic(){}			//default constructor
Optimusprime :: Optimusprime(int newStrength,int newHit) : Humanic(0,newStrength,newHit){	//constructor

}
string Optimusprime :: getType(){	//return robot type

    return Humanic :: getType();
}

int Optimusprime :: getDamage(){	// Returns amount of damage this robot
     
    int damage = Humanic :: getDamage();	//get daöage value from Humanic class
    
    
     int random = rand() % (20) + 1;		//choose random number between 1-20
     
  // With a 15% chance optimusprime robots inflict a strong attack that doubles the normal amount of damage.
    if(random == 1 || random == 2 || random == 3 ){	// %15 = 3/20.So if equal to one of the three will attack strong
        
        damage = damage * 2;				//damage doubled
        cout << getType() << " made a strong attack(x2)."<<endl;
    }
    
    return damage;    

}
