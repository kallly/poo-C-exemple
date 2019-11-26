#include <stdlib.h>
#include <stdio.h>
 
#include "Ouvrier.h"
#include "Cadre.h"
#include "Patron.h"

//  ./employe AAEE1111 TEST test


int main(int argc,const char* argv[])
{
    
    Employe *ouvrier,*cadre,*patron;
    
    if(argc > 2){
            ouvrier = (Employe*)New_Ouvrier(argv[1],argv[2],argv[3],(date){20,03,1997});
	        cadre = (Employe*)New_Cadre(argv[4],argv[5],argv[6],(date){10,07,1995},3);
			patron = (Employe*)New_Patron(argv[7],argv[8],argv[9],(date){12,11,1972});
    }
    else {
            ouvrier = (Employe*)New_Ouvrier("AAEE1111","OUVRIER","ouvrier",(date){20,03,1997});
	        cadre = (Employe*)New_Cadre("AAEE2222","CADRE","cadre",(date){10,07,1995},3);
			patron = (Employe*)New_Patron("AAEE3333","PATRON","patron",(date){12,11,1972});
    }

	printf("\n%s\n",ouvrier->toString(ouvrier));
	printf("\n%s\n",cadre->toString(cadre));
	printf("\n%s\n",patron->toString(patron));

#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

