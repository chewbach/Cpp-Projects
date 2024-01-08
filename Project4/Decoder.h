#include<iostream>
#include<string>
#include"Gate.h"

using namespace std;

#ifndef DECODER_H
#define DECODER_H

class Decoder : public Gate{
public:

Decoder();
void set_input_name_1(string name1);
string get_input_name_1();
void set_input_name_2(string name2);
string get_input_name_2();
void set_outputs(string o1,string o2,string o3,string o4);

string get_gate_type();
void set_gate(string gate);

void set_input_pointer_1(Gate* input1);
void set_input_pointer_2(Gate* input2);

void set_output_1(string output1);
void set_output_2(string output2);
void set_output_3(string output3);
void set_output_4(string output4);
int evaluate();
void print();
void check_repetition(){return;}


private:
    
    string input_name;
    string input_name2;
    string output_name1;
    string output_name2;
    string output_name3;
    string output_name4;
    int output_datas[4];
    Gate *in1 = nullptr;
    Gate *in2 = nullptr;

};
#endif