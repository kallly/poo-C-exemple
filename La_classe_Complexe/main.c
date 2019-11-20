#include <stdlib.h>
#include <stdio.h>
 
#include "Complexe.h"

//gcc -o Complexe -c Complexe.c ; gcc main.c Complexe; ./a.out  3 -2


int main(int argc,const char* argv[])
{
    Complexe *Complexe;
    
    if(argc > 2)Complexe = New_Complexe(atoi(argv[1]),atoi(argv[2]));
    else Complexe = New_Complexe(2,4);

    printf("\nnombre Complexe: %s\n",Complexe->afficher(Complexe));

    Complexe = Complexe->plus(Complexe,New_Complexe(4,5));
    printf("\nnombre Complexe: %s\n",Complexe->afficher(Complexe));

    Complexe = Complexe->moins(Complexe,New_Complexe(4,5));
    printf("\nnombre Complexe: %s\n",Complexe->afficher(Complexe));


#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

