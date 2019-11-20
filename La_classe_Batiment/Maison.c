#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "Maison.h"

static void Maison_Init(Maison*);

static unsigned int get_NbPieces(Maison *This);
static int set_NbPieces(Maison *This,unsigned int NbPieces);

static char* Maison_to_string( Maison *This);

/******************************************************************************/
Maison* New_Maison(size_t nbarg,...)
{
     va_list ap;
    va_start(ap,nbarg);

    Maison *This = malloc(sizeof(Maison));
    if(!This) return NULL;
    Maison_Init(This);
    
    if(nbarg>0)This->set_adresse(This, va_arg(ap,char*) );
    if(nbarg>1)This->set_NbPieces(This, va_arg(ap,unsigned int) );

    va_end(ap);

    return This;
}

/******************************************************************************/
static void Maison_Init(Maison *This)
{
    This->to_string=Maison_to_string;

    This->get_NbPieces=get_NbPieces;
    This->set_NbPieces=set_NbPieces;

    This->get_adresse=(void*)get_adresse;
    This->set_adresse=(void*)set_adresse;

    
    This->set_adresse(This, " " );
    This->NbPieces=0;
}

/******************************************************************************/
static unsigned int get_NbPieces(Maison *This)
{
       return This->NbPieces;
}

/******************************************************************************/
static int set_NbPieces(Maison *This,unsigned int NbPieces)
{
       This->NbPieces = NbPieces;
       return 1;
}

/******************************************************************************/
static char* Maison_to_string( Maison *This)
{
       size_t size = sizeof(This->get_adresse(This)) + sizeof(char) * 70;
       char* string = (char*)malloc(size);
       
       snprintf(string, size, "Adresse :%s\t Nombre de pieces :%u", This->get_adresse(This), This->NbPieces);    
       return string;
}