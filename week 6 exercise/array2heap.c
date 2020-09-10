#include<stdio.h>
void fixup(int *heap,int index){
    int swap;
    while (index>1 && heap[index]>heap[index/2]){
        swap=heap[index];
        heap[index]=heap[index/2];
        heap[index/2]=swap;
        index=index/2;
    }
    }

void show(int *heap){
    for(int i=0;i<=7;i++){
        printf("%d",*(heap+i));
        
        
    }
}

int main(void){
    int heap[] = {-999,1,2,3,4,5,6,7};
    
    for(int i=7;i>=1;i--){
        fixup(heap,i);
        }
    show(heap);
    return 1;
    
}
