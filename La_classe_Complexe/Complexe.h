#ifndef CGI_COMPLEXE_H
#define CGI_COMPLEXE_H

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Complexe. */
typedef struct Complexe
    {

        struct Complexe* (*plus)(struct Complexe*,struct Complexe*);
        struct Complexe* (*moins)(struct Complexe*,struct Complexe*);
        char*            (*afficher)(struct Complexe*);

        float		(*get_reelle)(struct Complexe*);
        int			(*set_reelle)(struct Complexe*,float);
        float		(*get_imaginaire)(struct Complexe*);
        int			(*set_imaginaire)(struct Complexe*,float);
        

        float reelle,imaginaire;
    } Complexe ;


Complexe* New_Complexe(float reelle,float imaginaire);

static Complexe* plus(Complexe *This,Complexe *complexe2);
static Complexe* moins(Complexe *This,Complexe *complexe2);
static char* afficher(Complexe *This);

static float get_reelle(Complexe *This);
static int set_reelle(Complexe *This,float reelle);
static float get_imaginaire(Complexe *This);
static int set_imaginaire(Complexe *This,float imaginaire);

#ifdef __cplusplus
}
#endif

#endif
            