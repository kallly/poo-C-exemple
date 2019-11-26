#include <stdlib.h>
#include <stdio.h>
 
#include "Directeur.h"


int main(int argc,const char* argv[])
{
    
    Personne *personne[8];
    
//
    personne[0] = (Personne*)New_Personne("A","a",(date){03,03,2000});
    personne[1] = (Personne*)New_Personne("B","b",(date){04,03,2001});
    personne[2] = (Personne*)New_Employe("C","c",(date){04,03,2002},(float)2400);
    personne[3] = (Personne*)New_Employe("D","d",(date){05,03,2003},(float)1800);
    personne[4] = (Personne*)New_Employe("E","e",(date){06,03,2004},(float)1500);

    personne[5] = (Personne*)New_Chef("F","f","service1",(date){07,04,1990},(float)5000);
    personne[6] = (Personne*)New_Chef("G","g","service2",(date){8,04,1995},(float)5200);

    personne[7] = (Personne*)New_Directeur("H","h","service3","societe1",(date){9,05,1977},(float)99000);
//
    printf("%ld\t%ld\t%ld\t%ld\n",sizeof(personne[0]),sizeof(personne[1]),sizeof(personne[2]),sizeof(personne[7]));

    for(int n=0;n<8;n++){
        printf("%s\n",personne[n]->afficher(personne[n]));
    }
    
    

#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

