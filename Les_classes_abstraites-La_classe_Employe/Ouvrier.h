#ifndef CGI_OUVRIER_H
#define CGI_OUVRIER_H

#include "Employe.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Ouvrier. */
typedef struct Ouvrier
    {
        char*       (*toString)(struct Employe*);

        char*		(*get_matricule)(struct Ouvrier*);
        int			(*set_matricule)(struct Ouvrier*,char*);
        char*		(*get_nom)(struct Ouvrier*);
        int			(*set_nom)(struct Ouvrier*,char*);
        char*		(*get_prenom)(struct Ouvrier*);
        int			(*set_prenom)(struct Ouvrier*,char*);
        date		(*get_dateNaissance)(struct Ouvrier*);
        int			(*set_dateNaissance)(struct Ouvrier*,date);
        float		(*get_salaire)(struct Ouvrier*);
        int			(*set_salaire)(struct Ouvrier*,float);
        

        char *matricule,*nom,*prenom;
        date dateNaissance;
        float salaire;
    } Ouvrier ;


Ouvrier* New_Ouvrier();

#ifdef __cplusplus
}
#endif

#endif
            