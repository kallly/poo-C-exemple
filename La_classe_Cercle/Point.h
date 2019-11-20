#ifndef CGI_POINT_H
#define CGI_POINT_H

#ifdef __cplusplus
    extern "C" {
#endif

/*  Structure représantant l'objet Point. */
typedef struct Point
    {
        char*   (*afficher)(struct Point*);

        int		(*get_x)(struct Point*);
        int			(*set_x)(struct Point*,int);
        int		(*get_y)(struct Point*);
        int			(*set_y)(struct Point*,int);
        

        int x,y;
    } Point ;


Point* New_Point();

#ifdef __cplusplus
}
#endif

#endif
            