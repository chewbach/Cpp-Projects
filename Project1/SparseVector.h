#ifndef SPARSEVECTOR_H
#define SPARSEVECTOR_H

#include<iostream>
#include<fstream>
#include<vector>
#include<string>


using namespace std;

class SparseVector{
    public:
    
    SparseVector();
    SparseVector(const string & name_of_file);
    SparseVector(int _index,double _data);
    friend ostream& operator <<(ostream& outputStream,const SparseVector& var);
    friend double dot(const SparseVector & first ,const SparseVector & second);
    const SparseVector operator -();
    const SparseVector operator=(const SparseVector & v);
    const SparseVector operator + (const SparseVector &v);
    const SparseVector operator - (const SparseVector &v);
    int get_var_index();
    double get_var_num();

    private:

    struct variables{
        int index;
        double num;
    };
    
    vector<variables> var;
    string filename;
    int check_errors(ifstream *f);
};

#endif 
