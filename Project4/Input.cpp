#include<iostream>
#include<string>
#include"Input.h"
#include"Gate.h"
using namespace std;
Input :: Input() : Gate(){}
/*
Input :: Input (string gate,string output):Gate(gate){
    output_name = output;
   
}*/

string Input ::  get_output_name(){
    return output_name;
}



void Input :: set_data(int _data){
    data = _data;
}

void Input :: set_gate(string gate){
    gate_type = gate;

}

void Input :: set_output(string output){
    output_name = output;
}

int Input :: get_data(){
    return data;
}

string Input :: get_gate_type(){
    return gate_type;
}

int Input :: evaluate(){

    return this->data;
}

void Input :: set_input_pointer_1(Gate* input1){
    in1 = input1;
}

void Input :: set_input_pointer_2(Gate* input2){
    return;
}
