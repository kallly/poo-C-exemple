#include <stdlib.h>
#include <stdio.h>
 
#include "Cercle.h"
//gcc -o Point -c Point.c ;gcc -o Cercle -c Cercle.c; gcc main.c Cercle Point; ./a.out  0 0 4


int main(int argc,const char* argv[])
{
    Cercle *Cercle;
    
    if(argc > 3)Cercle = New_Cercle(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
    else Cercle = New_Cercle(2,4,5);

    printf("\n%s\n",Cercle->afficher(Cercle));
    printf("Le périmétre est : %0.2f\n",Cercle->getPerimetre(Cercle));
    printf("La surface est : %0.2f\n",Cercle->getSurface(Cercle));
    
    Point *p=New_Point(4,0);
    printf("%s\n",p->afficher(p));
    printf("%s\n", Cercle->appartient(Cercle,p)?"Le point appartient au cercle":"Le point n'appartient pas au cercle" );

#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

