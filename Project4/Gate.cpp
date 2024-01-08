#include<iostream>
#include"Gate.h"
using namespace std;

Gate :: Gate(){
    

}

/*Gate :: Gate(string _gate_type){

    gate_type = _gate_type;
}
*/
string Gate :: get_gate_type(){
    return gate_type;
}