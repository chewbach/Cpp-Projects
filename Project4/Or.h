#include<iostream>
#include<string>
#include"Gate.h"

using namespace std;

#ifndef OR_H
#define OR_H

class Or : public Gate{

public:
Or();
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
int get_output_data();
void check_repetition();
private:
string input_name;
string input_name2;
string output;
int output_data;
int counter = 0;
bool controller = false;
Gate *in1 = nullptr;
Gate *in2 = nullptr;


};
#endif





