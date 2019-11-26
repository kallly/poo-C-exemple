#include<stdlib.h>
#include<stdio.h>
#include <stdarg.h>

#include "ComptePayant.h"

#define ABS(x) (x>0?x:-x)

static void ComptePayant_Init(ComptePayant*);

static int crediter(ComptePayant *This,float val,int nbarg,...);
static int debiter(ComptePayant *This,float val,int nbarg,...);

/******************************************************************************/
ComptePayant* New_ComptePayant(const char *CIN,const char *nom,const char *prenom,const char *tel,size_t nbarg,...)
{
    ComptePayant *This = malloc(sizeof(ComptePayant));
    if(!This) return NULL;
    ComptePayant_Init(This);

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
static void ComptePayant_Init(ComptePayant *This)
{
    This->toString=(void*)toString;
    This->crediter=crediter;
    This->debiter=debiter;

    This->get_client=(void*)get_client;
    This->get_id=(void*)get_id;
    This->get_solde=(void*)get_solde;
    This->set_client=(void*)set_client;
}


/******************************************************************************/
static int crediter(ComptePayant *This,float val,int nbarg,...)
{
    va_list ap;
    va_start(ap,nbarg);

    set_solde((void*)This, This->get_solde(This) + ABS(val) - 5.);

    if(nbarg>0){
        ComptePayant *compte2=va_arg(ap,ComptePayant*);
        set_solde((void*)compte2, compte2->get_solde(compte2) - ABS(val) );
    }

    va_end(ap);
    return 1;
}

/******************************************************************************/
static int debiter(ComptePayant *This,float val,int nbarg,...)
{
    va_list ap;
    va_start(ap,nbarg);

    set_solde((void*)This, This->get_solde(This) - ABS(val) );

    if(nbarg>0){
        ComptePayant *compte2=va_arg(ap,ComptePayant*);
        set_solde((void*)compte2, compte2->get_solde(compte2) + ABS(val) );
    }

    va_end(ap);
    return 1;
}