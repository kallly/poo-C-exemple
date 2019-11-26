#include <stdlib.h>
#include <stdio.h>
 
#include "Complexe.h"

//gcc -o Complexe -c Complexe.c ; gcc main.c Complexe; ./a.out  3 -2


int main(int argc,const char* argv[])
{
    Complexe *complexe;
    
    if(argc > 2)complexe = New_Complexe(atoi(argv[1]),atoi(argv[2]));
    else complexe = New_Complexe(2,4);

    printf("\nnombre Complexe: %s\n",complexe->afficher(complexe));

    complexe = complexe->plus(complexe,New_Complexe(4,5));
    printf("\nnombre Complexe: %s\n",complexe->afficher(complexe));

    complexe = complexe->moins(complexe,New_Complexe(4,5));
    printf("\nnombre Complexe: %s\n",complexe->afficher(complexe));


#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

