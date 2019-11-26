#include <stdlib.h>
#include <stdio.h>
 
#include "Employe.h"

//gcc -o Employe -c Employe.c ; gcc main.c Employe; ./a.out  "Programmer en C" "Claude Delannoy" 350


int main(int argc,const char* argv[])
{
    Employe *employe;
    
    if(argc > 6)
    {
        employe = New_Employe(atoi(argv[1]),argv[2],argv[3],
                (Date) {atoi(argv[4]),atoi(argv[5]),atoi(argv[6])},
                (Date) {atoi(argv[7]),atoi(argv[8]),atoi(argv[9])}, 
                (float)atoi(argv[10]));
    }
    else employe = New_Employe(10,"KALLY","Kally",(Date) {28,03,2000},(Date) {21,10,2017},4000);

    printf("%s",employe->afficherEmploye(employe));

#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

