#ifndef CGI_VECTEUR2D_H
#define CGI_VECTEUR2D_H

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Vecteur2D. */
typedef struct Vecteur2D
    {
        char*       (*toString)(struct Vecteur2D*);
        int         (*equals)(struct Vecteur2D*,struct Vecteur2D*);
        float       (*norme)(struct Vecteur2D*);

        float		(*get_x)(struct Vecteur2D*);
        int			(*set_x)(struct Vecteur2D*,float);
        float		(*get_y)(struct Vecteur2D*);
        int			(*set_y)(struct Vecteur2D*,float);
        int		    (*get_id)(struct Vecteur2D*);
        int			(*set_id)(struct Vecteur2D*,int);
        

        int id;
        float x,y;
    } Vecteur2D ;


Vecteur2D* New_Vecteur2D(float x,float y);

int get_id(Vecteur2D *This);
int set_id(Vecteur2D *This,int id);
float get_x(Vecteur2D *This);
int set_x(Vecteur2D *This,float x);
float get_y(Vecteur2D *This);
int set_y(Vecteur2D *This,float y);

#ifdef __cplusplus
}
#endif

#endif
            