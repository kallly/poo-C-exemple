#ifndef CGI_CHEF_H
#define CGI_CHEF_H

#include "Employe.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Chef. */
typedef struct Chef
    { 
        char*       (*afficher)(struct Chef*);

        char*		(*get_nom)(struct Chef*);
        int			(*set_nom)(struct Chef*,char*);
        char*		(*get_prenom)(struct Chef*);
        int			(*set_prenom)(struct Chef*,char*);
        date		(*get_dateNaissance)(struct Chef*);
        int			(*set_dateNaissance)(struct Chef*,date);

        char *nom,*prenom;
        date dateNaissance;
        
        
        float		(*get_salaire)(struct Chef*);
        int			(*set_salaire)(struct Chef*,float);

        float salaire;

        char*		(*get_service)(struct Chef*);
        int			(*set_service)(struct Chef*,char*);

        char *service;
    } Chef ;


Chef* New_Chef(char *nom,char *prenom,char *service,date dateNaissance,float salaire);

char* get_service(Chef *This);
int set_service(Chef *This,char* service);

#ifdef __cplusplus
}
#endif

#endif
            