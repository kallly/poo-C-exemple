#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Voiture.h"

static void Voiture_Init(Voiture*);

static char* demarrer( Voiture *This);
static char* accelerer( Voiture *This);

/******************************************************************************/
Voiture* New_Voiture(const char *matricule,int anneeModel,float prix)
{
    Voiture *This = malloc(sizeof(Voiture));
    if(!This) return NULL;
    Voiture_Init(This);
    This->set_matricule(This,matricule);
    This->set_anneModel(This,anneeModel);
    This->set_prix(This,prix);
    
    return This;
}

/******************************************************************************/
static void Voiture_Init(Voiture *This)
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
static char* demarrer( Voiture *This)
{

    char* src="Voiture demarrer";
    
    char* string = (char*)malloc(sizeof(char)*(strlen(src)+1));
    strcpy(string,src);

    return string;
}

/******************************************************************************/
static char* accelerer( Voiture *This)
{
    char* src="Voiture accelerer";
    char* string = (char*)malloc(sizeof(char)*(strlen(src)+1));
    
    strcpy(string,src);
       
    return string;
}