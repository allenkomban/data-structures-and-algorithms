#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    if(argc!=2){
        printf("error")
        return 0;
    }
    int temp;
    
    if(sscanf(argv[1],"%d",temp)!=1){
        printf("error in input");
        return 0;
    }
    
    while(temp>0){
        quack p;
        push(temp%2,p);
        temp=temp/2;
    
    }
    
    while(isemptyquack(s)){
        printf(%d,pop(s));
        
    }
    return 1;
    
}
