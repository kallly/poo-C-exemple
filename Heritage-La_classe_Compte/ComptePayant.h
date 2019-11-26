#ifndef CGI_COMPTEPAYANT_H
#define CGI_COMPTEPAYANT_H

#include "Compte.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet ComptePayant. */
typedef struct ComptePayant
    {
        char*       (*toString)(struct ComptePayant*);
        int         (*crediter)(struct ComptePayant*,float,int,...);
        int         (*debiter)(struct ComptePayant*,float,int,...);

        float		(*get_solde)(struct ComptePayant*);
        int		    (*get_id)(struct ComptePayant*);
        Client*		(*get_client)(struct ComptePayant*);
        int			(*set_client)(struct ComptePayant*,Client*);
        
        float solde;
        int id;
        Client* client;

    } ComptePayant ;


ComptePayant* New_ComptePayant(const char *CIN,const char *nom,const char *prenom,const char *tel,size_t nbarg,...);

#ifdef __cplusplus
}
#endif

#endif
            