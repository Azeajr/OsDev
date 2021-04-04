#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"


int main(int argc, char const *argv[])
{
    int i = 0;

    VECTOR_INIT(v);

    int p[10]
    
    v.pfVectorAdd(&v, &p);
    v.pfVectorAdd(&v, &q);
    v.pfVectorAdd(&v, &r);
    
    for( i = 0; i < v.pfVectorTotal(&v); i++){
        printf("%d\n", *(int*)v.pfVectorGet(&v, i));
    }

    p=40;
    //v.pfVectorSet(&v, 0, "change1\n");

    printf("\n\n\nVector list after changes\n\n\n");

    for(i = 0; i < v.pfVectorTotal(&v); i++){
        printf("%d\n", *(int*)v.pfVectorGet(&v, i));
    }

    return 0;
}
