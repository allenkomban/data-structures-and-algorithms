
#include<stdio.h>
#include<stdlib.h>

void fixup(int *heap,int index){
    int swap;
    while (index>1 && heap[index]>heap[index/2]){
        swap=heap[index];
        heap[index]=heap[index/2];
        heap[index/2]=swap;
        index=index/2;
    }
    }
void insert(int *heap,int e,int index){
    *(heap+index)=e;

}

void show(int *heap,int size){
    for(int i=0;i<size;i++)
        printf("%d",*(heap+i));
}
int main(int argc,char *argv[]){
    
    for(int i=1;i<argc;i++){
        int inc=0;
        while(*(argv[i]+inc)!='\0'){
           // printf("%c",*(argv[i]+inc));
            if(*(argv[i]+inc)<'0'|| *(argv[i]+inc)>'9'){
                
                printf("error");
                return 0;
            }
            inc++;
            
        }
    }
    int e;
    int *heap=malloc(argc*sizeof(int));
    heap[0]=-999;
    for(int i=1;i<argc;i++){
        if(sscanf(argv[i],"%d",&e)!=1){
            printf("error");
            return 0;
        }
        insert(heap,e,i);
        fixup(heap,i);
        
        
        
        
        
    
        }
    show(heap,argc-1);
    
    return 1;
}
