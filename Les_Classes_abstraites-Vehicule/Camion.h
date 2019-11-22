#ifndef CGI_CAMION_H
#define CGI_CAMION_H

#include "Vehicule.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Camion. */
typedef struct Camion
    {
        char*           (*toString)(struct Camion*);
        char*           (*accelerer)(struct Camion*);
        char*           (*demarrer)(struct Camion*);

        const char*		(*get_matricule)(struct Camion*);
        int			    (*set_matricule)(struct Camion*,const char*);
        int		        (*get_anneModel)(struct Camion*);
        int			    (*set_anneModel)(struct Camion*,int);
        float		    (*get_prix)(struct Camion*);
        int			    (*set_prix)(struct Camion*,float);
        
        char *matricule;
        int anneeModel;
        float prix;
    } Camion ;


Camion* New_Camion(const char *matricule,int anneeModel,float prix);

#ifdef __cplusplus
}
#endif

#endif
            