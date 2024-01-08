#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

int check_errors(ifstream* f) {
int stop = 0;
if (f->eof()) {

stop = 0;
}
if (f->fail()) {
stop = 1;
}
if (f->bad()) {
stop = 1;
}
return stop;
}

void read_file(int &number_of_input,int &number_of_output,int &number_of_gate){

    ifstream circuitfile;
    circuitfile.open("circuit.txt");

    string line;
    string var; 

    if (circuitfile.is_open())
    {
    while(getline(circuitfile, line)) {
        
    
    if (check_errors(&circuitfile)) {   
    break;
    }
    stringstream ss(line);
  
    
   
    ss>>var;
    if(var == "INPUT"){

    
    while (ss >> var) 
    {
        number_of_input++;
         
    }
    }

    else if(var == "OUTPUT"){
       
        while (ss >> var) 
    {
        number_of_output++;
         
    }
    }
    else{
        number_of_gate++;
    }
    ss.clear();
    }
    
    }
    circuitfile.close();


}

Gate** read_circuit(Gate **p){
     ifstream circuitfile;
    circuitfile.open("circuit.txt");
     int i = 0;
    string line,var;
    string input;
    
  //circuitfile.clear();
  //circuitfile.seekg(0, circuitfile.beg);
    if (circuitfile.is_open())
    {
    while(getline(circuitfile, line)) {
        
    
    stringstream ss(line);
  
    
   
    ss>>var;
    
    if(var == "INPUT"){
        i = 0;
    
    while (ss >> var) 
    {
        
          p[i]=new Input;
          p[i]->set_output(var);
          p[i++]->set_gate("INPUT");    
          
    }
    
    }

     else if(var == "OUTPUT"){
         while (ss >> var) 
    {
        
          p[i] = new Output;
          p[i]->set_input_name(var);
          p[i++]->set_gate("OUTPUT");    
          
    }
    }
     else if(var =="AND"){
         
        
          p[i] = new And;
          p[i]->set_gate("AND");
          ss>>var;
          p[i]->set_output(var);
          ss>>var;
          p[i]->set_input_name_1(var);
          ss>>var;
          p[i]->set_input_name_2(var);
           i++;  
           
          
    }

    else if(var == "OR"){
          p[i] = new Or;
          p[i]->set_gate("OR");
          ss>>var;
          p[i]->set_output(var);
          ss>>var;
          p[i]->set_input_name_1(var);
          ss>>var;
          p[i]->set_input_name_2(var);
           i++;  


    }

    else if(var == "NOT"){
        p[i] = new Not;
        p[i]->set_gate("NOT");
        ss>>var;
        p[i]->set_output(var);
        ss>>var;
        p[i]->set_input_name_1(var);
        i++;
    }

    else if(var == "FLIPFLOP"){
        p[i] = new Flipflop;
        p[i]->set_gate("FLIPFLOP");
        ss>>var;
        p[i]->set_output(var);
        ss>>var;
        p[i]->set_input_name_1(var);
        i++;
    }
    else if(var == "DECODER"){
        string *out;
        p[i] = new Decoder;
        p[i]->set_gate("DECODER");
        ss>>var;
        p[i]->set_output_1(var);
        ss>>var;
        p[i]->set_output_2(var);
        ss>>var;
        p[i]->set_output_3(var);
        ss>>var;
        p[i]->set_output_4(var);
        ss>>var;
        p[i]->set_input_name_1(var);
        ss>>var;
        p[i]->set_input_name_2(var);
    }
    
    }
    }
        circuitfile.close();
        return p;
}