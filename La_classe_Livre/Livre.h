#ifndef CGI_POINT_H
#define CGI_POINT_H
 
#ifdef __cplusplus
  extern "C" {
#endif
 
/*  Structure représantant l'objet point. */
typedef struct Livre
        {
          char*     (*get_titre)       (struct Livre*);
          int       (*set_titre)       (struct Livre*,char*);
          char*     (*get_auteur)      (struct Livre*);
          int       (*set_auteur)      (struct Livre*,char*);
          float     (*get_prix)        (struct Livre*);
          int       (*set_prix)        (struct Livre*,float);
          char*     (*afficher)        (struct Livre*);
          
          char* titre;
          char* auteur;
          float prix;
 
        } Livre ;
 
 
Livre* New_Livre();

#ifdef __cplusplus
}
#endif
 
#endif
