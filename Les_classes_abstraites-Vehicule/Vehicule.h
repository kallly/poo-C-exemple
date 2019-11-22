#ifndef CGI_VEHICULE_H
#define CGI_VEHICULE_H

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Vehicule. */
typedef struct Vehicule
    {
        char*           (*toString)(struct Vehicule*);
        char*           (*accelerer)(struct Vehicule*);
        char*           (*demarrer)(struct Vehicule*);

        const char*		(*get_matricule)(struct Vehicule*);
        int			    (*set_matricule)(struct Vehicule*,const char*);
        int		        (*get_anneModel)(struct Vehicule*);
        int			    (*set_anneModel)(struct Vehicule*,int);
        float		    (*get_prix)(struct Vehicule*);
        int			    (*set_prix)(struct Vehicule*,float);
        

        char *matricule;
        int anneeModel;
        float prix;
    } Vehicule ;


Vehicule* New_Vehicule();

char* toString( Vehicule *This);

const char* get_matricule(Vehicule *This);
int set_matricule(Vehicule *This,const char* matricule);
int get_anneeModel(Vehicule *This);
int set_anneeModel(Vehicule *This,int anneeModel);
float get_prix(Vehicule *This);
int set_prix(Vehicule *This,float prix);

#ifdef __cplusplus
}
#endif

#endif
            