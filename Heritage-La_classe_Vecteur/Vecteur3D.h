#ifndef CGI_VECTEUR3D_H
#define CGI_VECTEUR3D_H

#include "Vecteur2D.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Vecteur3D. */
typedef struct Vecteur3D
    {
        char*       (*toString)(struct Vecteur3D*);
        int         (*equals)(struct Vecteur3D*,struct Vecteur3D*);
        float       (*norme)(struct Vecteur3D*);

        float		(*get_x)(struct Vecteur3D*);
        int			(*set_x)(struct Vecteur3D*,float);
        float		(*get_y)(struct Vecteur3D*);
        int			(*set_y)(struct Vecteur3D*,float);
        float		(*get_z)(struct Vecteur3D*);
        int			(*set_z)(struct Vecteur3D*,float);
        int		    (*get_id)(struct Vecteur3D*);
        int			(*set_id)(struct Vecteur3D*,int);
        
        

        int id;
        float x,y,z;        
    } Vecteur3D ;


Vecteur3D* New_Vecteur3D(float x,float y,float z);


#ifdef __cplusplus
}
#endif

#endif
            