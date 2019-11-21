#include<stdlib.h>
#include<stdio.h>
#include <time.h>

#include "Employe.h"

static void Employe_Init(Employe*);

static int get_matricule(Employe *This);
static int set_matricule(Employe *This,int matricule);
static float get_salaire(Employe *This);
static int set_salaire(Employe *This,float salaire);
static char* get_nom(Employe *This);
static int set_nom(Employe *This,char* nom);
static char* get_prenom(Employe *This);
static int set_prenom(Employe *This,char* pernom);
static Date get_dateNaissance(Employe *This);
static int set_dateNaissance(Employe *This,Date dateNaissance);
static Date get_dateEmbauche(Employe *This);
static int set_dateEmbauche(Employe *This,Date dateEmbauche);

static int augmentationDuSalaire(Employe *This);
static int anciennete(Employe *This);
static int age(Employe *This);
static char* afficherEmploye( Employe *This);

/******************************************************************************/
Employe* New_Employe(int matricule,char *nom,char *prenom,Date naissance,Date embauche,float salaire)
{
    Employe *This = malloc(sizeof(Employe));
    if(!This) return NULL;
    Employe_Init(This);
    This->set_matricule(This,matricule);
	This->set_nom(This,nom);
	This->set_prenom(This,prenom);
	This->set_dateNaissance(This,naissance);
	This->set_dateEmbauche(This,embauche);
	This->set_salaire(This,salaire);
    return This;
}

/******************************************************************************/
static void Employe_Init(Employe *This)
{      
	This->augmentationDuSalaire=augmentationDuSalaire;
	This->anciennete=anciennete;
    This->age=age;
    This->afficherEmploye=afficherEmploye;

    This->get_dateEmbauche=get_dateEmbauche;
    This->get_dateNaissance=get_dateNaissance;
    This->get_matricule=get_matricule;
    This->get_salaire=get_salaire;
    This->get_nom=get_nom;
    This->get_prenom=get_prenom;
    This->set_dateEmbauche=set_dateEmbauche;
    This->set_dateNaissance=set_dateNaissance;
    This->set_matricule=set_matricule;
    This->set_salaire=set_salaire;
    This->set_nom=set_nom;
    This->set_prenom=set_prenom;
    
    This->set_dateEmbauche(This, (Date){0,0,0} );
    This->set_dateNaissance(This, (Date){0,0,2000} );
    This->matricule=0;
    This->nom=malloc(sizeof(char));
    This->nom=" ";
    This->prenom=malloc(sizeof(char));
    This->prenom=" ";
    
}

/******************************************************************************/
static int get_matricule(Employe *This)
{
       return This->matricule;
}

/******************************************************************************/
static int set_matricule(Employe *This,int matricule)
{
       This->matricule = matricule;
       return 1;
}

/******************************************************************************/
static float get_salaire(Employe *This)
{
       return This->salaire;
}

/******************************************************************************/
static int set_salaire(Employe *This,float salaire)
{
       This->salaire = salaire;
       return 1;
}

/******************************************************************************/
static char* get_nom(Employe *This)
{
       return This->nom;
}

/******************************************************************************/
static int set_nom(Employe *This,char* nom)
{
       This->nom = nom;
       return 1;
}
/******************************************************************************/
static char* get_prenom(Employe *This)
{
       return This->prenom;
}

/******************************************************************************/
static int set_prenom(Employe *This,char* prenom)
{
       This->prenom = prenom;
       return 1;
}

/******************************************************************************/
static Date get_dateNaissance(Employe *This)
{
       return This->dateNaissance;
}

/******************************************************************************/
static int set_dateNaissance(Employe *This,Date dateNaissance)
{
       This->dateNaissance = dateNaissance;
       return 1;
}

/******************************************************************************/
static Date get_dateEmbauche(Employe *This)
{
       return This->dateEmbauche;
}

/******************************************************************************/
static int set_dateEmbauche(Employe *This,Date dateEmbauche)
{
       This->dateEmbauche = dateEmbauche;
       return 1;
}

/******************************************************************************/
static int age(Employe *This)
{
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    return local->tm_year + 1900 - This->get_dateNaissance(This).a;
}

/******************************************************************************/
static int anciennete(Employe *This)
{
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    return local->tm_year + 1900 - This->get_dateEmbauche(This).a;
}

/******************************************************************************/
static int augmentationDuSalaire(Employe *This)
{
	if(This->anciennete(This) < 5)This->set_salaire(This, This->get_salaire(This)*1.02);
	else if(This->anciennete(This) <10)This->set_salaire(This, This->get_salaire(This)*1.05);
	else This->set_salaire(This, This->get_salaire(This)*1.1);

    return 1;
}


/******************************************************************************/
static char* afficherEmploye(Employe *This)
{
       size_t size = sizeof(This->get_nom(This)) + sizeof(This->get_prenom(This)) + sizeof(char)*100;
       char* string = (char*)malloc(size);
       
       snprintf(string, size, 
            "Matricule: %d\nNom: %s\nPrenom: %s\nAge: %d\nAnciennete : %d\nSalaire: %0.2f\n",
            This->get_matricule(This),
            This->get_nom(This),
            This->get_prenom(This),
            This->age(This),
			This->anciennete(This),
            This->get_salaire(This)
       );
       
       return string;
}