#include <stdlib.h>
#include <stdio.h>
 
#include "Cercle.h"
//gcc -o Point -c Point.c ;gcc -o Cercle -c Cercle.c; gcc main.c Cercle Point; ./a.out  0 0 4


int main(int argc,const char* argv[])
{
    Cercle *cercle;
    
    if(argc > 3)cercle = New_Cercle(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
    else cercle = New_Cercle(2,4,5);

    printf("\n%s\n",cercle->afficher(cercle));
    printf("Le périmétre est : %0.2f\n",cercle->getPerimetre(cercle));
    printf("La surface est : %0.2f\n",cercle->getSurface(cercle));
    
    Point *p=New_Point(4,0);
    printf("%s\n",p->afficher(p));
    printf("%s\n", cercle->appartient(cercle,p)?"Le point appartient au cercle":"Le point n'appartient pas au cercle" );

#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

