#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[]){
    //printf(%s,argv[1]);
    char *temp=argv[1];
    int count=0,t;
    while(*temp!='\0'){
        count=count+1;
        temp=temp+1;
    }
    printf("count-%d",count);
    
    
    for(int i=0;i<count;i++){
        
        
        for(int j=0;j<(count-i);j++){
            printf("%c",*(argv[1]+j));
            
            
        }
        printf("\n");
        
    }
    
    
    return 1;
}
