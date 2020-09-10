#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>



void fixup(char *heap,int index){
    char swap;
    while (index>1 && heap[index]>heap[index/2]){
        swap=*(heap+index);
        *(heap+index)=*(heap+(index/2));
       *( heap+(index/2))=swap;
        index=index/2;
    }
}

void insert(char *heap,char e,int index){
    *(heap+index)=e;
    
}

void show(char *heap,int size){
    for(int i=0;i<size;i++)
        printf("%c",*(heap+i));
}

int main(int argc,char *argv[]){
    char *heap=malloc(argc*sizeof(char));
    *heap='#';
   // show(heap,argc);
    int size=1;
    for(int i=1;i<argc;i++){
        if( strlen(argv[i])==1){
            if(isalnum(*argv[i])){
                insert(heap,*argv[i],size);
                fixup(heap,size);
                size++;
                
                
                
                
                
            }
        }
        
    }
    if(size!=1){
        show(heap,size);}
    free(heap);
    return 0;
}
