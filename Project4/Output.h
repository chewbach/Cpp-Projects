#include<iostream>
#include<string>
#include"Gate.h"
using namespace std;

#ifndef OUTPUT_H
#define OUTPUT_H

class Output : public Gate{
public:
Output();
string get_input_name();
void set_input_name(string input);
void set_gate(string gate);
string get_gate_type();
void set_input_pointer_1(Gate* input1);
void set_input_pointer_2(Gate* input2);
int evaluate();
int get_output_data();
void set_input_name_1(string name1){return;}
void set_input_name_2(string name2){return;}
string get_input_name_1(){return " ";}
string get_input_name_2(){return " ";}
void check_repetition(){return;}
private:
string input_name;
Gate *in1;
bool controller = false;


};

#endif