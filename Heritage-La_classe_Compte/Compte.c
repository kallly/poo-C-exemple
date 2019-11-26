#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "Compte.h"

#define ABS(x) (x>0?x:-x)

static void Compte_Init(Compte*);


/******************************************************************************/
Compte* New_Compte(char *CIN,char *nom,char *prenom,char *tel,size_t nbarg,...)
{
    Compte *This = malloc(sizeof(Compte));
    if(!This) return NULL;
    Compte_Init(This);

    set_client(This, New_Client(CIN,nom,prenom,tel));
    set_id(This,1);

    if(nbarg>0){
        va_list ap;
        va_start(ap,nbarg);

        set_solde(This,va_arg(ap,double));
		va_end(ap);
    }
    
    return This;
}

/******************************************************************************/
static void Compte_Init(Compte *This)
{
    This->toString=toString;
    This->crediter=Compte_crediter;
    This->debiter=Compte_debiter;

    This->get_client=get_client;
    This->get_id=get_id;
    This->get_solde=get_solde;
    This->set_client=set_client;
}

/******************************************************************************/
float get_solde(Compte *This)
{
       return This->solde;
}

/******************************************************************************/
int set_solde(Compte *This,float solde)
{
       This->solde = solde;
       return 1;
}

/******************************************************************************/
int get_id(Compte *This)
{
       return This->id;
}

/******************************************************************************/
int set_id(Compte *This,int id)
{
       This->id = id;
       return 1;
}

/******************************************************************************/
Client* get_client(Compte *This)
{
       return This->client;
}

/******************************************************************************/
int set_client(Compte *This,Client *client)
{
       This->client = client;
       return 1;
}

/******************************************************************************/
int Compte_crediter(Compte *This,float val,int nbarg,...)
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
int Compte_debiter(Compte *This,float val,int nbarg,...)
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
char* toString( Compte *This)
{
       size_t size = (strlen(This->get_client(This)->afficher(This->get_client(This))) + 1 + 150 )* sizeof(char);
       char* string = (char*)malloc(size);
       
       snprintf(string, size, "Numéro de Compte: %d\nSolde de compte: %0.2f\nPropriétaire du compte:\n%s",
                This->get_id(This),
                This->get_solde(This),
                This->get_client(This)->afficher(This->get_client(This))
         );
       
       return string;
}