#include <stdlib.h>
#include <stdio.h>
 
#include "Rectangle.h"

//gcc -o Rectangle -c Rectangle.c ; gcc main.c Rectangle; ./a.out  100 30


int main(int argc,const char* argv[])
{
    Rectangle *Rectangle;
    
    if(argc > 2)Rectangle = New_Rectangle(atoi(argv[1]),atoi(argv[2]));
    else Rectangle = New_Rectangle(10,20);

    printf("\nlongueur: %0.2f\nlargeur: %0.2f",Rectangle->get_longueur(Rectangle),Rectangle->get_largeur(Rectangle));
    printf("\nperimetre: %0.2f",Rectangle->perimetre(Rectangle));
    printf("\nsurface: %0.2f",Rectangle->aire(Rectangle));
    if(Rectangle->isCarre(Rectangle)) printf("\nc'est un carré\n");
    else printf("\nce n'est pas un carré\n");
    printf("%s\n",Rectangle->afficherRectangle(Rectangle));



#ifdef __WIN32__
        system("PAUSE");
#endif
        return 0;
}

