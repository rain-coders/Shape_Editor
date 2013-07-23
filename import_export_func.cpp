#include "import_export_func.h"


//function export verticles to .poly file
void func_export_poly(char *fName, vector<POINT> *vect)
{
    if(!fName){
        printf("\nERROR!!! fName is not exist!!\n");
        return;
    }


}

//function import verticles from .poly file
vector<POINT> *func_import_poly(char *fName)
{

}

//function export to chipmunk vector
char *func_export_cpVect(vector<POINT> *vect)
{
    char *result = new char[DYN_CHAR_SIZE];

    strcpy(result, "");
    strcat(result, "cpVect verts[] = {\n");

    printf("VECT SIZE : %d", vect->size());

    for(int i=0;i<vect->size();i++) {
        char *tmp = new char[DIGIT_SIZE];

        sprintf(tmp, "\tcpv(%d, %d),\n", vect->at(i).x, vect->at(i).y);
        strcat(result, tmp);

        delete tmp;
    }

    strcat(result, "};\n");

    return result;
}
