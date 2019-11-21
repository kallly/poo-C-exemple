#include <stdlib.h>
#include <stdio.h>
 
#include "Maison.h"
//gcc -o Batiment -c Batiment.c ;gcc -o Maison -c Maison.c -l Batiment; gcc main.c Maison Batiment; ./a.out  "rue de la licorne" 4


int main(int argc,const char* argv[])
{
    Maison *maison;
    
    if(argc > 2)maison = New_Maison(2, argv[1], atoi(argv[2]) );
    else maison = New_Maison(0);

    printf("\n%s\n",maison->to_string(maison));

#ifdef __WIN32__s
        system("PAUSE");
#endif
        return 0;
}

