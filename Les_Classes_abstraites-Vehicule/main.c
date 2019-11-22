#include <stdlib.h>
#include <stdio.h>
 
#include "Camion.h"
#include "Voiture.h"

//  ./vehicule AAEE1111 10 32


int main(int argc,const char* argv[])
{
    
    Vehicule *camion,*voiture;
    
    if(argc > 2){
            camion = (Vehicule*)New_Camion(argv[1],atoi(argv[2]),atoi(argv[3]));
			voiture = (Vehicule*)New_Voiture(argv[4],atoi(argv[5]),atoi(argv[6]));
    }
    else {
            camion = (Vehicule*)New_Camion("AAEE1111",2010,35000);
			voiture = (Vehicule*)New_Voiture("AAEE2222",2009,3500);
    }

    printf("\n%s\n",voiture->toString(voiture));
    printf("%s\n",voiture->demarrer(voiture));
    printf("%s\n",voiture->accelerer(voiture));

	printf("\n%s\n",camion->toString(camion));
    printf("%s\n",camion->demarrer(camion));
    printf("%s\n",camion->accelerer(camion));


#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

