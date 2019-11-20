#ifndef CGI_MAISON_H
#define CGI_MAISON_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "Batiment.h"

/*  Structure représantant l'objet Maison. */
typedef struct Maison
    {
        char*       (*to_string)(struct Maison*);

        char*		(*get_adresse)(struct Maison*);
        int			(*set_adresse)(struct Maison*,char*);
        unsigned int		(*get_NbPieces)(struct Maison*);
        int			(*set_NbPieces)(struct Maison*,unsigned int);
        

        char* adresse;
        unsigned int NbPieces;
    } Maison ;


Maison* New_Maison(size_t nbarg,...);

static unsigned int get_NbPieces(Maison *This);
static int set_NbPieces(Maison *This,unsigned int NbPieces);

static char* Maison_to_string( Maison *This);

#ifdef __cplusplus
}
#endif

#endif
            