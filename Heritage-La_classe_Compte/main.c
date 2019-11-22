#include <stdlib.h>
#include <stdio.h>
 
#include "Compte.h"
#include "CompteEpargne.h"
#include "ComptePayant.h"

//      ./compte EE111222 Salim Omar 06111111


int main(int argc,const char* argv[])
{
    ComptePayant *compte;
    
    if(argc > 4 && argc < 6)
    {
        compte = New_ComptePayant(argv[1],argv[2],argv[3],argv[4],0);
    }
	else {
		if(argc > 5){
			compte = New_ComptePayant(argv[1],argv[2],argv[3],argv[4],1,(float)atoi(argv[5]));
		}
    	else compte = New_ComptePayant("EE111222","Salim","Omar","06111111",0);
	}
	CompteEpargne *compte2 = New_CompteEpargne("AA111222","KALLY","kally","06111112",1,5000.);

    printf("%s",compte->toString(compte));

	compte->crediter(compte,500,0);
	printf("***************************Salim +500\n");
	printf("%s",compte->toString(compte));

	compte->crediter(compte,147,1,compte2);
	printf("***************************Kally -> 147 -> Salim\n");
	printf("%s",compte->toString(compte));

	compte->debiter(compte,500,0);
	printf("***************************Salim -500\n");
	printf("%s",compte->toString(compte));

	compte->debiter(compte,500,1,compte2);
	printf("***************************Kally <- 500 <- Salim\n");
	printf("%s",compte->toString(compte));


	printf("***************************Kally\n");
	printf("%s",compte2->toString(compte2));

	compte2->calculInteret(compte2);
	printf("***************************Kally Epargne\n");
	printf("%s",compte2->toString(compte2));

#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

