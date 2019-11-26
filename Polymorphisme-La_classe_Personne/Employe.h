#ifndef CGI_EMPLOYE_H
#define CGI_EMPLOYE_H

#include "Personne.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Employe. */
typedef struct Employe
    {   
        char*       (*afficher)(struct Employe*);

        char*		(*get_nom)(struct Employe*);
        int			(*set_nom)(struct Employe*,char*);
        char*		(*get_prenom)(struct Employe*);
        int			(*set_prenom)(struct Employe*,char*);
        date		(*get_dateNaissance)(struct Employe*);
        int			(*set_dateNaissance)(struct Employe*,date);

        char *nom,*prenom;
        date dateNaissance; 
        
        float		(*get_salaire)(struct Employe*);
        int			(*set_salaire)(struct Employe*,float);

        float salaire;
    } Employe ;


Employe* New_Employe(char *nom,char *prenom,date dateNaissance,float salaire);

float get_salaire(Employe *This);
int set_salaire(Employe *This,float salaire);

#ifdef __cplusplus
}
#endif

#endif
            