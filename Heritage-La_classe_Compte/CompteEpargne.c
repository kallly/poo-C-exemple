#include<stdlib.h>
#include<stdio.h>
#include <stdarg.h>

#include "CompteEpargne.h"

static void CompteEpargne_Init(CompteEpargne*);

static float get_tauxInteret(CompteEpargne *This);
static int set_tauxInteret(CompteEpargne *This,float tauxInteret);

static int calculInteret(CompteEpargne *This);

/******************************************************************************/
CompteEpargne* New_CompteEpargne(char *CIN,char *nom,char *prenom,char *tel,size_t nbarg,...)
{
    
    CompteEpargne *This = malloc(sizeof(CompteEpargne));
    if(!This) return NULL;
    CompteEpargne_Init(This);

    set_client((void*)This, New_Client(CIN,nom,prenom,tel));
    set_id((void*)This,1);

    if(nbarg>0){
        va_list ap;
        va_start(ap,nbarg);

        set_solde((void*)This,va_arg(ap,double));
		va_end(ap);
    }
    return This;
}

/******************************************************************************/
static void CompteEpargne_Init(CompteEpargne *This)
{
    This->toString=(void*)toString;
    This->crediter=(void*)Compte_crediter;
    This->debiter=(void*)Compte_debiter;

    This->get_client=(void*)get_client;
    This->get_id=(void*)get_id;
    This->get_solde=(void*)get_solde;
    This->set_client=(void*)set_client;

    This->calculInteret=calculInteret;
    This->get_tauxInteret=get_tauxInteret;
    This->set_tauxInteret=set_tauxInteret;
    This->tauxInteret=6.;

}

/******************************************************************************/
static float get_tauxInteret(CompteEpargne *This)
{
       return This->tauxInteret;
}

/******************************************************************************/
static int set_tauxInteret(CompteEpargne *This,float tauxInteret)
{
       This->tauxInteret = tauxInteret;
       return 1;
}


/******************************************************************************/
static int calculInteret(CompteEpargne *This)
{   
    set_solde((void*)This,This->get_solde(This) * (1+(This->tauxInteret/100.)));
    return  1;
}