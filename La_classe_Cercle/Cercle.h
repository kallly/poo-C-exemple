#ifndef CGI_CERCLE_H
#define CGI_CERCLE_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "Point.h"

/*  Structure représantant l'objet Cercle. */
typedef struct Cercle
    {
        char*       (*afficher)(struct Cercle*);
        int         (*appartient)(struct Cercle*,Point*);
        float       (*getSurface)(struct Cercle*);
        float       (*getPerimetre)(struct Cercle*);

        Point*		(*get_centre)(struct Cercle*);
        int			(*set_centre)(struct Cercle*,Point*);
        float		(*get_r)(struct Cercle*);
        int			(*set_r)(struct Cercle*,float);

        Point* centre;
        float r;
    } Cercle ;


Cercle* New_Cercle(int x,int y,float r);

#ifdef __cplusplus
}
#endif

#endif
            