#ifndef CGI_EMPLOYE_H
#define CGI_EMPLOYE_H

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct date
{
    int j;
    int m;
    int a;
}date;


/*  Structure représantant l'objet Employe. */
typedef struct Employe
    {
        char*       (*toString)(struct Employe*);

        char*		(*get_matricule)(struct Employe*);
        int			(*set_matricule)(struct Employe*,char*);
        char*		(*get_nom)(struct Employe*);
        int			(*set_nom)(struct Employe*,char*);
        char*		(*get_prenom)(struct Employe*);
        int			(*set_prenom)(struct Employe*,char*);
        date		(*get_dateNaissance)(struct Employe*);
        int			(*set_dateNaissance)(struct Employe*,date);
        float		(*get_salaire)(struct Employe*);
        int			(*set_salaire)(struct Employe*,float);
        
        #define SMIG 2500
        
        char *matricule,*nom,*prenom;
        date dateNaissance;
        float salaire;
    } Employe ;


Employe* New_Employe();

char* get_matricule(Employe *This);
int set_matricule(Employe *This,char* matricule);
char* get_nom(Employe *This);
int set_nom(Employe *This,char* nom);
char* get_prenom(Employe *This);
int set_prenom(Employe *This,char* prenom);
date get_dateNaissance(Employe *This);
int set_dateNaissance(Employe *This,date dateNaissance);
float get_salaire(Employe *This);
int set_salaire(Employe *This,float salaire);

#ifdef __cplusplus
}
#endif

#endif
            