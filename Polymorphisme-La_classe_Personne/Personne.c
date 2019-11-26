#include<stdlib.h>
#include<stdio.h>
#include <string.h>

#include "Personne.h"

static void Personne_Init(Personne*);

/******************************************************************************/
Personne* New_Personne(char *nom,char *prenom,date dateNaissance)
{
    Personne *This = malloc(sizeof(Personne));
    if(!This) return NULL;
    Personne_Init(This);
    This->set_dateNaissance(This,dateNaissance);
    This->set_nom(This,nom);
    This->set_prenom(This,prenom);
    
    return This;
}

/******************************************************************************/
static void Personne_Init(Personne *This)
{
    This->get_dateNaissance=get_dateNaissance;
    This->get_nom=get_nom;
    This->get_prenom=get_prenom;
    This->set_dateNaissance=set_dateNaissance;
    This->set_nom=set_nom;
    This->set_prenom=set_prenom;
    This->afficher=Personne_afficher;

    This->nom=NULL;
    This->prenom=NULL;
}

/******************************************************************************/
char* get_nom(Personne *This)
{
       return This->nom;
}

/******************************************************************************/
int set_nom(Personne *This,char* nom)
{
    if(This->nom!=NULL) free(This->nom);
    This->nom = malloc(sizeof(char)*(strlen(nom)+1));
    strcpy(This->nom,nom);
    return 1;
}

/******************************************************************************/
char* get_prenom(Personne *This)
{
       return This->prenom;
}

/******************************************************************************/
int set_prenom(Personne *This,char* prenom)
{
       if(This->prenom!=NULL) free(This->prenom);
       This->prenom = malloc(sizeof(char)*(strlen(prenom)+1));
       strcpy(This->prenom,prenom);
       return 1;
}

/******************************************************************************/
date get_dateNaissance(Personne *This)
{
       return This->dateNaissance;
}

/******************************************************************************/
int set_dateNaissance(Personne *This,date dateNaissance)
{
       This->dateNaissance.j = dateNaissance.j;
       This->dateNaissance.m = dateNaissance.m;
       This->dateNaissance.a = dateNaissance.a;
       return 1;
}

/******************************************************************************/
char* Personne_afficher( Personne *This)
{
       size_t size = sizeof(This->get_nom(This)) 
                    + sizeof(This->get_prenom(This)) 
                    + sizeof(char)*100;
                    
       char* string = (char*)malloc(size);
       
        date dateNaissance = This->get_dateNaissance(This);

       snprintf(string, size, "Nom: %s\nPrenom: %s\nDate de naissance %d/%d/%d", 
                This->get_nom(This),
                This->get_prenom(This),
                dateNaissance.j,dateNaissance.m,dateNaissance.a
                );
       
       return string;
}