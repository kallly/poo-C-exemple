#ifndef CGI_PERSONNE_H
#define CGI_PERSONNE_H

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct date
{
    int j;
    int m;
    int a;
}date;


/*  Structure représantant l'objet Personne. */
typedef struct Personne
    {
        char*       (*afficher)(struct Personne*);

        char*		(*get_nom)(struct Personne*);
        int			(*set_nom)(struct Personne*,char*);
        char*		(*get_prenom)(struct Personne*);
        int			(*set_prenom)(struct Personne*,char*);
        date		(*get_dateNaissance)(struct Personne*);
        int			(*set_dateNaissance)(struct Personne*,date);
        

        char *nom,*prenom;
        date dateNaissance;
    } Personne ;


Personne* New_Personne(char *nom,char *prenom,date dateNaissance);

char* get_nom(Personne *This);
int set_nom(Personne *This,char* nom);
char* get_prenom(Personne *This);
int set_prenom(Personne *This,char* prenom);
date get_dateNaissance(Personne *This);
int set_dateNaissance(Personne *This,date dateNaissance);
char* Personne_afficher( Personne *This);

#ifdef __cplusplus
}
#endif

#endif
            