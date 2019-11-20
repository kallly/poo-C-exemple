#include <stdlib.h>
#include <stdio.h>
 
#include "Point.h"

//gcc -o Point -c Point.c ; gcc main.c Point -lm; ./a.out 3 4
int main(int argc,const char* argv[])
{
    Point *point;
    
    if(argc > 2)point = New_Point(atoi(argv[1]),atoi(argv[2]));
    else point = New_Point(1,2);

    printf("\nLa norme du point (%0.1f,%0.1f) est: %f\n",point->get_abscisse(point),point->get_ordonne(point),point->norme(point));


#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}
