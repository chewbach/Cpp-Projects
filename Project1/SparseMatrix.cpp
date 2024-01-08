#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "SparseMatrix.h" 
#include"SparseVector.h"


using namespace std;

SparseMatrix :: SparseMatrix(){ }			//default constructor

SparseMatrix :: SparseMatrix(const string & filen){	

            filename = filen;				//open a file
            ifstream file;
            file.open(filename.c_str());	
            
       if(!(file.is_open())){			////if file does not exist,program will exit
                exit(1);
            }

       else{					//If the file exists, it is read.
            string line;
         while(getline(file, line)){		
                  
               if (check_errors(&file)) {
		break;					//skip the data processing and break
		}

             	int k=line.size();			//k hold size of line
		int find_dot;
		int counter=0;
    		
    	for(int i=0;i<k;i++){				//find ':' number.So we can find total element number in an line.
        	if(line[i]==':')
            	counter++;
    		}	
    
	    



	string delimiter = " ";
	string delimiterx = ":";
	int a =line.find(delimiter);          	//find delimiter in line 
	string token = line.substr(0, a); 		//get new string until delimiter
	int stoi_row_index = stoi(token);		// convert string to integer value
	line.erase(0,a+1);				//delete string until delimeter
	token.clear();					
							//By doing this, we read the row index from the file.
	
	int j=0;
	while ( j<counter-1){				//loop will continues until the number of elements



	a =line.find(delimiterx);			//find delimiterx in line
	token = line.substr(0, a);			//get new string until delimiter
	int stoi_index = stoi(token);			// convert string to integer value
	
	line.erase(0,a+1);				//delete string until delimeter
	
	//This allows us to find the column index
	token.clear();

	a =line.find(delimiter);			//find delimiter in line
	token = line.substr(0, a);			//get new string until delimiter
	double value = stod(token);			// convert string to double value

	////This allows us to find the data in matrix	
	line.erase(0,a+1);
	token.clear();

	
	token.clear();

	j++;

	vec.push_back({stoi_row_index,{stoi_index,value}});	//put the finded values ​​into vector

	}
	    token.clear();					//This part is done because it reads the data twice in reading the last line.
	    a =line.find(delimiterx);
	token = line.substr(0, a);
	    
	     line.erase(0,a+1);
	     int last_element_index=stoi(token);              
	     double d = stod(line);
	     vec.push_back({stoi_row_index,{last_element_index,d}});          
	           
		        }
		        
		  }
	    file.close();		  
        }

int SparseMatrix :: check_errors(ifstream *f){		//a helper function in order to secure file read operations
    int stop = 0;
if (f->eof()) {
// EOF after std::getline() is not the criterion to stop processing
// data: In case there is data between the last delimiter and EOF,
// getline() extracts it and sets the eofbit.
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




ostream& operator <<(ostream& outputStream,const SparseMatrix& v){		//overloading function for print sparse matrix

        									//print first row index
     for(int i = 0; i<v.vec.size();i++){					
	if(i==0){
	outputStream<<v.vec[0].row_index<<" ";
	}
        outputStream<<v.vec[i].d;					//print matrix
        if(i<v.vec.size()-1 && v.vec[i].row_index != v.vec[i+1].row_index){	//if there are different row index skip to line

        outputStream<<endl;
        outputStream<<v.vec[i+1].row_index<<" ";
        }
     }


        return outputStream;



}




const SparseMatrix SparseMatrix :: operator -(){			//negates elements of a Sparsematrix

    SparseMatrix temp;							//create temp object	
    temp.vec.resize(vec.size());					//resize vector of temp object 
    
    for (int i = 0; i < vec.size(); ++i)					
	{
		temp.vec[i].row_index = vec[i].row_index;		//assign indexes to temp.		
		 			
        temp.vec[i].d =  -vec[i].d;					// convert value to negative
    
    }

	return temp;
         


}

const SparseMatrix SparseMatrix :: operator=(const SparseMatrix & v){	//assign one sparsematrix to another
        
        vec.clear();
        vec.resize(v.vec.size());						//resize vector

	for (int i = 0; i < v.vec.size(); i++){
        this->vec[i].row_index = v.vec[i].row_index;				
        this->vec[i].d = v.vec[i].d;						//sync index and data
    
    
    }
		
	
	return *this;



}

  SparseMatrix SparseMatrix :: operator + (  SparseMatrix &v){  		//add one Sparsematrix from another
        SparseMatrix temp;							//create temp object
        int max_index = 0;
        int row_max_index=0;
        for(int i = 0;i<v.vec.size();i++){					//find max row index of first matrix
            if(v.vec[i].row_index>row_max_index)
                row_max_index = v.vec[i].row_index;


            if(v.vec[i].d.get_var_index()>max_index)				//find max row of first matrix
                max_index = v.vec[i].d.get_var_index();
        }

         for(int i = 0;i<vec.size();i++){					//find max row index of second matrix
             if(vec[i].row_index>row_max_index)
                row_max_index = vec[i].row_index;


            if(vec[i].d.get_var_index()>max_index)				//find max row of second matrix
                max_index = vec[i].d.get_var_index();
        }

        
        row_max_index = row_max_index+1;
        max_index=max_index+1;

        double first[row_max_index][max_index];				//create  temp matrixs for to be able to addition
        double second[row_max_index][max_index];
        double toplam[row_max_index][max_index];				//this matrix hold if sparsematrix have a data in it's row and column.Else matrix hold 0 values. 

        for(int i=0;i<row_max_index;i++){
            for(int j = 0 ; j<max_index;j++){					//matrix initialization

                first[i][j] = 0;
                second[i][j] = 0;
            }
        }
        

        

        for (int i = 0; i < vec.size();i++){
            int indx = vec[i].row_index;					//assign row index
            int indy = vec[i].d.get_var_index(); 				//assign column index
            first[indx][indy] = vec[i].d.get_var_num();			//fill matrix with datas
        }

         for (int i = 0; i < v.vec.size();i++){
            int indx = v.vec[i].row_index;					//assign row index 
            int indy = v.vec[i].d.get_var_index(); 				//assign column index
            second[indx][indy] = v.vec[i].d.get_var_num();			//fill matrix with datas
        }

        
                

            for(int i=0;i<row_max_index;i++){					//perform the addition
            for(int j = 0 ; j<max_index;j++){

                toplam[i][j] = first[i][j]+second[i][j];

            
            }
        }

        for(int i=0;i<row_max_index;i++){					//if the value in the matrix is ​​not 0, the elements are sent to the temp object
            for(int j = 0 ; j<max_index;j++){
                double res = toplam[i][j];
                if(res != 0){
                    temp.vec.push_back({i,{j,res}});                    
                }

            
            }
        }

        


    return temp;



}


SparseMatrix SparseMatrix ::  operator - (SparseMatrix &v){		//subtructs one Sparsematrix from another
    SparseMatrix temp;							//create temp object
        int max_index = 0;		
        int row_max_index=0;
        for(int i = 0;i<v.vec.size();i++){				
            if(v.vec[i].row_index>row_max_index)			//find max row index of first matrix
                row_max_index = v.vec[i].row_index;


            if(v.vec[i].d.get_var_index()>max_index)			//find max row of first matrix
                max_index = v.vec[i].d.get_var_index();
        }

         for(int i = 0;i<vec.size();i++){				
             if(vec[i].row_index>row_max_index)			//find max row index of second matrix
                row_max_index = vec[i].row_index;


            if(vec[i].d.get_var_index()>max_index)			//find max row of second matrix
                max_index = vec[i].d.get_var_index();
        }

        
        row_max_index = row_max_index+1;
        max_index=max_index+1;

        double first[row_max_index][max_index];			//create  temp matrixs for to be able to substruct 
        double second[row_max_index][max_index];			 	
        double sub[row_max_index][max_index];				//this matrix hold if sparsematrix have a data in it's row and column.Else matrix hold 0 values. 

        for(int i=0;i<row_max_index;i++){
            for(int j = 0 ; j<max_index;j++){
									//matrix initialization				
                first[i][j] = 0;
                second[i][j] = 0;
            }
        }
        

        

        for (int i = 0; i < vec.size();i++){				
            int indx = vec[i].row_index;				//assign row index 
            int indy = vec[i].d.get_var_index(); 			//assign column index
            first[indx][indy] = vec[i].d.get_var_num();		//fill matrix with datas
        }

         for (int i = 0; i < v.vec.size();i++){
            int indx = v.vec[i].row_index;				//assign row index 
            int indy = v.vec[i].d.get_var_index(); 			//assign column index
            second[indx][indy] = v.vec[i].d.get_var_num();		//fill matrix with datas
        }

        
                

            for(int i=0;i<row_max_index;i++){
           	 for(int j = 0 ; j<max_index;j++){			//perform the subtraction

               	 sub[i][j] = first[i][j]-second[i][j];

            
            }
        }

        for(int i=0;i<row_max_index;i++){
            for(int j = 0 ; j<max_index;j++){				//if the value in the matrix is ​​not 0, the elements are sent to the temp object
                double res = sub[i][j];
                if(res != 0){
                    temp.vec.push_back({i,{j,res}});                    
                }

            
            }
        }

        


    return temp;


}


 SparseMatrix SparseMatrix::transpose(){					//transpose of a matrix

 	SparseMatrix temp;							//create temp object
        int max_index = 0;
        int row_max_index=0;
       
         for(int i = 0;i<vec.size();i++){					//find max row index of matrix
             if(vec[i].row_index>row_max_index)
                row_max_index = vec[i].row_index;


            if(vec[i].d.get_var_index()>max_index)				//find max column of matrix
                max_index = vec[i].d.get_var_index();
        }

        
        row_max_index = row_max_index+1;
        max_index=max_index+1;

        double first[row_max_index][max_index];				//create  temp matrixs for to be able to substruct 	
        double transpose[max_index][row_max_index];				//this matrix for transpose
        for(int i=0;i<max_index;i++){
            for(int j = 0 ; j<row_max_index;j++){				//matrix initialization
            transpose[i][j]=0;
            }}

        for(int i=0;i<row_max_index;i++){					//matrix initialization
            for(int j = 0 ; j<max_index;j++){


                first[i][j] = 0;

                

            }

        }
        
        
        for (int i = 0; i < vec.size();i++){
            int indx = vec[i].row_index;
            int indy = vec[i].d.get_var_index(); 
            first[indx][indy] = vec[i].d.get_var_num();			//fill matrix using data
        }
        
       
        
            	
           for(int i=0;i<row_max_index;i++){					//find transpose of matrix and fill matrix transpose using data
            for(int j = 0 ; j<max_index;j++){
            if(first[i][j]!=0){
          	transpose[j][i] = first [i][j];
            	    	
            	    	}
            	    	} 	    	
		}
	for(int i=0;i<max_index;i++){						//if the value in the matrix is ​​not 0, the elements are sent to the temp object
            for(int j = 0 ; j<row_max_index;j++){
           	if(transpose[i][j]!=0){
           	double res = transpose[i][j];
           		temp.vec.push_back({i,{j,res}});
            }}
            }
        


    return temp;

 }
 
 SparseMatrix SparseMatrix :: operator *(SparseMatrix &v){			//multiplication of two matrix	
	SparseMatrix temp;
	
      int r1=0;
      int c1=0;
      for(int i = 0;i<vec.size();i++){			
             if(vec[i].row_index>r1)
                r1= vec[i].row_index;				//find max row of first matrix


            if(vec[i].d.get_var_index()>c1)			//find max column of first matrix
                c1 = vec[i].d.get_var_index();
        }
        
        int r2=0;
        int c2=0;
        
 	for(int i = 0;i<v.vec.size();i++){			//find max row of second matrix
            if(v.vec[i].row_index>r2)
                r2 = v.vec[i].row_index;


            if(v.vec[i].d.get_var_index()>c2)			//find max column of second matrix
                c2 = v.vec[i].d.get_var_index();
        }
 
 
 

 
 	if(c1 != r2){						//In matrix multiplication, the colum of the first vector and the row of the second vector must be the same.
 		exit(1);
 		} 
 
 
 	double first[r1+1][c1+1];				//create temp matrix
        double second[r2+1][c2+1];
        double mult[r1+1][c2+2];				//this matrix hold if sparsematrix have a data in it's row and column.Else matrix hold 0 values.
        
        for(int i=0;i<r1+1;i++){
        	for(int j=0;j<c1+1;j++){
        	first[i][j]=0;					//matrix initialization
	}
	} 
 	
 	for(int i=0;i<r2+1;i++){
        	for(int j=0;j<c2+1;j++){			//matrix initialization
        	second[i][j]=0;
        	}
        	}
        	
        for(int i=0;i<r1+1;i++){
        	for(int j=0;j<c2+1;j++){			//matrix initialization
        	mult[i][j]=0;
        	}
        	}
        	
        for (int i = 0; i < vec.size();i++){
            int indx = vec[i].row_index;			//assign row index
            int indy = vec[i].d.get_var_index(); 		//assgin column index
            first[indx][indy] = vec[i].d.get_var_num();	//fill matrix with datas
        }

         for (int i = 0; i < v.vec.size();i++){
            int indx = v.vec[i].row_index;			//assign row index
            int indy = v.vec[i].d.get_var_index(); 		//assgin column index
            second[indx][indy] = v.vec[i].d.get_var_num();	//fill matrix with datas
        }	
        	
        	
        	
        	
        	
        	
        	
        	
        for(int i = 0; i < r1+1; ++i)
        	for(int j = 0; j < c2+1; ++j)
                   for(int k = 0; k < c1+1; ++k)
            {
                mult[i][j] += first[i][k] * second[k][j];	//perform the multiplication
            }
            
            for(int i = 0; i < r1+1; ++i){
    for(int j = 0; j < c2+1; ++j)
    {
    	if(mult[i][j]!=0){					//if the value in the matrix is ​​not 0, the elements are sent to the temp object
    	double res = mult[i][j];
    	
    	temp.vec.push_back({i,{j,res}});
              
            }
            }
            }
        
        
	
 
 return temp;
 
 
 }
 
 
 
 
 











