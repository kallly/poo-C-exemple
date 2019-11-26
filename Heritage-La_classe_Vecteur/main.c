#include <stdlib.h>
#include <stdio.h>
 
#include "Vecteur2D.h"
#include "Vecteur3D.h"

//      ./vecteur 0 2 2 0 0 3 4 4 3 0


int main(int argc,const char* argv[])
{
    Vecteur2D *vecteur1,*vecteur2;
	Vecteur3D *vecteur3,*vecteur4;
    
    if(argc > 4)
    {
        vecteur1 = New_Vecteur2D(atoi(argv[1]),atoi(argv[2]));
		vecteur2 = New_Vecteur2D(atoi(argv[3]),atoi(argv[4]));
		vecteur3 = New_Vecteur3D(atoi(argv[5]),atoi(argv[6]),atoi(argv[7]));
		vecteur4 = New_Vecteur3D(atoi(argv[8]),atoi(argv[9]),atoi(argv[10]));
    }
    else {
		vecteur1 = New_Vecteur2D(2,4);
		vecteur2 = New_Vecteur2D(2,4);
		vecteur3 = New_Vecteur3D(2,4,6);
		vecteur4 = New_Vecteur3D(2,4,6);
	}
	

	printf("\n%s\n",vecteur1->toString(vecteur1));
	printf("\n%f\n",vecteur1->norme(vecteur1));
	printf("\n%s\n",vecteur2->toString(vecteur2));
	printf("\n%f\n",vecteur2->norme(vecteur2));
	printf("\n%s\n",vecteur1->equals(vecteur1,vecteur2)?"Les vecteurs sont equals":"Les vecteurs ne sont pas equals");

	printf("\n%s\n",vecteur3->toString(vecteur3));
	printf("\n%f\n",vecteur3->norme(vecteur3));
	printf("\n%s\n",vecteur4->toString(vecteur4));
	printf("\n%f\n",vecteur4->norme(vecteur4));
	printf("\n%s\n",vecteur3->equals(vecteur3,vecteur4)?"Les vecteurs sont equals":"Les vecteurs ne sont pas equals");
	

#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

