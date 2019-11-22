#include<stdlib.h>
#include<stdio.h>
#include <time.h>

#include "Ouvrier.h"

static void Ouvrier_Init(Ouvrier*);

static char* toString( Employe *This);

/******************************************************************************/
Ouvrier* New_Ouvrier(char *matricule,char *nom,char *prenom,date dateNaissance)
{
    Ouvrier *This = malloc(sizeof(Ouvrier));
    if(!This) return NULL;
    Ouvrier_Init(This);
    
    This->set_matricule(This,matricule);
    This->set_nom(This,nom);
    This->set_prenom(This,prenom);
    This->set_dateNaissance(This,dateNaissance);

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    float salaire = SMIG + ((float)local->tm_year + 1900. - (float)dateNaissance.a) * 100.;
    This->set_salaire(This,salaire>SMIG*2?SMIG*2:salaire);

    return This;
}

/******************************************************************************/
static void Ouvrier_Init(Ouvrier *This)
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
          size_t size = sizeof(This->get_matricule(This)) 
                        + sizeof(This->get_matricule(This)) 
                        + sizeof(This->get_matricule(This)) 
                        + sizeof(This->get_prenom(This))
                        + sizeof(char)*100;
          char* string = (char*)malloc(size);

          snprintf(string, size, "Ouvrier\nMatricule: %s\nNom: %s\nPrenom: %s\nDate de naissance: %d/%d/%d\nSalaire: %0.2f",
                     This->get_matricule(This),
                     This->get_nom(This),
                     This->get_prenom(This),
                     This->get_dateNaissance(This).j,This->get_dateNaissance(This).m,This->get_dateNaissance(This).a,
                     This->get_salaire(This)
           );
          
          return string;
}