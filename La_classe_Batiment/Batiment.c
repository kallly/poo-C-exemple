#include<stdlib.h>
#include<stdio.h>
#include <stdarg.h>

#include "Batiment.h"

static void Batiment_Init(Batiment*);

/******************************************************************************/
Batiment* New_Batiment(size_t nbarg,...)
{
    va_list ap;
    va_start(ap,nbarg);

    Batiment *This = malloc(sizeof(Batiment));
    if(!This) return NULL;
    Batiment_Init(This);
    
    if(nbarg>0)This->set_adresse(This, va_arg(ap,char*) );

    va_end(ap);
    return This;
}

/******************************************************************************/
static void Batiment_Init(Batiment *This)
{
    This->to_string=to_string;

    This->get_adresse=get_adresse;
    This->set_adresse=set_adresse;

    This->set_adresse(This, " " );

}

/******************************************************************************/
char* get_adresse(Batiment *This)
{
       return This->adresse;
}

/******************************************************************************/
int set_adresse(Batiment *This,char* adresse)
{
    This->adresse = malloc(sizeof(adresse));
    This->adresse = adresse;
    return 1;
}
/******************************************************************************/
static char* to_string( Batiment *This)
{
       size_t size = sizeof(This->get_adresse(This)) + sizeof(char) * 20;
       char* string = (char*)malloc(size);
       
       snprintf(string, size, "Adresse :%s", This->get_adresse(This));    
       return string;
}