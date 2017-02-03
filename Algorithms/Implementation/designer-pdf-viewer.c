//https://www.hackerrank.com/challenges/designer-pdf-viewer
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int cmpfunc (const void * a, const void * b)
{
    if( *(int*)a - *(int*)b < 0 ){
        return -1;
    }
    else if( *(int*)a - *(int*)b > 0 ){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int n = 26;
    int *h = malloc(sizeof(int) * n);
    for(int h_i = 0; h_i < n; h_i++){
       scanf("%d",&h[h_i]);
    }
    char* word = (char *)malloc(512000 * sizeof(char));
    char* letterHeights = (char *)malloc(512000 * sizeof(char));
    scanf("%s",word);
    int maxH = 0;
    for(int i=0; i<strlen(word); i++){
        //printf("%c", word[i]);
        if(h[word[i]-'a']>maxH){
            maxH = h[word[i]-'a'];
        }
    }
    printf("%d", maxH*(int)strlen(word));
    
    
    return 0;
}
