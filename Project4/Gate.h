#include<iostream>
using namespace std;

#ifndef GATE_H
#define GATE_H

class Gate{
public:

    Gate();
    Gate(string _gate_type);
    virtual string get_gate_type() = 0;
    virtual string get_output_name() {return " ";}
    virtual string get_input_name(){return " ";}
    virtual int get_data() {return 0;}
    virtual void set_data(int _data){return ;}
    virtual void set_output(string output) {return ;}
    virtual void set_gate(string gate)=0;
    virtual void set_input_name(string input){return; }
    virtual void set_input_name_1(string name1)=0;
    virtual void set_input_name_2(string name2)=0;
    virtual string get_input_name_1()=0;
    virtual string get_input_name_2()=0;
    virtual void set_input_pointer_1(Gate *input1) = 0;
    virtual void set_input_pointer_2(Gate *input2) = 0;
    virtual int evaluate(){ return output_data;}
    virtual void set_output_1(string output1){return;}
    virtual void set_output_2(string output2){return;}
    virtual void set_output_3(string output3){return;}
    virtual void set_output_4(string output4){return;}
    virtual void print(){return;}
    virtual void check_repetition() = 0;  
    virtual int get_output_data(){return 0;}





protected:
    string gate_type;
    int output_data;


};
#endif