#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#include "Point.h"

#define POW(a)  (a)*(a)

static void Point_Init(Point*);
 

/******************************************************************************/
Point* New_Point(float abscisse,float ordonne)
{
       Point *This = malloc(sizeof(Point));
       if(!This) return NULL;
       Point_Init(This);
       This->set_abscisse(This,abscisse);
       This->set_ordonne(This,ordonne);
       return This;
}
/******************************************************************************/
 
static void Point_Init(Point *This)
{
       This->get_abscisse = get_abscisse;
       This->set_abscisse = set_abscisse;
       This->get_ordonne = get_ordonne;
       This->set_ordonne = set_ordonne;
       This->norme = norme;
       This->abscisse = 0;
       This->ordonne = 0;
}

/******************************************************************************/
static float get_abscisse(Point *This)
{
       return This->abscisse;
}

/******************************************************************************/
static int set_abscisse(Point *This,float abscisse)
{
       This->abscisse = abscisse;
       return 1;
}

/******************************************************************************/
static float get_ordonne(Point *This)
{
       return This->ordonne;
}

/******************************************************************************/
static int set_ordonne(Point *This,float ordonne)
{
       This->ordonne = ordonne;
       return 1;
}

/******************************************************************************/
static float norme(Point *This)
{
       return sqrt( POW((double)This->get_abscisse(This)) + POW((double)This->get_ordonne(This)) );
}