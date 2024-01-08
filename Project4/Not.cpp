#include<iostream>
#include<string>
#include"Not.h"

using namespace std;


Not :: Not() : Gate(){}             //constructor



void Not :: set_input_name_1(string name1){ 
    input_name = name1;
    
    
}


string Not :: get_gate_type(){
    return gate_type;
}

void Not :: set_gate(string gate){
    gate_type = gate;
}

void Not :: set_output(string output){
    this->output = output;

}
string Not :: get_output_name(){
    return output;
}

string Not :: get_input_name_1(){
    return input_name;
}


void Not :: set_input_pointer_1(Gate* input1){
    in1 = input1;
}

void Not :: set_input_pointer_2(Gate* input2){      
    return;
}


int Not :: evaluate(){

    
     int wire1;
    
        
    if(controller == false){                        //check repetition
        
        wire1 = in1->evaluate();                    
        
        this->output_data = !(wire1);
        controller = true;
        
        
    }
    
       
    return output_data;
}

int Not :: get_output_data(){
    return output_data;
}

void Not :: check_repetition()                          //set controller

{
    this->controller = 0;
}

