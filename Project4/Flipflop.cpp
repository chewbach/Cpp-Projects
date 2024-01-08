#include<iostream>
#include<string>
#include"Flipflop.h"

using namespace std;



Flipflop :: Flipflop() : Gate(){
    
}



void Flipflop :: set_input_name_1(string name1){ 
    input_name = name1;
    
    
}


string Flipflop :: get_gate_type(){
    return gate_type;
}

void Flipflop :: set_gate(string gate){
    gate_type = gate;
}

void Flipflop :: set_output(string output){
    this->output = output;

}
string Flipflop :: get_output_name(){
    return output;
}

string Flipflop :: get_input_name_1(){
    return input_name;
}

void Flipflop :: set_input_pointer_1(Gate* input1){
    in1 = input1;
}

int Flipflop :: evaluate(){
     int input1;
  

    
    int temp;

    if (this->controller == false)//check repetition
    {
        temp = in1->evaluate();
        this->controller = true; 
        if (temp == 0 && former_out == 0)
    {
        output_data = 0; 
        
    }
    else if (temp == 0 && former_out == 1)
    {
        output_data = 1; 
        
    }
    else if (temp == 1 && former_out == 0)
    {
        output_data = 1; 
        former_out = 1;
        
    }
    else
    {
        output_data = 0; 
        former_out = 0;
        
        
    }

       
    }
   
    return output_data;
}

void Flipflop :: check_repetition()
{
    
    this->controller = 0;

}

int Flipflop :: get_output_data(){
    
    return output_data;
}

void Flipflop :: set_input_pointer_2(Gate* input2){
    return;
}
