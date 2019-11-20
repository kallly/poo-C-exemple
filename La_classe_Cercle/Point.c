#include<stdlib.h>
#include<stdio.h>

#include "Point.h"

static void Point_Init(Point*);

static char* afficher( Point *This);

static int get_x(Point *This);
static int set_x(Point *This,int x);
static int get_y(Point *This);
static int set_y(Point *This,int y);

/******************************************************************************/
Point* New_Point(int x,int y)
{
    Point *This = malloc(sizeof(Point));
    if(!This) return NULL;
    Point_Init(This);
    This->set_x(This,x);
    This->set_y(This,y);
    return This;
}

/******************************************************************************/
static void Point_Init(Point *This)
{
    This->afficher=afficher;
    This->get_x=get_x;
    This->set_x=set_x;
    This->get_y=get_y;
    This->set_y=set_y;
    This->x=0;
    This->y=0;
}

/******************************************************************************/
static int get_x(Point *This)
{
       return This->x;
}

/******************************************************************************/
static int set_x(Point *This,int x)
{
       This->x = x;
       return 1;
}

/******************************************************************************/
static int get_y(Point *This)
{
       return This->y;
}

/******************************************************************************/
static int set_y(Point *This,int y)
{
       This->y = y;
       return 1;
}

/******************************************************************************/
static char* afficher( Point *This)
{
       size_t size = sizeof(char) * 20;
       char* string = (char*)malloc(size);
       
       snprintf(string, size, "POINT(%d,%d)",This->get_x(This),This->get_y(This));
       
       return string;
}