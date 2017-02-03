//https://www.hackerrank.com/challenges/append-and-delete
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    char* t = (char *)malloc(512000 * sizeof(char));
    scanf("%s",t);
    int k; 
    scanf("%d",&k);
    int sLen = strlen(s);
    //printf("slen :%d\n",sLen);
    int tLen = strlen(t);
    //printf("tlen :%d\n",tLen);
    int matchingPrefixLen = 0;
    int i=0;
    
    while(s[i]==t[i] && s[i]!=0){
        matchingPrefixLen++;
        i++;
    }
    //printf("matchingLen :%d\n",matchingPrefixLen);
    int l;
    if(sLen>=tLen){
        l = sLen-matchingPrefixLen;
    }
    else{
        l = tLen-matchingPrefixLen;
    }
    //printf("l :%d\n",l);
    //printf("min k: %d\n",sLen-2*matchingPrefixLen+tLen);
    if(k>=(sLen-2*matchingPrefixLen+tLen) && k<=sLen+tLen){
        if(l%2 == 0 && k%2 == 0 ){
            printf("Yes");
        }
        else if((l%2 == 1 && k%2 == 1)){
            printf("Yes");
        }
        else{
             printf("No");
        }
    }
    else if(k>=sLen+tLen){
         printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
