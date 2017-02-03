//https://www.hackerrank.com/challenges/bon-appetit
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    int k;
    int b;
    int total = 0;
    scanf("%i %i",&n,&k);
    int c[n];
    for(int i=0;i<n;i++){
        scanf("%i", &c[i]);
        total += c[i];
    }
    scanf("%i", &b);
    double annaCost = (total-c[k]+0.0)/2;
    if(b == annaCost){
        printf("Bon Appetit");
    }
    else{
        printf("%i",(int)(b-annaCost));
    }
    return 0;
}
