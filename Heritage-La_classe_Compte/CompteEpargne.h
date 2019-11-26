#ifndef CGI_COMPTEEPARGNE_H
#define CGI_COMPTEEPARGNE_H

#include "Compte.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet CompteEpargne. */
typedef struct CompteEpargne
    {
        char*       (*toString)(struct CompteEpargne*);
        int         (*crediter)(struct CompteEpargne*,float,int,...);
        int         (*debiter)(struct CompteEpargne*,float,int,...);

        float		(*get_solde)(struct CompteEpargne*);
        int		    (*get_id)(struct CompteEpargne*);
        Client*		(*get_client)(struct CompteEpargne*);
        int			(*set_client)(struct CompteEpargne*,Client*);
        
        
        

        float solde;
        int id;
        Client* client;
        
        float		(*get_tauxInteret)(struct CompteEpargne*);
        int			(*set_tauxInteret)(struct CompteEpargne*,float);

        int         (*calculInteret)(struct CompteEpargne*);

        float tauxInteret;
    } CompteEpargne ;


CompteEpargne* New_CompteEpargne(char *CIN,char *nom,char *prenom,char *tel,size_t nbarg,...);

#ifdef __cplusplus
}
#endif

#endif
            