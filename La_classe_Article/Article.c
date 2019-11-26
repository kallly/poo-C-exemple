#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include "Article.h"

static void Article_Init(Article*);

static int get_reference(Article *This);
static int set_reference(Article *This,int reference);
static char* get_designation(Article *This);
static int set_designation(Article *This,const char *designation);
static float get_prixHT(Article *This);
static int set_prixHT(Article *This,float prixHT);
static float get_tauxTVA(Article *This);
static int set_tauxTVA(Article *This,float tauxTVA);

static char* afficherArticle( Article *This);
static float calculerPrixTTC(Article *This);

/******************************************************************************/
Article* New_Article(float tauxTVA,int reference,const char* designation,float prixHT)
{
    Article *This = malloc(sizeof(Article));
    if(!This) return NULL;
    Article_Init(This);
    This->set_tauxTVA(This,tauxTVA);
    This->set_reference(This,reference);
    This->set_deignation(This,designation);
    This->set_prixHT(This,prixHT);
    return This;
}

/******************************************************************************/
static void Article_Init(Article *This)
{
    This->afficherArticle=afficherArticle;
    This->calculerPrixTTC=calculerPrixTTC;

    This->get_reference=get_reference;
    This->get_deignation=get_designation;
    This->get_prixHT=get_prixHT;
    This->get_tauxTVA=get_tauxTVA;
    This->set_reference=set_reference;
    This->set_deignation=set_designation;
    This->set_prixHT=set_prixHT;
    This->set_tauxTVA=set_tauxTVA;

    This->designation=NULL;
}

/******************************************************************************/
static int get_reference(Article *This)
{
       return This->reference;
}

/******************************************************************************/
static int set_reference(Article *This,int reference)
{
       This->reference = reference;
       return 1;
}

/******************************************************************************/
static char* get_designation(Article *This)
{
       return This->designation;
}

/******************************************************************************/
static int set_designation(Article *This,const char *designation)
{
       if(This->designation!=NULL) free(This->designation);
       This->designation = malloc(sizeof(char)*(strlen(designation)+1));
       return 1;
}

/******************************************************************************/
static float get_prixHT(Article *This)
{
       return This->prixHT;
}

/******************************************************************************/
static int set_prixHT(Article *This,float prixHT)
{
       This->prixHT = prixHT;
       return 1;
}

/******************************************************************************/
static float get_tauxTVA(Article *This)
{
       return This->tauxTVA;
}

/******************************************************************************/
static int set_tauxTVA(Article *This,float tauxTVA)
{
       This->tauxTVA = tauxTVA;
       return 1;
}

/******************************************************************************/
static float calculerPrixTTC(Article *This)
{
       return This->get_prixHT(This) + (This->get_prixHT(This)*This->get_tauxTVA(This)/100) ;
}

/******************************************************************************/
static char* afficherArticle( Article *This)
{
       size_t size = (strlen(This->get_deignation(This)) + 1 + 100)* sizeof(char);
       char* string = (char*)malloc(size);
       
       snprintf(string, size,
            "Reference: %d\nDesignation: %s\nPrix HT: %0.2f\n",
            This->get_reference(This),
            This->get_deignation(This),
            This->calculerPrixTTC(This)
            );
       
       return string;
}