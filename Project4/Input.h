#include<iostream>
#include<string>
#include"Gate.h"
using namespace std;

#ifndef INPUT_H
#define INPUT_H

class Input : public Gate{
public:

Input();
//Input(string gate,string output);
string get_output_name();
int get_data() ;
string get_gate_type();
void set_data(int _data);
void set_gate(string gate);
void set_output(string output);
int evaluate();
void set_input_pointer_1(Gate* input1);
void set_input_pointer_2(Gate *input2);
void set_input_name_1(string name1){return;}
void set_input_name_2(string name2){return;}
string get_input_name_1(){return " ";}
string get_input_name_2(){return " ";}
void check_repetition(){return;}

private:

string output_name;
int data;
Gate *in1;
};

#endif
