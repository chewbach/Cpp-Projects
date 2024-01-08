#include<iostream>
#include<string>
#include"Gate.h"

using namespace std;

#ifndef FLIPFLOP_H
#define FLIPFLOP_H

class Flipflop : public Gate{
public:

Flipflop();
void set_input_name_1(string name1);
void set_input_name_2(string name2){return; }
string get_input_name_1();
void set_output(string output);
string get_output_name();
string get_gate_type();
void set_gate(string gate);

void set_input_pointer_1(Gate* input1);
void set_input_pointer_2(Gate* input2);
int evaluate();
void check_repetition();
int get_output_data();
string get_input_name_2(){return " ";}
private:
    string output;
    string input_name;
    Gate *in1 = nullptr;
    int output_data;
    bool controller=false;
    
    int former_out;
    int counter = 0;


};
#endif