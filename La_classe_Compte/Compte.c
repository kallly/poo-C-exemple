#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "Compte.h"

#define ABS(x) (x>0?x:-x)

static void Compte_Init(Compte*);

static float get_solde(Compte *This);
static int set_solde(Compte *This,float solde);
static int get_id(Compte *This);
static int set_id(Compte *This,int id);
static Client* get_client(Compte *This);
static int set_client(Compte *This,Client *client);

static char* afficher( Compte *This);
static int crediter(Compte *This,float val,size_t nbarg,...);
static int debiter(Compte *This,float val,size_t nbarg,...);

/******************************************************************************/
Compte* New_Compte(char *CIN,char *nom,char *prenom,char *tel)
{
    Compte *This = malloc(sizeof(Compte));
    if(!This) return NULL;
    Compte_Init(This);

    set_client(This, New_Client(CIN,nom,prenom,tel));
    set_id(This,1);
    
    return This;
}

/******************************************************************************/
static void Compte_Init(Compte *This)
{
    This->afficher=afficher;
    This->crediter=crediter;
    This->debiter=debiter;

    This->get_client=get_client;
    This->get_id=get_id;
    This->get_solde=get_solde;
    This->set_client=set_client;
}

/******************************************************************************/
static float get_solde(Compte *This)
{
       return This->solde;
}

/******************************************************************************/
static int set_solde(Compte *This,float solde)
{
       This->solde = solde;
       return 1;
}

/******************************************************************************/
static int get_id(Compte *This)
{
       return This->id;
}

/******************************************************************************/
static int set_id(Compte *This,int id)
{
       This->id = id;
       return 1;
}

/******************************************************************************/
static Client* get_client(Compte *This)
{
       return This->client;
}

/******************************************************************************/
static int set_client(Compte *This,Client *client)
{
       This->client = client;
       return 1;
}

/******************************************************************************/
static int crediter(Compte *This,float val,size_t nbarg,...)
{
    va_list ap;
    va_start(ap,nbarg);

    set_solde(This, This->get_solde(This) + ABS(val) );

    if(nbarg>0){
        Compte *compte2=va_arg(ap,Compte*);
        set_solde(compte2, compte2->get_solde(compte2) - ABS(val) );
    }

    va_end(ap);
    return 1;
}

/******************************************************************************/
static int debiter(Compte *This,float val,size_t nbarg,...)
{
    va_list ap;
    va_start(ap,nbarg);

    set_solde(This, This->get_solde(This) - ABS(val) );

    if(nbarg>0){
        Compte *compte2=va_arg(ap,Compte*);
        set_solde(compte2, compte2->get_solde(compte2) + ABS(val) );
    }

    va_end(ap);
    return 1;
}

/******************************************************************************/
static char* afficher( Compte *This)
{
       size_t size = ( strlen(This->get_client(This)->afficher(This->get_client(This))) + 1 + 150)* sizeof(char);
       char* string = (char*)malloc(size);
       
       snprintf(string, size, "Numéro de Compte: %d\nSolde de compte: %0.2f\nPropriétaire du compte:\n%s",
                This->get_id(This),
                This->get_solde(This),
                This->get_client(This)->afficher(This->get_client(This))
         );
       
       return string;
}