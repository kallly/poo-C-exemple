#ifndef CGI_COMPTE_H
#define CGI_COMPTE_H

#include "Client.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Compte. */
typedef struct Compte
    {
        char*       (*toString)(struct Compte*);
        int         (*crediter)(struct Compte*,float,int,...);
        int         (*debiter)(struct Compte*,float,int,...);

        float		(*get_solde)(struct Compte*);
        int		    (*get_id)(struct Compte*);
        Client*		(*get_client)(struct Compte*);
        int			(*set_client)(struct Compte*,Client*);
        
        float solde;
        int id;
        Client* client;
    } Compte ;


Compte* New_Compte(char *CIN,char *nom,char *prenom,char *tel,size_t nbarg,...);



float get_solde(Compte *This);
int set_solde(Compte *This,float solde);
int get_id(Compte *This);
int set_id(Compte *This,int id);
Client* get_client(Compte *This);
int set_client(Compte *This,Client *client);

char* toString( Compte *This);
int Compte_crediter(Compte *This,float val,int nbarg,...);
int Compte_debiter(Compte *This,float val,int nbarg,...);

#ifdef __cplusplus
}
#endif

#endif
            