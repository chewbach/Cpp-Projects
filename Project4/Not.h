#include<iostream>
#include<string>
#include"Gate.h"

using namespace std;

#ifndef NOT_H
#define NOT_H

class Not : public Gate{
public:

Not();
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
int get_output_data();
void check_repetition();
string get_input_name_2(){return " ";}


private:
    string output;
    string input_name;
    int output_data;
    int counter = 0;
    bool controller=false;
    Gate *in1 = nullptr;
};
#endif