#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"SparseVector.h"


using namespace std;

class SparseMatrix{
    public:
    SparseMatrix();
    SparseMatrix(const string & filen);

  
    friend ostream& operator <<(ostream& outputStream,const SparseMatrix& v);
    const SparseMatrix operator -();
    const SparseMatrix operator=(const SparseMatrix & v);
    SparseMatrix operator + (SparseMatrix &v);
    SparseMatrix operator - (SparseMatrix &v);
    SparseMatrix operator *(SparseMatrix &v);
    SparseMatrix transpose();	
     



    private:
    struct e2{
        int row_index;
        SparseVector d;
        };
        
        vector<e2> vec;
        string filename;
        int check_errors(ifstream *f);


};

#endif
