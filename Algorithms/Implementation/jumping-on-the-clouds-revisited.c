//https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *c = malloc(sizeof(int) * n);
    for(int c_i = 0; c_i < n; c_i++){
       scanf("%d",&c[c_i]);
    }
    int E = 100;
    int currentCloud = 0;
    int nextCloud = (currentCloud+k)%n;
    while(nextCloud != 0){
        E--;
        if(c[nextCloud] == 1){
            E = E-2;
        }
        currentCloud = nextCloud;
        nextCloud = (currentCloud+k)%n;
    }
    E--;
    if(c[nextCloud] == 1){
        E = E-2;
    }
    currentCloud = nextCloud;
    nextCloud = (currentCloud+k)%n;
    printf("%d",E);
    return 0;
}
