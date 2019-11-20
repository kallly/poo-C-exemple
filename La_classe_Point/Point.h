#ifndef CGI_POINT_H
#define CGI_POINT_H
 
#ifdef __cplusplus
  extern "C" {
#endif
 
/*  Structure représantant l'objet point. */
typedef struct Point
        {
          float(*get_abscisse)(struct Point*);
          int(*set_abscisse)(struct Point*,float);

          float(*get_ordonne)(struct Point*);
          int(*set_ordonne)(struct Point*,float);

          float (*norme)(struct Point*);

          float abscisse,ordonne;
 
        } Point ;
 
 
Point* New_Point(float abscisse,float ordonne);

static float get_abscisse(Point *This);
static int set_abscisse(Point *This,float abscisse);
static float get_ordonne(Point *This);
static int set_ordonne(Point *This,float ordonne);

static float norme(Point *This);

#ifdef __cplusplus
}
#endif
 
#endif
