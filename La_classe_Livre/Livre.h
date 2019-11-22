#ifndef CGI_POINT_H
#define CGI_POINT_H
 
#ifdef __cplusplus
  extern "C" {
#endif
 
/*  Structure représantant l'objet Livre. */
typedef struct Livre
        {
          char*     (*get_titre)       (struct Livre*);
          int       (*set_titre)       (struct Livre*,const char*);
          char*     (*get_auteur)      (struct Livre*);
          int       (*set_auteur)      (struct Livre*,const char*);
          float     (*get_prix)        (struct Livre*);
          int       (*set_prix)        (struct Livre*,float);
          char*     (*afficher)        (struct Livre*);
          
          char* titre;
          char* auteur;
          float prix;
 
        } Livre ;
 
 
Livre* New_Livre(const char* titre,const char* auteur,int prix);

#ifdef __cplusplus
}
#endif
 
#endif
