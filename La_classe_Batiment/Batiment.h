#ifndef CGI_BATIMENT_H
#define CGI_BATIMENT_H

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Batiment. */
typedef struct Batiment
    {
        char*       (*to_string)(struct Batiment*);

        char*		(*get_adresse)(struct Batiment*);
        int			(*set_adresse)(struct Batiment*,char*);
        
        char* adresse;
    } Batiment ;


Batiment* New_Batiment(size_t nbarg,...);

char* get_adresse(Batiment *This);
int set_adresse(Batiment *This,char* adresse);

#ifdef __cplusplus
}
#endif

#endif
            