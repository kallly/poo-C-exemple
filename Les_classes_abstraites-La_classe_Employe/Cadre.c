#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Cadre.h"

static void Cadre_Init(Cadre*);

static char* toString( Employe *This);
static int calSalaire(int indice);

/******************************************************************************/
Cadre* New_Cadre(char *matricule,char *nom,char *prenom,date dateNaissance,int indice)
{
    Cadre *This = malloc(sizeof(Cadre));
    if(!This) return NULL;
    Cadre_Init(This);
    
    This->set_matricule(This,matricule);
    This->set_nom(This,nom);
    This->set_prenom(This,prenom);
    This->set_dateNaissance(This,dateNaissance);

    This->set_salaire(This,calSalaire(indice));

    return This;
}

/******************************************************************************/
static void Cadre_Init(Cadre *This)
{
        This->toString=toString;

       This->get_dateNaissance=(void*)get_dateNaissance;
       This->get_matricule=(void*)get_matricule;
       This->get_nom=(void*)get_nom;
       This->get_prenom=(void*)get_prenom;
       This->get_salaire=(void*)get_salaire;
       This->set_dateNaissance=(void*)set_dateNaissance;
       This->set_matricule=(void*)set_matricule;
       This->set_nom=(void*)set_nom;
       This->set_prenom=(void*)set_prenom;
       This->set_salaire=(void*)set_salaire;
}

/******************************************************************************/
static char* toString( Employe *This)
{
          size_t size = ( strlen(This->get_matricule(This)) 
                        + strlen(This->get_matricule(This)) 
                        + strlen(This->get_matricule(This)) 
                        + strlen(This->get_prenom(This))
                        + 100
                        )* sizeof(char);
          char* string = (char*)malloc(size);
          
          snprintf(string, size, "Cadre\nMatricule: %s\nNom: %s\nPrenom: %s\nDate de naissance: %d/%d/%d\nSalaire: %0.2f",
                     This->get_matricule(This),
                     This->get_nom(This),
                     This->get_prenom(This),
                     This->get_dateNaissance(This).j,This->get_dateNaissance(This).m,This->get_dateNaissance(This).a,
                     This->get_salaire(This)
           );
          
          return string;
}

/******************************************************************************/
static int calSalaire(int indice){
 switch (indice) {    
     case 1: return 13000; 
     case 2: return 15000;
     case 3: return 17000;
     case 4: return 20000;        
     default:    return 13000;     
     }
}
