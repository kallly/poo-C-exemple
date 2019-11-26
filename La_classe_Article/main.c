#include <stdlib.h>
#include <stdio.h>
 
#include "Article.h"
//      ./article 20 1 ATA 300


int main(int argc,const char* argv[])
{
    Article *article;
    
    float tva=1;
    if(argc > 2)tva= (float)atoi(argv[1]);
    if(argc > 2)article = New_Article(tva, atoi(argv[2]), argv[3], atoi(argv[4])  );
    else article = New_Article(tva,1,"RER",10);

    printf("\n%s\n",article->afficherArticle(article));

#ifdef __WIN32__s
        system("PAUSE");
#endif
        return 0;
}

