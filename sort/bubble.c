#include <stdio.h>
#include <string.h>

extern int * (*getdata)();

int main(){
    int data;
    data=getdata();
    for(int i=0;i<strlen(data);i++){
        printf("%d--\n", data[i]);
    }
}
