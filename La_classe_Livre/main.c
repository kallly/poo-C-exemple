#include <stdlib.h>
#include <stdio.h>
 
#include "Livre.h"

//gcc -o Livre -c Livre.c ; gcc main.c Livre; ./a.out  "Programmer en C" "Claude Delannoy" 350


int main(int argc,const char* argv[])
{
    Livre *livre;
    
    if(argc > 3)livre = New_Livre(argv[1],argv[2],atoi(argv[3]));
    else livre = New_Livre("Programmer en C","Claude Delannoy",350);

    printf("%s",livre->afficher(livre));

#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

