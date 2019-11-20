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

#ifdef __cplusplus
}
#endif

#endif
            