#include <stdio.h>
#include <string.h>

int * (* getdata)(){
    int i=0;
    char *buf;
    FILE *pfile;
    int *data;
    char *tmp;

    pfile=fopen("data.txt","r");
    fgets(buf, 100, pfile);
    tmp=strtok(buf,",");
    while(tmp!=NULL){
        data[i]=(int)(*tmp);
        i++
        tmp=strtok(NULL,",");
    }
    return data;
}

