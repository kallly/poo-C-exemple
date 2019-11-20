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

static char* get_titre(Livre *This);
static int set_titre(Livre *This,char* titre);
static char* get_auteur(Livre *This);
static int set_auteur(Livre *This,char* auteur);
static float get_prix(Livre *This);
static int set_prix(Livre *This,float prix);
static char* afficher(Livre *This);

#ifdef __cplusplus
}
#endif
 
#endif
