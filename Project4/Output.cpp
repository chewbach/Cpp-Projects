#include<iostream>
#include<string>
#include"Output.h"
using namespace std;

Output :: Output() :Gate(){}

string Output :: get_input_name(){

    return input_name;
}

void Output :: set_input_name(string input){
    input_name = input;
}

void Output :: set_gate(string gate){
    gate_type = gate;
}

string Output :: get_gate_type(){
    return gate_type;
}

void Output :: set_input_pointer_1(Gate* input1){
    in1 = input1;
}

void Output :: set_input_pointer_2(Gate* input2){
    return;
}


int Output :: evaluate(){
    
     
    

    if(controller == false)
    {
        controller = true;
        output_data = in1->evaluate();
    }
    
    return output_data;
}

int Output :: get_output_data(){
    return output_data;
}