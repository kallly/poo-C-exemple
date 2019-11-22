#ifndef CGI_VOITURE_H
#define CGI_VOITURE_H

#include "Vehicule.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Voiture. */
typedef struct Voiture
    {
        char*           (*toString)(struct Voiture*);
        char*           (*accelerer)(struct Voiture*);
        char*           (*demarrer)(struct Voiture*);

        const char*		(*get_matricule)(struct Voiture*);
        int			    (*set_matricule)(struct Voiture*,const char*);
        int		        (*get_anneModel)(struct Voiture*);
        int			    (*set_anneModel)(struct Voiture*,int);
        float		    (*get_prix)(struct Voiture*);
        int			    (*set_prix)(struct Voiture*,float);
        
        char *matricule;
        int anneeModel;
        float prix;
    } Voiture ;


Voiture* New_Voiture(const char *matricule,int anneeModel,float prix);

#ifdef __cplusplus
}
#endif

#endif
            