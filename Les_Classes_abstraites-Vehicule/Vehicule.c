#include<stdlib.h>
#include<stdio.h>
#include <string.h>

#include "Vehicule.h"

static void Vehicule_Init(Vehicule*);

/******************************************************************************/
Vehicule* New_Vehicule()
{
    Vehicule *This = malloc(sizeof(Vehicule));
    if(!This) return NULL;
    Vehicule_Init(This);
    
    return This;
}

/******************************************************************************/
static void Vehicule_Init(Vehicule *This)
{
    This->toString=toString;

    This->get_matricule=get_matricule;
    This->get_anneModel=get_anneeModel;
    This->get_prix=get_prix;
    This->set_matricule=set_matricule;
    This->set_matricule=set_matricule;
    This->set_prix=set_prix;
}

/******************************************************************************/
const char* get_matricule(Vehicule *This)
{
       return This->matricule;
}

/******************************************************************************/
int set_matricule(Vehicule *This,const char* matricule)
{
       This->matricule = malloc(sizeof(matricule));
       strcpy(This->matricule,matricule);
       return 1;
}

/******************************************************************************/
int get_anneeModel(Vehicule *This)
{
       return This->anneeModel;
}

/******************************************************************************/
int set_anneeModel(Vehicule *This,int anneeModel)
{
       This->anneeModel = anneeModel;
       return 1;
}

/******************************************************************************/
float get_prix(Vehicule *This)
{
       return This->prix;
}

/******************************************************************************/
int set_prix(Vehicule *This,float prix)
{
       This->prix = prix;
       return 1;
}

/******************************************************************************/
char* toString( Vehicule *This)
{
       size_t size = sizeof(This->get_matricule(This)) + sizeof(char)*100;
       char* string = (char*)malloc(size);
       
       snprintf(string, size, "Matricule: %s\nAnnee model: %d\nPrix: %0.2f",
                This->get_matricule(This),
                This->get_anneModel(This),
                This->get_prix(This)
       );
       
       return string;
}