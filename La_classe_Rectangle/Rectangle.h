#ifndef CGI_RECTANGLE_H
#define CGI_RECTANGLE_H

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Rectangle. */
typedef struct Rectangle
    {

        float       (*perimetre)(struct Rectangle*);
        float       (*aire)(struct Rectangle*);
        int         (*isCarre)(struct Rectangle *);
        char*       (*afficherRectangle)(struct Rectangle*);

        float       (*get_longueur)(struct Rectangle*);
        int         (*set_longueur)(struct Rectangle*,float);
        float		(*get_largeur)(struct Rectangle*);
        int		    (*set_largeur)(struct Rectangle*,float);
        

        float longueur,largeur;
    } Rectangle ;


Rectangle* New_Rectangle(float longeur,float largeur);



#ifdef __cplusplus
}
#endif

#endif
            