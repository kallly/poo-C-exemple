#ifndef CGI_COMPTE_H
#define CGI_COMPTE_H

#include "Client.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Compte. */
typedef struct Compte
    {
        char*       (*afficher)(struct Compte*);
        int         (*crediter)(struct Compte*,float,size_t,...);
        int         (*debiter)(struct Compte*,float,size_t,...);

        float		(*get_solde)(struct Compte*);
        int		    (*get_id)(struct Compte*);
        Client*		(*get_client)(struct Compte*);
        int			(*set_client)(struct Compte*,Client*);
        
        float solde;
        int id;
        Client* client;
    } Compte ;


Compte* New_Compte();

#ifdef __cplusplus
}
#endif

#endif
            