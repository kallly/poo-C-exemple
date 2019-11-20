#include<stdlib.h>
#include<stdio.h>

#include "Rectangle.h"

static void Rectangle_Init(Rectangle*);

/******************************************************************************/
Rectangle* New_Rectangle(float longeur,float largeur)
{
       Rectangle *This = malloc(sizeof(Rectangle));
       if(!This) return NULL;
       Rectangle_Init(This);
       set_longueur(This,longeur);
       set_largeur(This,largeur);
       return This;
}

/******************************************************************************/
static void Rectangle_Init(Rectangle *This)
{
       This->perimetre=perimetre;
       This->aire=aire;
       This->isCarre=isCarre;
       This->afficherRectangle=afficherRectangle;

       This->get_longueur=get_longueur;
       This->get_largeur=get_largeur;
       This->set_longueur=set_longueur;
       This->set_largeur=set_largeur;
       This->longueur=0;
       This->largeur=0;
}

/******************************************************************************/
static float get_longueur(Rectangle *This)
{
          return This->longueur;
}

/******************************************************************************/
static int set_longueur(Rectangle *This,float longueur)
{
       This->longueur = longueur;
       return 1;
}

/******************************************************************************/
static float get_largeur(Rectangle *This)
{
          return This->largeur;
}

/******************************************************************************/
static int set_largeur(Rectangle *This,float largeur)
{
       This->largeur = largeur;
       return 1;
}

/******************************************************************************/
static float perimetre(Rectangle *This)
{
       return 2. *This->get_longueur(This) + 2. * This->get_largeur(This);
}

/******************************************************************************/
static float aire(Rectangle *This)
{
       return This->get_longueur(This) * This->get_largeur(This);
}

/******************************************************************************/
static int isCarre(Rectangle *This)
{
       return This->get_longueur(This) == This->get_largeur(This);
}

/******************************************************************************/
static char* afficherRectangle(Rectangle *This)
{
       
       size_t size = sizeof(char) * 200;
       char* string = (char*)malloc(size);  
       
       snprintf(string, size, "Longueur : %0.2f- Largeur : %0.2f- Périmétre : %0.2f- Aire : %0.2f- %s",
              This->get_longueur(This),This->get_largeur(This),
              This->perimetre(This),This->aire(This),
              This->isCarre?"Il s'agit d'un carré" : "Il ne s'agit pas d'un carré"
              );
       
       return string;
}