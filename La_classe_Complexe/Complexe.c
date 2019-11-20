#include<stdlib.h>
#include<stdio.h>

#include "Complexe.h"

static void Complexe_Init(Complexe*);

static Complexe* plus(Complexe *This,Complexe *complexe2);
static Complexe* moins(Complexe *This,Complexe *complexe2);
static char* afficher(Complexe *This);

static float get_reelle(Complexe *This);
static int set_reelle(Complexe *This,float reelle);
static float get_imaginaire(Complexe *This);
static int set_imaginaire(Complexe *This,float imaginaire);

/******************************************************************************/
Complexe* New_Complexe(float reelle,float imaginaire)
{
    Complexe *This = malloc(sizeof(Complexe));
    if(!This) return NULL;
    Complexe_Init(This);
    This->set_reelle(This,reelle);
    This->set_imaginaire(This,imaginaire);
    return This;
}

/******************************************************************************/
static void Complexe_Init(Complexe *This)
{
    This->moins=moins;
    This->plus=plus;
    This->afficher=afficher;

    This->get_reelle=get_reelle;
    This->get_imaginaire=get_imaginaire;
    This->set_imaginaire=set_imaginaire;
    This->set_reelle=set_reelle;
    This->reelle=0;
    This->imaginaire=0;
}

/******************************************************************************/
static float get_reelle(Complexe *This)
{
       return This->reelle;
}

/******************************************************************************/
static int set_reelle(Complexe *This,float reelle)
{
       This->reelle = reelle;
       return 1;
}

/******************************************************************************/
static float get_imaginaire(Complexe *This)
{
       return This->imaginaire;
}

/******************************************************************************/
static int set_imaginaire(Complexe *This,float imaginaire)
{
       This->imaginaire = imaginaire;
       return 1;
}

/******************************************************************************/
static Complexe* plus(Complexe *This,Complexe *complexe2)
{
       complexe2->set_imaginaire(complexe2,This->get_imaginaire(This) + complexe2->get_imaginaire(complexe2));
       complexe2->set_reelle(complexe2,This->get_reelle(This) + complexe2->get_reelle(complexe2));
       return complexe2;
}

/******************************************************************************/
static Complexe* moins(Complexe *This,Complexe *complexe2)
{
       complexe2->set_imaginaire(complexe2,This->get_imaginaire(This) - complexe2->get_imaginaire(complexe2));
       complexe2->set_reelle(complexe2,This->get_reelle(This) - complexe2->get_reelle(complexe2));
       return complexe2;
}

/******************************************************************************/
static char* afficher(Complexe *This)
{
   size_t size = sizeof(char) * 20;
   char* string = (char*)malloc(size);
   
   snprintf(string, size, "%0.2f %c%0.2fi",This->get_reelle(This),(This->get_imaginaire(This)> 0)?'+': ' ',This->get_imaginaire(This));

   return string;
}