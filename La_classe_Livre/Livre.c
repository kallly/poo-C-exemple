#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Livre.h"

static void Livre_Init(Livre*);
 
static char* get_titre(Livre *This);
static int set_titre(Livre *This,const char* titre);
static char* get_auteur(Livre *This);
static int set_auteur(Livre *This,const char* auteur);
static float get_prix(Livre *This);
static int set_prix(Livre *This,float prix);
static char* afficher(Livre *This);

/******************************************************************************/
Livre* New_Livre(const char* titre,const char* auteur,int prix)
{
       Livre *This = malloc(sizeof(Livre));
       if(!This) return NULL;
       Livre_Init(This);
       This->set_titre(This,titre);
       This->set_auteur(This,auteur);
       This->set_prix(This,prix);

       return This;
}
/******************************************************************************/
 
static void Livre_Init(Livre *This)
{
       This->get_prix = get_prix;
       This->set_prix = set_prix;
       This->get_auteur = get_auteur;
       This->set_auteur = set_auteur;
       This->get_titre = get_titre;
       This->set_titre = set_titre;
       This->afficher = afficher;
       
       This->titre = NULL;
       This->auteur = NULL;
       
}

/******************************************************************************/
static float get_prix(Livre *This)
{
       return This->prix;
}

/******************************************************************************/
static int set_prix(Livre *This,float prix)
{
       This->prix = prix;
       return 1;
}

/******************************************************************************/
static char* get_titre(Livre *This)
{
       return This->titre;
}

/******************************************************************************/
static int set_titre(Livre *This,const char* titre)
{
       if(This->titre != NULL)free(This->titre);
       This->titre=malloc(sizeof(char)*(strlen(titre)+1));
       strcpy(This->titre,titre);
       return 1;
}

/******************************************************************************/
static char* get_auteur(Livre *This)
{
       return This->auteur;
}

/******************************************************************************/
static int set_auteur(Livre *This,const char* auteur)
{
       if(This->auteur != NULL)free(This->auteur);
       This->auteur=malloc(sizeof(char)*(strlen(auteur)+1));
       strcpy(This->auteur,auteur);
       return 1;
}

/******************************************************************************/
static char* afficher(Livre *This)
{
       size_t size = ( strlen(This->get_titre(This)) + 1
                      + strlen(This->get_auteur(This)) + 1
                      + 50
                     )* sizeof(char);
       char* string = (char*)malloc(size);  
       
       snprintf(string, size, "Titre: %s\nAuteur: %s\nPrix: %0.4f\n", This->get_titre(This),This->get_auteur(This),This->get_prix(This));
       
       return string;
}