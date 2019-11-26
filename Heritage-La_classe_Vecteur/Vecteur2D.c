#include<stdlib.h>
#include<stdio.h>
#include <math.h>

#define E2(x) (x*x)

#include "Vecteur2D.h"

static void Vecteur2D_Init(Vecteur2D*);

static float norme(Vecteur2D *This);
static int equals(Vecteur2D *This,Vecteur2D *vecteur);
static char* toString( Vecteur2D *This);

/******************************************************************************/
Vecteur2D* New_Vecteur2D(float x,float y)
{
    Vecteur2D *This = malloc(sizeof(Vecteur2D));
    if(!This) return NULL;
    Vecteur2D_Init(This);

    This->set_x(This,x);
    This->set_y(This,y);
    return This;
}

/******************************************************************************/
static void Vecteur2D_Init(Vecteur2D *This)
{
    This->norme=norme;
    This->equals=equals;
    This->toString=toString;

    This->get_id=get_id;
    This->get_x=get_x;
    This->get_y=get_y;
    This->set_id=set_id;
    This->set_x=set_x;
    This->set_y=set_y;
    This->id=1;
    This->x=0;
    This->y=0;
}

/******************************************************************************/
int get_id(Vecteur2D *This)
{
       return This->id;
}

/******************************************************************************/
int set_id(Vecteur2D *This,int id)
{
       This->id = id;
       return 1;
}

/******************************************************************************/
float get_x(Vecteur2D *This)
{
       return This->x;
}

/******************************************************************************/
int set_x(Vecteur2D *This,float x)
{
       This->x = x;
       return 1;
}

/******************************************************************************/
float get_y(Vecteur2D *This)
{
       return This->y;
}

/******************************************************************************/
int set_y(Vecteur2D *This,float y)
{
       This->y = y;
       return 1;
}

/******************************************************************************/
static int equals(Vecteur2D *This,Vecteur2D *vecteur)
{
       return (This->get_x(This) == vecteur->get_x(vecteur) && This->get_y(This) == vecteur->get_y(vecteur));
}

/******************************************************************************/
static float norme(Vecteur2D *This)
{
       return sqrtf( E2(This->get_x(This)) + E2(This->get_y(This)) );
}

/******************************************************************************/
static char* toString( Vecteur2D *This)
{
       size_t size = sizeof(char)*20;
       char* string = (char*)malloc(size);
       
       snprintf(string, size, "X=%0.2f Y=%0.2f",This->get_x(This),This->get_y(This));
       
       return string;
}