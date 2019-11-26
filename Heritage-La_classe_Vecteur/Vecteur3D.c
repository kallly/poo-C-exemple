#include<stdlib.h>
#include<stdio.h>
#include <math.h>

#include "Vecteur3D.h"

#define E2(x) (x*x)

static void Vecteur3D_Init(Vecteur3D*);

static float get_z(Vecteur3D *This);
static int set_z(Vecteur3D *This,float z);

static int equals(Vecteur3D *This,Vecteur3D *vecteur);
static float norme(Vecteur3D *This);
static char* toString( Vecteur3D *This);

/******************************************************************************/
Vecteur3D* New_Vecteur3D(float x,float y,float z)
{
    Vecteur3D *This = malloc(sizeof(Vecteur3D));
    if(!This) return NULL;
    Vecteur3D_Init(This);
    
    This->set_x(This,x);
    This->set_y(This,y);
    This->set_z(This,z);
    return This;
}

/******************************************************************************/
static void Vecteur3D_Init(Vecteur3D *This)
{
    This->norme=norme;
    This->equals=equals;
    This->toString=toString;

    This->get_id=(void*)get_id;
    This->get_x=(void*)get_x;
    This->get_y=(void*)get_y;
    This->get_z=get_z;
    This->set_id=(void*)set_id;
    This->set_x=(void*)set_x;
    This->set_y=(void*)set_y;
    This->set_z=set_z;
    This->id=1;
    This->x=0;
    This->y=0;
}

/******************************************************************************/
static float get_z(Vecteur3D *This)
{
       return This->z;
}

/******************************************************************************/
static int set_z(Vecteur3D *This,float z)
{
       This->z = z;
       return 1;
}

/******************************************************************************/
static int equals(Vecteur3D *This,Vecteur3D *vecteur)
{
       return (This->get_x(This) == vecteur->get_x(vecteur) && This->get_y(This) == vecteur->get_y(vecteur) && This->get_z(This) == vecteur->get_z(vecteur));
}

/******************************************************************************/
static float norme(Vecteur3D *This)
{
       return sqrtf( E2(This->get_x(This)) + E2(This->get_y(This)) + + E2(This->get_z(This)) );
}

/******************************************************************************/
static char* toString( Vecteur3D *This)
{
       size_t size = sizeof(char)*20;
       char* string = (char*)malloc(size);
       
       snprintf(string, size, "X=%0.2f Y=%0.2f Z=%0.2f",This->get_x(This),This->get_y(This),This->get_z(This));
       
       return string;
}