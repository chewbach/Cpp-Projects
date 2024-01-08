#include<iostream>
#include<string>
#include"Gate.h"

using namespace std;

#ifndef AND_H
#define AND_H

class And : public Gate{

public:
And();
void set_input_name_1(string name1);
void set_input_name_2(string name2);
void set_output(string output);
string get_gate_type();
void set_gate(string gate);
string get_output_name();
string get_input_name_1();
string get_input_name_2();
void set_input_pointer_1(Gate* input1);
void set_input_pointer_2(Gate* input2);
int evaluate();
void check_repetition();
int get_output_data();

private:
string input_name;
string input_name2;
string output;
int output_data;
bool controller=false;
Gate *in1 = nullptr;
Gate *in2 = nullptr;



};
#endif





