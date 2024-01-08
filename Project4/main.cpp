#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"Gate.h"
#include"Input.h"
#include"Output.h"
#include"And.h"
#include"Or.h"
#include"Not.h"
#include"Flipflop.h"
#include"Decoder.h"
#include"Read.cpp"


using namespace std;

void simulate_circuit(Gate **p,int total_gate,int number_of_input,int number_of_output){    //simulate circuit
        string line,var,input;
        ifstream inputfile;
        inputfile.open("input.txt");                                    //open input folder

        while( getline(inputfile, input)){                              //read gates from folder
            
            
            
                stringstream  s(input);
                int i = 0;
                while(i < number_of_input){
             
                s >> var;
                int _data = stoi(var);                                  //convert string data to integer
                p[i]->set_data(_data);
                i++;
                }
        
        
        
        if(p[total_gate-1]->get_gate_type() == "DECODER" ){             //check if the program is finished with the decoder
        p[total_gate-1]->evaluate();                                    
        p[total_gate-1]->print();

        }
        else{

            cout<< p[total_gate-1]->evaluate()<<endl;                         //İmportant note : I suppressed this result because I thought the last element would be the output element (and I think there should be 1 output, excluding the decoder).
             

        }

        for(int m=0;m<total_gate;m++){                              //reset the controller
        p[m]->check_repetition();
        }
        

        
        }


}




int main(){

    
    
    int number_of_input = 0;
    int number_of_output = 0;
    int number_of_gate = 0;
    int i;
    read_file(number_of_input,number_of_output,number_of_gate);             //read datas from file and find total number of gates

    int total_gate = number_of_input+number_of_output+number_of_gate;       //calculate total number of gates
    
    
    Gate **p = new  Gate*[total_gate];                                      //create dynamic gate array
    read_circuit(p);                                                        //read circuit file and write gates into array


        for(i = 0;i<total_gate;i++){                          //It is used to connect two gates. If the input name is in the other gate object, the address of the object is sent.
            for(int j=0;j<total_gate;j++){
                if(p[i]->get_input_name_1() == p[j]->get_output_name() ){
                    p[i] -> set_input_pointer_1(p[j]);
                }
                else if(p[i]->get_input_name_2() == p[j]->get_output_name()){
                    p[i] -> set_input_pointer_2(p[j]);
                }
            }
        }
        
      

        simulate_circuit(p,total_gate,number_of_input,number_of_output);    //simulate circuit
        
        
    return 0;
}