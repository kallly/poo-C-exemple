#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Employe.h"

static void Employe_Init(Employe*);

static char* afficher( Employe *This);

/******************************************************************************/
Employe* New_Employe(char *nom,char *prenom,date dateNaissance,float salaire)
{
    Employe *This = malloc(sizeof(Employe));
    if(!This) return NULL;
    Employe_Init(This);
    This->set_dateNaissance(This,dateNaissance); 
    This->set_nom(This,nom);
    This->set_prenom(This,prenom);
   
    This->set_salaire(This,salaire);

    return This;
}

/******************************************************************************/
static void Employe_Init(Employe *This)
{
    This->get_dateNaissance=(void*)get_dateNaissance;
    This->get_nom=(void*)get_nom;
    This->get_prenom=(void*)get_prenom;
    This->set_dateNaissance=(void*)set_dateNaissance;
    This->set_nom=(void*)set_nom;
    This->set_prenom=(void*)set_prenom;

    This->get_salaire=get_salaire;
    This->set_salaire=set_salaire;

    This->afficher=afficher;
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

/******************************************************************************/
static char* afficher( Employe *This)
{
       size_t size = (  strlen(This->get_nom(This)) + 1
                    +   strlen(This->get_prenom(This)) + 1
                    + 150
                    )* sizeof(char);
       char* string = (char*)malloc(size);
       
       date dateNaissance = This->get_dateNaissance(This);

       snprintf(string, size, "Nom: %s\nPrenom: %s\nDate de naissance %d/%d/%d\nSalaire: %0.2f", 
                This->get_nom(This),
                This->get_prenom(This),
                dateNaissance.j,dateNaissance.m,dateNaissance.a,
                This->get_salaire(This)
                );
       
       return string;
}