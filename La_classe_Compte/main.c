#include <stdlib.h>
#include <stdio.h>
 
#include "Compte.h"

//      ./compte 20 1 ATA 300


int main(int argc,const char* argv[])
{
    Compte *compte;
    
    if(argc > 4)
    {
        compte = New_Compte(argv[1],argv[2],argv[3],argv[4]);
    }
    else compte = New_Compte("EE111222","Salim","Omar","06111111");

	Compte *compte2 = New_Compte("AA111222","KALLY","kally","06111112");

    printf("%s",compte->afficher(compte));

	compte->crediter(compte,500,0);
	printf("***************************\n Salim +500\n");
	printf("%s",compte->afficher(compte));

	compte->crediter(compte,147,1,compte2);
	printf("***************************\n Kally -> 500 -> Salim\n");
	printf("%s",compte->afficher(compte));

	compte->debiter(compte,500,0);
	printf("***************************\n Salim -500\n");
	printf("%s",compte->afficher(compte));

	compte->debiter(compte,147,1,compte2);
	printf("***************************\n Kally <- 500 <- Salim\n");
	printf("%s",compte->afficher(compte));

#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

