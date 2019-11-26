#include<stdlib.h>
#include<stdio.h>
#include <math.h>

#include "Cercle.h"

#define PI 3.14159265358979323846
#define E2(a) a*a

static void Cercle_Init(Cercle*);

static char* Cercle_afficher(Cercle *This);
static int appartient(Cercle *This,Point *p);
static float getSurface(Cercle *This);
static float getPerimetre(Cercle *This);

static float get_r(Cercle *This);
static int set_r(Cercle *This,float centre);
static Point* get_centre(Cercle *This);
static int set_centre(Cercle *This,Point* centre);

/******************************************************************************/
Cercle* New_Cercle(int x,int y,float r)
{
    Cercle *This = malloc(sizeof(Cercle));
    if(!This) return NULL;
    Cercle_Init(This);
    This->set_r(This,r);
    This->set_centre(This,New_Point(x,y));
    return This;
}

/******************************************************************************/
static void Cercle_Init(Cercle *This)
{
    This->afficher=Cercle_afficher;
    This->appartient=appartient;
    This->getSurface=getSurface;
    This->getPerimetre=getPerimetre;

    This->get_centre=get_centre;
    This->set_centre=set_centre;
    This->get_r=get_r;
    This->set_r=set_r;
    This->centre=New_Point(0,0);
    This->r=0;
}

/******************************************************************************/
static Point* get_centre(Cercle *This)
{
       return This->centre;
}

/******************************************************************************/
static int set_centre(Cercle *This,Point* centre)
{
       This->centre = centre;
       return 1;
}

/******************************************************************************/
static float get_r(Cercle *This)
{
       return This->r;
}

/******************************************************************************/
static int set_r(Cercle *This,float r)
{
       This->r = r;
       return 1;
}

/******************************************************************************/
static float getPerimetre(Cercle *This)
{
       
       return 2 * PI * This->r;
}

/******************************************************************************/
static float getSurface(Cercle *This)
{
       
       return PI * E2(This->r);
}

/******************************************************************************/
static int appartient(Cercle *This,Point *p)
{
       
       return ( 
                ( E2( p->get_x(p) - This->get_centre(This)->get_x(This->get_centre(This)) ) + 
                    E2( p->get_y(p) - This->get_centre(This)->get_y(This->get_centre(This)) )
                ) == This->get_r(This) 
            );
}
/******************************************************************************/
static char* Cercle_afficher( Cercle *This)
{
       size_t size = sizeof(char) * 20;
       char* string = (char*)malloc(size);
       
       snprintf(string, size, "CERCLE(%d,%d,%0.2f)", This->get_centre(This)->get_x(This->get_centre(This))
                                                        ,This->get_centre(This)->get_y(This->get_centre(This))
                                                        ,This->get_r(This) );
       
       return string;
}