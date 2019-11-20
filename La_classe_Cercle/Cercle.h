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

static char* Cercle_afficher(Cercle *This);
static int appartient(Cercle *This,Point *p);
static float getSurface(Cercle *This);
static float getPerimetre(Cercle *This);

static float get_r(Cercle *This);
static int set_r(Cercle *This,float centre);
static Point* get_centre(Cercle *This);
static int set_centre(Cercle *This,Point* centre);

#ifdef __cplusplus
}
#endif

#endif
            