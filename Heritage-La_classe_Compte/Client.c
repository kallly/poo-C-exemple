#include<stdlib.h>
#include<stdio.h>
#include <string.h>

#include "Client.h"

static void Client_Init(Client*);

static char* get_CIN(Client *This);
static int set_CIN(Client *This,const char* CIN);
static char* get_nom(Client *This);
static int set_nom(Client *This,const char* nom);
static char* get_prenom(Client *This);
static int set_prenom(Client *This,const char* prenom);
static char* get_tel(Client *This);
static int set_tel(Client *This,const char* tel);


static char* afficher( Client *This);

/******************************************************************************/
Client* New_Client(const char *CIN,const char *nom,const char *prenom,const char *tel)
{
    Client *This = malloc(sizeof(Client));
    if(!This) return NULL;
    Client_Init(This);
    This->set_CIN(This,CIN);
    This->set_nom(This,nom);
    This->set_prenom(This,prenom);
    This->set_tel(This,tel);

    return This;
}

/******************************************************************************/
static void Client_Init(Client *This)
{
    This->afficher=afficher;
    This->get_CIN=get_CIN;
    This->get_nom=get_nom;
    This->get_prenom=get_prenom;
    This->get_tel=get_tel;
    This->set_CIN=set_CIN;
    This->set_nom=set_nom;
    This->set_prenom=set_prenom;
    This->set_tel=set_tel;
}

/******************************************************************************/
static char* get_CIN(Client *This)
{
       return This->CIN;
}

/******************************************************************************/
static int set_CIN(Client *This,const char* CIN)
{
       This->CIN = malloc(sizeof(CIN));
       strcpy(This->CIN,CIN);
       return 1;
}

/******************************************************************************/
static char* get_nom(Client *This)
{
       return This->nom;
}

/******************************************************************************/
static int set_nom(Client *This,const char* nom)
{
       This->nom = malloc(sizeof(nom));
       strcpy(This->nom,nom);
       return 1;
}

/******************************************************************************/
static char* get_prenom(Client *This)
{
       return This->prenom;
}

/******************************************************************************/
static int set_prenom(Client *This,const char* prenom)
{      
       This->prenom = malloc(sizeof(prenom));
       strcpy(This->prenom,prenom);
       return 1;
}

/******************************************************************************/
static char* get_tel(Client *This)
{
       return This->tel;
}

/******************************************************************************/
static int set_tel(Client *This,const char* tel)
{
       This->tel = malloc(sizeof(tel));
       strcpy(This->tel,tel);
       return 1;
}

/******************************************************************************/
static char* afficher( Client *This)
{
       size_t size = sizeof(This->get_CIN(This)) 
                        + sizeof(This->get_nom(This)) 
                        + sizeof(This->get_prenom(This)) 
                        + sizeof(This->get_tel(This)) 
                        + sizeof(char)*50;

       char* string = (char*)malloc(size);
       
       snprintf(string, size, "CIN: %s\nNOM: %s\nPRENOM: %s\nTEL: %s\n", 
                This->get_CIN(This),
                This->get_nom(This),
                This->get_prenom(This),
                This->get_tel(This)
        );
       
       return string;
}