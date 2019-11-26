#include<stdlib.h>
#include<stdio.h>
#include <string.h>

#include "Directeur.h"

static void Directeur_Init(Directeur*);

static char* get_societe(Directeur *This);
static int set_societe(Directeur *This,char* societe);

static char* afficher( Directeur *This);
/******************************************************************************/
Directeur* New_Directeur(char *nom,char *prenom,char *service, char *societe,date dateNaissance,float salaire)
{
    Directeur *This = malloc(sizeof(Directeur));
    if(!This) return NULL;
    Directeur_Init(This);


    This->set_nom(This,nom);
    This->set_prenom(This,prenom);
    This->set_dateNaissance(This,dateNaissance);
               
    This->set_salaire(This,salaire);

    This->set_service(This,service);
    
    This->set_societe(This,societe);
    

    
    return This;
}

/******************************************************************************/
static void Directeur_Init(Directeur *This)
{
    This->get_dateNaissance=(void*)get_dateNaissance;
    This->get_nom=(void*)get_nom;
    This->get_prenom=(void*)get_prenom;
    This->set_dateNaissance=(void*)set_dateNaissance;
    This->set_nom=(void*)set_nom;
    This->set_prenom=(void*)set_prenom;

    This->get_salaire=(void*)get_salaire;
    This->set_salaire=(void*)set_salaire;

    This->get_service=(void*)get_service;
    This->set_service=(void*)set_service;

    This->get_societe=get_societe;
    This->set_societe=set_societe;

    This->afficher=afficher;
}

/******************************************************************************/
static char* get_societe(Directeur *This)
{
       return This->societe;
}

/******************************************************************************/
static int set_societe(Directeur *This,char* societe)
{
       if(This->societe!=NULL) free(This->societe);
        This->societe = malloc(sizeof(char)*(strlen(societe)+1));
        strcpy(This->societe,societe);
       return 1;
}


/******************************************************************************/
static char* afficher( Directeur *This)
{
       size_t size =( strlen(This->get_nom(This)) + 1
                    + strlen(This->get_prenom(This)) + 1
                    + strlen(This->get_service(This)) + 1
                    + strlen(This->get_societe(This)) + 1
                    + 150
                     )* sizeof(char);
       char* string = (char*)malloc(size);
       
        date dateNaissance = This->get_dateNaissance(This);

       snprintf(string, size, "Nom: %s\nPrenom: %s\nDate de naissance %d/%d/%d\nSalaire: %0.2f\nService: %s\nSociete: %s", 
                This->get_nom(This),
                This->get_prenom(This),
                dateNaissance.j,dateNaissance.m,dateNaissance.a,
                This->get_salaire(This),
                This->get_service(This),
                This->get_societe(This)
                );
       
       return string;
}