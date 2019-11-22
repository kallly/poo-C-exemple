#ifndef CGI_EMPLOYE_H
#define CGI_EMPLOYE_H

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct Date
{
    int j;
    int m;
    int a;
}Date;


/*  Structure représantant l'objet Employe. */
typedef struct Employe
    {
        char*       (*afficherEmploye)(struct Employe*);
        int         (*age)(struct Employe*);
        int         (*anciennete)(struct Employe*);
        int         (*augmentationDuSalaire)(struct Employe*);

        int		    (*get_matricule)(struct Employe*);
        int			(*set_matricule)(struct Employe*,int);
        float		    (*get_salaire)(struct Employe*);
        int			(*set_salaire)(struct Employe*,float);
        char*		(*get_nom)(struct Employe*);
        int			(*set_nom)(struct Employe*,const char*);
        char*		(*get_prenom)(struct Employe*);
        int			(*set_prenom)(struct Employe*,const char*);
        Date		(*get_dateNaissance)(struct Employe*);
        int			(*set_dateNaissance)(struct Employe*,Date);
        Date		(*get_dateEmbauche)(struct Employe*);
        int			(*set_dateEmbauche)(struct Employe*,Date);
        
        

        int matricule;
        float salaire;
        char *nom,*prenom;
        Date dateNaissance,dateEmbauche;
    } Employe ;


Employe* New_Employe(int matricule,const char *nom,const char *prenom,Date naissance,Date embauche,float salaire);

#ifdef __cplusplus
}
#endif

#endif
            