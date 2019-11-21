#ifndef CGI_CLIENT_H
#define CGI_CLIENT_H

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Client. */
typedef struct Client
    {
        char*       (*afficher)(struct Client*);

        char*		(*get_CIN)(struct Client*);
        int			(*set_CIN)(struct Client*,char*);
        char*		(*get_nom)(struct Client*);
        int			(*set_nom)(struct Client*,char*);
        char*		(*get_prenom)(struct Client*);
        int			(*set_prenom)(struct Client*,char*);
        char*		(*get_tel)(struct Client*);
        int			(*set_tel)(struct Client*,char*);
        

        char *CIN,*nom,*prenom,*tel;
    } Client ;


Client* New_Client();

#ifdef __cplusplus
}
#endif

#endif
            