#include<stdio.h>
#include <string.h>
#include <stdlib.h>

// creating function
int concat(int x,int y){
    char str1[20];
    char str2[20];
    char str3[20];

    sprintf(str1,"%d",x);
    sprintf(str2,"%d",y);
    sprintf(str3,"%d",x);
    strcat(str1,str2);
    strcat(str2,str3);
//sting to integer
    if(atoi(str1)>atoi(str2))
        return atoi(str1);
    else
        return atoi(str2);
}
//main function

int main(){
    int x,a,b,i; //declare variables
    scanf("%d",&x);
    scanf("%d",&a);
    for(i=1;i<x;i++){
        scanf("%d",&b);
        a=concat(a,b);
    }
    printf("%d",a);
    return 0;
}
