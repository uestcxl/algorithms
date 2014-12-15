#ifndef UTL_H_
#define UTL_H_

#include "stdio.h"
#include "stdlib.h"

//申请内存
inline void *xalloc(int size){
    void *p;
    p=(void *)malloc(size);
    if(p==NULL){
        printf("Memory error!\n");
    }
    return p;
}

//释放内存
#define xfree(p)    free(p)

#endif
