#ifndef IMPORT_EXPORT_FUNC_H
#define IMPORT_EXPORT_FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

const int DYN_CHAR_SIZE = 5000;
const int DIGIT_SIZE = 50;

struct POINT{
    int x;
    int y;

    POINT(){
        x = 0;
        y = 0;
    }

    POINT(int x, int y){
        this->x = x;
        this->y = y;
    }
};


//function export verticles to .poly file
void func_export_poly(char *fName, vector<POINT> *vect);

//function import verticles from .poly file
vector<POINT> *func_import_poly(char *fName);

//function export to chipmunk vector
char *func_export_cpVect(vector<POINT> *vect);

#endif // IMPORT_EXPORT_FUNC_H
