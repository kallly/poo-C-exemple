#ifndef CGI_CADRE_H
#define CGI_CADRE_H

#include "Employe.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Cadre. */
typedef struct Cadre
    {
        char*       (*toString)(struct Employe*);

        char*		(*get_matricule)(struct Cadre*);
        int			(*set_matricule)(struct Cadre*,char*);
        char*		(*get_nom)(struct Cadre*);
        int			(*set_nom)(struct Cadre*,char*);
        char*		(*get_prenom)(struct Cadre*);
        int			(*set_prenom)(struct Cadre*,char*);
        date		(*get_dateNaissance)(struct Cadre*);
        int			(*set_dateNaissance)(struct Cadre*,date);
        float		(*get_salaire)(struct Cadre*);
        int			(*set_salaire)(struct Cadre*,float);

        char *matricule,*nom,*prenom;
        date dateNaissance;
        float salaire;
    } Cadre ;


Cadre* New_Cadre(char *matricule,char *nom,char *prenom,date dateNaissance,int indice);

#ifdef __cplusplus
}
#endif

#endif
            