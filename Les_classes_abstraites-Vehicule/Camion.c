#include<stdlib.h>
#include<stdio.h>
#include <string.h>

#include "Camion.h"

static void Camion_Init(Camion*);

static char* demarrer( Camion *This);
static char* accelerer( Camion *This);

/******************************************************************************/
Camion* New_Camion(const char *matricule,int anneeModel,float prix)
{
    Camion *This = malloc(sizeof(Camion));
    if(!This) return NULL;
    Camion_Init(This);
    This->set_matricule(This,matricule);
    This->set_anneModel(This,anneeModel);
    This->set_prix(This,prix);

    return This;
}

/******************************************************************************/
static void Camion_Init(Camion *This)
{
    This->toString=(void*)toString;
    This->demarrer=demarrer;
    This->accelerer=accelerer;

    This->get_matricule=(void*)get_matricule;
    This->get_anneModel=(void*)get_anneeModel;
    This->get_prix=(void*)get_prix;
    This->set_matricule=(void*)set_matricule;
    This->set_anneModel=(void*)set_anneeModel;
    This->set_prix=(void*)set_prix;
}

/******************************************************************************/
static char* demarrer( Camion *This)
{

    char* src="Camion demarrer";
    char* string = (char*)malloc(sizeof(src));
    
    strcpy(string,src);

    return string;
}

/******************************************************************************/
static char* accelerer( Camion *This)
{
    char* src="Camion accelerer";
    char* string = (char*)malloc(sizeof(src));
    
    strcpy(string,src);
       
    return string;
}