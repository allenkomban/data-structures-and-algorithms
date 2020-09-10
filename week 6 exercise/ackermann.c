#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int A(m,n){
    
    if(m==0 &&  (n==0 || n>0)){
        return n+1;
    }
    
    if (m>0 && n==0){
        return A(m-1,1);
    }
    
    if(m>0 && n>0){
        return A(m-1,A(m,n-1));
    }
    
}

int main(int argc, char *argv[]){
    for(int i=1;i<argc;i++){
        int inc=0;
        while(*(argv[i]+inc)!='\0'){
            //printf("%c",*(argv[i]+inc));
            if(*(argv[i]+inc)<'0'|| *(argv[i]+inc)>'9'){
                
                printf("error");
                return 0;
            }
            inc++;
            
        }
    }
    
    if (argc!=3){
        printf("enter correct number of input");
        return 0;
    }
    int n,m,ans;
    if(sscanf(argv[1], "%d",&m)!=1){
        printf("error");
        return 0;
    }
    if(sscanf(argv[2],"%d",&n)!=1){
        printf("error");
        return 0;
    
    }
    
    ans=A(m,n);
    
    printf("ans  is %d",ans);
    
    
    
   
    
    
    
    return 1;
}
