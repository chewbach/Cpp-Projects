#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "SparseVector.h"

using namespace std;


SparseVector :: SparseVector(){		//default constructor
    filename="";
}

SparseVector :: SparseVector(const string & name_of_file){
        filename = name_of_file;				//open a file
        ifstream file;
       
        file.open(filename.c_str());
        int i = 0;
        if(!(file.is_open())){				//if file does not exist,program will exit
            exit(1);
	}
        
        else {							//If the file exists, it is read.
            int a;						
            double b;						
            char line;						
            while(file>>a>>line>>b){				//Values ​​are read in accordance with the writing style of the file.
                if(check_errors(&file)){			//a helper function in order to secure file read operations
                    break;}

        var.push_back ({a, b});				//add index and data in a sparse vector

        }
    }
    file.close();
}


int SparseVector ::  check_errors(ifstream *f){		//a helper function in order to secure file read operations

    int stop = 0;
	if (f->eof()) {					//check end of file

	stop = 0;
	
	}
	
	if (f->fail()) {					//check failes
	stop = 1;
	}
	
	if (f->bad()) {					//check if it's bad
	stop = 1;
	}
	
return stop;
}

ostream& operator <<(ostream& outputStream,const SparseVector& v){	//overloading function for print sparse vector
			
    for(unsigned int i=0;i<v.var.size();i++)
            outputStream<<v.var[i].index<<":"<<v.var[i].num<<" ";	//it will print variable that desired format

    return outputStream;
}


const SparseVector SparseVector :: operator -(){			//negates elements of a SparseVector
    SparseVector temp;
    temp.var.resize(var.size());					//resize temp object
    
    for (int i = 0; i < var.size(); ++i)					
	{
		temp.var[i].index = var[i].index;			//assign indexes to temp.		
		temp.var[i].num = var[i].num * -1;			// convert value to negative
	}

	return temp;							//return negative value object
         
       
}


double dot(const SparseVector & first ,const SparseVector & second){
        int min;
        int max;
        double total=0;
        if(first.var.size()>second.var.size()){	//the sizes of the vectors are compared
            min = second.var.size();			//It is assigned to the vector size with the max or min.
	    max = first.var.size();

         }
        else{						//It is assigned to the vector size with the max or min.
            min=first.var.size();
            max=second.var.size();
        }

        if(first.var.size()>second.var.size()){	//if the size of the first vector is greater than the second
        int i=0;
        while(i<min){
            for (int j=0;j<max;j++){					//check same index. Multiply if values ​​with same index exist.
                if (second.var[i].index == first.var[j].index){
                   total += second.var[i].num * first.var[j].num;
                } 
            }
            i++;
        }
        }
        else{						//if the size of the second vector is greater than the first

            int i = 0;
            while(i<min){
            for (int j=0;j<max;j++){
                if (first.var[i].index == second.var[j].index){	//check same index. Multiply if values ​​with same index exist.
                    total += first.var[i].num * second.var[j].num;

                } 
            }
            i++;
        }

        }

                return total;						//return result of dot product

}



const SparseVector  SparseVector::operator=( const SparseVector & v)	//assign one sparsevector to another
{
	var.clear();					//clear vector
	var.resize(v.var.size());			//resize vector

	for (int i = 0; i < v.var.size(); i++)	//loop for size of vector
		this->var[i] = v.var[i];		//sync index and data
	
	return *this;
}


 const SparseVector SparseVector :: operator + (const SparseVector &v){	//add two sparsevector

        SparseVector temp;				//create a temp object
        
       
        int max;
        int min;
        int counter=0;
        int a;
        double b;
      
        int maxa=0;
        for(unsigned int i=0;i<var.size();i++){	//find maximum index of first 
                    if(var[i].index>maxa ){
                        maxa = var[i].index;
                    }
                   
        }
       


        int maxb=0;
        for(unsigned int i=0;i<v.var.size();i++){	//find maximum index of second 
                    if(v.var[i].index > maxb ){
                        maxb = v.var[i].index;
                    }
        }
       
        
        int absolute_max;					
        if(maxa>maxb){				//find absolute max
            absolute_max = maxa;
        }
        else{
            absolute_max = maxb;
        }
        absolute_max = absolute_max+1;	//The vector that has as many elements as Absolute_max should have 1 extra size.

        vector<double>f1(absolute_max,0);	//these variables create a normal vector using their Sparse vector values.
        vector<double>f2(absolute_max,0);	//these variables create a normal vector using their Sparse vector values.
        
        for(int i = 0 ; i<absolute_max;i++){
            for(int j=0;j<var.size();j++){	//if the sparse matrix has that index, write the value inside the index to the normal vector.
            if(i == var[j].index){		
            f1[i]  = var[j].num;
            }
            }
        }
        

            for(int i = 0 ; i<absolute_max;i++){	//if the sparse matrix has that index, write the value inside the index to the normal vector.
            for(int j=0;j<v.var.size();j++){
            if(i == v.var[j].index){
            f2[i]  = v.var[j].num;
            }
            }
        }
      
        vector<double>total;				//create a regular vector for add two vector 
        for(int i = 0 ; i<absolute_max;i++){
            total.push_back(f1[i]+f2[i]);		//add vectors into total vector
        }
         
      

        for(int i = 0 ; i<absolute_max;i++){
            if(total[i] != 0){			//If the value in the index is not 0, send the values ​​to the temp object.
                    a = i;
                    b = total[i];
                    temp.var.push_back({a,b});	//send the values ​​to the temp object.

            }
        }
        
        return temp;
    }



    const SparseVector SparseVector :: operator - (const SparseVector &v){	//subtructs one Sparsevector from another

        SparseVector temp;				//create a temp object
        
        int max;
        int min;
        int counter=0;
        int a;
        double b;
      
        int maxa=0;
        for(unsigned int i=0;i<var.size();i++){	//find maximum index of first vector
                    if(var[i].index>maxa ){
                        maxa = var[i].index;
                    }
                   
        }
       


        int maxb=0;
        for(unsigned int i=0;i<v.var.size();i++){	////find maximum index of second
                    if(v.var[i].index > maxb ){
                        maxb = v.var[i].index;
                    }
        }
       
        
        int absolute_max;				//find absolute max
        if(maxa>maxb){
            absolute_max = maxa;
        }
        else{
            absolute_max = maxb;
        }
        absolute_max = absolute_max+1;	//The vector that has as many elements as Absolute_max should have 1 extra size.

        vector<double>f1(absolute_max,0);	//these variables create a normal vector using their Sparse vector values.
        vector<double>f2(absolute_max,0);	//these variables create a normal vector using their Sparse vector values.
        for(int i = 0 ; i<absolute_max;i++){
            for(int j=0;j<var.size();j++){	//if the sparse matrix has that index, write the value inside the index to the normal vector.
            if(i == var[j].index){
            f1[i]  = var[j].num;
            }
            }
        }
        

            for(int i = 0 ; i<absolute_max;i++){	//if the sparse matrix has that index, write the value inside the index to the normal vector.
            for(int j=0;j<v.var.size();j++){
            if(i == v.var[j].index){
            f2[i]  = v.var[j].num;
            }
            }
        }
      
        vector<double>sub;				//create a regular vector for subtracts two vector
        for(int i = 0 ; i<absolute_max;i++){
            sub.push_back(f1[i]-f2[i]);
        }
         
      

        for(int i = 0 ; i<absolute_max;i++){		//If the value in the index is not 0, send the values ​​to the temp object.
            if(sub[i] != 0){
                    a = i;
                    b = sub[i];			// send the values ​​to the temp object.
                    temp.var.push_back({a,b});

            }
        }
        
        return temp;

    }

     SparseVector :: SparseVector(int _index,double _data){
       
        var.push_back({_index,_data});
   
    }
    
    double SparseVector :: get_var_num(){
        double b=var[0].num;
        return b;
    }
    
    int SparseVector :: get_var_index(){
        int a = var[0].index;
        return a;
    }
