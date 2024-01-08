#include<iostream>
#include<string>
#include"Or.h"

using namespace std;

Or :: Or() : Gate(){}



void Or :: set_input_name_1(string name1){ 
    input_name = name1;
    
    
}

void Or :: set_input_name_2(string name2){
    input_name2 = name2;
}
string Or :: get_gate_type(){
    return gate_type;
}

void Or :: set_gate(string gate){
    gate_type = gate;
}

void Or :: set_output(string output){
    this->output = output;

}
string Or :: get_output_name(){
    return output;
}

string Or :: get_input_name_1(){
    return input_name;
}


string Or :: get_input_name_2(){
    return input_name2;
}

void Or :: set_input_pointer_1(Gate* input1){
    in1 = input1;
}

void Or :: set_input_pointer_2(Gate* input2){
    in2 = input2;
}


int Or :: evaluate(){

    
       
    int wire1;
     int wire2;
    
        
    if(controller == false){
        
        wire1 = in1->evaluate(); 
        wire2 = in2->evaluate();
        this->output_data = wire1 || wire2;
        controller = true;
        
        
    }
    
    
    
    return output_data;

    
    
  
}

int Or :: get_output_data(){
    return output_data;
}

void Or :: check_repetition()
{
    this->controller = 0;
}