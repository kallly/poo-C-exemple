#ifndef CGI_ARTICLE_H
#define CGI_ARTICLE_H

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Article. */
typedef struct Article
    {
        char*       (*afficherArticle)(struct Article*);
        float       (*calculerPrixTTC)(struct Article*);

        int		    (*get_reference)(struct Article*);
        int			(*set_reference)(struct Article*,int);
        char*		(*get_deignation)(struct Article*);
        int			(*set_deignation)(struct Article*,char*);
        float		(*get_prixHT)(struct Article*);
        int			(*set_prixHT)(struct Article*,float);
        float		(*get_tauxTVA)(struct Article*);
        int			(*set_tauxTVA)(struct Article*,float);
        

        int reference;
        char* designation;
        float prixHT,tauxTVA;
    } Article ;


Article* New_Article(float tauxTVA,int reference,char* designation,float prixHT);

#ifdef __cplusplus
}
#endif

#endif
            