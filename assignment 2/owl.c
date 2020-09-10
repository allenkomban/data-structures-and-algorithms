
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include"Graph.h"

int z=1;


int differByOne(char *m, char *n){
    char *x=m;
    char *y=n;
    int count1=0;
    int count2=0;
    while(*x!='\0'){
        count1++;
        x=x+1;
    }
    
    while(*y!='\0'){
        count2++;
        y=y+1;
    }
    x=m;
    y=n;
   
    
    
    if(abs(count1-count2)==0){
        
        //printf("test1\n");
        
        int flag=0;
        
        
        for(int v=0;v<count1;v++){
            
            if(*(x+v)==*(y+v)){
                
            }
            else{
                flag=flag+1;
            }
            
        }
        if(flag==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(abs(count1-count2)==1){
        
        char *swap;
        int error=0;
        int d=0;
        int f=0;
        int s;
        
        if (count1>count2){
            
        }
        else{
            swap=x;
            x=y;
            y=swap;
            s=count1;
            count1=count2;
            count2=s;
            
        }
        
        while(d<count1 || f<count2){
            
            if(*(x+d)==*(y+f)){
                d++;
                f++;
                
                
            }
            else{
                d++;
                error=error+1;
            }
        }
        
        if (error!=1){
            return 0;
        }
        else{
            return 1;
            
        }
        
    }
    else{
        return 0;
    }
    
}



void findLongestPathlength(Graph g,Vertex v,int *maxlength,int len,int d) // this funtion usues recursion to find the length of maximum length
{
    // if destination is found, update max_dist
    
    int end=0;
    for(int i=0;i<len;i++){
        Edge h;
        h=newEdge(v,i);
        
        if(isEdge(h,g) && i>v){
            end=1;
            findLongestPathlength(g,i,maxlength,len,d+1);
        }
        
        
        
        
        if (end==0)
        {
            if(*maxlength<d){
                *maxlength=d;
            }
            //return;
        }
    }
}



void findLongestPath(Graph g,Vertex v,int first,char *dictionary[],int        // this funtion uses recursion to print the paths of maximum length.
                     pathlength[],int maxpath,int len,int d){
    extern int z;
    int end=0;
    pathlength[0]=first;
    for(int i=0;i<len;i++){
        Edge y;
        y=newEdge(v,i);
        
        if(isEdge(y,g)==1 && i>v){
            end=1;
            pathlength[d+1]=i;
            
            findLongestPath(g,i,first,dictionary,pathlength,maxpath,len,d+1);
        }
        
        
        
    }
    if (end==0 && d==maxpath)
    {
        //printf("%d %d\n",v,first);
        for(int i=0;i<=maxpath;i++){
            if(i!=maxpath){
                if(i==0){
                    printf("%2d: %s -> ",z,dictionary[pathlength[i]]);
                    z++;}
                else{
                printf("%s -> ",dictionary[pathlength[i]]);
                    }}
            else{
                if (i==0){
                    printf("%2d: %s",z,dictionary[pathlength[i]]);
                    z++;
                    
                    
                }
                else{
                     printf("%s",dictionary[pathlength[i]]);
                    
                }
               
                
            }
        
        
        }
        printf("\n");
    }}




int main(){
    
    char c;
    int empty=0;
    char l[2000][40];
    int p=0,flg=0,x=0,m=0;
    //printf("enter input\n");
    while ((c = getchar()) != EOF){
        
       // if(c=='\n'){
          //  printf("newline");
        //}
        
        if (isalpha(c)==1){
            empty=1;
            if (flg==0){
                flg=1;
                x=0;
                l[p][x]=c;
                x++;
            }
            else{
                l[p][x]=c;
                x++;
            } }
        else{
            if (flg==1){
                flg=0;
                l[p][x]='\0';
                p++;
                
                
            }
            else{
                
                
            }
            
            
        }
        
    }
    
    if (flg==1){
        
        l[p][x]='\0';
        p++;
        
    }
    

    
    
    printf("Dictionary\n");
    char *v[1000];
    int flag=0;
    int count=0;
    //printf("p:%d",p);
    for(int i=0;i<p;i++){
        flag=0;
        
        for(int j=0;j<i;j++){
            //printf("%s and %s \n",argv[i],argv[j]);
            
            if(strcmp(l[i],l[j])==0){
                //printf("flagset\n");
                flag=1;
            }
        }
        
        if(flag==0){
            v[count]=l[i];
            count++;
        }
        
    }
    
    //printf("count:%d",count);
    for (int i=0;i<count;i++){
        printf("%d :%s\n",i,v[i]);
    }
    //printf("checkpoint0");
    Graph g;
    //printf("checkpoint1");
    g=newGraph(count);
    //printf("checkpoint2");

    
    for(int i=0;i<count;i++){
        
        
        for(int j=0;j<count;j++){
            if (differByOne(v[i],v[j])==1){
                
                // printf("differ:%d",differByOne(argv[i],argv[j]));
                if(i<j){
                    //printf("i:%d j:%d\n",i,j);
                    Edge e;
                    e=newEdge(i,j);
                    insertEdge(e,g);
                }}}}
    
    showGraph(g);
    int temp=0;
    //int maxcount=0;
    int tempmax=0;
    for (int i=0;i<count;i++){
        temp=0;
        findLongestPathlength(g,i,&tempmax,count,0);
        if (temp>tempmax){
            tempmax=temp;
        }
        
        
    }
    if (empty==0){
        
        printf("Longest ladder length: %d\n",tempmax);
        
    }
    else{
        
        printf("Longest ladder length: %d\n",tempmax+1);

        
    }
    int path[tempmax+1];
    
    for(int i=0;i<count;i++){
        findLongestPath(g,i,i,v,path,tempmax,count,0);
        
    }
    printf("\n");
    freeGraph(g);
    
    
    
    return 1;
}
