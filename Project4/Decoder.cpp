#include<iostream>
#include<string>
#include"Decoder.h"

using namespace std;

Decoder :: Decoder () : Gate(){}

void Decoder :: set_input_name_1(string name1){
    input_name = name1;
}
string Decoder :: get_input_name_1(){
    return input_name;
}
void Decoder :: set_input_name_2(string name2){
    input_name2 = name2;
}
string Decoder :: get_input_name_2(){
    return input_name2;
}


string Decoder :: get_gate_type(){
    return gate_type;
}
void Decoder :: set_gate(string gate){
    gate_type = gate;
}
void Decoder :: set_input_pointer_1(Gate* input1){
    in1 = input1;
}

void Decoder :: set_input_pointer_2(Gate* input2){
    in2 = input2;
}

void Decoder :: set_output_1(string output1){
    output_name1 = output1;
}
void Decoder :: set_output_2(string output2){
    output_name2 = output2;
}
void Decoder :: set_output_3(string output3){
    output_name3 = output3;
}
void Decoder :: set_output_4(string output4){
    output_name4 = output4;
}

int Decoder :: evaluate(){              //set value and print result according to this value
    int wire1 = in1->evaluate();
    int wire2 = in2->evaluate();    

    if (wire1 == 0 && wire2 == 0)
    {
        this->output_datas[0] = 1;
        this->output_datas[1] = 0;
        this->output_datas[2] = 0;
        this->output_datas[3] = 0;
    }
    else if (wire1 == 0 && wire2 == 1)
    {
        this->output_datas[0] = 0;
        this->output_datas[1] = 1;
        this->output_datas[2] = 0;
        this->output_datas[3] = 0;
    }
    else if (wire1 == 1 && wire2 == 0)
    {
        this->output_datas[0] = 0;
        this->output_datas[1] = 0;
        this->output_datas[2] = 1;
        this->output_datas[3] = 0;
    }
    else if (wire1 == 1 && wire2 == 1)
    {
        this->output_datas[0] = 0;
        this->output_datas[1] = 0;
        this->output_datas[2] = 0;
        this->output_datas[3] = 1;
    }
    return 0;

}

void Decoder::print()                       //print decoder
{
    for(int i = 0;i<4;i++)    
    cout<<output_datas[i]<<" ";
    cout<<endl;
}