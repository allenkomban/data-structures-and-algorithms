//
//  asng9.c
//  practice
//
//  Created by Allen kombasseril on 6/13/19.
//  Copyright © 2019 Allen kombasseril. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main(){
    float r;
    float a[20],b[20];
    int len;
    printf("enter maximum 20 numbers, terminate with 0.0\n");
    printf("enter first element");
    scanf("%f",&r);
    a[0]=r;
    int i;
    i=1;
    len=1;
    
    do{
        printf("next:");
        scanf("%f",&a[i]);
        i++;
        len=len+1;
        
    }while(r!=0 && i<=19);
    i=0;
    
    while(i<len){
        if (i%2==0){
            b[i]=a[i]*2;
            i++;
            
        }
        else{
            b[i]=cbrt(a[i]);
            i++;
        }
        
    }
    
    printf("there are in total %d numbers given as input",len);
    
    printf("input array        2nd array\n");
        
    while(i<len){
        
        printf("%f       %f",a[i],b[i] );
        i++;
    }
        
    
    
    
    
    
    
    
}
