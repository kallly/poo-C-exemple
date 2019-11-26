#include<stdlib.h>
#include<stdio.h>
#include <string.h>

#include "Chef.h"

static void Chef_Init(Chef*);

static char* afficher( Chef *This);

/******************************************************************************/
Chef* New_Chef(char *nom,char *prenom,char *service,date dateNaissance,float salaire)
{
    Chef *This = malloc(sizeof(Chef));
    if(!This) return NULL;
    Chef_Init(This);

    This->set_nom(This,nom);
    This->set_prenom(This,prenom);
    This->set_dateNaissance(This,dateNaissance);
    
    This->salaire=salaire;
    This->set_service(This,service);
    
    return This;
}

/******************************************************************************/
static void Chef_Init(Chef *This)
{
    This->afficher=afficher;

    This->get_dateNaissance=(void*)get_dateNaissance;
    This->get_nom=(void*)get_nom;
    This->get_prenom=(void*)get_prenom;
    This->set_dateNaissance=(void*)set_dateNaissance;
    This->set_nom=(void*)set_nom;
    This->set_prenom=(void*)set_prenom;

    This->get_salaire=(void*)get_salaire;
    This->set_salaire=(void*)set_salaire;

    This->get_service=get_service;
    This->set_service=set_service;
    
}

/******************************************************************************/
char* get_service(Chef *This)
{
       return This->service;
}

/******************************************************************************/
int set_service(Chef *This,char* service)
{
    if(This->service!=NULL) free(This->service);
    This->service = malloc(sizeof(char)*(strlen(service)+1));
    strcpy(This->service,service);
    return 1;
}


/******************************************************************************/
static char* afficher( Chef *This)
{
       size_t size = (strlen(This->get_nom(This)) + 1
                    + strlen(This->get_prenom(This)) + 1
                    + strlen(This->service) + 1
                    + 200
                    * sizeof(char));
       char* string = (char*)malloc(size);
       
        date dateNaissance = This->get_dateNaissance(This);

       snprintf(string, size, "Nom: %s\nPrenom: %s\nDate de naissance %d/%d/%d\nSalaire: %0.2f\nService: %s", 
                This->get_nom(This),
                This->get_prenom(This),
                dateNaissance.j,dateNaissance.m,dateNaissance.a,
                This->get_salaire(This),
                This->get_service(This)
                );
       
       return string;
}