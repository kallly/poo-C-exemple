#ifndef CGI_DIRECTEUR_H
#define CGI_DIRECTEUR_H

#include "Chef.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Directeur. */
typedef struct Directeur
    {
        char*       (*afficher)(struct Directeur*);

        char*		(*get_nom)(struct Directeur*);
        int			(*set_nom)(struct Directeur*,char*);
        char*		(*get_prenom)(struct Directeur*);
        int			(*set_prenom)(struct Directeur*,char*);
        date		(*get_dateNaissance)(struct Directeur*);
        int			(*set_dateNaissance)(struct Directeur*,date);

        
        char *nom,*prenom;
        date dateNaissance;
        
        
        float		(*get_salaire)(struct Directeur*);
        int			(*set_salaire)(struct Directeur*,float);
        
        float salaire;

        char*		(*get_service)(struct Directeur*);
        int			(*set_service)(struct Directeur*,char*);
        
        char *service;

        char*		(*get_societe)(struct Directeur*);
        int			(*set_societe)(struct Directeur*,char*);

        char *societe;

    } Directeur ;


Directeur* New_Directeur(char *nom,char *prenom,char *service, char *societe,date dateNaissance,float salaire);

#ifdef __cplusplus
}
#endif

#endif
            