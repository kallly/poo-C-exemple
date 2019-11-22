#ifndef CGI_PATRON_H
#define CGI_PATRON_H

#include "Employe.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Patron. */
typedef struct Patron
    {
        char*       (*toString)(struct Employe*);
            
        char*		(*get_matricule)(struct Patron*);
        int			(*set_matricule)(struct Patron*,char*);
        char*		(*get_nom)(struct Patron*);
        int			(*set_nom)(struct Patron*,char*);
        char*		(*get_prenom)(struct Patron*);
        int			(*set_prenom)(struct Patron*,char*);
        date		(*get_dateNaissance)(struct Patron*);
        int			(*set_dateNaissance)(struct Patron*,date);
        float		(*get_salaire)(struct Patron*);
        int			(*set_salaire)(struct Patron*,float);

        char *matricule,*nom,*prenom;
        date dateNaissance;
        float salaire;
    } Patron ;


Patron* New_Patron();

#ifdef __cplusplus
}
#endif

#endif
            