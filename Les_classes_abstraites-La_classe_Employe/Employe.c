#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Employe.h"

static void Employe_Init(Employe*);



/******************************************************************************/
Employe* New_Employe(char *matricule,char *nom,char *prenom,date dateNaissance)
{
    Employe *This = malloc(sizeof(Employe));
    if(!This) return NULL;
    Employe_Init(This);

    This->set_matricule(This,matricule);
    This->set_nom(This,nom);
    This->set_prenom(This,prenom);
    This->set_dateNaissance(This,dateNaissance);
    
    return This;
}

/******************************************************************************/
static void Employe_Init(Employe *This)
{
       This->get_dateNaissance=get_dateNaissance;
       This->get_matricule=get_matricule;
       This->get_nom=get_nom;
       This->get_prenom=get_prenom;
       This->get_salaire=get_salaire;
       This->set_dateNaissance=set_dateNaissance;
       This->set_matricule=set_matricule;
       This->set_nom=set_nom;
       This->set_prenom=set_prenom;
       This->set_salaire=set_salaire;

       This->matricule=NULL;
       This->nom=NULL;
       This->prenom=NULL;
}

/******************************************************************************/
char* get_matricule(Employe *This)
{
       return This->matricule;
}

/******************************************************************************/
int set_matricule(Employe *This,char* matricule)
{
       if(This->matricule!=NULL) free(This->matricule);
       This->matricule = malloc(sizeof(char)*(strlen(matricule)+1));
       strcpy(This->matricule,matricule);
       return 1;
}

/******************************************************************************/
char* get_nom(Employe *This)
{
          return This->nom;
}

/******************************************************************************/
int set_nom(Employe *This,char* nom)
{
       if(This->nom!=NULL) free(This->nom);
       This->nom = malloc(sizeof(char)*(strlen(nom)+1));
       strcpy(This->nom,nom);
       return 1;
}

/******************************************************************************/
char* get_prenom(Employe *This)
{
          return This->prenom;
}

/******************************************************************************/
int set_prenom(Employe *This,char* prenom)
{
       if(This->prenom!=NULL) free(This->prenom);
       This->prenom = malloc(sizeof(char)*(strlen(prenom)+1));
       strcpy(This->prenom,prenom);
       return 1;
}

/******************************************************************************/
date get_dateNaissance(Employe *This)
{
          return This->dateNaissance;
}

/******************************************************************************/
int set_dateNaissance(Employe *This,date dateNaissance)
{
       This->dateNaissance = dateNaissance;
       return 1;
}

/******************************************************************************/
float get_salaire(Employe *This)
{
          return This->salaire;
}

/******************************************************************************/
int set_salaire(Employe *This,float salaire)
{
       This->salaire = salaire;
       return 1;
}