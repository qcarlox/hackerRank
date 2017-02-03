//https://www.hackerrank.com/challenges/sock-merchant
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int comparator(const void *p, const void *q) 
{
    int elem1 = *(int*)p;
    int elem2 = *(int*)q;
    if (elem1 > elem2){
        return  1;
    } 
    else if (elem1 < elem2){
        return -1;
    }
    else{
        return 0;
    }
}
int main(){
    int n; 
    scanf("%d",&n);
    int *c = malloc(sizeof(int) * n);
    for(int c_i = 0; c_i < n; c_i++){
       scanf("%d",&c[c_i]);
    }
    qsort (c, n, sizeof(int), comparator);
    int color = c[0];
    int matches = 1;
    int pairs = 0;
    for(int i=1;i<n;i++){
        if(color == c[i]){
            matches += 1;
            //printf("matches: %i\n",matches);
        }
        else{
            color = c[i];
            pairs += matches/2;
            matches = 1;
        }
    }
    pairs += matches/2;
    printf("%i",pairs);
    return 0;
}
